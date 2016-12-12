#include <cmath>
#include "HashQueue.h"

bool HashQueue::empty() {
	return size_ == 0;
}

size_t HashQueue::size() {
	return size_;
}

HashQueue::HashQueue(size_t capacity) {
	size_ = 0;
	head = back = 0;
	rows = (size_t) ceil((double) capacity/SIZE);
	hash = (uint32_t**) calloc(rows, sizeof(uint32_t*));
}

HashQueue::~HashQueue() {
	for (size_t i = 0; i < rows; ++i) {
		if (hash[i] != NULL)
			free(hash[i]);
	}
	free(hash);
}

void HashQueue::push(uint32_t id) {
	size_t row = back/SIZE;
	size_t col = back%SIZE;

	if (hash[row] == NULL) {
		hash[row] = (uint32_t*) malloc(sizeof(uint32_t)*SIZE);
	}

	hash[row][col] = id;
	back++;
	size_++;
}

uint32_t HashQueue::pop() {
	size_t row = head/SIZE;
	size_t col = head%SIZE;

	uint32_t id = hash[row][col];

	if (col == SIZE-1) {
		free(hash[row]);
		hash[row] = NULL;
	}
	head++;
	size_--;

	return id;
}

