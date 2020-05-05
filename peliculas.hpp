#ifndef _PELICULAS_HPP_
#define _PELICULAS_HPP_

#include <iostream>
#include <string>

class Pelicula{
public:
  Pelicula(string titulo, int año, string director, vector <string> actores, vector <string> generos);
  string getTitulo();
  int getAnho();
  string getDirector();
  vector <string> getActores();
  vector <string> getGeneros();

private:
  int a;
  string t, d, s;
  vector <string> ac, g;

};

#endif //_peliculas_h_
