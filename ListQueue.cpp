#include "ListQueue.h"

ListQueue::Node::Node(uint32_t id) : id(id), next(NULL) {
}

ListQueue::ListQueue(void) : head(NULL), back(NULL) {
}

ListQueue::~ListQueue() {
	while (head != NULL) {
		pop();
	}
}

void ListQueue::push(uint32_t id) {
	size++;
	Node* node = new Node(id);
	if (!head) head = back = node;
	else back = back->next = node;
}

uint32_t ListQueue::pop() {
	size--;
	Node* node = head;
	head = head->next;
	if (!head) back = NULL;
	uint32_t id = node->id;
	delete node;
	return id;
}

