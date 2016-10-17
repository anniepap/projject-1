#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Buffer.h"
#include "NodeIndex.h"

class Pair {
	Buffer buffer;
	NodeIndex index;
public:
	Pair();
	~Pair();
	createNode(uint32_t id);
	addEdge(uint32_t from, uint32_t to);
};

class Graph
{
	Pair in;
	Pair out;
public:
	Graph();
	~Graph();
	createNode(uint32_t id);
	addEdge(uint32_t from, uint32_t to);
	question(uint32_t from, uint32_t to);
};

#endif
