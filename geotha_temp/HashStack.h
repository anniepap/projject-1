#ifndef __HASH_STACK_H__
#define __HASH_STACK_H__

#include "../Part1/defines.h"

class HashStack {
	uint32_t top;
	uint32_t rows;
	uint32_t** hash;
public:
	HashStack(uint32_t capacity);
	~HashStack();
	uint32_t size_;

	void push(uint32_t id);
	uint32_t pop(void);
	uint32_t top_();
	bool empty(void);
	uint32_t size(void);
};

#endif
