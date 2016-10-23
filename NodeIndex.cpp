#include "NodeIndex.h"

NodeIndex::NodeIndex() {
	capacity = NODE_INDEX_CAPACITY;
	table = (Node*) malloc(capacity*sizeof(Node));
	for (size_t i = 0; i < capacity; ++i)
	{
		table[i].size = LIST_NODE_CAPACITY;
		table[i].offset = NONE;
	}
}

NodeIndex::~NodeIndex() {
	free(table);
}

Node& NodeIndex::operator[](size_t index) {
	return table[index];
}

void NodeIndex::insertNode(uint32_t nodeId) {
	if (capacity > nodeId) return;
	size_t old_cap = capacity;
	while (capacity <= nodeId)//kati pio eksupno?
		capacity <<=1;
	table = (Node*) realloc(table, capacity*sizeof(Node));
	for (size_t i = old_cap; i < capacity; ++i)
	{
		table[i].size = LIST_NODE_CAPACITY;
		table[i].offset = NONE;
	}
}

size_t NodeIndex::getListHead(uint32_t nodeId) {
	return (capacity > nodeId) ? NONE : table[nodeId].offset;
}
