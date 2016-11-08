#include "ArraySet.h"

ArraySet::ArraySet(size_t size) {
	set = new bool[size];
	for (size_t i = 0; i < size; ++i) {
		set[i] = false;
	}
}

ArraySet::~ArraySet() {
	delete[] set;
}

bool ArraySet::contains(uint32_t id) {
	return set[id];
}

void ArraySet::add(uint32_t id) {
	set[id] = true;
}

