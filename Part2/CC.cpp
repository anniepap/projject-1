#include "CC.h"

CC::CC(Graph* graph) : number_of_update_index_queries(0), number_of_queries(0) {
	size = graph->SizeOfNodes();
	ccindex= new uint32_t[size];
	updateIndex= new UpdateIndex(size);

	GraphPostOrderCursor DfsIterator(graph, true);
	uint32_t components_counter=0;		
	uint32_t curr_id;

	short res;
	while ((res = DfsIterator.next(&curr_id)) != ENDOFCURSOR) {
		if (res==ENDOFCOMPONENT){
			components_counter++;
			continue;
		}
		ccindex[curr_id]= components_counter; 
	}
}

CC::~CC() {
	delete[] ccindex;
	delete updateIndex;
}

void CC::rebuildIndexes() {
	for (uint32_t i=0;i<size;i++) {
		ccindex[i] = updateIndex->component_belongs_to_component(ccindex[i]);
	}
}

bool CC::OverflowThreshhold(){
	return number_of_update_index_queries > THRESHOLD * (double) number_of_queries;
}

uint32_t CC::findNodeConnectedComponentID(uint32_t nodeId){
	return ccindex[nodeId];
}

void CC::insertNewEdge(uint32_t nodeIdS, uint32_t nodeIdE){
	uint32_t componentS, componentE;
	componentS = findNodeConnectedComponentID(nodeIdS);
	componentE = findNodeConnectedComponentID(nodeIdE);
	updateIndex->MergeComponent(componentS,componentE);
}

bool CC::isPossiblyReachable(uint32_t source_node,uint32_t target_node){
	bool answer=false;
	uint32_t source_component = findNodeConnectedComponentID(source_node);
	uint32_t target_component = findNodeConnectedComponentID(target_node);
	if ( source_component == target_component ) {
		answer = true;
	}
	// Search in Update Index
	else if ( updateIndex->component_belongs_to_component(source_component) == updateIndex->component_belongs_to_component(target_component) ) {
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
	for (uint32_t i = 0; i < size; ++i){
		index[i] = (uint32_t)-1;
		index_list[i] = new StackLinkedList();
	}
}

UpdateIndex::~UpdateIndex(){
	for (uint32_t i = 0; i < size; ++i)
	{
		delete index_list[i];
	}
	delete[] index_list;
	delete[] index;
}

uint32_t UpdateIndex::component_belongs_to_component(uint32_t component){
	return (index[component]==(uint32_t)-1) ? component : index[component];
}

void UpdateIndex::MergeComponent(uint32_t componentS,uint32_t componentE){
	uint32_t tcomponentS = component_belongs_to_component(componentS);
	uint32_t tcomponentE = component_belongs_to_component(componentE);

	if (tcomponentS==tcomponentE)
		return;

	uint32_t max,min;		
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
	uint32_t cur_comp;
	while (!index_list[max]->isEmpty()){
		cur_comp = index_list[max]->pop();
		index_list[min]->push(cur_comp);
		index[cur_comp] = min;
	}

}
