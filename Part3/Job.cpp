
#include "Job.h"

Job::Job(long int (*func)(void*)) : func(func) {}

long int Job::execute()
{
	return (*func)(arg);
}

void Job::Id(uint32_t id)
{
	this->id=id;
}

void Job::Arg(void* arg)
{
	this->arg=arg;
}

uint32_t Job::Id()
{
	return id;
}

