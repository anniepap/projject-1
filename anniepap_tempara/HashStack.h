#ifndef __HASH_STACK_H__
#define __HASH_STACK_H__

#include "defines.h"

class HashStack {
	size_t size_;
	size_t top;

	size_t rows;
	uint32_t** hash;
public:
	HashStack(size_t capacity);
	~HashStack();

	uint32_t pop(void);
	void push(uint32_t id);
	bool empty(void);
	size_t size(void);
};

#endif
