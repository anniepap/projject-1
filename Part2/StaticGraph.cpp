#include "StaticGraph.h"
#include "GrailIndex.h"

bool Pair::bfs(QueueSet& start, QueueSet& target, SCC* scc, uint32_t sccId) {
	size_t size = start.size();
	PairCursor pc(this);
	uint32_t id;
	uint32_t sccNid;
	for (size_t i = 0; i < size; ++i) {
		pc.init(start.pop());
		while (pc.next(&id)) {
			sccNid = scc->findNodeStronglyConnectedComponentID(id);
			if (sccNid == sccId && start.visited(id) == false) {
				if (target.visited(id) == true) return true;
				start.push(id);
			}
		}
	}
	return false;
}

int Pair::bfs(QueueSet& start, QueueSet& target, GrailIndex* grail_index) {
	size_t size = start.size();
	PairCursor pc(this);
	uint32_t id;
	uint32_t target_top=target.top();
	for (size_t i = 0; i < size; ++i) {
		pc.init(start.pop());
		while (pc.next(&id)) {
			if (grail_index->isReachableGrailIndex(id, target_top) == NO) return -1;
			if (start.visited(id) == false) {
				if (target.visited(id) == true) return 1;
				start.push(id);
			}
		}
	}
	return 0;
}

long StaticGraph::question(uint32_t from, uint32_t to, SCC* scc, uint32_t sccId) {
	if (to == from) return 0;

	size_t max = (out.getCapacity() > in.getCapacity()) ? out.getCapacity() : in.getCapacity();

	QueueSet start(max);
	QueueSet target(max);

	long lvl = 1;

	start.push(from);
	target.push(to);

	int result;
	while (!start.empty() && !target.empty()) {
		if (target.size() < start.size()) {
			result = in.bfs(target, start, scc, sccId);
			if (result == -1)
				return -1;
			else if (result == 1)
				return lvl;
		}
		else {
			result = out.bfs(start, target, scc, sccId);
			if (result == -1)
				return -1;
			else if (result == 1) 
				return lvl;
		}
		lvl++;
	}

	return -1;
}

long StaticGraph::question(uint32_t from, uint32_t to, GrailIndex* grail_index) {

	if (to == from) return 0;

	size_t max = (out.getCapacity() > in.getCapacity()) ? out.getCapacity() : in.getCapacity();

	QueueSet start(max);
	QueueSet target(max);

	long lvl = 1;

	start.push(from);
	target.push(to);

	while (!start.empty() && !target.empty()) {
		if (target.size() < start.size()) {
			if (in.bfs(target, start, grail_index)) return lvl;
		}
		else {
			if (out.bfs(start, target, grail_index)) return lvl;
		}
		lvl++;
	}

	return -1;

}

void StaticGraph::init(void) {
	components = new SCC(*this);
	grail_index = new GrailIndex(components);
}

#include <iostream>
long StaticGraph::question(uint32_t from, uint32_t to,uint32_t version) {
	GRAIL_ANSWER answer = grail_index->isReachableGrailIndex(from, to);
	switch (answer)
	{
		case NO:
			return -1;
		case MAYBE:
			//return question(from, to, grail_index);
			return Graph::question(from, to, version);	
		default:
			return components->estimateShortestPathStronglyConnectedComponents(from, to);
	}
}

StaticGraph::~StaticGraph() {
	delete components;
	delete grail_index;
}
