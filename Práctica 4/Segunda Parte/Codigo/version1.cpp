#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>
#define MAX_DISTANCE	9999999999

using namespace std;
///////////////////////////////////////////////////////////////////
struct Ciudad{
	int indice;
	double x;
	double y;
} ciudad;
///////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////7
//Método para calcular la distancia entre dos ciudades (FUNCIONA)
double calcularDistancia(Ciudad a, Ciudad b){

	double distancia = 0.0, x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
	x1 = a.x;
	y1 = a.y;
	x2 = b.x;
	y2 = b.y;
	distancia = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
	return distancia;
}
///////////////////////////////////////////////////////////////////
// Funcion para generar una matriz de distancias (FUNCIONA)
vector< vector<double> > generaMatriz(vector <Ciudad> ciudades){

	vector <double> fila;	
	vector<vector<double> > salida(ciudades.size());

	for ( int i = 0 ; i < ciudades.size() ; i++ )
	   salida[i].resize(ciudades.size());

	double distancia = 0.0, x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
	for (int i =0; i < ciudades.size() ; i++){
		for(int j =0; j<ciudades.size();j++){
			if(i==j) salida[i][j]=0;
			else{
				distancia = calcularDistancia(ciudades[i], ciudades[j]);			
				salida[i][j]= distancia;
			}		
		}
	}
	return salida;
}
//////////////////////   A PARTIR DE AQUI ES MIERDA (NO ESTA PROBADO)///
// Sin probar probablemente tambien mierda
void mincostCalculation(int city,double &minimum_cost, vector< <double> > cost_matrix)
{
	int i,ncity;
	visited[city]=1;
	printf("%d ===> ",city+1);
	ncity=findMinValue(city);
	if(ncity==MAX_DISTANCE)
	{
		ncity=0;
		printf("%d",ncity+1);
		minimum_cost+=cost_matrix[city][ncity];
		return;
	}
	mincostCalculation(ncity);
}
/// Es mierda no esta probado 
double findMinValue(double c, vector< <double> > cost_matrix)
{	
	int i =MAX_DISTANCE;
	double nc=MAX_DISTANCE;
	double min=MAX_DISTANCE,kmin;
	for(i=0;i<total_input;i++)
	{
		if((cost_matrix[c][i]!=0)&&(visited[i]==0))
			if(cost_matrix[c][i]<min)
			{
				min=cost_matrix[i][0]+cost_matrix[c][i];
				kmin=cost_matrix[c][i];
				nc=i;
			}
	}

	if(min!=MAX_DISTANCE)
		minimum_cost+=kmin;
	return nc;
}
//////////////////////////////////////////////////////////////////7
// Funcion principal
int main(int argc, char* argv[]){
	vector<Ciudad> ciudades;
	leerCiudades(ciudades, argv[1]);
	vector< vector<double> > matriz = generaMatriz(ciudades);
	for (int i = 0; i<ciudades.size(); i++){
		for (int j = 0; j<ciudades.size(); j++){
			cout << matriz[i][j] << " ";
		}
	cout << endl;
	}	
	//////////////////////////////////////////////////////////////



	return 0;
}
