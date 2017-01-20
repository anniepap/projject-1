#ifndef __STATIC_GRAPH_H__
#define __STATIC_GRAPH_H__

#include "../Part1/Graph.h"
#include "GrailIndex.h"

class StaticGraph : public Graph {
	SCC* components;
	GrailIndex* grail_index;
public:
	~StaticGraph();
	long question(uint32_t from, uint32_t to);
	void init(void);
};

#endif
