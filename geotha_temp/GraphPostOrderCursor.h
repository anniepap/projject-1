#ifndef __GRAPHPOSTORDERCURSOR_H__
#define __GRAPHPOSTORDERCURSOR_H__

#include "../Part1/Graph.h"
#include "../Part1/PairCursor.h"
#include "HashStack.h"

#define OK_SUCCESS 0
#define ENDOFCURSOR 1
#define ENDOFCOMPONENT 2

class Stack;
class Collection;

class GraphPostOrderCursor {		// Elegxthike
	Graph* graph;
	bool undirected;
	HashStack* stack;
	HashSet* visited;
	Collection* random_nodes;
public: 
	GraphPostOrderCursor(Graph* graph, bool undirected=false); 
	~GraphPostOrderCursor();
	short next(uint32_t* id);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Stack {					// Elegxthike
	uint32_t size_of_stack;
	uint32_t* array;
	uint32_t size;
public: 
	Stack(uint32_t size_of_stack);
	~Stack();
	void push(uint32_t element);
	uint32_t pop();
	uint32_t top_();
	//bool find(uint32_t element);
	bool empty();
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

class Dokimi {					// Elegxthike
	uint32_t size_of_collection;
	uint32_t* array;
	uint32_t cur_pos;
public:
	Dokimi(const uint32_t size);
	~Dokimi();
	uint32_t Pop();	
};



#endif
