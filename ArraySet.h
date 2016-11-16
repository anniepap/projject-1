#ifndef __ARRAY_SET_H__
#define __ARRAY_SET_H__

#include "Set.h"

class ArraySet : public Set {
	bool* set;
public:
	ArraySet(size_t size);
	~ArraySet();
	bool find(uint32_t id);
	void insert(uint32_t id);
};

#endif
