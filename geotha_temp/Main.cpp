#include <iostream>
#include "GrailIndex.h"
#include "../Graph.h"
#include <fstream>

using namespace std;

main(int argc, char** argv){


	if (argc != 2) return -1;

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



	GrailIndex* temp= new GrailIndex(&graph);

	cout<< temp->isReachableGrailIndex(5,6) << endl;

	delete temp;

	
}