
#include "Job.h"

Job::Job(int (*func)(void*)) : func(func) {}

int Job::execute()
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

// Auto tha mpei stin main
/*
struct question_arguments
{
	Graph graph;
	unint32_t from;
	unint32_t to;
	unint32_t version;
}

void* encode_question(void* question_arg)
{
	struct question_arguments* arguments = (struct question_arguments*) question_arg;
	arguments->graph.question(arguments->from, arguments->to, arguments->version);
	return NULL;
}


// Stin main h logiki einai
JobScheduler job_scheduler(SIZEOFTHREADPOOL);
// Stin main to Jop tha arxikopoieitai
struct question_arguments arg;
arg.graph=graph;
arg.from=from;
arg.to=to;
arg.version=//version pou prepei;

Job cur_job(id,&question_arguments,(void*)&arg);
job_scheduler.submit_job(cur_job);

*/