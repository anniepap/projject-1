/* PART 2 MAIN */

#include "StaticGraph.h"
#include "DynamicGraph.h"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	if (argc != 3) return -1;
	
	Graph* graph;
	ifstream firstFile(argv[1]);
	ifstream secondFile(argv[2]);	
	char graphType[10];
	char com;
	uint32_t from;
	uint32_t to;

	if (!firstFile.is_open())
		cerr<<"File can not open"<<endl;
	if (!secondFile.is_open())
		cerr<<"File can not open"<<endl;

	// Read Type
	secondFile>>graphType;
	if (strcmp(graphType,"STATIC")==0)
		graph = new StaticGraph();
	else
		graph = new DynamicGraph();

	// Read Graph
	if (firstFile.is_open()) {
		while (!firstFile.eof()) {
			firstFile >> from >> to;
			if (!firstFile.good())
				break;
			graph->Graph::addEdge(from, to);
		}
	}
	firstFile.close();
 	
	graph->init();


	while(!secondFile.eof()) {
		secondFile>>com;
		if (com != 'F') {
			secondFile >> from >> to;
			if (com == 'A')
				graph->addEdge(from, to);
			if (com == 'Q')
				cout << graph->question(from, to) << endl;
		}
	}

	secondFile.close();

	delete graph;
	
	return 0;
}

