#include "NodeIndex.h"

NodeIndex::NodeIndex() {
	capacity = NODE_INDEX_CAPACITY;
	table = (Node*) malloc(capacity*sizeof(Node));
	for (size_t i = 0; i < capacity; ++i)
	{
		table[i].size = LIST_NODE_CAPACITY;
		table[i].offset = NONE;
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
		table[i].size = LIST_NODE_CAPACITY;
		table[i].offset = NONE;
		table[i].count = 0;
	}
}

Node& NodeIndex::operator[](size_t index) {
	return table[index];
}

size_t NodeIndex::getListHead(uint32_t nodeId) {
	return (capacity > nodeId) ? NONE : table[nodeId].offset;
}

size_t NodeIndex::getCapacity(void) {
	return capacity;
}

/*
Component* NodeIndex::strongConnect() {
	int index = 0;
	StackSet S(v.getCapacity());

	size_t listnodesize = v[i].size;		//graph.table[i]
	for (size_t j = 0; j < listnodesize; ++j)
	{
		
	}
}*/

SCC* NodeIndex::estimateStronglyConnectedComponents(NodeIndex* graph) {
	SCC* scc(graph.getCapacity());
	scc->components = (Component*) realloc(scc->components, sizeof(Component) * scc.size);
	Component* component;

	for (size_t i = 0; i < graph.getCapacity(); ++i)
	{
		if (/* condition */) {
			component = strongConnect(v);

			
		}
	}
}