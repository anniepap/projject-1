#ifndef __GRAILINDEX_H__
#define __GRAILINDEX_H__

#define NUMBEROFLABELS 5

//#include "ListNode.h"

class GrailIndex {
	const uint32_t SizeOfIndex;
	GrailIndexNode** IndexTables;
	enum GRAIL_ANSWER = {NO=0, MAYBE=1, YES=2};		// Isws Global
public:
	GrailIndex(NodeIndex* graph, SCC* components); 
	~GrailIndex(); 
	GRAIL_ANSWER isReachableGrailIndex(uint32_t source_node,uint32_t target_node);
};

class GrailIndexNode {
	int min_rank;
	int rank;
public: 
	GrailIndexNode(int min_rank, int rank);
	bool isSubSet(GrailIndexNode X, GrailIndexNode Y);
}

#endif