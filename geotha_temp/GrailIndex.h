#ifndef __GRAILINDEX_H__
#define __GRAILINDEX_H__

#include "../Part 1/defines.h"
#include "../Part 1/Graph.h"

#define NUMBEROFLABELS 1
enum GRAIL_ANSWER  {NO=0, MAYBE=1, YES=2};		

class GrailIndexNode;
class Stack;

class GrailIndex {
	const uint32_t SizeOfIndex;
	GrailIndexNode** IndexTables;

	unsigned int calc_min_rank(const int curr_label,int rank/*, out_edges, number_of_edges*/); // elipes.... prepei na allaksoun ta 2 teleuataia
public:
	GrailIndex(Graph* graph/*, SCC* components pros to parwn den xreiazetai*/);  // to Graph eixe NodeIndex
	~GrailIndex(); 
	GRAIL_ANSWER isReachableGrailIndex(uint32_t source_node,uint32_t target_node);
};

class GrailIndexNode {
	int min_rank;
	int rank;
public:
	set(int min_rank, int rank);
	bool isSubSet(GrailIndexNode& Y);
	int MinRank();
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class GraphPostOrderCursor {
	NodeIndex* graph;
	Stack* stack;
	HashSet* visited;
public: 
	GraphPostOrderCursor(Graph* graph);  // Stin ekfwnisi thelei orisma Index
	~GraphPostOrderCursor();
	uint32_t Next();
};

class Stack {
	uint32_t size_of_stack;
	uint32_t* array;
	uint32_t size;
public: 
	Stack(uint32_t size_of_stack);
	~Stack();
	void Push(uint32_t element);
	uint32_t Pop();
	uint32_t Top();
	bool find(uint32_t element);
	bool IsEmpty();
};

#endif