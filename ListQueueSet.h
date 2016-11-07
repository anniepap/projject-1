#ifndef __LIST_QUEUESET_H__
#define __LIST_QUEUESET_H__

#include "QueueSet.h"

class ListQueueSet : public QueueSet {

	struct Node {
		uint32_t id;
		Node* next;
		Node(uint32_t id);
	};

	Node* head;
	Node* back;
public:
	ListQueueSet(size_t size);
	~ListQueueSet();

	uint32_t pop(void);
	void push(uint32_t id);
};

#endif
