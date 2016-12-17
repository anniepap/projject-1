#ifndef __GRAPHPOSTORDERCURSOR_H__
#define __GRAPHPOSTORDERCURSOR_H__

#include "../Part1/Graph.h"
#include "../Part1/PairCursor.h"

#define ENDOFCOMPONENT -2

class Stack;
class Collection;

class GraphPostOrderCursor {		// Elegxthike
	Graph* graph;
	bool undirected;
	Stack* stack;
	HashSet* visited;
	Collection* random_nodes;
public: 
	GraphPostOrderCursor(Graph* graph, bool undirected=false); 
	~GraphPostOrderCursor();
	uint32_t Next();
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Stack {					// Elegxthike
	uint32_t size_of_stack;
	uint32_t* array;
	uint32_t size;
public: 
	Stack(uint32_t size_of_stack);
	~Stack();
	void Push(uint32_t element);
	uint32_t Pop();
	uint32_t Top();
	//bool find(uint32_t element);
	bool IsEmpty();
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Collection {					// Elegxthike
	uint32_t size_of_collection;
	uint32_t* array;
	uint32_t cur_pos;
public:
	Collection(const uint32_t size);
	~Collection();
	uint32_t Pop();	
};

#endif