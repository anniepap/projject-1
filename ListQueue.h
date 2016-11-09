#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

#include "Queue.h"

class ListQueue : public Queue {

	struct Node {
		uint32_t id;
		Node* next;
		Node(uint32_t id);
	};

	Node* head;
	Node* back;
public:
	ListQueue(void);
	~ListQueue();

	uint32_t pop(void);
	void push(uint32_t id);
};

#endif
