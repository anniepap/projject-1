#ifndef __JOB_H__
#define __JOB_H__


#include "../Part1/defines.h"

class Job
{
	uint32_t id;
	void* (*func)(void*);
	void* arg;
public:
	Job(int id, void* (*func)(void*),void* arg);
	void execute();

	void Id(uint32_t id);
	void Arg(void* arg);
};

#endif
