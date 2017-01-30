#include "DynamicGraph.h"

void DynamicGraph::addEdge(uint32_t from, uint32_t to,uint32_t version) {
	Graph::addEdge(from, to, version);
	cc->insertNewEdge(from, to);
}

long DynamicGraph::question(uint32_t from, uint32_t to,uint32_t version) {
	return (cc->isPossiblyReachable(from, to)) ? Graph::question(from, to,version) : -1;
	// prepei na doume poia sunartisi kaleitai edw
}

void DynamicGraph::init(void) {
	cc = new CC(this);
}

DynamicGraph::~DynamicGraph() {
	delete cc;
}
