
#include "GraphPostOrderCursor.h"
#include <ctime>

using namespace std;

GraphPostOrderCursor::GraphPostOrderCursor(Graph* graph, bool undirected ): graph(graph), undirected(undirected) {
	uint32_t size= graph->SizeOfNodes();
	if (size<1) {
		//cout<<"Line 10"<<endl;
		return;
	}
	stack= new HashStack(size);
	visited= new HashSet(size);
	random_nodes= new Collection(size);
	uint32_t element = random_nodes->Pop();	
	if (element==NONE){
		//cout<<"Line 18"<<endl;
	}
	stack->push( element );
	visited->insert( element );
}

GraphPostOrderCursor::~GraphPostOrderCursor(){
	delete stack;
	delete visited;
	delete random_nodes;
}

short GraphPostOrderCursor::next(uint32_t* id) {	
	if (stack->empty() && !visited->IsFull() ){
		uint32_t cur_id;

		cur_id=random_nodes->Pop();
		if (cur_id==NONE){
			//cout<<"Line 35"<<endl;
		}

		while (	visited->find(cur_id) ){
			cur_id=random_nodes->Pop();
			if (cur_id==NONE){
				//cout<<"Line 42"<<endl;
			}
		 }	
		stack->push( cur_id );	
		visited->insert( cur_id );		
		return ENDOFCOMPONENT;
	}

	PairCursor out_cursor( *graph, true );
	uint32_t curr_id,cur_edge;
	PairCursor in_cursor( *graph, false );
	while(!stack->empty())
	{
		///cout<<"GIA "<<stack->size_<<endl;
		curr_id=stack->top_();
		//cout<<"DW "<<endl;
		out_cursor.init(curr_id);
		bool flag=0;
 		while (out_cursor.next(&cur_edge)) {
			if (!visited->find(cur_edge)){
				stack->push(cur_edge);
				visited->insert(cur_edge);
				flag=1;
			}
  		}
  		if (undirected){
			in_cursor.init(curr_id);		
	 		while (in_cursor.next(&cur_edge)) {
				if (!visited->find(cur_edge)){
					stack->push(cur_edge);
					visited->insert(cur_edge);
					flag=1;
				}
	  		}
	  	}
		if (!flag){ 
			stack->pop();
			*id = curr_id;
			return OK_SUCCESS;
		}
	}

	return ENDOFCURSOR;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Stack::Stack(uint32_t size_of_stack): size_of_stack(size_of_stack), size(0){
	array= new uint32_t[size_of_stack];
}

Stack::~Stack(){
	delete[] array;
}

void Stack::push(uint32_t element){
	array[size++]=element;
}

uint32_t Stack::pop(){
	if (size==0){
		return NONE;
	}
	return array[--size];
}

uint32_t Stack::top_(){
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
bool Stack::empty(){
	return size==0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Collection::Collection(const uint32_t size): size_of_collection(size), cur_pos(0){
	array= new uint32_t[size];

	//srand(time(NULL));
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


	Dokimi::Dokimi(const uint32_t size){
		array= new uint32_t[size];

		
		for (int i=0; i<size; i++){
			array[i]=i;
		}
	}
	Dokimi::~Dokimi(){
		delete[] array;
	}
	uint32_t Dokimi::Pop(){

	}	