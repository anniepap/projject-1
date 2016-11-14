#include <cmath>
#include "HashQueue.h"

#define SIZE 1000

HashQueue::HashQueue(size_t capacity) {
	head = back = 0;
	rows = (size_t) ceil((double) capacity/SIZE);
	hash = new uint32_t*[rows];
	for (size_t i = 0; i < rows; ++i) {
		hash[i] = NULL;
	}
}

HashQueue::~HashQueue() {
	for (size_t i = 0; i < rows; ++i) {
		if (hash[i] != NULL)
			delete[] hash[i];
	}
	delete[] hash;
}

void HashQueue::push(uint32_t id) {
	size_t row = back/SIZE;
	if (hash[row] == NULL) {
		hash[row] = new uint32_t[SIZE];
	}

	hash[row][back%SIZE] = id;
	back++;
	size++;
}

uint32_t HashQueue::pop() {
	size_t row = head/SIZE;
	size_t col = head%SIZE;
	uint32_t id = hash[row][col];

	if (col == SIZE-1) {
		delete[] hash[row];
		hash[row] = NULL;
	}
	head++;
	size--;

	return id;
}

