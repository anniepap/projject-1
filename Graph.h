#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "NodeIndex.h"
#include "Buffer.h"

class Pair {
	Buffer buffer;
	NodeIndex index;
public:
	Pair();
	~Pair();
	void insertNode(uint32_t id);
	void addEdge(uint32_t from, uint32_t to);
	void print(void);
};

class Graph
{
	Pair out;
	Pair in;
public:
	Graph();
	~Graph();
	void insertNode(uint32_t id);
	void addEdge(uint32_t from, uint32_t to);
	void question(uint32_t from, uint32_t to);
	void print(void);
};

#endif
