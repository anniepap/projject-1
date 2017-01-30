#include "DynamicGraph.h"

void DynamicGraph::addEdge(uint32_t from, uint32_t to) {
	Graph::addEdge(from, to);
	cc->insertNewEdge(from, to);
}

long DynamicGraph::question(uint32_t from, uint32_t to) {
	std::cerr<<"Mpika 3"<<std::endl;
	return (cc->isPossiblyReachable(from, to)) ? question(from, to) : -1;
	// prepei na doume poia sunartisi kaleitai edw
}

void DynamicGraph::init(void) {
	cc = new CC(this);
}

DynamicGraph::~DynamicGraph() {
	delete cc;
}
