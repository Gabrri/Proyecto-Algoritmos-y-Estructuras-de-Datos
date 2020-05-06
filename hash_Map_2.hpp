#ifndef _hash_Map_2_hpp_
#define _hash_Map_2_hpp_

#include <iostream>
#include <list>

const std::size_t INITIAL_DIMENSION = 200;

template<typename dataType>
class hashf {
public:
	std::size_t operator()(const dataType & key);

};


template<typename keyType, typename valueType>
class hash_map {
private:

	struct pair {
		keyType key;
		valueType val;
	};

	std::size_t count;
	std::size_t nBuckets;
	std::list<pair> *table;

	std::size_t hashing(const keyType & key);

public:

	hash_map();
	~hash_map();
	void find(const keyType & key);
	bool insert(const keyType & key, const valueType & data);
	bool remove(const keyType & key);

	void clear();
	void display() const;
};

#include "hash_Map_2.cpp"

#endif //_hash_Map_2_hpp_
