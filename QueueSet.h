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
	bool* visited;
public:
	ListQueueSet(size_t size);
	~ListQueueSet();
	void push(uint32_t id);
	uint32_t pop();
	bool empty();
	size_t getSize();
	bool getVisited(size_t index);
};

#endif
