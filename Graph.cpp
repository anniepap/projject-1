#include "Graph.h"

Graph::Graph() {
	printf("Graph::Graph\n");
}

Graph::~Graph() {
	printf("Graph::~Graph\n");
}

void Graph::createNode(uint32_t id) {
	printf("Graph::createNode\n");
	out.createNode(id);
	in.createNode(id);
}

void Graph::addEdge(uint32_t from, uint32_t to) {
	printf("Graph::addEdge\n");
	createNode(from);
	createNode(to);
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

void Pair::createNode(uint32_t id) {
	printf("Pair::createNode\n");
}

void Pair::addEdge(uint32_t from, uint32_t to) {
	printf("Pair::addEdge\n");
}

