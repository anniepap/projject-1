#include <iostream>
#include "SCC.h"
#include "StackLinkedList.h"
using namespace std;

Component::Component(uint32_t id) {
	component_id = id;
	included_nodes_count = 0;
}

SCC::SCC(size_t capacity) {
	table = new TarNode[capacity];
	for (size_t i = 0; i < capacity; ++i)
	{
		table[i].index = NONE;
		table[i].lowlink = NONE;
		table[i].onStack = false;
	}

	components_count = 0;
	components = NULL;
	number_of_nodes = capacity;
	id_belongs_to_component = new uint32_t[capacity];
	for (uint32_t i = 0; i < capacity; ++i)
	{
		id_belongs_to_component[i] = NONE;
	}
}

Component** SCC::getComponents() {
	return components;
}

void SCC::increaseComponents(uint32_t sccId) {
	components_count++;
	components = (Component**) realloc(components, sizeof(Component*) * components_count);
	components[components_count - 1] = new Component(sccId);
}

void SCC::addNodeToComponent(uint32_t nodeId, uint32_t sccId) {
	uint32_t i;
	for (i = 0; i < components_count; ++i)
		if (components[i]->component_id == sccId)
			break;

	components[i]->included_nodes_count++;
	if (components[i]->included_nodes_count == 1) {
		components[i]->included_node_ids = (uint32_t*) malloc(sizeof(uint32_t));
	}
	else {
		components[i]->included_node_ids = 
		(uint32_t*) realloc(components[i]->included_node_ids, sizeof(uint32_t) * components[i]->included_nodes_count);
	}
	components[i]->included_node_ids[components[i]->included_nodes_count - 1] = nodeId;

	id_belongs_to_component[nodeId] = sccId;
}

void SCC::print() {
	for (uint32_t i = 0; i < components_count; ++i)
	{
		cout << "component " << components[i]->component_id << endl;
		for (uint32_t j = 0; j < components[i]->included_nodes_count; ++j)
		{
			cout << components[i]->included_node_ids[j] << endl;
		}
	}

	/*
	for (uint32_t i = 0; i < number_of_nodes; ++i)
	{
		cout << i << " -> " << id_belongs_to_component[i] << endl;
	}
	*/
}

SCC::~SCC() {
	destroyStronglyConnectedComponents();
}

bool SCC::destroyStronglyConnectedComponents() {
	delete[] table;
	for (uint32_t i = 0; i < components_count; ++i)
	{
		free(components[i]->included_node_ids);
		delete components[i];
	}

	free(components);
	components_count = 0;
}

/*
int findNodeStronglyConnectedComponentID(uint32_t nodeId) {

}
OK_SUCCESS iterateStronglyConnectedComponentID(ComponentCursor* cursor) {

}
bool next_StronglyConnectedComponentID(ComponentCursor* cursor) {

}
int estimateShortestPathStronglyConnectedComponents(NodeIndex* graph, uint32_t source_node, uint32_t target_node) {

}
*/

void SCC::estimateStronglyConnectedComponents(Pair& pair) {
/*	uint32_t index = 0;
	uint32_t lastw_id = NONE;
	Stack tarjanStack;

	Stack activeStack;
	Stack offsetStack;
	Stack indexStack;

	for (size_t id = 0; id < pair.getCapacity(); ++id) {
		if (table[id].index == NONE) {
			// Simulate the dfs search that recursion is doing
			activeStack.push(id);
			talbe[id].pc = new PairCursor(&pair);
			talbe[id].pc->init(id);
			while (!activeStack.isEmpty()) {
				uint32_t id = activeStack.top();
				TarNode& v = table[id];

				// First time visiting node
				if (v.index == NONE) {
					v.index = index;
					v.lowlink = index;
					v.onStack = true;
					index++;
					tarjanStack.push(id);
				}
				else {
					uint32_t t = indexStack.pop();
					indexStack.push(t+1);
					Node w = table[lastw_id];
					v.lowlink = (v.lowlink < w.lowlink) ? v.lowlink : w.lowlink;
				}

				bool continueDfs = false;
				// Take all edges
				uint32_t nextOffset = offsetStack.top();
				uint32_t startIndex = indexStack.top();
				uint32_t currentCapacity = LIST_NODE_CAPACITY;
				if (v.offset == nextOffset) {
					currentCapacity = v.size;
				}
				while (nextOffset != NONE) {
					list_node& neighbors = buffer[nextOffset];
					for (int j = startIndex; j < currentCapacity ; ++j) {
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
							v.lowlink = (v.lowlink < w.index) ? v.lowlink : w.index;
						}
					}
					if (continueDfs)
						break;
					nextOffset = neighbors.nextListNode;
					startIndex = 0;
					currentCapacity = LIST_NODE_CAPACITY;
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
*/
}
