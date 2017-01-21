#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

class Stack {					// Elegxthike
	uint32_t size_of_stack;
	uint32_t* array;
	uint32_t size;
public: 
	Stack(uint32_t size_of_stack);
	~Stack();
	void push(uint32_t element);
	uint32_t pop();
	uint32_t top_();
	bool empty();
};

#endif
