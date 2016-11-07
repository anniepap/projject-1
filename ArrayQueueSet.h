#ifndef __ARRAY_QUEUESET_H__
#define __ARRAY_QUEUESET_H__

#include "QueueSet.h"

class ArrayQueueSet : public QueueSet {
	size_t head;
	size_t back;
	uint32_t* array;
public:
	ArrayQueueSet(size_t capacity);
	~ArrayQueueSet();

	bool full();
	uint32_t pop(void);
	void push(uint32_t id);
};

#endif
