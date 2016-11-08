#include "QueueSet.h"

QueueSet::QueueSet(size_t capacity) : capacity(capacity), size(0), visited(capacity) {
}

bool QueueSet::empty() {
	return size == 0;
}

size_t QueueSet::getSize() {
	return size;
}

bool QueueSet::getVisited(size_t index) {
	return visited.contains(index);
}
