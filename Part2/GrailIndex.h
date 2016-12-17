#ifndef __GRAILINDEX_H__
#define __GRAILINDEX_H__

#include "../Part1/defines.h"
#include "../Part1/Graph.h"
#include "SCC.h"
#include "GraphPostOrderCursor.h"

#define NUMBEROFLABELS 1
enum GRAIL_ANSWER  {NO=0, MAYBE=1, YES=2};		

class GrailIndexNode;

class GrailIndex {
	const uint32_t SizeOfIndex;
	GrailIndexNode** IndexTables;
	SCC* components;
public:
	GrailIndex(SCC* components ); 				// Elegxitke
	~GrailIndex(); 
	GRAIL_ANSWER isReachableGrailIndex(uint32_t source_node,uint32_t target_node);		// Den elegxike	
};

class GrailIndexNode {
	int min_rank;
	int rank;
public:
	void set(int min_rank, int rank);
	bool isSubSet(GrailIndexNode& Y);
	int MinRank();
};

#endif
