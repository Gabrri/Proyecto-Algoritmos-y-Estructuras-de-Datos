#ifndef __HASHMAP_P_HPP
#define __HASHMAP_P_HPP

#include <iostream>
#include <stdexcept>
#include <string>

const int INITIAL_SIZE = 200;

// Tenemos la clase pelicula que va a ser el value de nuestro HashMap en donde guardaremos cada pelicula
// class Pelicula{
// public:
//   Pelicula(string titulo, int año, string director, vector <string> actores, string genero);
//   string getTitulo();
//   int getAnho();
//   string getDirector();
//   vector <string> getActores();
//   string getGenero();
//
// private:
//   int a;
//   string t, d, s, g;
//   vector <string> ac;
//
// };

template <typename VT>
struct KeyValueNode {
  int key;
  VT value;
  KeyValueNode<VT> *next;

template <typename VT>
class HashMap {
private:
  KeyValueNode<VT> **table;
  int table_size;
  int count;
  int hash_fun(int key);

public:
  HashMap();
  ~HashMap();
  void insert(int key, VT value);
  KeyValueNode<VT>* search_bucket(int i, int key);

  VT get(int key);
  bool contains(int key);

};



#include "hashmap_Pelis.cpp"
#endif
