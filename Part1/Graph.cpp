#include "Graph.h"
#include "PairCursor.h"
#include "QueueSet.h"

void Graph::addEdge(uint32_t from, uint32_t to) {

	if (in.getCapacity() > to && out.getCapacity() > from) {
		if (in.getCount(to) < out.getCount(from)) {
			if (in.find(from, to)) return;
		}
		else {
			if (out.find(to, from)) return;
		}
	}

	out.addEdge(from, to);
	in.addEdge(to, from);
}

long Graph::question(uint32_t from, uint32_t to) {
	if (to == from) return 0;

	size_t max = (out.getCapacity() > in.getCapacity()) ? out.getCapacity() : in.getCapacity();

	QueueSet start(max);
	QueueSet target(max);

	long lvl = 1;

	start.push(from);
	target.push(to);
/*
	while (!start.empty() && !target.empty()) {
		if (out.bfs(start, target)) return (lvl<<1)-1;
		if (in.bfs(target, start)) return lvl<<1;
		lvl++;
	}
*/
	while (!start.empty() && !target.empty()) {
		if (target.size() < start.size()) {
			if (in.bfs(target, start)) return lvl;
		}
		else {
			if (out.bfs(start, target)) return lvl;
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

void Pair::addEdge(uint32_t from, uint32_t to) {
	insertNode(from);

	Node& node = index[from];

	if (node.size[to % NODE_HASH] == LIST_NODE_CAPACITY) {
		node.offset[to % NODE_HASH] = buffer.allocNewNode(node.offset[to % NODE_HASH]);
		node.size[to % NODE_HASH] = 0;
		node.count++;
	}

	buffer[node.offset[to % NODE_HASH]].neighbor[node.size[to % NODE_HASH]] = to;
	node.size[to % NODE_HASH]++;
}

bool Pair::bfs(QueueSet& start, QueueSet& target) {
	size_t size = start.size();
	PairCursor pc(this);
	for (size_t i = 0; i < size; ++i) {
		pc.init(start.pop());			// Edw skaei.
		uint32_t id;
		while (pc.next(&id)) {
			if (start.visited(id) == false) {
				if (target.visited(id) == true) return true;
				start.push(id);
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
