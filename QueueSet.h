#ifndef __QUEUE_SET_H__
#define __QUEUE_SET_H__

#include "HashQueue.h"
#include "HashSet.h"

class QueueSet {
	HashQueue queue;
	HashSet set;
public:
	QueueSet(size_t capacity);

	void push(uint32_t id);
	uint32_t pop(void);
	bool empty(void);
	size_t size(void);
	bool visited(size_t index);
};

#endif
