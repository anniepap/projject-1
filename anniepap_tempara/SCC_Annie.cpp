#include "SCC_Annie.h"

void SCC::SCC(uint32_t N) {
/*	components_count = 0;
	rows = (size_t) ceil(size/COLUMNS);
	components = (Component**) calloc(rows, sizeof(Component*)); */

	components = NULL;
	size = 0;

	id_belongs_to_component = new uint32_t[N];
	for (uint32_t i = 0; i < N; ++i)
	{
		id_belongs_to_component[i] = NONE;
	}
}

/*
int findNodeStronglyConnectedComponentID(uint32_t nodeId) {

}
OK_SUCCESS iterateStronglyConnectedComponentID(ComponentCursor* cursor) {

}
bool next_StronglyConnectedComponentID(ComponentCursor* cursor) {

}
int estimateShortestPathStronglyConnectedComponents(NodeIndex* graph, uint32_t source_node, uint32_t target_node) {

}
*/