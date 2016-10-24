#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "NodeIndex.h"
#include "Buffer.h"

struct Pair {
	Buffer buffer;
	NodeIndex index;
public:
	void insertNode(uint32_t id);
	void addEdge(uint32_t from, uint32_t to);
	void print(void);
};

class Graph
{
	Pair out;
	Pair in;
public:
	void insertNode(uint32_t id);
	void addEdge(uint32_t from, uint32_t to);
	void question(uint32_t from, uint32_t to);
	void print(void);
};

#endif
