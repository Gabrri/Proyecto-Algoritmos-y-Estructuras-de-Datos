#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "hashmap_Pelis.cpp"
using namespace std;


int main() {
  // LEER TABLA EXCEL E IR GUARDANDO EN TABLA HASH

  HashMap<int> my_map;

  ifstream lectura;
    lectura.open("BaseDeDatos_Peliculas.xlsx",ios::in);
    string mystrings[200]={};
    while (lectura.good())
    {
      for(int i = 1; i < 201; i++){
        getline(lectura,mystrings[i]);
        my_map.insert(i,mystrings[i]);
      }
    }
    lectura.close();

  // leer el archivo que dice los datos que se quieren buscar
  string instruc;
  ifstream file1;
    lfile1.open("arch1.txt",ios::in); // archivo en modo lectura
    if(file1.fail()){
      cout << '\n';
    }
    while(!file.eof()){
      getline(file1,instruc);
      cout << my_map.get(instruct);
    }
    lectura.close();


  // Crear el archivo para guardar los resultados obtenidos
  // al buscar la Pelicula
  ofstream file2;
  file2.open("arch2.txt");
  file2 << my_map.get(instruct);
  file2.close();




  return 0;
}
