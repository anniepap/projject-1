#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "defines.h"

class Queue {
protected:
	size_t size;
public:
	Queue(void);

	virtual void push(uint32_t id) = 0;
	virtual uint32_t pop() = 0;

	bool empty();
	size_t getSize();
};

#endif
