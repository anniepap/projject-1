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

		for (int i = 0; gType[i] != '\n'; ++i) {
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

	for (int i = 0; i < size; ++i) {
		graphType[i] = gType[i];
	}
	graphType[size] = '\0';

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
		cout<<"STATIC"<<endl;
		return 0;
		SCC components( graph.SizeOfNodes() );
		// hypergraph()
		GrailIndex grail_index(&hypergraph ,&components);	

		myReadFile.open(argv[2]);
		if (myReadFile.is_open()) {
			while(!myReadFile.eof()) {
				myReadFile >> com;
				if (com != 'F')
					myReadFile >> from >> to;
				if (com == 'Q'){
					GRAIL_ANSWER answer = grail_index.isReachableGrailIndex(from,to);
					if ( answer == NO )
						cout << -1 << endl;
					else if ( answer == YES )
						cout << 1/*components->estimateShortestPathStronglyConnectedComponents( graph, source_node, target_node) Prepei na ulopoihthei (tha mporouse na pernaei kai to Component gia grigori anazitisi)*/ << endl;  // An nai, anazitisi sto sto SCC pou anikoun ta 2 node
					else 
						cout << 1 /*graph.question(from, to)*/ << endl;  // Psaksimo se olo to graph kai elegxos kathe fora eswterika sto grail
				}
			}
		}
		myReadFile.close();
	}

	else if (strcmp(graphType, "DYNAMIC") == 0) {
		cout<<"DYNAMIC"<<endl;
		return 0;
		CC cc( graph.SizeOfNodes(), &graph );

		myReadFile.open(argv[2]);
		if (myReadFile.is_open()) {
			while(!myReadFile.eof()) {
				myReadFile >> com;
				if (com != 'F')
					myReadFile >> from >> to;
				if ( com == 'A'){
					graph.addEdge( from, to );
					cc.insertNewEdge( from, to ); 
				}
				if (com == 'Q'){
					if ( cc.isPossiblyReachable( from, to ) )
						// Anazitisi  cout << graph.question(from, to) << endl;		
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


/*
leipoun 
1) hypergraph
2) CC
3) Anazitisi sto idio component
4) Anazitisi se diaforetika component alla me elegxo kathe fora
*/ 