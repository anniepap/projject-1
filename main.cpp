#define N 3
#define OK_SUCCESS 1
#include <cstdio>

typedef unsigned int long uint32_t;

struct list_node {
	uint32_t neighbor[N]; //the ids of the neighbor nodes
	uint32_t edgeProperty[N]; //property for each edge
	size_t nextListNode; //
};

class Buffer {
	size_t size;
	size_t capacity;
	list_node* table;
public:
	Buffer(); //Buffer* createBuffer();
	~Buffer(); //OK_SUCCESS destroyBuffer(Buffer*);
	size_t allocNewNode();
	list_node* getListNode(size_t);
};

class NodeIndex {
	size_t size;
	size_t capacity;
	size_t* table;
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
