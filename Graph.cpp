#include "Graph.h"
#include "QueueSet.h"

void Graph::insertNode(uint32_t id) {
	out.insertNode(id);
	in.insertNode(id);
}

void Graph::addEdge(uint32_t from, uint32_t to) {
	out.addEdge(from, to);
	in.addEdge(to, from);
}

long Graph::question(uint32_t from, uint32_t to) {
	if (to == from) return 0;

	size_t max = (out.index.getCapacity() > in.index.getCapacity()) ? out.index.getCapacity() : in.index.getCapacity();
	ListQueueSet start(max);
	ListQueueSet target(max);

	long lvl = 1;

	start.push(from);
	target.push(to);

	while (!start.empty() && !target.empty()) {
		if (out.bfs(start, target)) return 2*lvl-1;
		if (in.bfs(target, start)) return 2*lvl;
		lvl++;
	}

	return -1;
}

void Graph::print(void) {
	std::cout << "OUT EDGES" << std::endl;
	out.print();
	std::cout << "IN EDGES" << std::endl;
	in.print();
}

/////////////////////////////////////////////////

void Pair::insertNode(uint32_t id) {
	index.insertNode(id);
}

void Pair::addEdge(uint32_t from, uint32_t to) {
	index.insertNode(from);
	//index.insertNode(to);

	Node& node = index[from];
//	if (buffer.find(node.offset, to, node.size) == true) return;
	if (node.size == LIST_NODE_CAPACITY) {
		node.offset = buffer.allocNewNode(node.offset);
		node.size = 0;
	}

	buffer[node.offset].neighbor[node.size] = to;
	node.size++;
}

void Pair::print(void) {
	for (uint32_t i = 0; i < index.getCapacity(); ++i)
	{
		std::cout << "NODE " << i << std::endl;
		Node& node = index[i];
		size_t size = node.size;
		size_t offset = node.offset;
		while (offset != NONE)
		{
			list_node& bucket = buffer[offset];
			std::cout << "\tBUCKET " << offset << ':';
			for (size_t i = 0; i < size; ++i)
				std::cout << ' ' << bucket.neighbor[i];
			std::cout << std::endl;
			offset = bucket.nextListNode;
			size = LIST_NODE_CAPACITY;
		}
	}
}

bool Pair::bfs(ListQueueSet& start, ListQueueSet& target) {
	size_t size = start.getSize();
	for (size_t i = 0; i < size; ++i) {
		uint32_t id = start.pop();
		
		Node& node = index[id];
		size_t size = node.size;
		size_t offset = node.offset;
		while (offset != NONE)
		{
			list_node& bucket = buffer[offset];
			for (size_t i = 0; i < size; ++i) {
				id = bucket.neighbor[i];
				if (start.getVisited(id) == false) {
					if (target.getVisited(id) == true) return true;
					start.push(id);
				}
			}
			offset = bucket.nextListNode;
			size = LIST_NODE_CAPACITY;
		}
	}
	return false;
}
