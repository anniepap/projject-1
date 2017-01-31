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
	return set.find(index);
}

void QueueSet::push(uint32_t id) {
	if (!set.find(id)) {
		queue.push(id);
		set.insert(id);
	}
}

uint32_t QueueSet::pop() {
	return queue.pop();
}

uint32_t QueueSet::top() {
	return queue.top();
}

