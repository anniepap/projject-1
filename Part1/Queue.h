#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <cstdlib>

class Queue {
protected:
	size_t size_;
public:
	Queue(void);

	bool empty(void);
	size_t size(void);
};

#endif
