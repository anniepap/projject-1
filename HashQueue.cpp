#include <cmath>
#include "HashQueue.h"

HashQueue::HashQueue(size_t capacity) {
	head.k = head.p = 0;
	back.k = back.p = 0;
	n = (size_t) ceil(sqrt((double) capacity));
	hash = new uint32_t*[n];
	for (size_t i = 0; i < n; ++i) {
		hash[i] = NULL;
	}
}

HashQueue::~HashQueue() {
	for (size_t i = 0; i < n; ++i) {
		if (hash[i] != NULL)
			delete[] hash[i];
	}
	delete[] hash;
}

void HashQueue::push(uint32_t id) {
	size++;
	if (back.p == 0) {
		hash[back.k] = new uint32_t[n];
	}

	hash[back.k][back.p] = id;
	back.p = ( back.p + 1 ) % n;

	if (back.p == 0)
		back.k = ( back.k + 1 ) % n;
}

uint32_t HashQueue::pop() {
	size--;

	uint32_t id = hash[head.k][head.p];
	head.p = ( head.p + 1 ) % n;

	if (head.p == 0) {
		delete[] hash[head.k];
		hash[head.k] = NULL;
		head.k = ( head.k + 1 ) % n;
	}

	return id;
}

