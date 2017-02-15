#include "MultiDynamicGraph.h"


MultiDynamicGraph::MultiDynamicGraph()
{
	pthread_mutex_init(&mutex, NULL);
}

MultiDynamicGraph::~MultiDynamicGraph()
{
	pthread_mutex_destroy(&mutex);
}

long MultiDynamicGraph::question(uint32_t from, uint32_t to,uint32_t version) {
	bool flag;

	pthread_mutex_lock( &mutex );
	flag = cc->isPossiblyReachable(from, to);
	pthread_mutex_unlock( &mutex );
	
	return (flag) ? Graph::question(from, to,version) : -1;
}
