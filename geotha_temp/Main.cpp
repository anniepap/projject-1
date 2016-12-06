#include <iostream>
#include "GrailIndex.h"
#include "../Graph.h"
#include <fstream>

using namespace std;

main(int argc, char** argv){

	if (argc != 3) return -1;

	Graph graph;
	ifstream myReadFile;
	char com;
	uint32_t from;
	uint32_t to;

	myReadFile.open(argv[1]);
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			myReadFile >> from >> to;
			if (!myReadFile.good())
				break;
			graph.addEdge(from, to);
		}
	}
	myReadFile.close();

	GraphPostOrderCursor* temp= new GraphPostOrderCursor(&graph);

	
}