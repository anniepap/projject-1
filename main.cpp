#define N 3
#define OK_SUCCESS 1
#include <cstdio>

typedef unsigned int long uint32_t;

class list_node {
	size_t size; //current size of capacity used (N is the capacity)
	//size_t capacity = N;
	uint32_t neighbor[N]; //the ids of the neighbor nodes //offset of NodeIndex line
	uint32_t edgeProperty[N]; //property for each edge
	size_t nextListNode; //0 means no overflow
};

class Buffer {
	size_t size; //current size of capacity used
	size_t capacity; //capacity of table
	list_node* table; //offset of Buffer line
public:
	Buffer(); //Buffer* createBuffer();
	~Buffer(); //OK_SUCCESS destroyBuffer(Buffer*);
	size_t allocNewNode();
	list_node* getListNode(size_t);
};

class NodeIndex {
	size_t size; //current size of capacity used
	size_t capacity; //capacity of table
	size_t* table; //offset of Buffer line
public:
	NodeIndex(); //NodeIndex* createNodeIndex();
	~NodeIndex(); //OK_SUCCESS destroyNodeIndex(NodeIndex*);
	bool insertNode(NodeIndex*, uint32_t nodeId, ...);
	size_t getListHead(NodeIndex*, uint32_t nodeId);
};

class Pair {
	Buffer buffer;
	NodeIndex index;
public:
	Pair();
	~Pair();
	createNode(uint32_t id);
	addEdge(uint32_t from, uint32_t to);
};

class Graph
{
	Pair in;
	Pair out;
public:
	Graph();
	~Graph();
	createNode(uint32_t id);
	addEdge(uint32_t from, uint32_t to);
	question(uint32_t from, uint32_t to);
};

int main(int argc, char const *argv[]) {
	uint32_t test = 0x00ffffff;
	printf("%lu\n", test);
	printf("%lu\n", sizeof(test));
	return 0;
}
