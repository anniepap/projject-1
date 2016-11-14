#include <cmath>
#include "HashSet.h"

#define COLUMNS 256

HashSet::HashSet(size_t size) {
	rows = (size_t) ceil(((double) size)/COLUMNS);
	set = new bool*[rows];
	for (size_t i = 0; i < rows; ++i) {
		set[i] = NULL;
	}
}

HashSet::~HashSet() {
	for (size_t i = 0; i < rows; ++i) {
		if (set[i] != NULL)
			delete[] set[i];
	}
	delete[] set;
}

bool HashSet::contains(uint32_t id) {
	size_t k = id/COLUMNS;
	return (set[k] == NULL) ? false : set[k][id%COLUMNS];
}

void HashSet::add(uint32_t id) {
	size_t k = id/COLUMNS;
	if (set[k] == NULL) {
		set[k] = new bool[COLUMNS];
		for (size_t p = 0; p < COLUMNS; ++p) {
			set[k][p] = false;
		}
	}
	set[k][id%COLUMNS] = true;
}

