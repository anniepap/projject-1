#ifndef __QUEUESET_H__
#define __QUEUESET_H__

#include "defines.h"
#include "HashSet.h"

class QueueSet {
protected:
	size_t capacity;
	size_t size;
	HashSet visited;
public:
	QueueSet(size_t capacity);

	virtual void push(uint32_t id) = 0;
	virtual uint32_t pop() = 0;

	bool empty();
	size_t getSize();
	bool getVisited(size_t index);
};

#endif
