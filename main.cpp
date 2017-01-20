/* PART 2 MAIN */

#include "Part2/StaticGraph.h"
#include "Part2/DynamicGraph.h"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	if (argc != 3) return -1;
	
	Graph* graph;
	ifstream myReadFile;	
	char graphType[10];
	char com;
	uint32_t from;
	uint32_t to;

	// Read Type
	myReadFile.open(argv[2]);
	if (!myReadFile.is_open())
		cerr<<"File can not open"<<endl;
	myReadFile>>graphType;
	myReadFile.close();

	if (strcmp(graphType,"STATIC")==0)
		graph = new StaticGraph();
	else
		graph = new DynamicGraph();

	myReadFile.open(argv[1]);
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			myReadFile >> from >> to;
			if (!myReadFile.good())
				break;
			graph->Graph::addEdge(from, to);
		}
	}
	myReadFile.close();
 	
	graph->init();

	// Read Type
	myReadFile.open(argv[2]);

	while(!myReadFile.eof()) {
		myReadFile>>com;
		if (com != 'F')
			myReadFile >> from >> to;
		if (com == 'A'){
			graph->addEdge(from, to);
		}
		if (com == 'Q'){
			graph->question(from, to);
		}
	}


/*
	// Check Type
	if (strcmp(graphType,"STATIC")==0) {
		SCC components(graph.SizeOfNodes(), graph);
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
					//cout << 1 /*graph.question(from, to)*/ /*<< endl;  // Psaksimo se olo to graph kai elegxos kathe fora eswterika sto grail
			}
		}
	}
	else if (strcmp(graphType,"DYNAMIC")==0) {
		CC cc(graph.SizeOfNodes(), &graph);

		while(!myReadFile.eof()) {
			myReadFile>>com;
			if (com != 'F')
				myReadFile >> from >> to;
			if (com == 'A'){
				graph.addEdge(from, to);
				cc.insertNewEdge(from, to); 
			}
			if (com == 'Q'){
				if (cc.isPossiblyReachable(from, to))
					cout << graph.question(from, to) << endl;	// prepei na doume poia sunartisi kaleitai edw
				else
					cout<<-1<<endl;		
			}
		}
	}
*/
 
	delete graph; 

	myReadFile.close();
	
	return 0;
}

