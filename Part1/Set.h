#ifndef __SET_H__
#define __SET_H__

#include "defines.h"

class Set {
public:
	virtual bool find(uint32_t id) = 0;
	virtual void insert(uint32_t id) = 0;
};

#endif
