#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "NodeIndex.h"
#include "QueueSet.h"
#include "Buffer.h"

struct Pair {
	Buffer buffer;
	NodeIndex index;
public:
	void insertNode(uint32_t id);
	void addEdge(uint32_t from, uint32_t to);
	bool bfs(ListQueueSet& start, ListQueueSet& target);
};

class Graph
{
	Pair out;
	Pair in;
public:
	void insertNode(uint32_t id);
	void addEdge(uint32_t from, uint32_t to);
	long question(uint32_t from, uint32_t to);
};

#endif
