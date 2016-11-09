#include <cmath>
#include "HashSet.h"

HashSet::HashSet(size_t size) {
	n = (size_t) ceil(sqrt((double) size));
	set = new bool*[n];
	for (size_t i = 0; i < n; ++i) {
		set[i] = NULL;
	}
}

HashSet::~HashSet() {
	for (size_t i = 0; i < n; ++i) {
		if (set[i] != NULL)
			delete[] set[i];
	}
	delete[] set;
}

bool HashSet::contains(uint32_t id) {
	size_t k = id/n;
	size_t p = id%n;
	return (set[k] == NULL) ? false : set[k][p];
}

void HashSet::add(uint32_t id) {
	size_t k = id/n;
	size_t p = id%n;
	if (set[k] == NULL) {
		set[k] = new bool[n];
		for (size_t p = 0; p < n; ++p) {
			set[k][p] = false;
		}
	}
	set[k][p] = true;
}

