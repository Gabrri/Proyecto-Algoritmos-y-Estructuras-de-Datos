#ifndef HASHMAP_PELIS_CPP
#define HASHMAP_PELIS_CPP

#include "hashmap_P.hpp"
#include<string>
#include<vector>
#include <cmath>
// Usamos la clase hashmap dada por el profesor adaptada a nuestro obejtivo

// constructor
template <typename VT, typename KT>
HashMap<VT,KT>::HashMap() {
  table_size = INITIAL_SIZE;
  table = new KeyValueNode<VT,KT>*[table_size];
  for(int i = 0; i < table_size; ++i) table[i] = nullptr;
  count = 0;
}

template <typename VT, typename KT>
void HashMap<VT,KT>::clear() {
  KeyValueNode<VT,KT> *cursor;
  for(int i = 0; i < table_size; + +i){
    cursor = table[i];
    while(table[i] != nullptr){
      cursor = cursor->next;
      delete table[i];
      table[i] = cursor;
    }
  }
  count = 0;
}

// destructor
template <typename VT, typename KT>
HashMap<VT,KT>::~HashMap() {
  clear();
  delete[] table;
}

//funcion hash, sabemos que con los numeros primos no hay coliciones
// asi que convertiremos cada key ingresado en uno primos

template <typename VT, typename KT>
int HashMap<VT,KT>::hash_fun(KT key) {
  int count2=0; // 1  a 5
  int numprim[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999};
  int index=0;
  for(int i=0;i < 200;i++){
    count2+=1;
    key = index;
    index = pow(numprim[i],count2);
    if(count2 == 5){
      count2=0;
    }
  }
  return index % table_size;
}

template <typename VT, typename KT>
KeyValueNode<VT,KT>* HashMap<VT,KT>::search_bucket(int i, KT key) {
  KeyValueNode<VT,KT> *cursor = table[i];
  while(cursor != nullptr){
    if(cursor->key == key) return cursor;
    cursor = cursor->next;
  }
  return nullptr;
}
template <typename VT, typename KT>
void HashMap<VT,KT>::rehash() {
  int old_table_size = table_size;
  KeyValueNode<VT,KT> **old_table = table;
  table_size *= 2;
  table = new KeyValueNode<VT,KT>*[table_size];
  for(int i = 0; i < table_size; ++i) table[i] = nullptr;
  count = 0;

  KeyValueNode<VT,KT> *cursor;
  for(int i = 0; i < old_table_size; ++i){
    cursor = old_table[i];
    while(old_table[i] != nullptr){
      insert(cursor->key, cursor->value);
      cursor = cursor->next;
      delete old_table[i];
      old_table[i] = cursor;
    }
  }
  delete[] old_table;
}

// insertar un elemento al mapa
template <typename VT, typename KT>
void HashMap<VT,KT>::insert(KT key, VT value) {
  if(count == 2*table_size) rehash();
  int index = hash_fun(key);
  KeyValueNode<VT,KT> *cursor = search_bucket(index, key);
  if(cursor != nullptr){
    cursor->value = value;
  } else{
    KeyValueNode<VT,KT> *new_node = new KeyValueNode<VT,KT>;
    new_node->key = key;
    new_node->value = value;
    new_node->next = table[index];
    table[index] = new_node;
    count++;
  }
}

// obtener el elemento a traves del key y retornando los
// los elementos relacionados
template <typename VT, typename KT>
VT HashMap<VT,KT>::get(KT key ) {
  vector<string> myvector;
  KeyValueNode<VT,KT> *cursor;
  int index = hash_fun(key);
  for(int i = 0; i < table_size; ++i){
    if(key==1){
      while(cursor->next!=nullptr)
      cursor = table[i];
      if(cursor->key == pow(i,key)){
        myvector.insert(cursor->value);
        return cursor->value;
        }
    }else if(key == 2){
      cursor = table[i];
      if(cursor->key == pow(i,key)){
        myvector.insert(cursor->value);
        return cursor->value;
        }
    }else if(key == 3){
      cursor = table[i];
      if(cursor->key == pow(i,key)){
        myvector.insert(cursor->value);
        return cursor->value;
        }
    }else if(key == 4){
      cursor = table[i];
      if(cursor->key == pow(i,key)){
        myvector.insert(cursor->value);
        return cursor->value;
        }
    }else if(key == 5){
      cursor = table[i];
      if(cursor->key == pow(i,key)){
        myvector.insert(cursor->value);
        return cursor->value;
        }
    }
  }
  return 0;
}

// verificar si un elemento esta en el map por su key
template <typename VT, typename KT>
bool HashMap<VT,KT>::contains(KT key ) {
  int index = hash_fun(key);
  KeyValueNode<VT,KT> *cursor;
  for(int i = 0; i < table_size; ++i){
    cursor = table[i];
    if(cursor->key == index)return true;
  }
  return false;
}



#endif
