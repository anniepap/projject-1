#include "GrailIndex.h"


//buildGrailIndex
GrailIndex::GrailIndex(Graph* graph/*, SCC* components*/): SizeOfIndex(1/*graph->sizeofnodes()*/) {
	// Allocation of table
	IndexTables= new GrailIndexNode*[SizeOfIndex];
	for(int i=0;i<SizeOfIndex;i++){
		IndexTables[i]= new GrailIndexNode[NUMBEROFLABELS];
	}

//---------------------------------------
	for (int j=0 ; j<NUMBEROFLABELS ;j++){
		//Post Order
		GraphPostOrderCursor* post_order_cursor= new GraphPostOrderCursor(graph);
		uint32_t curr_id;
		int rank=1;
		unsigned int min_rank;
		GrailIndexNode curr_grail_node;
		while( (curr_id=post_order_cursor->Next())!=NONE ) {
			/*graph->OutEdges(curr_id,);*/ //Find children of curr_grail_node  // OutEdges,number_of_edges //////////////////
			min_rank= calc_min_rank(j,rank/*,OutEdges,number_of_edges*/);
			curr_grail_node.Rank(rank); 
			curr_grail_node.MinRank(min_rank); 
			IndexTables[curr_id][j] = curr_grail_node;
			rank++;
		}
		delete post_order_cursor;
	}

}

//destroyGrailIndex
GrailIndex::~GrailIndex() {
	for(int i=0;i<SizeOfIndex;i++){
		delete[] IndexTables[i];
	}
	delete[] IndexTables;
}

GRAIL_ANSWER GrailIndex::isReachableGrailIndex(uint32_t source_node,uint32_t target_node){
	for(int i=0;i<NUMBEROFLABELS;i++){
		if ( !IndexTables[target_node][i].isSubSet(IndexTables[source_node][i]) ){
			return NO;
		}
	}
	return MAYBE;
}

unsigned int GrailIndex::calc_min_rank(const int curr_label,int rank/*,out_edges,number_of_edges*/){
	if (1/*number_of_edges==0*/) return rank;
	unsigned int min=-1;
	for (int i=0 ; i<1/*number_of_edges*/; i++){
		if ( IndexTables[ 1/*out_edges[i]*/ ][curr_label].MinRank() <min){
			min= IndexTables[ 1/*out_edges[i]*/ ][curr_label].MinRank();
		}
	}
	return min;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

GrailIndexNode::GrailIndexNode(int min_rank, int rank): min_rank(min_rank), rank(rank){
}

bool GrailIndexNode::isSubSet(GrailIndexNode Y){
	return (Y.min_rank<=min_rank && rank<=Y.rank);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

GraphPostOrderCursor::GraphPostOrderCursor(Graph* graph){
	uint32_t size= 6;//graph->SizeOfNodes();
	stack= new Stack(size);
	stack->Push( 1 /*rand()%size*/ );	// katallhlh xrisi tis time
	visited= new HashSet(size);
}

GraphPostOrderCursor::~GraphPostOrderCursor(){
	delete stack;
	delete visited;
}

uint32_t GraphPostOrderCursor::Next(){	///////////////////////////////
	if (stack->IsEmpty() && 1 /*!visited->isFull() lipei auth h sunartisi*/ ){
		stack->Push( 6/*ena apo ta kena*/ );		
	}
	uint32_t curr_id,cur_edge;
	while(!stack->IsEmpty())
	{
		curr_id=stack->Top();
		if (1/* graph->HasOutEdges(curr_id) den uparxei*/){
			// For all childen //////// cur_edge
			if (!visited->find(cur_edge) && !stack->find(cur_edge) ){
				stack->Push(cur_edge);
			}
		}
		else{
			stack->Pop();
			visited->insert(curr_id);
			return curr_id;
		}
	}
	return NONE;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Stack::Stack(uint32_t size_of_stack): size_of_stack(size_of_stack), top(NONE){
	array= new uint32_t[size_of_stack];
}

Stack::~Stack(){
	delete[] array;
}

void Stack::Push(uint32_t element){
	array[++top]=element;
}

uint32_t Stack::Pop(){
	if (top==-1){
		return NONE;
	}
	top--;
	return array[top+1];
}

uint32_t Stack::Top(){
	if (top==NONE)
		return NONE;
	return array[top];
}

bool Stack::find(uint32_t element){
	for (int i=0 ; i<=top ;i++){
		if (array[i]==element) 
			return true;
	}
	return false;
}

bool Stack::IsEmpty(){
	return top==NONE;
}
