#ifndef __SCC_H__
#define __SCC_H__

#include "../Part1/defines.h"
#include "../Part1/NodeIndex.h"
#include "../Part1/Graph.h"
#include "../Part1/Buffer.h"

class NodeIndex;
class SCC;

struct Component {
	uint32_t component_id; 		   // current component id
	uint32_t included_nodes_count; // number of nodes in component
	uint32_t* included_node_ids;   // ids of included nodes
	Component(uint32_t id); 
};

class ComponentCursor{
	SCC* scc;
	int index;
public :
	void iterateStronglyConnectedComponentID(SCC* components);
	bool next_StronglyConnectedComponentID();
	Component* GetCurrentConnectedComponent();
};

struct TarNode {
	uint32_t index;
	uint32_t lowlink;
	bool onStack;
};

class SCC {
	TarNode* table;
	uint32_t components_count;
	Component** components; 				 // Components index - a vector which stores the components information
	uint32_t number_of_nodes;
	uint32_t* id_belongs_to_component;   // inverted index	
public:
	SCC(size_t capacity);
	~SCC();
	
	int findNodeStronglyConnectedComponentID(uint32_t nodeId);
	int estimateShortestPathStronglyConnectedComponents(NodeIndex* graph, uint32_t source_node, uint32_t target_node);
	bool destroyStronglyConnectedComponents();

	uint32_t ComponentsCount();
	Component** getComponents();

	void increaseComponents(uint32_t sccId);
	void addNodeToComponent(uint32_t nodeId, uint32_t sccId);
	void print();

	void estimateStronglyConnectedComponents(Pair& pair);
};

#endif
