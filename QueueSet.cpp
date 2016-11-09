#include "QueueSet.h"

QueueSet::QueueSet(size_t capacity) : queue(capacity), visited(capacity) {
}

bool QueueSet::empty() {
	return queue.empty();
}

size_t QueueSet::getSize() {
	return queue.getSize();
}

bool QueueSet::getVisited(size_t index) {
	return visited.contains(index);
}

void QueueSet::push(uint32_t id) {
	if (!visited.contains(id)) {
		queue.push(id);
		visited.add(id);
	}
}

uint32_t QueueSet::pop() {
	return queue.pop();
}

