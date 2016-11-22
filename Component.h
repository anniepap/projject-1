#ifndef __COMPONENT_H__
#define __COMPONENT_H__

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

#endif