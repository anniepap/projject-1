#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

#include "Job.h"
#include "../Part1/Queue.h"

class ListQueue : public Queue {
	struct Node {
		Job job;
		Node* next;
		Node(Job* job);
	};

	Node* head;
	Node* back;
public:
	ListQueue(void);
	~ListQueue();

	Job pop(void);
	void push(Job* job);
};

#endif
