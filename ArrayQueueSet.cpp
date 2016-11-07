#include "ArrayQueueSet.h"

ArrayQueueSet::ArrayQueueSet(size_t capacity) : QueueSet(capacity), head(0), back(0) {
	array = new uint32_t[capacity];
}

ArrayQueueSet::~ArrayQueueSet() {
	delete[] array;
}

bool ArrayQueueSet::full() {
	return ( back + 1 ) % capacity == head;
}

void ArrayQueueSet::push(uint32_t id) {
	if (!visited[id])
	{
		if (full()) std::cout << "PROSEXE PSHLE" << std::endl;
		size++;
		array[back] = id;
		back = ( back + 1 ) % capacity;
		visited[id] = true;
	}
}

uint32_t ArrayQueueSet::pop() {
	if (size == 0) std::cout << "PROSEXE PSHLE!!" << std::endl;
	size--;
	uint32_t id = array[head];
	head = ( head + 1 ) % capacity;
	return id;
}
