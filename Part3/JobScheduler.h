#ifndef __JOBSCHEDULER_H__
#define __JOBSCHEDULER_H__

#include <pthread.h>
#include "Job.h"

#define SIZEOFTHREADPOOL 10

class JobScheduler
{
	int execution_threads;	 // number of execution threads
	pthread_t* tids; 	// execution threads
	//ListQueue* q; 	// a queue that holds submitted jobs / tasks
	int* printlist;
	pthread_mutex_t q_mutex;
public:
	JobScheduler(int execution_threads);	//initialize_scheduler
	~JobScheduler();	//destroy_scheduler
	
	void submit_job(Job* j);
	void execute_all_jobs();
	void wait_all_tasks_finish(); //waits all submitted tasks to finish
};

#endif
