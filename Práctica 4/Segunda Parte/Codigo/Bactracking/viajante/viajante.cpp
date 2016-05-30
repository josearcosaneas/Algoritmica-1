#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>
#include <limits>

using namespace std;

double cota_local = 0.0;
double cota_global = numeric_limits<double>::max();
int nodos_explorados = 0;

struct Ciudad{
	int indice;
	double x;
	double y;
} ciudad;

//Método para leer las ciudades desde un fichero
void leerCiudades(vector<Ciudad> &ciudades, const char fichero[]){

	ifstream f(fichero);
	double valor_leido = 0.0;
	int num_ciudades = 0;

	if(f){
		f.ignore(11);
		f >> num_ciudades;
		
		for(int i = 0; i < num_ciudades; i++){
			f >> valor_leido;
			ciudad.indice = valor_leido;
			f >> valor_leido;
			ciudad.x = valor_leido;
			f >> valor_leido;
			ciudad.y = valor_leido;

			ciudades.push_back(ciudad);
		}
	}
	f.close();
}

//Método para calcular la distancia entre dos ciudades
double calcularDistancia(Ciudad a, Ciudad b){

	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Funcion para generar una matriz de distancias (FUNCIONA)
vector< vector<double> > generaMatriz(vector <Ciudad> ciudades){

	vector<vector<double> > salida(ciudades.size());
	double distancia = 0.0;

	for ( int i = 0 ; i < ciudades.size() ; i++ )
	   salida[i].resize(ciudades.size());

	for (int i =0; i < ciudades.size() ; i++){
		for(int j =0; j<ciudades.size();j++){
			if(i==j)
				salida[i][j]=0;
			else{
				distancia = calcularDistancia(ciudades[i], ciudades[j]);			
				salida[i][j]= distancia;
			}		
		}
	}
	return salida;
}

void backtracking (int nivel, int ciudad_actual, vector<bool> &visitadas, int solucion[], const vector< vector<double> > &matriz) {

	visitadas[ciudad_actual] = true;
	solucion[nivel - 1] = ciudad_actual;
	nodos_explorados++; 

	for (int siguiente_ciudad = 0; siguiente_ciudad < visitadas.size(); siguiente_ciudad++) {
		if (visitadas[siguiente_ciudad] == false) {	

			cota_local = cota_local + matriz[ciudad_actual][siguiente_ciudad];
			if (cota_local < cota_global) {				
				backtracking(nivel + 1, siguiente_ciudad, visitadas, solucion, matriz);
			}
			else{
				if (nivel == (visitadas.size() - 1)) {		

					cota_local += matriz[0][ciudad_actual];					
					if (cota_local < cota_global) {
						cota_global = cota_local;
					} 
				}
				else {
					cota_local = cota_local - matriz[ciudad_actual][siguiente_ciudad];
				}
			}	
			visitadas[siguiente_ciudad] = false;
		}
	}
}

unsigned int factorial(unsigned int n){

    if (n == 0)
       return 1;

    return n * factorial(n - 1);
}

int main (int argc, char* argv[]) {	
	
	if(argc != 2){
		cerr << "USO: ./" << argv[0] << " archivo_ciudades.tsp" << endl;
		exit(1);
	}

	vector<Ciudad> ciudades;
	vector< vector<double> > matriz_distancias; 

	leerCiudades(ciudades, argv[1]);
	matriz_distancias = generaMatriz(ciudades);

	vector<bool> visitadas(ciudades.size(), false);
	int solucion[ciudades.size()];

	backtracking (1, ciudades[0].indice-1, visitadas, solucion, matriz_distancias);

	double distancia = 0;

	cout << "Matriz de distancias" << endl;
	for(int i = 0; i < matriz_distancias.size(); i++){
		for(int j = 0; j < matriz_distancias.size(); j++){
			cout << matriz_distancias[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i < ciudades.size(); i++){
		distancia += matriz_distancias[solucion[i-1]][solucion[i]];
		cout << "CIUDAD " << solucion[i-1] + 1<< endl;
	}

	cout << "CIUDAD " << solucion[visitadas.size() - 1] + 1<< endl;

	distancia += matriz_distancias[0][solucion[ciudades.size() - 1]];

	cout << "DISTANCIA: " << distancia << endl;

	int nodos_totales = factorial(ciudades.size());
	cout << "NODOS TOTALES " << nodos_totales << endl;
	cout << "NODOS PODADOS " << nodos_totales - nodos_explorados << endl;
	cout << "NODOS EXPLORADOS " << nodos_explorados << endl;


	return 0;
}
