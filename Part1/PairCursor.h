#ifndef __PAIR_CURSOR_H__
#define __PAIR_CURSOR_H__

class Pair;
class Node;
class Graph;

#include "Graph.h"
#include "NodeIndex.h"

class PairCursor {
	Pair* pair;
	Node* node;
	size_t hash;
	size_t offset;
	size_t size;
	size_t pos;
public:
	PairCursor(Pair* pair);
	PairCursor(Graph& graph, bool out);
	void init(uint32_t id);
	bool next(uint32_t* id);
};

#endif
