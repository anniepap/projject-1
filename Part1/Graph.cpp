#include "Graph.h"
#include "../Part2/SCC.h"

void Graph::addEdge(uint32_t from, uint32_t to, uint32_t version) {

	if (in.getCapacity() > to && out.getCapacity() > from) {
		if (in.getCount(to) < out.getCount(from)) {
			if (in.find(from, to)) return;
		}
		else {
			if (out.find(to, from)) return;
		}
	}

	out.addEdge(from, to, version);
	in.addEdge(to, from, version);
}

long Graph::question(uint32_t from, uint32_t to, uint32_t version) {
	if (to == from) return 0;

	size_t max = (out.getCapacity() > in.getCapacity()) ? out.getCapacity() : in.getCapacity();

	QueueSet start(max);
	QueueSet target(max);

	long lvl = 1;

	start.push(from);
	target.push(to);

	while (!start.empty() && !target.empty()) {
		if (target.size() < start.size()) {
			if (in.bfs(target, start, version)) return lvl;
		}
		else {
			if (out.bfs(start, target, version)) return lvl;
		}
		lvl++;
	}

	return -1;
}

Pair& Graph::getOut() {
	return out;
}

Pair& Graph::getIn() {
	return in;
}

uint32_t Graph::SizeOfNodes(){
	return (out.getCapacity() > in.getCapacity()) ? out.getCapacity() : in.getCapacity();
}

/////////////////////////////////////////////////

void Pair::addEdge(uint32_t from, uint32_t to, uint32_t version) {
	insertNode(from);

	Node& node = index[from];

	int mod = to % NODE_HASH;

	if (node.size[mod] == LIST_NODE_CAPACITY) {
		node.offset[mod] = buffer.allocNewNode(node.offset[mod]);
		node.size[mod] = 0;
		node.count++;
	}

	buffer[node.offset[mod]].neighbor[node.size[mod]] = to;
	buffer[node.offset[mod]].edgeProperty[node.size[mod]] = version;
	node.size[to % NODE_HASH]++;
}

bool Pair::bfs(QueueSet& start, QueueSet& target, uint32_t version) {
	size_t size = start.size();
	PairCursor pc(this);
	uint32_t id;
	uint32_t vid;
	for (size_t i = 0; i < size; ++i) {
		pc.init(start.pop());
		while (pc.next(&id, &vid)) {
			if (vid <= version) {
				if (start.visited(id) == false) {
					if (target.visited(id) == true) return true;
					start.push(id);
				}
			}
		}
	}
	return false;
}

void Pair::insertNode(uint32_t id) {
	index.insertNode(id);
}

size_t Pair::getCapacity() {
	return index.getCapacity();
}

size_t Pair::getCount(uint32_t id) {
	return index[id].count;
}

bool Pair::find(uint32_t to, uint32_t from) {
	Node& node = index[from];
	return buffer.find(node.offset[to % NODE_HASH], to, node.size[to % NODE_HASH]);
}

Buffer& Pair::getBuffer() {
	return buffer;
}

NodeIndex& Pair::getIndex() {
	return index;
}
