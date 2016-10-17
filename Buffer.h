#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "defines.h"

class Buffer {
	size_t size; //current size of capacity used
	size_t capacity; //capacity of table
	list_node* table; //offset of Buffer line
public:
	Buffer(); //Buffer* createBuffer();
	~Buffer(); //OK_SUCCESS destroyBuffer(Buffer*);
	size_t allocNewNode();
	list_node* getListNode(size_t);
};

#endif
