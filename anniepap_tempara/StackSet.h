#ifndef __STACK_SET_H__
#define __STACK_SET_H__

#include "defines.h"
#include "StackLinkedList.h"
#include "HashSet.h"

class StackSet {
	Stack stack;
	HashSet visited;
public:
	StackSet(size_t capacity);

	void push(uint32_t id);
	uint32_t pop();

	bool empty();
	size_t getSize();
	bool getVisited(size_t index);
};

#endif
