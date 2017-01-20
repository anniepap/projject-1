#include "StaticGraph.h"
/*

long Graph::question(uint32_t from, uint32_t to, uint32_t version, SCC* scc, uint32_t sccId) {
	if (to == from) return 0;

	size_t max = (out.getCapacity() > in.getCapacity()) ? out.getCapacity() : in.getCapacity();

	QueueSet start(max);
	QueueSet target(max);

	long lvl = 1;

	start.push(from);
	target.push(to);

	while (!start.empty() && !target.empty()) {
		if (target.size() < start.size()) {
			if (in.bfs(target, start, scc, sccId)) return lvl;
		}
		else {
			if (out.bfs(start, target, scc, sccId)) return lvl;
		}
		lvl++;
	}

	return -1;
}

bool Pair::bfs(QueueSet& start, QueueSet& target, SCC* scc, uint32_t sccId) {
	size_t size = start.size();
	PairCursor pc(this);
	for (size_t i = 0; i < size; ++i) {
		pc.init(start.pop());
		uint32_t id;
		uint32_t sccNid;
		while (pc.next(&id)) {
			sccNid = scc->findNodeStronglyConnectedComponentID(id);
			if (start.visited(id) == false && sccNid == sccId) {
				if (target.visited(id) == true) return true;
				start.push(id);
			}
		}
	}
	return false;
}
*/
void StaticGraph::init(void) {
	components = new SCC(this);
	grail_index = new GrailIndex(components);
}

long StaticGraph::question(uint32_t from, uint32_t to) {
	GRAIL_ANSWER answer = grail_index->isReachableGrailIndex(from, to);
	if (answer == NO)
		return -1;
	else if (answer == YES)
		return components->estimateShortestPathStronglyConnectedComponents(from, to);
	else 
		return Graph::question(from, to);
		// Psaksimo se olo to graph kai elegxos kathe fora eswterika sto grail
}

StaticGraph::~StaticGraph() {
	delete components;
	delete grail_index;
}
