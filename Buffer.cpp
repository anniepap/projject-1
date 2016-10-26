#include "Buffer.h"

Buffer::Buffer() {
	size = 0;
	capacity = BUFFER_CAPACITY;
	table = (list_node*) malloc(capacity*sizeof(list_node));
}

Buffer::~Buffer() {
	free(table);
}

list_node& Buffer::operator[](size_t index) {
	return table[index];
}

size_t Buffer::allocNewNode(size_t ptr) {
	if (size == capacity)
	{
		capacity <<= 1;
		table = (list_node*) realloc(table, capacity*sizeof(list_node));
	}
	table[size].nextListNode = ptr;
	return size++;
}

list_node* Buffer::getListNode(size_t index) {
	return (capacity > index) ? NULL : &table[index];
}

bool Buffer::find(size_t offset, uint32_t id, size_t size) {
	while (offset != NONE) {
		list_node& bucket = table[offset];
		for (size_t i = 0; i < size; ++i)
			if (bucket.neighbor[i] == id)
				return true;
		offset = bucket.nextListNode;
		size = LIST_NODE_CAPACITY;
	}
	return false;
}
