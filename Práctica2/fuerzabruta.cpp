#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <fstream>
//#include <algorithm>
#include <vector>



int main(int argc, char * argv[])
{

  if (argc != 4)
    {
      cerr << "Formato " << argv[0] << "<ruta_del_archivo_de_entrada>  <num_elem>  <num_vect>" << endl;
      return -1;
    }

    /*
    Lo que haremos será leer cual es el archivo de entrada, la cantidad de filas y la cantidad de elementos por fila


    */
  int n = atoi(argv[2]);
  int k=atoi(argv[3]);
  int a=0;
  int num;
  string ruta=argv[1];
  ifstream archivo(ruta.c_str());
  vector<int> gigante ;
  while(a<n*k){
  archivo >> num;
  gigante.push_back(num);
  a++;
}

 for(int i=0;i<gigante.size()-1;i++)
    for (int j=i+1; j<gigante.size(); j++)
      if(gigante.at(i) > gigante.at(j)){
        num=gigante.at(i);
        gigante.at(i) = gigante.at(j);
        gigante.at(j) = num;
      }


for(int i=0;i<gigante.size();i++)
  cout<<gigante.at(i);
}
