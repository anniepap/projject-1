#ifndef __JOB_H__
#define __JOB_H__


#include "../Part1/defines.h"

class Job
{
	uint32_t id;
	long int (*func)(void*);
	void* arg;
public:
	Job(long int (*func)(void*));

	long int execute();

	void Id(uint32_t id);
	void Arg(void* arg);

	uint32_t Id();
};

#endif
