#ifndef _HASHMAP_PELIS_CPP_
#define _HASHMAP_PELIS_CPP_

#include "hashmap_P.hpp"
#include<string>
#include<vector>
// Usamos la clase hashmap dada por el profesor adaptada a nuestro obejtivo

// constructor
template <typename VT>
HashMap<VT>::HashMap() {
  table_size = INITIAL_SIZE;
  table = new KeyValueNode<VT>*[table_size];
  for(int i = 0; i < table_size; ++i) table[i] = nullptr;
  count = 0;
}

// destructor
template <typename VT>
HashMap<VT>::~HashMap() {
  clear();
  delete[] table;
}

//funcion hash, sabemos que con los numeros primos no hay coliciones
// asi que convertiremos cada key ingresado en uno primos

template <typename VT>
int HashMap<VT>::hash_fun(int key) {
  bool primo = true;
  int index;
  int n = 400;
  for(int i = 1; i < 6; i++){
    while (400 > 0){
      es_primo = 1;
      for (d = 2; d < n; ++d) {
          if (n % d == 0) {
              for(int c: key)
                index = n^i;
          }
      }
    }
  }
  return index % table_size
}

template <typename VT>
KeyValueNode<VT>* HashMap<VT>::search_bucket(int i, int key) {
  KeyValueNode<VT> *cursor = table[i];
  while(cursor != nullptr){
    if(cursor->key == key) return cursor;
    cursor = cursor->next;
  }
  return nullptr;
}

// insertar un elemento al mapa
template <typename VT>
void HashMap<VT>::insert(int key, VT value) {
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

// obtener el elemento a traves del key y retornando los
// los elementos relacionados
template <typename VT>
VT HashMap<VT>::get(int key ) {
  KeyValueNode<VT> *cursor;
  int index = hash_fun(key);
  for(int i = 0; i < table_size; ++i){
    cursor = table[i];
    if(cursor->key == index)return cursor->value;
  }
  return -1;
}

// verificar si un elemento esta en el map por su key
template <typename VT>
bool HashMap<VT>::contains(int key ) {
  int index = hash_fun(key);
  KeyValueNode<VT> *cursor;
  for(int i = 0; i < table_size; ++i){
    cursor = table[i];
    if(cursor->key == index)return true;
  }
  return false;
}



#endif
