#ifndef __MULTI_DYNAMIC_GRAPH_H__
#define __MULTI_DYNAMIC_GRAPH_H__

#include <pthread.h>
#include "../Part2/DynamicGraph.h"

class MultiDynamicGraph : public DynamicGraph {
	pthread_mutex_t mutex;
public:
	MultiDynamicGraph();
	~MultiDynamicGraph();
	long question(uint32_t from, uint32_t to, uint32_t version);
};

#endif
