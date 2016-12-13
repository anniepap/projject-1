#include "../Part1/Graph.h"
#include "SCC.h"

int main(void) {
	Graph graph;

	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(2, 0);

	graph.addEdge(2, 3);

	graph.addEdge(3, 4);
	graph.addEdge(4, 5);
	graph.addEdge(5, 3);

	graph.addEdge(6, 5);

	graph.addEdge(6, 7);
	graph.addEdge(7, 8);
	graph.addEdge(8, 9);
	graph.addEdge(9, 6);

	graph.addEdge(9, 10);

	SCC scc(graph.SizeOfNodes());
	scc.estimateStronglyConnectedComponents(graph.getOut());
	scc.print();

	return 0;
}
