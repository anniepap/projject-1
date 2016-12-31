#include "ListQueue.h"

ListQueue::Node::Node(Job* job) : job(*job), next(NULL) {
}

ListQueue::ListQueue(void) : size_(0), head(NULL), back(NULL) {
}

ListQueue::~ListQueue() {
	while (head != NULL) {
		pop();
	}
}

void ListQueue::push(Job* job) {
	size_++;
	Node* node = new Node(job);
	if (!head) head = back = node;
	else back = back->next = node;
}

Job ListQueue::pop() {
	size_--;
	Node* node = head;
	head = head->next;
	if (!head) back = NULL;
	Job job = node->job;
	delete node;
	return job;
}


bool ListQueue::empty() {
	return size_ == 0;
}

size_t ListQueue::size() {
	return size_;
}
