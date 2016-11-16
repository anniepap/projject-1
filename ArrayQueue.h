#ifndef __ARRAY_QUEUE_H__
#define __ARRAY_QUEUE_H__

#include "Queue.h"

class ArrayQueue : public Queue {
	size_t head;
	size_t back;
	size_t capacity;
	uint32_t* array;
public:
	ArrayQueue(size_t capacity);
	~ArrayQueue();

	uint32_t pop(void);
	void push(uint32_t id);
};

#endif
