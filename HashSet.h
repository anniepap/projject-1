#ifndef __HASH_SET_H__
#define __HASH_SET_H__

#include "Set.h"

class HashSet : public Set {
	size_t n;
	bool** set;
	void assert(size_t key);
public:
	HashSet(size_t size);
	~HashSet();
	bool contains(uint32_t id);
	void add(uint32_t id);
};

#endif