#ifndef __HASH_QUEUE_H__
#define __HASH_QUEUE_H__

#include "defines.h"

class HashQueue {
	size_t size_;
	size_t head;
	size_t back;

	size_t rows;
	uint32_t** hash;
public:
	HashQueue(size_t capacity);
	~HashQueue();

	uint32_t pop(void);
	void push(uint32_t id);
	bool empty(void);
	size_t size(void);
};

#endif
