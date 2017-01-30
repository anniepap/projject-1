#ifndef __GRAILINDEX_H__
#define __GRAILINDEX_H__

#include "../Part1/defines.h"
#include "../Part1/Graph.h"
#include "SCC.h"
#include "GraphPostOrderCursor.h"

#define NUMBEROFLABELS 2
enum GRAIL_ANSWER {NO=0, MAYBE=1, YES=2};

class GrailIndexNode;

class GrailIndex {
	const uint32_t SizeOfIndex;
	GrailIndexNode** IndexTables;
	SCC* components;
public:
	GrailIndex(SCC* components);
	~GrailIndex();
	GRAIL_ANSWER isReachableGrailIndex(uint32_t source_node,uint32_t target_node);
};

class GrailIndexNode {
	uint32_t min_rank;
	uint32_t rank;
public:
	GrailIndexNode();
	void set(uint32_t min_rank, uint32_t rank);
	bool isSeted();
	bool isSubSet(GrailIndexNode& Y);
	uint32_t MinRank();
};

#endif
