#include "GrailIndex.h"
#include "CC.h"
#include "SCC.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	if (argc != 3) return -1;
	
	Graph graph;
	ifstream myReadFile;
	string graphType;
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
 	
	// Read Type
	myReadFile.open(argv[2]);
	if (!myReadFile.is_open())
		cerr<<"File can not open"<<endl;

	getline(myReadFile, graphType);
	
	cout<<"|"<<graphType<<"|"<<endl;

	// Check Type
	if (graphType == "STATIC") {
		SCC components( graph.SizeOfNodes(), graph );
		GrailIndex grail_index(&components);	

		while(!myReadFile.eof()) {
			myReadFile >> com;
			if (com != 'F')
				myReadFile >> from >> to;
			if (com == 'Q'){
				GRAIL_ANSWER answer = grail_index.isReachableGrailIndex(from,to);
				if ( answer == NO )
					cout << -1 << endl;
				else if ( answer == YES )
					cout << components.estimateShortestPathStronglyConnectedComponents( graph, from, to) << endl;  
				else 
					cout << graph.question(from, to) << endl;	
					//cout << 1 /*graph.question(from, to)*/ << endl;  // Psaksimo se olo to graph kai elegxos kathe fora eswterika sto grail
			}
		}
		myReadFile.close();
	}

	else if (graphType == "DYNAMIC") {
		CC cc( graph.SizeOfNodes(), &graph );

		myReadFile.open(argv[2]);
		if (myReadFile.is_open()) {
			while(!myReadFile.eof()) {
				myReadFile >> com;
				cout<<com<<endl;
				return 0;
				if (com != 'F')
					myReadFile >> from >> to;
				if (com == 'A'){
					graph.addEdge( from, to );
					cc.insertNewEdge( from, to ); 
				}
				if (com == 'Q'){
					if ( cc.isPossiblyReachable( from, to ) )
						cout << graph.question(from, to) << endl;	// prepei na doume poia sunartisi kaleitai edw
					else
						cout<<-1<<endl;		
				}
			}
		}
		myReadFile.close();
	}

	return 0;
}
