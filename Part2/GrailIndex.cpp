#include "GrailIndex.h"

//buildGrailIndex
GrailIndex::GrailIndex(SCC* components): SizeOfIndex( components->getHyperGraph()->SizeOfNodes() ), components(components) {  // To hyper_graph prepei na einai upergrafos
	// Allocation of table
	IndexTables= new GrailIndexNode*[SizeOfIndex];
	for(int i=0;i<SizeOfIndex;i++){
		IndexTables[i]= new GrailIndexNode[NUMBEROFLABELS];
	}

	Graph* hyper_graph = components->getHyperGraph();
//---------------------------------------
	PairCursor graph_cursor( &hyper_graph-> getOut() );
	uint32_t curr_id,cur_edge;

	GraphPostOrderCursor* post_order_cursor= new GraphPostOrderCursor(hyper_graph);

	for (int j=0; j<NUMBEROFLABELS;j++){
		//Post Order
		int rank=1;
		unsigned int min_rank;
		short res;
		while ((res = post_order_cursor->next(&curr_id)) != ENDOFCURSOR) {
			if (res==ENDOFCOMPONENT)
				continue;
						
			uint32_t min_rank = -1;
			graph_cursor.init(curr_id);
			bool f = graph_cursor.next(&cur_edge);
			if (!f)
				min_rank = rank;
	 		while (f) {
				if ( IndexTables[ cur_edge ][j].MinRank() < min_rank){
					min_rank= IndexTables[ cur_edge ][j].MinRank();
				}
				f = graph_cursor.next(&cur_edge);
	  		} 

			IndexTables[curr_id][j].set(min_rank, rank);
			rank++;
		}
	}
	delete post_order_cursor;
}

//destroyGrailIndex
GrailIndex::~GrailIndex() {
	for(int i=0;i<SizeOfIndex;i++){
		delete[] IndexTables[i];
	}
	delete[] IndexTables;
}

GRAIL_ANSWER GrailIndex::isReachableGrailIndex(uint32_t source_node,uint32_t target_node){
	int source_component = components->findNodeStronglyConnectedComponentID(source_node);
	int target_component = components->findNodeStronglyConnectedComponentID(target_node);
	if ( source_component == target_component )
		return YES;

	for(int i=0;i<NUMBEROFLABELS;i++){
		if ( !IndexTables[target_component][i].isSubSet(IndexTables[source_component][i]) ){
			return NO;
		}
	}
	return MAYBE;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void GrailIndexNode::set(int min_rank, int rank) {
	this->min_rank = min_rank;
	this->rank = rank;
}

int GrailIndexNode::MinRank() {
	return min_rank;
}

bool GrailIndexNode::isSubSet(GrailIndexNode& Y){
	return (Y.min_rank<=min_rank && rank<=Y.rank);
}
