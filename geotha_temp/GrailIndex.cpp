#include "GrailIndex.h"

//buildGrailIndex
GrailIndex::GrailIndex(NodeIndex* graph, SCC* components): SizeOfIndex(graph.sizeofnodes()) {
	// Allocation of table
	IndexTables= new GrailIndexNode*[SizeOfIndex];
	for(i=0;i<SizeOfIndex;i++){
		IndexTables[i]= new GrailIndexNode[NUMBEROFLABELS];
	}


	for()
	{

	}

}

//destroyGrailIndex
GrailIndex::~GrailIndex() {
	for(i=0;i<SizeOfIndex;i++){
		delete[] IndexTables[i];
	}
	delete[] IndexTables;
}

GRAIL_ANSWER isReachableGrailIndex(uint32_t source_node,uint32_t target_node){
	for(i=0;i<NUMBEROFLABELS;i++){
		if ( !IndexTables[target_node][i].isSubSet(IndexTables[source_node][i]) ){
			return GRAIL_ANSWER.NO;
		}
	}
	return GRAIL_ANSWER.Maybe;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

GrailIndexNode::GrailIndexNode(int min_rank, int rank): min_rank(min_rank), rank(rank){
}

bool GrailIndexNode::isSubSet(GrailIndexNode Y){
	return (Y.min_rank<=this->min_rank && X.rank<=Y.rank);
}