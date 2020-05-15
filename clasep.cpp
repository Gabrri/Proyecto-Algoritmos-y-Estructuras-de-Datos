#include "peliculas.hpp"
#include<string>
#include<vector>

Peliculas::Peliculas(string titulo, int año, string director, vector <string> actores,string generos){
  t = titulo;
  a = año;
  d = director;
  ac = actores;
  g = generos

}
int Peliculas::getTitulo(){return t;}
int Peliculas::getAnho(){return a;};
string Peliculas::getDirector(){return d;}
vector <string> Peliculas::getActores(){return ac;}
string Peliculas::getGenero(){return g;}
