#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(size_t capacity) : head(0), back(0), capacity(capacity) {
	array = new uint32_t[capacity];
}

ArrayQueue::~ArrayQueue() {
	delete[] array;
}

bool ArrayQueue::full() {
	return ( back + 1 ) % capacity == head;
}

void ArrayQueue::push(uint32_t id) {
	size++;
	array[back] = id;
	back = ( back + 1 ) % capacity;
}

uint32_t ArrayQueue::pop() {
	size--;
	uint32_t id = array[head];
	head = ( head + 1 ) % capacity;
	return id;
}
