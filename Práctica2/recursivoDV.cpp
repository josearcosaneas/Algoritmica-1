#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> combinarVectores(const vector<int> v1, const vector<int> v2){
	int i = 0, j = 0;
	vector<int> v_resultado;

	//Meter números ordenados en el vector ordenado
	while(i < v1.size() && j < v2.size()){
		if(v1.at(i) < v2.at(j)){
			v_resultado.push_back(v1.at(i));
			i++;
		}
		else{
			v_resultado.push_back(v2.at(j));
			j++;
		}
	}

	//Terminar de completar vector resultado
	for(i; i < v1.size(); i++)
		v_resultado.push_back(v1.at(i));
	for(j; j < v2.size(); j++)
		v_resultado.push_back(v2.at(j));

	return v_resultado;
}

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
	vector<int> vectorAux;
	vector< vector<int> > vectorT (num_vectores, vector<int>(tam_vectores));
	vector< vector<int> >  vectorRes;


	for(int i = 0; i < num_vectores; i++){
		for (int j = 0 ; j < tam_vectores; j++){
			archivo >> num;
			vectorT[i][j] = num;			

		}
	}

	for (int i = 0; i < num_vectores; i++){
		for (int j=0; j < tam_vectores; j++){
			cout << vectorT.at(i).at(j) << " ";
		}
		cout << "\n "	<< endl;
	}		
	return 0;
}
