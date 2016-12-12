#include <cmath>
#include "HashSet.h"

HashSet::HashSet(size_t size) {
	rows = (size_t) ceil(((double) size)/SIZE);
	set = (bool**) calloc(rows, sizeof(bool*));
	size_ = 0;
}

HashSet::~HashSet() {
	for (size_t i = 0; i < rows; ++i) {
		if (set[i] != NULL)
			free(set[i]);
	}
	free(set);
}

bool HashSet::find(uint32_t id) {
	size_t k = id/SIZE;
	return (set[k] == NULL) ? false : set[k][id%SIZE];
}

void HashSet::insert(uint32_t id) {
	size_t k = id/SIZE;
	if (set[k] == NULL) {
		set[k] = (bool*) calloc(SIZE, sizeof(bool));
	}
	set[k][id%SIZE] = true;
	size_++;
}

void HashSet::erase(uint32_t id) {
	size_t k = id/SIZE;
	set[k][id%SIZE] = false;
	size_--;
}

