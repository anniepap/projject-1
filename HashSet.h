#ifndef __HASH_SET_H__
#define __HASH_SET_H__

#include "Set.h"

class HashSet : public Set {
	size_t rows;
	bool** set;
	size_t size;
	size_t number_of_elements;
public:
	HashSet(size_t size);
	~HashSet();
	bool find(uint32_t id);
	void insert(uint32_t id);
	bool IsFull();
};

#endif
