#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

#include "Job.h"
//#include "../Part1/Queue.h"

// Prepei na doume an kanoume pio genikes tis domes h' den tha klironomei apo Queue

class ListQueue /*: public Queue prosorino*/ {
	size_t size_;		

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

	bool empty();
	size_t size();
};

#endif
