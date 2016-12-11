#include "SCC.h"

#include <iostream>
using namespace std;

Component::Component(uint32_t id) {
	component_id = id;
	included_nodes_count = 0;
}

SCC::SCC(uint32_t N) {
	components_count = 0;
	components = NULL;
	number_of_nodes = N;
	id_belongs_to_component = new uint32_t[N];
	for (uint32_t i = 0; i < N; ++i)
	{
		id_belongs_to_component[i] = NONE;
	}
}

Component** SCC::getComponents() {
	return components;
}

void SCC::increaseComponents(uint32_t sccId) {
	components_count++;
	if (components_count == 1) {
		components = (Component**) malloc(sizeof(Component*));
	}
	else {
		components = (Component**) realloc(components, sizeof(Component*) * components_count);
	}
	Component* component = new Component(sccId);
	components[components_count - 1] = component;
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
	}*/
}

SCC::~SCC() {
	destroyStronglyConnectedComponents();
}

bool SCC::destroyStronglyConnectedComponents() {
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