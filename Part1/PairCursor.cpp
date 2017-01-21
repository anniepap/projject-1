#include "PairCursor.h"

PairCursor::PairCursor(Pair* pair) : pair(pair) {
	hash = NODE_HASH;
}

PairCursor::PairCursor(Graph& graph, bool out) {
	pair = (out) ? &graph.getOut() : &graph.getIn();
	hash = NODE_HASH;
}

void PairCursor::init(uint32_t id) {
	node = &pair->getIndex()[id];
	for (hash = 0; hash < NODE_HASH; ++hash)
	{
		if (node->offset[hash] != NONE) {
			offset = node->offset[hash];
			size = node->size[hash];
			pos = 0;
			return;
		}
	}
}

bool PairCursor::next(uint32_t* id, uint32_t* vid) {
	if (hash == NODE_HASH) return false;
	*id = pair->buffer[offset].neighbor[pos];
	if (vid != NULL)
		*vid = pair->buffer[offset].edgeProperty[pos];
	pos++;

	if (pos != size) return true;
	if (pair->buffer[offset].nextListNode != NONE) {
		offset = pair->buffer[offset].nextListNode;
		size = LIST_NODE_CAPACITY;
		pos = 0;
	}
	else {
		while (++hash < NODE_HASH) {
			if (node->offset[hash] != NONE) {
				offset = node->offset[hash];
				size = node->size[hash];
				pos = 0;
				break;
			}
		}
	}
	return true;
}

