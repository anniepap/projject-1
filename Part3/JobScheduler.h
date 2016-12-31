#ifndef __JOBSCHEDULER_H__
#define __JOBSCHEDULER_H__

#include <pthread.h>
#include "Job.h"
#include "ListQueue.h"

#define SIZEOFTHREADPOOL 16
#define CAPACITYOFPRINTARRAY 1024

class JobScheduler
{
	int execution_threads;	 // number of execution threads
	pthread_t* tids; 	// execution threads
	ListQueue* q; 	// a queue that holds submitted jobs / tasks
	
	uint32_t print_array_capacity;
	int* print_array;
	uint32_t last_job;

	pthread_mutex_t q_mutex;
public:
	JobScheduler(int execution_threads);	//initialize_scheduler
	~JobScheduler();	//destroy_scheduler
	
	void submit_job(Job* j);
	void execute_all_jobs();
	void wait_all_tasks_finish(); //waits all submitted tasks to finish
	void print_all_return_values();

	pthread_mutex_t* QMutex();
	ListQueue* Q();
	uint32_t PrintArrayCapacity();
	void PrintArrayCapacity(uint32_t capacity);
	int* PrintArray();
	void PrintArray(int* new_array);
	uint32_t LastJob();
	void LastJob(uint32_t last_job);

};

#endif
