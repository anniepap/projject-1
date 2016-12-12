#include "Graph.h"
#include <cstring>
#include <fstream>
#include <iostream>
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
		// static graph

	}
	else if (strcmp(graphType, "DYNAMIC")) {
		/* code */
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