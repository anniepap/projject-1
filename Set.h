#ifndef __SET_H__
#define __SET_H__

#include "defines.h"

class Set {
public:
	virtual bool contains(uint32_t id) = 0;
	virtual void add(uint32_t id) = 0;
};

#endif
