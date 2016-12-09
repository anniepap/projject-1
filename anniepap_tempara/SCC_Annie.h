#ifndef __SCC_H__
#define __SCC_H__

#include "defines.h"

struct Component {
	uint32_t component_id; 		   // current component id
	uint32_t included_nodes_count; // number of nodes in component
	uint32_t* included_node_ids;   // ids of included nodes
};

struct ComponentCursor{
	Component* component_ptr; // pointer to current’s iteration component
	// Any other necessary information in order to move to next component in the vector
};

class SCC{
	uint32_t numberofcomponents;
	Component* components; 				 // Components index - a vector which stores the components information
	uint32_t components_count;
	uint32_t id_belongs_to_component[N]; // inverted index	
public:
	SCC(uint32_t N);
	int findNodeStronglyConnectedComponentID(uint32_t nodeId);
	OK_SUCCESS iterateStronglyConnectedComponentID(ComponentCursor* cursor);
	bool next_StronglyConnectedComponentID(ComponentCursor* cursor);
	int estimateShortestPathStronglyConnectedComponents(NodeIndex* graph, uint32_t source_node, uint32_t target_node);
	//DISTRACTOR: OK_SUCCESS destroyStronglyConnectedComponents(SCC* components);
};