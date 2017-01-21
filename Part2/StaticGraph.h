#ifndef __STATIC_GRAPH_H__
#define __STATIC_GRAPH_H__

#include "../Part1/Graph.h"
#include "SCC.h"

class GrailIndex;

class StaticGraph : public Graph {
	SCC* components;
	GrailIndex* grail_index;
public:
	~StaticGraph();
	long question(uint32_t from, uint32_t to);
	long question(uint32_t from, uint32_t to, SCC*, uint32_t);
	void init(void);
};

#endif
