#ifndef _HASHMAP_PELIS_CPP_
#define _HASHMAP_PELIS_CPP_

#include "hashmap_P.hpp"
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

template <typename VT>
HashMap<VT>::HashMap() {
  table_size = INITIAL_SIZE;
  table = new KeyValueNode<VT>*[table_size];
  for(int i = 0; i < table_size; ++i) table[i] = nullptr;
  count = 0;
}

template <typename VT>
HashMap<VT>::~HashMap() {
  clear();
  delete[] table;
}

template <typename VT>
int HashMap<VT>::hash_fun(std::string key) {
  int index = 0;
  for(char c : key)
    index += c;
  return index % table_size;
}

template <typename VT>
KeyValueNode<VT>* HashMap<VT>::search_bucket(int i, std::string key) {
  KeyValueNode<VT> *cursor = table[i];
  while(cursor != nullptr){
    if(cursor->key == key) return cursor;
    cursor = cursor->next;
  }
  return nullptr;
}

template <typename VT>
void HashMap<VT>::insert(std::string key, Pelicula value) {
  if(count == 2*table_size) rehash();
  int index = hash_fun(key);
  KeyValueNode<VT> *cursor = search_bucket(index, key);
  if(cursor != nullptr){
    cursor->value = value;
  } else{
    KeyValueNode<VT> *new_node = new KeyValueNode<VT>;
    new_node->key = key;
    new_node->value = value;
    new_node->next = table[index];
    table[index] = new_node;
    count++;
  }
}

template <typename VT>
VT HashMap<VT>::get(std::string key ) {
  KeyValueNode<VT> *cursor;
  int index = hash_fun(key);
  for(int i = 0; i < table_size; ++i){
    cursor = table[i];
    if(cursor->key == index)return cursor->value;
  }
  return -1;
}


template <typename VT>
bool HashMap<VT>::contains(std::string key ) {
  int index = hash_fun(key);
  KeyValueNode<VT> *cursor;
  for(int i = 0; i < table_size; ++i){
    cursor = table[i];
    if(cursor->key == index)return true;
  }
  return false;
}

#endif
