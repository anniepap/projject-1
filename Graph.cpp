#include "Graph.h"

Graph::Graph() {
	printf("Graph::Graph\n");
}

Graph::~Graph() {
	printf("Graph::~Graph\n");
}

void Graph::insertNode(uint32_t id) {
	printf("Graph::insertNode\n");
	out.insertNode(id);
	in.insertNode(id);
}

void Graph::addEdge(uint32_t from, uint32_t to) {
	printf("Graph::addEdge\n");
	out.addEdge(from, to);
	in.addEdge(to, from);
}

void Graph::question(uint32_t from, uint32_t to) {
	printf("Graph::question\n");
}

/////////////////////////////////////////////////

Pair::Pair() {
	printf("Pair::Pair\n");
}

Pair::~Pair() {
	printf("Pair::~Pair\n");
}

void Pair::insertNode(uint32_t id) {
	printf("Pair::insertNode\n");
	index.insertNode(id);
}

void Pair::addEdge(uint32_t from, uint32_t to) {
	printf("Pair::addEdge\n");
	index.insertNode(from);
	index.insertNode(to);

	Node& node = index[from];
	if (buffer.find(node.offset, to) == true) return;
	if (node.size == LIST_NODE_CAPACITY) {
		node.offset = buffer.allocNewNode(node.offset);
	}

	buffer[node.offset].neighbor[node.size] = to;
	node.size++;
}

