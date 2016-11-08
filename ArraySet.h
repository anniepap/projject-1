#ifndef __ARRAY_SET_H__
#define __ARRAY_SET_H__

#include "Set.h"

class ArraySet : public Set {
	bool* set;
public:
	ArraySet(size_t size);
	~ArraySet();
	bool contains(uint32_t id);
	void add(uint32_t id);
};

#endif
