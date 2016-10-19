#include "NodeIndex.h"

NodeIndex::NodeIndex() {
	size = 0;
	capacity = NODE_INDEX_CAPACITY;
	table = (size_t*) malloc(capacity*sizeof(size_t));
	printf("NodeIndex::NodeIndex\n");
}

NodeIndex::~NodeIndex() {
	free(table);
	printf("NodeIndex::~NodeIndex\n");
}

bool NodeIndex::insertNode(NodeIndex*, uint32_t nodeId, ...) {
	printf("NodeIndex::insertNode\n");
	return true;
}

size_t NodeIndex::getListHead(NodeIndex*, uint32_t nodeId) {
	printf("NodeIndex::getListHead\n");
	return 0;
}
