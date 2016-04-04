#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


class matrix
{
public:
	matrix(int filas, int columnas)
	{
		datos.resize(filas);
		for(int i = 0; i< filas; i++)
		{
			datos[i].resize(columnas);
		}
	}
	vector< vector<int> > datos;
	/*
 *
 * @brief Función para sobrecargar el operados == para dos vectores 
 * @param vectores : matriz en que cada fila corresponde a un vector 
 *	 				 ordenado
 * @return resultAux : vector ordenado a partir 
 */

matrix& operator=( const matrix  v2)
{
	matrix& m= *this;
    for (int i = 0; i < this->datos.size(); i++){
		for (int j = 0; j< this->datos.at(0).size();j++){
			this->datos[i][j] = v2.datos[i][j];
		}
    }	
	return *this;
}

};

//typedef vector< vector<int> > matrix; // tipo de dato matrix
/*
 * @brief Funcion para imprimir un vector< vector<int> >  
 * @param matrix v : matriz de tipo vector< vector<int> >  
 */
void print(matrix v)
{
	for(int i = 0; i < v.datos.size(); i++) 
	{

		for (int j =0; j < v.datos.at(0).size(); j++)
		{
			cout << v.datos[i][j] << " ";
		}
	}
	cout << endl;
}

/*
 * @brief Función combinar dos vector< vector<int> > en otro ya ordenado
 * por filas
 *
 * @param matrix v1
 * @param matrix v2
 * @return vector<int>
 */
matrix merge( matrix v1,  matrix v2){

	int f1 = 0,f2 = 0,c1 = 0,c2 = 0, fr=0, cr=0;
	
	matrix v_resultado(v1.datos.size()+v2.datos.size(),v1.datos.at(0).size());

	//Meter números ordenados en el vector ordenado
	while(f1 < v1.datos.size() && f2 < v2.datos.size() && c1 < v1.datos.at(0).size() && c2 < v2.datos.at(0).size()){
		if(v1.datos.at(f1).at(c1) < v2.datos.at(f2).at(c2)){
			v_resultado.datos[fr][cr] = v1.datos.at(f1).at(c1);
			c1++;
			cr++;
		}
		else{
			v_resultado.datos[fr][cr] = v1.datos.at(f2).at(c2);
			c2++;
			cr++;
		}
		if (c1+1 % v1.datos.at(0).size()) f1++;
		if (c2+1 % v1.datos.at(0).size()) f2++;
		if (cr+1 % v1.datos.at(0).size()) fr++;

	}

	//Terminar de completar vector resultado
	for(f1; f1 < v1.datos.size(); f1++)
	{
		for (c1; c1 < v1.datos.at(0).size(); c1++)
		{
			v_resultado.datos[fr][cr] = v1.datos.at(f1).at(c1);
			cr++;
			if (cr+1 % v1.datos.at(0).size()) fr++;
		}
			
	}
	for(f2; f2 < v2.datos.size(); f2++)
	{
		for (c2; c2 < v2.datos.at(0).size(); c2++)
		{

			v_resultado.datos[fr][cr] = v1.datos.at(f2).at(c2);
			cr++;
			if (cr+1 % v1.datos.at(0).size()) fr++;

		}
			
	}

	return v_resultado;
}


/*
 *
 * @brief Funcion Recursiva que calculara  un vector ordenado 
 * @param vectores : matriz en que cada fila corresponde a un vector 
 *	 				 ordenado
 * @return resultAux : vector ordenado a partir 
 */

matrix mergeKvectors(matrix &vectores)
{


    if (vectores.datos.size() <= 1)
    {
    	
        return vectores;
    }
    	

    int middle;
   	if(vectores.datos.size()%2 == 0)
   	{
   		middle = vectores.datos.size()/2;
   	}
   	else
   	{
   		middle = (vectores.datos.size()/2) +1;
    }
	

    matrix up (middle ,vectores.datos.at(0).size());
	matrix down (vectores.datos.size() - middle,vectores.datos.at(0).size());	
	

    matrix resultAux(100,100);
    vector<int> Aux;
	
    

    for (int i = 0; i < middle; i++){
		for (int j = 0; j< vectores.datos.at(0).size();j++){
			up.datos[i][j] = vectores.datos[i][j];		
		}
    }	
   

    for (int i = middle; i < vectores.datos.size(); i++){
		for (int j = 0; j< vectores.datos.at(0).size();j++){
			down.datos[i - middle][j]= vectores.datos[i][j];		
		}
    }	

    
    cout << "HE LLEGADO!!!" << endl;
    print(up);
    print(down);
    up = mergeKvectors(up);
    down = mergeKvectors(down);
    resultAux = merge(up, down);

 
	return resultAux;   
}
/*
 *
 * @brief Funcion Principal: 
 *
 */
int main(int argc, char const *argv[]){

	if (argc != 4){
		cerr << "Formato " << argv[0] << "<ruta_del_archivo_de_entrada>  <num_elem>  <num_vect>" << endl;
		return -1;
    }

	int tam_vectores = atoi(argv[2]); //Tamaño vectores
	int num_vectores = atoi(argv[3]); //Número vectores

	int num = 0;
	string ruta=argv[1];
	ifstream archivo(ruta.c_str());
	// cargamos todos los vectores en una matriz de tipo vector<vector>	
	matrix vectorAux(num_vectores,tam_vectores);
	matrix vectorT (num_vectores, tam_vectores);
	vector< vector<int> >  vectorRes;

	for(int i = 0; i < num_vectores; i++){
		for (int j = 0 ; j < tam_vectores; j++){
			archivo >> num;
			vectorT.datos[i][j] = num;			
		}
	}		

	
   cout << "------------------" << endl;

   vectorAux = mergeKvectors(vectorT);
	
	/*for (int i =0; i < vectorAux.size(); i++)
		cout << vectorAux[i]<<" ";

	cout << " " << endl;
	*/
	print(vectorAux);
	return 0;
}
