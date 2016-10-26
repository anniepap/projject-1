#include "QueueSet.h"

ListQueueSet::Node::Node(uint32_t id) : id(id), next(NULL) {
}

ListQueueSet::ListQueueSet(size_t size) : size(0), head(NULL), back(NULL) {
	visited = new bool[size];
	for (size_t i = 0; i < size; ++i) {
		visited[i] = false;
	}
}

ListQueueSet::~ListQueueSet() {
	while (head != NULL) {
		pop();
	}
	delete visited;
}

void ListQueueSet::push(uint32_t id) {
	if (!visited[id])
	{
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

bool ListQueueSet::empty() {
	return size == 0;
}

size_t ListQueueSet::getSize() {
	return size;
}

bool ListQueueSet::getVisited(size_t index) {
	return visited[index];
}
