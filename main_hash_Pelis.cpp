#include <iostream>
#include <string>
#include <fstream>
#include "hashmap_Pelis.cpp"
using namespace std;


int main() {
  // LEER TABLA EXCEL E IR GUARDANDO EN TABLA HASH

  HashMap<string,string> my_map;

    string movies[400]; // guardamos los datos de las peliculas en un array, y sabemos que cada 5 datos es una pelicula nueva
    ifstream lectura_Datos;
    lectura_Datos.open("BaseDatos_Pelicula.txt",ios::in);
    if(lectura_Datos.fail()){
      cout << "ERROr" << endl;
    }
    while(!lectura_Datos.eof()){
      for(int i = 1; i < 400; i++){
        getline(lectura_Datos,movies[i]);
      }
    }
    // insertamos las peliculas al mapa
    for(int i = 0; i < 400; i++){
      my_map.insert(to_s(i),moies[i]);
    }

    lectura_Datos.close();

  // leer el archivo que dice los datos que se quieren buscar
    int instruc;
    ifstream file1;
    file1.open("arch1.txt",ios::in); // archivo en modo lectura
    if(file1.fail()){
      cout << "ERROR" << endl;
    }
    while(!file1.eof()){
      getline(file1,instruc);
    }
    //cout << my_map.get(instruc);
    file1.close();


  // Crear el archivo para guardar los resultados obtenidos
  // al buscar la Pelicula para botarle los resultados al usuario
  ofstream file2;
  file2.open("arch2.txt");
  //file2 <<my_map.get(instruc);
  file2.close();




  return 0;
}
