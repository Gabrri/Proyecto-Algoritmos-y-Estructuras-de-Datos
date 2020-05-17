#ifndef __HASHMAP_P_HPP
#define __HASHMAP_P_HPP

#include <iostream>
#include <stdexcept>
#include <string>

const int INITIAL_SIZE = 200;

template <typename VT, typename KT>
struct KeyValueNode {
  KT key;
  VT value;
  KeyValueNode<VT,KT> *next;
};

template <typename VT, typename KT>
class HashMap {
private:
  KeyValueNode<VT,KT> **table;
  int table_size;
  int count;
  int hash_fun(KT key);
  KeyValueNode<VT,KT>* search_bucket(int i, KT key);
  void rehash();

public:
  HashMap();
  ~HashMap();
  void clear();
  void insert(KT key, VT value);
  VT get(KT key);
  bool contains(KT key);

};



#include "hashmap_Pelis.cpp"
#endif
