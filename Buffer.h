#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "ListNode.h"

class Buffer {
	size_t size; //current size of capacity used
	size_t capacity; //capacity of table
	list_node* table; //offset of Buffer line
public:
	Buffer(); //Buffer* createBuffer();
	~Buffer(); //OK_SUCCESS destroyBuffer(Buffer*);
	list_node& operator[](size_t index);
	size_t allocNewNode(size_t ptr);
	list_node* getListNode(size_t);
	size_t find(size_t offset, uint32_t id);
};

#endif
