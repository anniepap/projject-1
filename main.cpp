#include "Graph.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(void)
{
	Graph graph;
	ifstream myReadFile;
	char com;
	uint32_t from;
	uint32_t to;

	myReadFile.open("datasets/small/smallGraph.txt");
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			myReadFile >> from >> to;
			if (!myReadFile.good())
				break;
			graph.addEdge(from, to);
		}
	}
	myReadFile.close();

	myReadFile.open("datasets/small/smallWorkload_FINAL.txt");
	if (myReadFile.is_open()) {
		while(!myReadFile.eof()) {
			myReadFile >> com;
			if (com != 'F')
				myReadFile >> from >> to;
			if (com == 'A')
				graph.addEdge(from, to);
			if (com == 'Q')
				cout << graph.question(from, to) << endl;
		}
	}
	myReadFile.close();

	return 0;
}
