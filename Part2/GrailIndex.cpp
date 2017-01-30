#include "GrailIndex.h"

//buildGrailIndex
GrailIndex::GrailIndex(SCC* components): SizeOfIndex( components->getHyperGraph().SizeOfNodes() ), components(components) {  // To hyper_graph prepei na einai upergrafos
	// Allocation of table
	IndexTables= new GrailIndexNode*[SizeOfIndex];
	for(uint32_t i=0;i<SizeOfIndex;i++){
		IndexTables[i]= new GrailIndexNode[NUMBEROFLABELS];
	}

	Graph& hyper_graph = components->getHyperGraph();
//---------------------------------------
	PairCursor graph_cursor( &hyper_graph.getOut() );
	uint32_t curr_id,cur_edge;

	GraphPostOrderCursor* post_order_cursor;
	for (int j=0; j<NUMBEROFLABELS;j++){
		post_order_cursor= new GraphPostOrderCursor(&hyper_graph);//change
		//Post Order
		uint32_t rank=1;
		short res;
		while ((res = post_order_cursor->next(&curr_id)) != ENDOFCURSOR) {
			if (res==ENDOFCOMPONENT)
				continue;

			if (!IndexTables[curr_id][j].isSeted())
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
		delete post_order_cursor;
	}
}

//destroyGrailIndex
GrailIndex::~GrailIndex() {
	for(uint32_t i=0;i<SizeOfIndex;i++){
		delete[] IndexTables[i];
	}
	delete[] IndexTables;
}

GRAIL_ANSWER GrailIndex::isReachableGrailIndex(uint32_t source_node,uint32_t target_node){
	uint32_t source_component = components->findNodeStronglyConnectedComponentID(source_node);
	uint32_t target_component = components->findNodeStronglyConnectedComponentID(target_node);
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

GrailIndexNode::GrailIndexNode():min_rank(0),rank(0){}

void GrailIndexNode::set(uint32_t min_rank, uint32_t rank) {
	this->min_rank = min_rank;
	this->rank = rank;
}

bool GrailIndexNode::isSeted(){
	return rank!=0 && min_rank!=0;
}

uint32_t GrailIndexNode::MinRank() {
	return min_rank;
}

bool GrailIndexNode::isSubSet(GrailIndexNode& Y){
	return (Y.min_rank<=min_rank && rank<=Y.rank);
}
