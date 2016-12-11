#include "NodeIndex.h"
#include "StackLinkedList.h"
#include "ListNode.h"

uint32_t minimum(uint32_t a, uint32_t b) {
	if (a < b)
		return a;
	return b;
}

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

SCC* NodeIndex::estimateStronglyConnectedComponents(Buffer& buffer) {
	for (size_t i = 0; i < capacity; ++i)
	{
		table[i].index = NONE;
		table[i].lowlink = NONE;
		table[i].onStack = false;
	}
	uint32_t index = 0;
	uint32_t lastw_id = NONE;
	Stack tarjanStack;

	Stack activeStack;
	Stack offsetStack;
	Stack indexStack;

	SCC* scc = new SCC(capacity);

	for (size_t i = 0; i < capacity; ++i)
	{
		if (table[i].index == NONE) {
			// Simulate the dfs search that recursion is doing
			activeStack.push(i);
			offsetStack.push(table[i].offset);
			indexStack.push(0);
			while (!activeStack.isEmpty()) {
				uint32_t id = activeStack.top();
				Node& v = table[id];

				// First time visiting node
				if (v.index == NONE) {
					v.index = index;
					v.lowlink = index;
					index++;
					tarjanStack.push(id);
					v.onStack = true;
				} else {
					uint32_t t = indexStack.pop();
					indexStack.push(t+1);
					Node w = table[lastw_id];
					v.lowlink = minimum(v.lowlink, w.lowlink);
				}
				
				bool continueDfs = false;
				// Take all edges
				uint32_t nextOffset = offsetStack.top();
				uint32_t startIndex = indexStack.top();
				uint32_t currentCapacity = LIST_NODE_CAPACITY;
				if (v.offset == nextOffset) {
					currentCapacity = v.size;
				}	
				if (nextOffset != NONE) {
					do {
						list_node& neighbors = buffer[nextOffset];
						for (int j = startIndex; j < currentCapacity ; ++j)
						{
							uint32_t neighbor_id = neighbors.neighbor[j];
							Node& w = table[neighbor_id];
							if (w.index == NONE) {
								activeStack.push(neighbor_id);
								offsetStack.push(w.offset);
								indexStack.push(0);
								continueDfs = true;
								break;
							}
							else if (w.onStack) {
								v.lowlink  = minimum(v.lowlink, w.index);
							}
						}
						if (continueDfs)
							break;
						nextOffset = neighbors.nextListNode;
						startIndex = 0;
						currentCapacity = LIST_NODE_CAPACITY;
					} while (nextOffset != NONE);
				}

				if (!continueDfs) {	
					if (v.lowlink == v.index) {
						scc->increaseComponents(v.lowlink);
						uint32_t neighbor_id;
						do {
							neighbor_id = tarjanStack.pop();
							Node& w = table[neighbor_id];
							w.onStack = false;
							scc->addNodeToComponent(neighbor_id, w.lowlink);
						} while(neighbor_id != id);
					}
					lastw_id = activeStack.pop();
					offsetStack.pop();
					indexStack.pop();
				}
			}
		}
	}
	return scc;
}
