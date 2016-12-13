#include "GrailIndex.h"
#include <ctime>

//buildGrailIndex
GrailIndex::GrailIndex(Graph* graph/*, SCC* components*/): SizeOfIndex( graph->SizeOfNodes() )/*, components(components)*/ {
	// Allocation of table
	IndexTables= new GrailIndexNode*[SizeOfIndex];
	for(int i=0;i<SizeOfIndex;i++){
		IndexTables[i]= new GrailIndexNode[NUMBEROFLABELS];
	}

//---------------------------------------
	PairCursor graph_cursor( &graph-> getOut() );
	uint32_t curr_id,cur_edge;

	for (int j=0; j<NUMBEROFLABELS;j++){
		//Post Order
		GraphPostOrderCursor* post_order_cursor= new GraphPostOrderCursor(graph);
		int rank=1;
		unsigned int min_rank;
		while( (curr_id=post_order_cursor->Next())!=NONE ) {
			if (curr_id==ENDOFCOMPONENT)
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
	for(int i=0;i<SizeOfIndex;i++){
		delete[] IndexTables[i];
	}
	delete[] IndexTables;
}

GRAIL_ANSWER GrailIndex::isReachableGrailIndex(uint32_t source_node,uint32_t target_node){
//	if ( findNodeStronglyConnectedComponentID(source_node) == findNodeStronglyConnectedComponentID(target_node) )
//		return YES;

	for(int i=0;i<NUMBEROFLABELS;i++){
		if ( !IndexTables[target_node][i].isSubSet(IndexTables[source_node][i]) ){
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

GraphPostOrderCursor::GraphPostOrderCursor(Graph* graph, bool undirected ): graph(graph), undirected(undirected) {
	uint32_t size= graph->SizeOfNodes();
	stack= new Stack(size);
	visited= new HashSet(size);
	random_nodes= new Collection(size);
	uint32_t element = random_nodes->Pop();	
	stack->Push( element );
	visited->insert( element );
}

GraphPostOrderCursor::~GraphPostOrderCursor(){
	delete stack;
	delete visited;
	delete random_nodes;
}

uint32_t GraphPostOrderCursor::Next(){	
	if (stack->IsEmpty() && !visited->IsFull() ){
		uint32_t cur_id;
		while (	visited->find(cur_id=random_nodes->Pop()) ){ }	
		stack->Push( cur_id );	
		visited->insert( cur_id );		
		return ENDOFCOMPONENT;
	}

	PairCursor out_cursor( *graph, true );
	uint32_t curr_id,cur_edge;
	PairCursor in_cursor( *graph, false );
	while(!stack->IsEmpty())
	{
		curr_id=stack->Top();
		out_cursor.init(curr_id);
		bool flag=0;
 		while (out_cursor.next(&cur_edge)) {
			if (!visited->find(cur_edge)){
				stack->Push(cur_edge);
				visited->insert(cur_edge);
				flag=1;
			}
  		}
  		if (undirected){
			in_cursor.init(curr_id);		
	 		while (in_cursor.next(&cur_edge)) {
				if (!visited->find(cur_edge)){
					stack->Push(cur_edge);
					visited->insert(cur_edge);
					flag=1;
				}
	  		}
	  	}
		if (!flag){ 
			stack->Pop();
			return curr_id;
		}
	}
	return NONE;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Stack::Stack(uint32_t size_of_stack): size_of_stack(size_of_stack), size(0){
	array= new uint32_t[size_of_stack];
}

Stack::~Stack(){
	delete[] array;
}

void Stack::Push(uint32_t element){
	array[size++]=element;
}

uint32_t Stack::Pop(){
	if (size==0){
		return NONE;
	}
	return array[--size];
}

uint32_t Stack::Top(){
	if (size==0)
		return NONE;
	return array[size-1];
}
/*
bool Stack::find(uint32_t element){			// Na fugei. na ginetai visited otan ginetai push
	for (int i=0; i<size;i++){
		if (array[i]==element) 
			return true;
	}
	return false;
}
*/
bool Stack::IsEmpty(){
	return size==0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Collection::Collection(const uint32_t size): size_of_collection(size), cur_pos(0){
	array= new uint32_t[size];

	srand(time(NULL));
	uint32_t up_index=0, down_index=size-1, first_num=0, last_num=size-1, index,curr_id;
	for (int i=0; i<size; i++){
		index= (rand()%2==0)? up_index++: down_index--;
		curr_id= (rand()%2==0)? first_num++: last_num--;
		array[index]= curr_id;
	}
}

Collection::~Collection(){
	delete[] array;
}

uint32_t Collection::Pop(){
	return (cur_pos>size_of_collection-1)? NONE : array[cur_pos++];
}
