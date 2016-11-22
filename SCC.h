#ifndef __SCC_H__
#define __SCC_H__

#include "defines.h"
#include "Component.h"

class SCC{
	Component* components; 				 // Components index - a vector which stores the components information
	uint32_t components_count;
	uint32_t id_belongs_to_component[N]; // inverted index	
public:
	SCC();
	~SCC();
	//SCC* estimateStronglyConnectedComponents(NodeIndex* graph);
	int findNodeStronglyConnectedComponentID(uint32_t nodeId);
	OK_SUCCESS iterateStronglyConnectedComponentID(ComponentCursor* cursor);
	bool next_StronglyConnectedComponentID(ComponentCursor* cursor);
	int estimateShortestPathStronglyConnectedComponents(NodeIndex* graph, uint32_t source_node, uint32_t target_node);
	//DISTRACTOR: OK_SUCCESS destroyStronglyConnectedComponents(SCC* components);
};

SCC* estimateStronglyConnectedComponents(NodeIndex* graph);
//int findNodeStronglyConnectedComponentID(SCC* components, uint32_t nodeId);
//OK_SUCCESS iterateStronglyConnectedComponentID(SCC* components,ComponentCursor* cursor);
//bool next_StronglyConnectedComponentID(SCC* components, ComponentCursor* cursor);
//int estimateShortestPathStronglyConnectedComponents(SCC* components, NodeIndex* graph, uint32_t source_node, uint32_t target_node);

#endif

iterate
for()
{

next()1

}
