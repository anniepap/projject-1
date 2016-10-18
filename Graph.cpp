#include "Graph.h"

Graph::Graph() {
}

Graph::~Graph() {
}

void Graph::createNode(uint32_t id) {
	out.createNode(id);
	in.createNode(id);
}

void Graph::addEdge(uint32_t from, uint32_t to) {
	createNode(from);
	createNode(to);
	out.addEdge(from, to);
	in.addEdge(to, from);
}

void Graph::question(uint32_t from, uint32_t to){
}

/////////////////////////////////////////////////

Pair::Pair() {
}

Pair::~Pair() {
}

void Pair::createNode(uint32_t id) {
}

void Pair::addEdge(uint32_t from, uint32_t to) {
}

