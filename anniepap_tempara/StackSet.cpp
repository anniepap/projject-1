#include "StackSet.h"

StackSet::StackSet(size_t capacity) : stack(/*capacity*/), visited(capacity) {
}

bool StackSet::empty() {
	return stack.isEmpty();
}

size_t StackSet::getSize() {
	return stack.getSize();
}

bool StackSet::getVisited(size_t index) {
	return visited.contains(index);
}

void StackSet::push(uint32_t id) {
	if (!visited.contains(id)) {
		stack.push(id);
		visited.add(id);
	}
}

uint32_t StackSet::pop() {
	return stack.pop();
}

