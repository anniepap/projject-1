#include "Graph.h"

int main(void) {
	Graph graph;

	graph.addEdge(1, 2);
	graph.addEdge(2, 3);
	graph.addEdge(3, 1);
	graph.addEdge(4, 1);
	graph.addEdge(2, 4);

	graph.question(1, 3);
	graph.addEdge(4, 5);
	graph.question(1, 5);
	graph.question(5, 1);

	graph.print();
	return 0;
}
