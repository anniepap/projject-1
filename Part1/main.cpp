#include "Graph.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
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

	myReadFile.open(argv[2]);
	if (myReadFile.is_open()) {
		myReadFile >> com;
		if (com == 'S' || com == 'D') {
			myReadFile.ignore(10, '\n');
			myReadFile >> com;
		}
		while(myReadFile.good()) {
			if (com != 'F') {
				myReadFile >> from >> to;
				if (com == 'A')
					graph.addEdge(from, to);
				else if (com == 'Q')
					cout << graph.question(from, to) << endl;
			}
			myReadFile >> com;
		}
	}
	myReadFile.close();

	return 0;
}
