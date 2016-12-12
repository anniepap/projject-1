#include "NodeIndex.h"

NodeIndex::NodeIndex() {
	capacity = NODE_INDEX_CAPACITY;
	table = (Node*) malloc(capacity*sizeof(Node));
	for (size_t i = 0; i < capacity; ++i)
	{
		for (int z = 0; z < NODE_HASH; ++z) {
			table[i].size[z] = LIST_NODE_CAPACITY;
			table[i].offset[z] = NONE;
		}
		table[i].count = 0;
	}
}

NodeIndex::~NodeIndex() {
	free(table);
}

void NodeIndex::insertNode(uint32_t nodeId) {
	if (capacity > nodeId) return;
	size_t old_cap = capacity;
	while (capacity <= nodeId) //kati pio eksupno?
		capacity <<= 1;
	table = (Node*) realloc(table, capacity*sizeof(Node));
	for (size_t i = old_cap; i < capacity; ++i)
	{
		for (int z = 0; z < NODE_HASH; ++z) {
			table[i].size[z] = LIST_NODE_CAPACITY;
			table[i].offset[z] = NONE;
		}
		table[i].count = 0;
	}
}

Node& NodeIndex::operator[](size_t index) {
	return table[index];
}

size_t NodeIndex::getCapacity(void) {
	return capacity;
}

