#define N 3
#define OK_SUCCESS 1
#include <cstdio>

typedef unsigned int long uint32_t;

/*
NodeIndex* createNodeIndex();
OK_SUCCESS insertNode(NodeIndex*, uint32_t nodeId,.. );
size_t getListHead( NodeIndex*, uint32_t nodeId );
OK_SUCCESS destroyNodeIndex( NodeIndex* );
*/

struct list_node {
	uint32_t neighbor[N]; //the ids of the neighbor nodes
	uint32_t edgeProperty[N]; //property for each edge
	size_t nextListNode; //
};

class Buffer {
	size_t size;
	size_t current;
	list_node* table;
public:
	Buffer(); //Buffer* createBuffer();
	~Buffer(); //OK_SUCCESS destroyBuffer(Buffer*);
	size_t allocNewNode();
	list_node* getListNode(size_t);
};

class NodeIndex {
	size_t size;
	size_t current;
	size_t* table;
public:
	NodeIndex(); //NodeIndex* createNodeIndex();
	~NodeIndex(); //OK_SUCCESS destroyNodeIndex(NodeIndex*);
	bool insertNode(NodeIndex*, uint32_t nodeId, ...);
	size_t getListHead( NodeIndex*, uint32_t nodeId );
};

int main(int argc, char const *argv[]) {
	uint32_t test = 0x00ffffff;
	printf("%lu\n", test);
	printf("%lu\n", sizeof(test));
	return 0;
}
