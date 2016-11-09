#include "Queue.h"

Queue::Queue(void) : size(0) {
}

bool Queue::empty() {
	return size == 0;
}

size_t Queue::getSize() {
	return size;
}

