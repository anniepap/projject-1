#ifndef __NODEINDEX_H__
#define __NODEINDEX_H__

#include "defines.h"

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

#endif
