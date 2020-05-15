#ifndef _PELICULAS_HPP_
#define _PELICULAS_HPP_

#include <iostream>
#include <string>

class Pelicula{
public:
  Pelicula(string titulo, int año, string director, vector <string> actores, string genero);
  string getTitulo();
  int getAnho();
  string getDirector();
  vector <string> getActores();
  string getGenero();

private:
  int a;
  string t, d, s, g;
  vector <string> ac;

};

#endif //_peliculas_h_
