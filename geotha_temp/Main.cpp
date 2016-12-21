#include <iostream>
#include "../Part1/Graph.h"
#include <fstream>
#include "GraphPostOrderCursor.h"


using namespace std;

main(int argc, char** argv){


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


HashStack h(2000);
for (int i=0;i<2000;i++)
{
	h.push(i);
}
for (int i=0;i<2000;i++)
{
	cout<<h.top_()<<" ";
	cout<<h.pop()<<endl;
}



GraphPostOrderCursor temp(&graph,true);
	int flag;
	uint32_t cur;
	while ((flag=temp.next(&cur))!=ENDOFCURSOR){
		if (flag==ENDOFCOMPONENT){
			//cout<<endl;
			continue;
		}
		//cout<<cur<<endl;
	}

}