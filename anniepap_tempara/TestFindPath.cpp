#include <cstring>
#include <fstream>
#include <iostream>
#include "Graph.h"
#include "SCC.h"
using namespace std;

int main(int argc, char** argv) {
	//if (argc != 3) return -1;

	Graph graph;
	ifstream myReadFile;
	char com;
	char* gType = new char[10];
	int size = 0;
	uint32_t from;
	uint32_t to;

	myReadFile.open(argv[1]);
	if (myReadFile.is_open()) {
		myReadFile.getline(gType, sizeof(gType)*10);

		for (int i = 0; gType[i] != '\0'; ++i) {
			size++;
		}

		while (!myReadFile.eof()) {
			myReadFile >> from >> to;
			if (!myReadFile.good())
				break;
			graph.addEdge(from, to);
		}
	}
	myReadFile.close();

	char* graphType = new char[size];

	for (int i = 0; i < size-1; ++i) {
		graphType[i] = gType[i];
	}

	if (strcmp(graphType, "STATIC") == 0) {
		SCC scc(11, graph);
		uint32_t* ptr = scc.getInvertedIndex();
		ptr[0] = 1;
		ptr[1] = 1;
		ptr[2] = 1;
		ptr[3] = 2;
		ptr[4] = 2;
		ptr[5] = 2;
		ptr[6] = 3;
		ptr[7] = 3;
		ptr[8] = 3;
		ptr[9] = 3;
		ptr[10] = 4;

		cout << "not the same SCC: " << scc.estimateShortestPathStronglyConnectedComponents(graph, 0, 10) << endl; 
		cout << "not the same SCC: " << scc.estimateShortestPathStronglyConnectedComponents(graph, 2, 3) << endl;
		cout << "not the same SCC: " << scc.estimateShortestPathStronglyConnectedComponents(graph, 10, 9) << endl;
		cout << "not the same SCC: " << scc.estimateShortestPathStronglyConnectedComponents(graph, 5, 7) << endl;
		cout << "same SCC: " << scc.estimateShortestPathStronglyConnectedComponents(graph, 6, 9) << endl;
		cout << "same SCC: " << scc.estimateShortestPathStronglyConnectedComponents(graph, 0, 2) << endl;
		cout << "same SCC: " << scc.estimateShortestPathStronglyConnectedComponents(graph, 3, 4) << endl;
	}

	else if (strcmp(graphType, "DYNAMIC")) {
		cout << "er!" << endl;
	}
	
	//graph.test();

/*
	myReadFile.open(argv[2]);
	if (myReadFile.is_open()) {
		while(!myReadFile.eof()) {
			myReadFile >> com;
			if (com != 'F')
				myReadFile >> from >> to;
			if (com == 'A')
				graph.addEdge(from, to);
			if (com == 'Q')
				cout << graph.question(from, to) << endl;
//				graph.question(from, to);
		}
	}
	myReadFile.close();
*/
	
	delete[] gType;
	delete[] graphType;
	return 0;
}