#include "CC.h"

CC::CC(const uint32_t size):size(size),number_of_update_index_queries(0),number_of_queries(0){
	ccindex= new uint32_t[size];
	updateIndex= new UpdateIndex(size);
}

CC::~CC(){
	delete[] ccindex;
	delete updateIndex;
}

void CC::insertNewEdge(uint32_t nodeIdS, uint32_t nodeIdE){
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

void CC::UpdateMetric(bool update_index_used){
	if (update_index_used) number_of_update_index_queries;
	number_of_queries++;	
}

float CC::Metric(){
	return (float)number_of_update_index_queries/number_of_queries;
}

void CC::SetIndex(uint32_t nodeId, uint32_t componentId ){
	ccindex[nodeId]= componentId;
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

void UpdateIndex::SetUpdateIndex(uint32_t componentId, uint32_t component_attached){
	index[componentId]= component_attached;
}

uint32_t UpdateIndex::Size(){
	return size;
}

uint32_t UpdateIndex::Index(uint32_t pos){
	return index[pos];
}
