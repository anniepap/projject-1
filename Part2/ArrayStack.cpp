#include "ArrayStack.h"

Stack::Stack(uint32_t size_of_stack): size_of_stack(size_of_stack), size(0){
	array= new uint32_t[size_of_stack];
}

Stack::~Stack(){
	delete[] array;
}

void Stack::push(uint32_t element){
	array[size++]=element;
}

uint32_t Stack::pop(){
	if (size==0){
		return NONE;
	}
	return array[--size];
}

uint32_t Stack::top_(){
	if (size==0)
		return NONE;
	return array[size-1];
}

bool Stack::empty(){
	return size==0;
}
