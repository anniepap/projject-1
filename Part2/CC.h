
#include "../Part1/defines.h"
#include "GrailIndex.h"

#define THRESHOLD 0.6

class UpdateIndex;

class CC{
	uint32_t*  ccindex;
	uint32_t size;
	UpdateIndex* updateIndex;
	uint32_t number_of_update_index_queries;
	uint32_t number_of_queries;		

	int findNodeConnectedComponentID(uint32_t nodeId);
	void rebuildIndexes();
	bool OverflowThreshhold();
	void SetUpdateIndex(uint32_t componentId, uint32_t component_attached);
public:
	CC(uint32_t size, Graph* graph);
	~CC();
	void insertNewEdge(uint32_t nodeIdS, uint32_t nodeIdE);
	bool isPossiblyReachable(uint32_t source_node,uint32_t target_node);
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class UpdateIndex{
	uint32_t* index;	
	uint32_t size;
public:	
	UpdateIndex(uint32_t size);
	~UpdateIndex();
	bool isConnected(uint32_t from, uint32_t to);
	void SetUpdateIndex(uint32_t componentId, uint32_t component_attached);
	uint32_t Size();
	uint32_t Index(uint32_t pos);
};

/*
CC* estimateConnectedComponents(NodeIndex* graph){ 		//Auti den tin egrapsa giati den paei edw
	CC cc_index=new CC(graph->sizeofnodes());
	GraphPostOrderCursor* DfsIterator =new GraphPostOrderCursor(graph);		// O grafos prepei na theeorithei ws mh kateuthinomenos
	uint32_t components_counter=0; // mporei na thelei 1
	uint32_t curr_id;
	while((curr_id=DfsIterator->Next())!=NONE){
		if (curr_id==ENDOFCOMPONENT){
			components_counter++;
			continue;
		}
		cc_index->SetIndex(curr_id,components_counter);
	}
	delete DfsIterator;
	return cc_index;
}
*/
