#ifndef __DYNAMIC_GRAPH_H__
#define __DYNAMIC_GRAPH_H__

#include "../Part1/Graph.h"
#include "CC.h"

class DynamicGraph : public Graph {
	CC* cc;
public:
	~DynamicGraph();
	void addEdge(uint32_t from, uint32_t to, uint32_t version);
	long question(uint32_t from, uint32_t to,uint32_t version);
	void init(void);
};

#endif
