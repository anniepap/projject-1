#include "Queue.h"

Queue::Queue(void) {
	size_ = 0;
}

bool Queue::empty() {
	return size_ == 0;
}

size_t Queue::size() {
	return size_;
}

