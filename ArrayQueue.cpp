#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(size_t capacity) : head(0), back(0), capacity(capacity) {
	array = new uint32_t[capacity];
}

ArrayQueue::~ArrayQueue() {
	delete[] array;
}

void ArrayQueue::push(uint32_t id) {
	size_++;
	array[back] = id;
	back++;
}

uint32_t ArrayQueue::pop() {
	size_--;
	uint32_t id = array[head];
	head++;
	return id;
}
