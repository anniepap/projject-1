#include "../Part1/Graph.h"
#include "GrailIndex.h"
#include "CC.h"
#include "SCC.h"
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

/* 		Na dokimastei
	SCC scc(6);
	scc.estimateStronglyConnectedComponents(graph.getOut());
	ComponentCursor cursor;

	cursor.iterateStronglyConnectedComponentID(&scc);
		cout<<"GRIGORA"<<endl;
	Component* comp = cursor.GetCurrentConnectedComponent();
	cout << comp << endl;

	while ( cursor.next_StronglyConnectedComponentID() )
	{
		comp = cursor.GetCurrentConnectedComponent();
		cout << comp << endl;
	}
*/


	if (strcmp(graphType, "STATIC") == 0) {
		SCC components( graph.SizeOfNodes() );
		GrailIndex grail_index(&graph/*,&components*/);	

		myReadFile.open(argv[2]);
		if (myReadFile.is_open()) {
			while(!myReadFile.eof()) {
				myReadFile >> com;
				if (com != 'F')
					myReadFile >> from >> to;
				if (com == 'Q'){
					if ( grail_index.isReachableGrailIndex(from,to) == NO )
					{
						cout << -1 << endl;
						continue;
					}
					cout << graph.question(from, to) << endl;
				}
			}
		}
		myReadFile.close();
	}

	else if (strcmp(graphType, "DYNAMIC")) {
		CC cc( graph.SizeOfNodes(),& graph );

		myReadFile.open(argv[2]);
		if (myReadFile.is_open()) {
			while(!myReadFile.eof()) {
				myReadFile >> com;
				if (com != 'F')
					myReadFile >> from >> to;
				if ( com == 'A')
					cc.insertNewEdge( from, to ); 
					// graph indert()
				if (com == 'Q'){
					if ( cc.OverflowThreshhold() ){
						cc.rebuildIndexes();
					}
					if ( cc.findNodeConnectedComponentID(from) == cc.findNodeConnectedComponentID(to) ) {
						// Anazitisi  cout << graph.question(from, to) << endl;
					}
					else if ( cc.getUpdateIndex()->isConnected( from, to) ) {
						// Anazitisi  cout << graph.question(from, to) << endl;
						cc.UpdateMetric(true);
						continue;
					}
					cc.UpdateMetric();					
				}
			}
		}
		myReadFile.close();
	}
	
	//graph.test();


	delete[] gType;
	delete[] graphType;


	return 0;
}