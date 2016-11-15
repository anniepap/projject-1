#include "QueueSet.h"

QueueSet::QueueSet(size_t capacity) : queue(capacity), set(capacity) {
}

bool QueueSet::empty(void) {
	return queue.empty();
}

size_t QueueSet::size(void) {
	return queue.size();
}

bool QueueSet::visited(size_t index) {
	return set.contains(index);
}

void QueueSet::push(uint32_t id) {
	if (!set.contains(id)) {
		queue.push(id);
		set.add(id);
	}
}

uint32_t QueueSet::pop() {
	return queue.pop();
}

