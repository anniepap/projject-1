#ifndef __QUEUESET_H__
#define __QUEUESET_H__

#include "defines.h"

class ListQueueSet {

	struct Node {
		uint32_t id;
		Node* next;
		Node(uint32_t id);
	};

	size_t size;
	Node* head;
	Node* back;
public:
	ListQueueSet();
	~ListQueueSet();
	void push(uint32_t id);
	uint32_t pop();
	bool empty();
	bool find(uint32_t id);
};

#endif
