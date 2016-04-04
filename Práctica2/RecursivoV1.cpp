#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


typedef vector< vector<int> > matrix; // tipo de dato matrix
/*
 * @brief Funcion para imprimir un vector< vector<int> >  
 * @param matrix v : matriz de tipo vector< vector<int> >  
 */
void print(matrix v)
{
	for(int i = 0; i < v.size(); i++) 
		for (int j =0; j < v.at(0).size(); j++)
			cout << v[i][j] << " ";
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
vector<int> merge( matrix v1,  matrix v2){

	int f1 = 0,f2 = 0,c1 = 0,c2 = 0;
	
	vector<int> v_resultado;

	//Meter números ordenados en el vector ordenado
	while(f1 < v1.size() && f2 < v2.size() && c1 < v1.at(0).size() && c2 < v2.at(0).size()){
		if(v1.at(f1).at(c1) < v2.at(f2).at(c2)){
			v_resultado.push_back(v1.at(f1).at(c1));
			c1++;
		}
		else{
			v_resultado.push_back(v2.at(f2).at(c2));
			c2++;
		}
		if (c1+1 % v1.at(0).size()) f1++;
		if (c2+1 % v1.at(0).size()) f2++;
	}

	//Terminar de completar vector resultado
	for(f1; f1 < v1.size(); f1++)
		for (c1; c1 < v1.at(0).size(); c1++)
			v_resultado.push_back(v1.at(f1).at(c1));
	for(f2; f2 < v2.size(); f2++)
		for (c2; c2 < v2.at(0).size(); c2++)	
			v_resultado.push_back(v2.at(f2).at(c2));

	return v_resultado;
}


/*
 *
 * @brief Función para sobrecargar el operados == para dos vectores 
 * @param vectores : matriz en que cada fila corresponde a un vector 
 *	 				 ordenado
 * @return resultAux : vector ordenado a partir 
 */

matrix& operator=(const matrix  v2)
{
	matrix& m= *this;
    for (int i = 0; i < me.size(); i++){
		for (int j = 0; j< me.at(0).size();j++){
			v2[i][j] = me[i][j];		
		}
    }	
	return *this;
}

/*
 *
 * @brief Funcion Recursiva que calculara  un vector ordenado 
 * @param vectores : matriz en que cada fila corresponde a un vector 
 *	 				 ordenado
 * @return resultAux : vector ordenado a partir 
 */

vector<int> mergeKvectors(vector< vector<int> > vectores )
{


    if (vectores.size() <= 1)
       return vectores.at(0);

	int middle= vectores.size()/2;

    vector< vector<int> > up (middle ,vector<int> (vectores.at(0).size()));
	vector< vector<int> > down (vectores.size() - middle,vector<int> (vectores.at(0).size()));	

    vector<int> resultAux;
    vector<int> Aux;
	
    

    for (int i = 0; i < middle; i++){
		for (int j = 0; j< vectores.at(0).size();j++){
			up[i][j] = vectores[i][j];		
		}
    }	
   

    for (int i = middle; i < vectores.size(); i++){
		for (int j = 0; j< vectores.at(0).size();j++){
			down[i - middle][j]= vectores[i][j];		
		}
    }	

    

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
	vector<int> vectorAux;
	vector< vector<int> > vectorT (num_vectores, vector<int>(tam_vectores));
	vector< vector<int> >  vectorRes;

	for(int i = 0; i < num_vectores; i++){
		for (int j = 0 ; j < tam_vectores; j++){
			archivo >> num;
			vectorT[i][j] = num;			
		}
	}		


   cout << "------------------" << endl;



   vectorAux = mergeKvectors(vectorT);
	
	for (int i =0; i < vectorAux.size(); i++)
		cout << vectorAux[i]<<" ";

	cout << " " << endl;
	
return 0;
}
