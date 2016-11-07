#include "QueueSet.h"

QueueSet::QueueSet(size_t capacity) : capacity(capacity), size(0) {
	visited = new bool[capacity];
	for (size_t i = 0; i < capacity; ++i) {
		visited[i] = false;
	}
}

QueueSet::~QueueSet() {
	delete visited;
}

bool QueueSet::empty() {
	return size == 0;
}

size_t QueueSet::getSize() {
	return size;
}

bool QueueSet::getVisited(size_t index) {
	return visited[index];
}
