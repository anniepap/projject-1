
#include "../Part1/defines.h"
#include "../Part1/Graph.h"
#include "GraphPostOrderCursor.h"

#define THRESHOLD 0.6

class UpdateIndex;

class CC{
	uint32_t*  ccindex;
	uint32_t size;
	UpdateIndex* updateIndex;
	uint32_t number_of_update_index_queries;
	uint32_t number_of_queries;		

	void rebuildIndexes();				// Tha mporousame na kanoume inverted pinaka gia min diatrexoume olo ton ccindex
	bool OverflowThreshhold();
	int findNodeConnectedComponentID(uint32_t nodeId);
public:
	CC(uint32_t size, Graph* graph);
	~CC();
	void insertNewEdge(uint32_t nodeIdS, uint32_t nodeIdE);
	bool isPossiblyReachable(uint32_t source_node,uint32_t target_node);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class UpdateIndex{
	uint32_t* index;
	//List** index_list;	// thelei lista
	uint32_t size;
public:	
	UpdateIndex(uint32_t size);
	~UpdateIndex();
	int component_belongs_to_component(int component);
	void MergeComponent(int componentS,int componentE);
};
