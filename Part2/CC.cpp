#include "CC.h"

CC::CC(const uint32_t size, Graph* graph):size(size),number_of_update_index_queries(0),number_of_queries(0){
	ccindex= new uint32_t[size];
	updateIndex= new UpdateIndex(size);

	GraphPostOrderCursor* DfsIterator =new GraphPostOrderCursor(graph, true);
	uint32_t components_counter=0;		
	uint32_t curr_id;
	while((curr_id=DfsIterator->Next())!=NONE){
		if (curr_id==ENDOFCOMPONENT){
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

bool CC::isPossiblyReachable(uint32_t source_node,uint32_t target_node){
	bool answer=false, isUpdateUsed=false;
	if ( findNodeConnectedComponentID(from) == findNodeConnectedComponentID(to) ) {
		answer = true;
	}
	else if ( updateIndex->isConnected( from, to) ) {
		answer = true;
		isUpdateUsed = true;
	}
	
	// Update Metric
	if (isUpdateUsed) number_of_update_index_queries++;
	number_of_queries++;	

	// Check for overflow
	if ( OverflowThreshhold() ){
		rebuildIndexes();
	}

	return answer;
}


UpdateIndex* CC::getUpdateIndex(){
	return updateIndex;
}

void CC::insertNewEdge(uint32_t nodeIdS, uint32_t nodeIdE){
	// An ennonwntai 2 component
	uint32_t componentS, componentE;
	componentS= findNodeConnectedComponentID(nodeIdS);
	componentE= findNodeConnectedComponentID(nodeIdE);
	if (componentS!=componentE){
		SetUpdateIndex(componentS, componentE);
		SetUpdateIndex(componentE, componentS);	
	}
}

int CC::findNodeConnectedComponentID(uint32_t nodeId){
	return ccindex[nodeId];
}

void  CC::rebuildIndexes(){
	for (int i=0;updateIndex->Size();i++){
		if ( i<updateIndex->Index(i) ){
			for(int j=0;j<size;j++){		// theloume Allo algorithmo. Autos kanei n^2
				if ( ccindex[j]==updateIndex->Index(i) ){
					ccindex[j]= i;
				}
			}
		}
	}
}

bool CC::OverflowThreshhold(){
	return (float)number_of_update_index_queries/number_of_queries > THRESHOLD;
}


void CC::SetUpdateIndex(uint32_t componentId, uint32_t component_attached){
	updateIndex->SetUpdateIndex(componentId,component_attached);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

UpdateIndex::UpdateIndex(uint32_t size):size(size){
	index= new uint32_t[size];
}

UpdateIndex::~UpdateIndex(){
	delete[] index;
}

bool UpdateIndex::isConnected(uint32_t from, uint32_t to){
	//////// code here

}

void UpdateIndex::SetUpdateIndex(uint32_t componentId, uint32_t component_attached){
	index[componentId]= component_attached;
}

uint32_t UpdateIndex::Size(){
	return size;
}

uint32_t UpdateIndex::Index(uint32_t pos){
	return index[pos];
}
