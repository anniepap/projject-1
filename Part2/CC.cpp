#include "CC.h"

CC::CC(const uint32_t size, Graph* graph):size(size),number_of_update_index_queries(0),number_of_queries(0){
	ccindex= new uint32_t[size];
	updateIndex= new UpdateIndex(size);

	GraphPostOrderCursor* DfsIterator =new GraphPostOrderCursor(graph, true);
	uint32_t components_counter=0;		
	uint32_t curr_id;

	short res;
	while ((res = DfsIterator->next(&curr_id)) != ENDOFCURSOR){
		if (res==ENDOFCOMPONENT){
			components_counter++;
			continue;
		}
		ccindex[curr_id]= components_counter; 
	}
}

CC::~CC(){
	delete[] ccindex;
	delete updateIndex;
}

void CC::rebuildIndexes(){
	for (int i=0;size;i++){
		ccindex[i] = updateIndex->component_belongs_to_component(ccindex[i]);
	}
}

bool CC::OverflowThreshhold(){
	return (float)number_of_update_index_queries/number_of_queries > THRESHOLD;
}

int CC::findNodeConnectedComponentID(uint32_t nodeId){
	return ccindex[nodeId];
}

void CC::insertNewEdge(uint32_t nodeIdS, uint32_t nodeIdE){
	uint32_t componentS, componentE;
	componentS= findNodeConnectedComponentID(nodeIdS);
	componentE= findNodeConnectedComponentID(nodeIdE);
	updateIndex->MergeComponent(componentS,componentE);
}

bool CC::isPossiblyReachable(uint32_t source_node,uint32_t target_node){
	bool answer=false;
	int source_component = findNodeConnectedComponentID(source_node);
	int target_component =  findNodeConnectedComponentID(target_node);
	if ( source_component == target_component ) {
		answer = true;
	}
	// Search in Update Index
	else if( updateIndex->component_belongs_to_component(source_component) == updateIndex->component_belongs_to_component(target_component) ) {
		answer = true;
		number_of_update_index_queries++;
	}
	
	// Update Metric
	number_of_queries++;	

	// Check for overflow
	if ( OverflowThreshhold() ){
		rebuildIndexes();
	}

	return answer;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

UpdateIndex::UpdateIndex(uint32_t size):size(size){
	index= new uint32_t[size];
	index_list = new StackLinkedList*[size];
	for (int i = 0; i < size; ++i){
		index[i] = -1;
		index_list[i] = new StackLinkedList();					// Mporoume na min dimiourgoume gia ola. Na dimiourgoume mono otan xreiazetai
	}
}

UpdateIndex::~UpdateIndex(){
	for (int i = 0; i < size; ++i)
	{
		delete index_list[i];
	}
	delete[] index_list;
	delete[] index;
}

int UpdateIndex::component_belongs_to_component(int component){
	return (index[component]==-1)? component : index[component] ;
}

void UpdateIndex::MergeComponent(int componentS,int componentE){
	int tcomponentS = component_belongs_to_component(componentS);
	int tcomponentE = component_belongs_to_component(componentE);

	// Same Component
	if (tcomponentS==tcomponentE)
		return;

	int max,min;		// mporoume na epilegoume ws min auto me tin mikroteri lista gia megaluteri apodosi
	if (tcomponentS>tcomponentE){
		max = tcomponentS;
		min = tcomponentE;
	}
	else{
		max = tcomponentE;
		min = tcomponentS;
	}

	index[max] = min;
	index_list[min]->push(max);
	int cur_comp;
	while (!index_list[max]->isEmpty()){
		cur_comp = index_list[max]->pop();
		index_list[min]->push(cur_comp);
		index[cur_comp] = min;
	}

}
