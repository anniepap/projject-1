#ifndef __QUEUE_SET_H__
#define __QUEUE_SET_H__

#include "defines.h"
#include "HashQueue.h"
#include "HashSet.h"
#include "ArraySet.h"
#include "ArrayQueue.h"

class QueueSet {
	HashQueue queue;
	HashSet visited;
public:
	QueueSet(size_t capacity);

	void push(uint32_t id);
	uint32_t pop();

	bool empty();
	size_t getSize();
	bool getVisited(size_t index);
};

#endif
