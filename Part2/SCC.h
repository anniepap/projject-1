#ifndef __SCC_H__
#define __SCC_H__

#include "../Part1/defines.h"
#include "../Part1/NodeIndex.h"
#include "../Part1/Graph.h"
#include "../Part1/Buffer.h"
#include "../Part1/PairCursor.h"

class NodeIndex;

struct Component {
	uint32_t included_nodes_count; // number of nodes in component
	uint32_t* included_node_ids;   // ids of included nodes
	Component(); 
};

struct ComponentCursor{
	Component* component_ptr; // pointer to current's iteration component
	// Any other necessary information in order to move to next component in the vector
};

struct TarNode {
	uint32_t index;
	uint32_t lowlink;
	bool onStack;
	TarNode* caller;
	PairCursor* pc;
};

class SCC {
	size_t capacity;
	uint32_t components_count;
	Component** components; 				 // Components index - a vector which stores the components information
	uint32_t* id_belongs_to_component;   // inverted index	
	void destroyStronglyConnectedComponents();
public:
	SCC(size_t capacity);
	~SCC();
	
	int findNodeStronglyConnectedComponentID(uint32_t nodeId);
	bool iterateStronglyConnectedComponentID(ComponentCursor* cursor);
	bool next_StronglyConnectedComponentID(ComponentCursor* cursor);
	int estimateShortestPathStronglyConnectedComponents(NodeIndex* graph, uint32_t source_node, uint32_t target_node);

	Component** getComponents();

	void increaseComponents();
	void addNodeToComponent(uint32_t nodeId);
	void print();

	void estimateStronglyConnectedComponents(Pair& pair);
};

#endif
