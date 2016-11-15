#include <cmath>
#include "HashSet.h"

HashSet::HashSet(size_t size) {
	rows = (size_t) ceil(((double) size)/SIZE);
	set = (bool**) calloc(rows, sizeof(bool*));
}

HashSet::~HashSet() {
	for (size_t i = 0; i < rows; ++i) {
		if (set[i] != NULL)
			free(set[i]);
	}
	free(set);
}

bool HashSet::contains(uint32_t id) {
	size_t k = id/SIZE;
	return (set[k] == NULL) ? false : set[k][id%SIZE];
}

void HashSet::add(uint32_t id) {
	size_t k = id/SIZE;
	if (set[k] == NULL) {
		set[k] = (bool*) calloc(SIZE, sizeof(bool));
	}
	set[k][id%SIZE] = true;
}

