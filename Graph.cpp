#include "Graph.h"

Graph::Graph() {
	printf("Graph::Graph\n");
}

Graph::~Graph() {
	printf("Graph::~Graph\n");
}

void Graph::insertNode(uint32_t id) {
	out.insertNode(id);
	in.insertNode(id);
}

void Graph::addEdge(uint32_t from, uint32_t to) {
	out.addEdge(from, to);
	in.addEdge(to, from);
}

void Graph::question(uint32_t from, uint32_t to) {
	printf("Graph::question %lu->%lu\n", from, to);
}

void Graph::print(void) {
	printf("OUT EDGES\n");
	out.print();
	printf("IN EDGES\n");
	in.print();
}

/////////////////////////////////////////////////

Pair::Pair() {
	printf("Pair::Pair\n");
}

Pair::~Pair() {
	printf("Pair::~Pair\n");
}

void Pair::insertNode(uint32_t id) {
	index.insertNode(id);
}

void Pair::addEdge(uint32_t from, uint32_t to) {
	index.insertNode(from);
	index.insertNode(to);

	Node& node = index[from];
	if (buffer.find(node.offset, to, node.size) == true) return;
	if (node.size == LIST_NODE_CAPACITY) {
		node.offset = buffer.allocNewNode(node.offset);
		node.size = 0;
	}

	buffer[node.offset].neighbor[node.size] = to;
	node.size++;
}

void Pair::print(void) {
	for (uint32_t i = 0; i < 8; ++i)
	{
		printf("NODE %lu\n", i);
		Node& node = index[i];
		size_t size = node.size;
		size_t offset = node.offset;
		while (offset != NONE)
		{
			list_node& bucket = buffer[offset];
			printf("\tBUCKET %u:", offset);
			for (size_t i = 0; i < size; ++i)
				printf(" %lu", bucket.neighbor[i]);
			printf("\n");
			offset = bucket.nextListNode;
			size = LIST_NODE_CAPACITY;
		}
	}
}
