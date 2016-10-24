#include "QueueSet.h"

ListQueueSet::Node::Node(uint32_t id) : id(id), next(NULL) {
}

ListQueueSet::ListQueueSet() : size(0), head(NULL), back(NULL) {
}

ListQueueSet::~ListQueueSet() {
	while (head != NULL) {
		pop();
	}
}

void ListQueueSet::push(uint32_t id) {
	if (!find(id)) {
		size++;
		Node* node = new Node(id);
		if (!head) head = back = node;
		else back = back->next = node;
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

bool ListQueueSet::empty() {
	return size == 0;
}

bool ListQueueSet::find(uint32_t id) {
	Node* node = head;
	while (node != NULL) {
		if (node->id == id) return true;
		node = node->next;
	}
	return false;
}

