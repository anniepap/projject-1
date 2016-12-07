
#include "../defines.h"

#define THRESHOLD 0.6
#define OK_SUCCESS 1	// Mporei na thelei allagh,  na koitaksw kai opou xrisimopoieitai

class UpdateIndex;

class CC{
	uint32_t*  ccindex;	// To allaksa. prin eixe auto uint32_t  ccindex[];
	uint32_t size;
	UpdateIndex* updateIndex;
	uint32_t metricVal;		// Na to spasoume se #queries with update kai #queries

	void SetIndex(uint32_t nodeId, uint32_t componentId);
	void SetUpdateIndex(uint32_t componentId, uint32_t component_attached);
	int findNodeConnectedComponentID(uint32_t nodeId);
public:
	CC(uint32_t size);
	~CC();
	/*OK_SUCCESS*/ void  insertNewEdge(uint32_t nodeIdS, uint32_t nodeIdE);
	/*OK_SUCCESS*/ void  rebuildIndexes();
	void UpdateMetric();		// Na ulopoihthei
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class UpdateIndex{
	uint32_t* index;	// To allaksa. prin eixe auto uint32_t index[];
	uint32_t size;
public:	
	UpdateIndex(uint32_t size);
	~UpdateIndex();
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