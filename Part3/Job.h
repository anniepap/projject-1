#ifndef __JOB_H__
#define __JOB_H__


#include "../Part1/defines.h"

class Job
{
	uint32_t id;
	int (*func)(void*);
	void* arg;
public:
	Job(int id, int (*func)(void*) ,void* arg);

	int execute();

	void Id(uint32_t id);
	void Arg(void* arg);

	uint32_t Id();
};

#endif
