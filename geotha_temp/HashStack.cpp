#include <cmath>
#include "HashStack.h"
using namespace std;

HashStack::HashStack(uint32_t capacity) {
	size_ = 0;
	top = 0;
	rows = (uint32_t) ceil((double) capacity/SIZE);
	hash = (uint32_t**) calloc(rows, sizeof(uint32_t*));
}

HashStack::~HashStack() {
	for (uint32_t i = 0; i < rows; ++i) {
		if (hash[i] != NULL)
			free(hash[i]);
	}
	free(hash);
}

void HashStack::push(uint32_t id) {
	uint32_t row = top/SIZE;
	uint32_t col = top%SIZE;


	if (hash[row] == NULL) {
		hash[row] = (uint32_t*) malloc(sizeof(uint32_t)*SIZE);
	}

	hash[row][col] = id;
	top++;
	size_++;
}

uint32_t HashStack::pop() {
	top -= 1;
	uint32_t row = top/SIZE;
	uint32_t col = top%SIZE;
	uint32_t id = hash[row][col];


	if (col == 0) {
		free(hash[row]);
		hash[row] = NULL;
	}
	
	size_--;

	return id;
}

uint32_t HashStack::top_(){
	uint32_t row = (top-1)/SIZE;
	uint32_t col = (top-1)%SIZE;



	return hash[row][col];
}

bool HashStack::empty() {
	return size_ == 0;
}

uint32_t HashStack::size() {
	return size_;
}
