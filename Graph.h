#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "NodeIndex.h"
#include "QueueSet.h"
#include "Buffer.h"

class Pair {
	Buffer buffer;
	NodeIndex index;
public:
	void insertNode(uint32_t id);
	void addEdge(uint32_t from, uint32_t to);
	bool bfs(QueueSet& start, QueueSet& target);
	size_t getCapacity();
	size_t getCount(uint32_t id);
	bool find(uint32_t to, uint32_t from);
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
