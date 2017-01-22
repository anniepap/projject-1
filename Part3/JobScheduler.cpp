
#include <iostream>
#include "JobScheduler.h"

using namespace std;

void* ThreadWork(void* arg){
	JobScheduler* job_scheduler = (JobScheduler*) arg;
	Job cur_job(NULL);//change maybe
	int ret;
	while (1)
	{
		pthread_mutex_lock( job_scheduler->QMutex() );
			// termination condition
			if (job_scheduler->Q()->empty())
			{
				pthread_mutex_unlock( job_scheduler->QMutex() );
				return NULL;
			}
			
			cur_job = job_scheduler->Q()->pop();

			// Check if realloc need
			job_scheduler->resize(cur_job.Id());

			// Set last position
			if (cur_job.Id()>=job_scheduler->LastJob())
			{
				job_scheduler->LastJob( cur_job.Id()+1 );
			}
		pthread_mutex_unlock( job_scheduler->QMutex() );
			
		ret=cur_job.execute(); 	
		pthread_mutex_lock( job_scheduler->QMutex() );			// Den mou aresei alla den ginetai alliws afou kanoume realloc - trwei 2 sec
			job_scheduler->PrintArray()[cur_job.Id()] = ret;
		pthread_mutex_unlock( job_scheduler->QMutex() );
	}
	return NULL;
}

JobScheduler::JobScheduler(int execution_threads) : execution_threads(execution_threads), print_array_capacity(CAPACITYOFPRINTARRAY), last_job(0)
{
	tids = new pthread_t[execution_threads];
	q = new ListQueue();
	print_array = (long*) malloc(print_array_capacity*sizeof(long));
	pthread_mutex_init(&q_mutex, NULL);
}

JobScheduler::~JobScheduler()
{
	pthread_mutex_destroy(&q_mutex);
	delete q;
	delete[] tids;
	free(print_array);
}

void JobScheduler::submit_job(Job* j)
{
	q->push(j);
}

void JobScheduler::execute_all_jobs()
{
	for (int i=0; i<execution_threads; i++)
		pthread_create(tids+i, NULL, ThreadWork, this);
}

void JobScheduler::wait_all_tasks_finish()
{
	for (int i=0; i<execution_threads; i++)
		pthread_join(tids[i], NULL);
}

void JobScheduler::print_all_return_values()
{
	for (int i=0; i<last_job; i++)
		cout << print_array[i]<< endl;
	last_job = 0;
}

pthread_mutex_t* JobScheduler::QMutex()
{
	return &q_mutex;
}

ListQueue* JobScheduler::Q()
{
	return q;
}

long* JobScheduler::PrintArray()
{
	return print_array;
}

void JobScheduler::resize(uint32_t cur_id)
{
	if (cur_id >= print_array_capacity)
	{
		while (cur_id >= print_array_capacity)
			print_array_capacity <<= 1;

		print_array = (long*) realloc(print_array, sizeof(long)*print_array_capacity);
	}
}

uint32_t JobScheduler::LastJob()
{
	return last_job;
}

void JobScheduler::LastJob(uint32_t last_job)
{
	this->last_job = last_job;
}
