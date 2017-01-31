#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "NodeIndex.h"
#include "QueueSet.h"
#include "Buffer.h"

class SCC;
class GrailIndex;

class Pair {
	friend class PairCursor;
	Buffer buffer;
	NodeIndex index;
public:
	void insertNode(uint32_t id);
	void addEdge(uint32_t from, uint32_t to, uint32_t version);
	bool bfs(QueueSet& start, QueueSet& target, uint32_t version);
	bool bfs(QueueSet& start, QueueSet& target, SCC* scc, uint32_t sccId);
	bool bfs(QueueSet& start, QueueSet& target, SCC* scc, GrailIndex* grail_index);
	size_t getCapacity();
	size_t getCount(uint32_t id);
	bool find(uint32_t to, uint32_t from);

	Buffer& getBuffer();
	NodeIndex& getIndex();
};

class Graph {
protected:
	Pair out;
	Pair in;
public:
	virtual ~Graph() {}
	virtual void addEdge(uint32_t from, uint32_t to, uint32_t version=0);
	virtual long question(uint32_t from, uint32_t to, uint32_t version=0);
	virtual void init(void) {}

	Pair& getOut();
	Pair& getIn();
	uint32_t SizeOfNodes();
};

#endif
