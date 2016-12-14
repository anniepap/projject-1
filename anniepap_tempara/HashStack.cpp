#include <cmath>
#include "HashStack.h"

bool HashStack::empty() {
	return size_ == 0;
}

size_t HashStack::size() {
	return size_;
}

HashStack::HashStack(size_t capacity) {
	size_ = 0;
	top = 0;
	rows = (size_t) ceil((double) capacity/SIZE);
	hash = (uint32_t**) calloc(rows, sizeof(uint32_t*));
}

HashStack::~HashStack() {
	for (size_t i = 0; i < rows; ++i) {
		if (hash[i] != NULL)
			free(hash[i]);
	}
	free(hash);
}

void HashStack::push(uint32_t id) {
	size_t row = top/SIZE;
	size_t col = top%SIZE;

	if (hash[row] == NULL) {
		hash[row] = (uint32_t*) malloc(sizeof(uint32_t)*SIZE);
	}

	hash[row][col] = id;
	top++;
	size_++;
}

uint32_t HashStack::pop() {
	top -= 1;
	size_t row = top/SIZE;
	size_t col = top%SIZE;
	uint32_t id = hash[row][col];

	if (col == SIZE-1) {
		free(hash[row]);
		hash[row] = NULL;
	}
	
	size_--;

	return id;
}
