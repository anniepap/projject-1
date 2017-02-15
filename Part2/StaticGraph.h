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
	virtual long question(uint32_t from, uint32_t to,uint32_t version=0);
	virtual long question(uint32_t from, uint32_t to, SCC*, uint32_t);
	virtual long question(uint32_t from, uint32_t to,GrailIndex* grail_index);
	void init(void);
};

#endif
