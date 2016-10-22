#include "NodeIndex.h"

NodeIndex::NodeIndex() {
	capacity = NODE_INDEX_CAPACITY;
	table = (Node*) malloc(capacity*sizeof(Node));
	printf("NodeIndex::NodeIndex\n");
}

NodeIndex::~NodeIndex() {
	free(table);
	printf("NodeIndex::~NodeIndex\n");
}

Node& operator[](size_t index) {
	return table[index];
}

bool NodeIndex::insertNode(uint32_t nodeId) {
	printf("NodeIndex::insertNode\n");
	return true;
}

size_t NodeIndex::getListHead(uint32_t nodeId) {
	printf("NodeIndex::getListHead\n");
	return 0;
}

size_t NodeIndex::findEdge(uint32_t nodeId) {
	printf("NodeIndex::findEdge\n");
	return 0;
}
