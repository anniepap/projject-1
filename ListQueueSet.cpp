#include "ListQueueSet.h"

ListQueueSet::Node::Node(uint32_t id) : id(id), next(NULL) {
}

ListQueueSet::ListQueueSet(size_t capacity) : QueueSet(capacity), head(NULL), back(NULL) {
}

ListQueueSet::~ListQueueSet() {
	while (head != NULL) {
		pop();
	}
}

void ListQueueSet::push(uint32_t id) {
	if (!visited[id]) {
		size++;
		Node* node = new Node(id);
		if (!head) head = back = node;
		else back = back->next = node;
		visited[id] = true;
	}
}

uint32_t ListQueueSet::pop() {
	size--;
	Node* node = head;
	head = head->next;
	if (!head) back = NULL;
	uint32_t id = node->id;
	delete node;
	return id;
}

