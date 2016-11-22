#ifndef __CC_H__
#define __CC_H__

#include "defines.h"

struct CCIndex {
	uint32_t nodeId;
	uint32_t ccId;
};

struct UpdateIndex {
	uint32_t fromccId;
	uint32_t toccId;
};

class CC {
	CCIndex* ccindex; 			// CCIndex
	UpdateIndex* updateIndex;
	uint32_t metricVal;
public:
 	CC();
 	~CC();
	CC* estimateConnectedComponents(NodeIndex* graph);
	OK_SUCCESS insertNewEdge(CC* components, uint32_t nodeIdS, uint32_t nodeIdE);
	int findNodeConnectedComponentID(CC* components, uint32_t nodeId);
	OK_SUCCESS rebuildIndexes(CC* components);
	//DISTRACTOR: OK_SUCCESS destroyConnectedComponents(CC* components);
};