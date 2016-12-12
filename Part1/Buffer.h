#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "defines.h"

struct list_node {
	uint32_t neighbor[LIST_NODE_CAPACITY]; //the ids of the neighbor nodes //offset of NodeIndex line
	uint32_t edgeProperty[LIST_NODE_CAPACITY]; //property for each edge
	size_t nextListNode; // NONE means no overflow
};

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
	bool find(size_t offset, uint32_t id, size_t size);
};

#endif
