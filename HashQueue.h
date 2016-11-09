#ifndef __HASH_QUEUE_H__
#define __HASH_QUEUE_H__

#include "Queue.h"

class HashQueue : public Queue {
	struct Point {
		size_t k;
		size_t p;
	};
	Point head;
	Point back;

	size_t n;
	uint32_t** hash;
public:
	HashQueue(size_t capacity);
	~HashQueue();

	bool full();
	uint32_t pop(void);
	void push(uint32_t id);
};

#endif
