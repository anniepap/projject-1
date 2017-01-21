
#include <iostream>
#include "JobScheduler.h"

using namespace std;

void* ThreadWork(void* arg){
	JobScheduler* job_scheduler = (JobScheduler*)arg;
	Job cur_job(NULL);//change maybe
	int ret;
	uint32_t capacity;
	while(1)
	{
		pthread_mutex_lock( job_scheduler->QMutex() ) ;
			// termination condition
			if (job_scheduler->Q()->empty())
			{
				pthread_mutex_unlock( job_scheduler->QMutex() );
				return NULL;
			}
			
			cur_job = job_scheduler->Q()->pop();

			// Check if realloc need
			if (cur_job.Id()>=job_scheduler->PrintArrayCapacity())
			{
				capacity= job_scheduler->PrintArrayCapacity();
				while(cur_job.Id()>=capacity) {
					capacity = 2*capacity;
				};

				job_scheduler->PrintArrayCapacity(capacity);
				job_scheduler->PrintArray( (int*)realloc( job_scheduler->PrintArray(), job_scheduler->PrintArrayCapacity()*sizeof(int) ) );	
			}

			// Set last position
			if (cur_job.Id()>=job_scheduler->LastJob())
			{
				job_scheduler->LastJob( cur_job.Id()+1 );
			}
		pthread_mutex_unlock( job_scheduler->QMutex() );
			
		ret=cur_job.execute(); 	
		pthread_mutex_lock( job_scheduler->QMutex() ) ;			// Den mou aresei alla den ginetai alliws afou kanoume realloc - trwei 2 sec
				job_scheduler->PrintArray()[cur_job.Id()] = ret;
		pthread_mutex_unlock( job_scheduler->QMutex() );			
	}
	return NULL;
}

JobScheduler::JobScheduler(int execution_threads):execution_threads(execution_threads), print_array_capacity(CAPACITYOFPRINTARRAY),last_job(0)
{
	tids= new pthread_t[execution_threads];
	q = new ListQueue();
	print_array = new int[print_array_capacity];
	pthread_mutex_init( &q_mutex , NULL ) ;

}

JobScheduler::~JobScheduler()
{
	pthread_mutex_destroy( &q_mutex ) ;
	delete q;
	delete[] tids;
	delete[] print_array;
}

void JobScheduler::submit_job(Job* j)
{
	q->push(j);
}

void JobScheduler::execute_all_jobs( )
{
	for(int i=0; i<execution_threads; i++ )
	{
		pthread_create(tids+i , NULL , ThreadWork , this );
	}
}

void JobScheduler::wait_all_tasks_finish()
{
	for(int i=0;i<execution_threads;i++)
		pthread_join(tids[i], NULL);
}

void JobScheduler::print_all_return_values()
{
	for (int i=0; i<last_job; i++)
	{
		cout<< print_array[i]<< endl;
	}
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

uint32_t JobScheduler::PrintArrayCapacity()
{
	return print_array_capacity;
}

void JobScheduler::PrintArrayCapacity(uint32_t capacity)
{
	print_array_capacity = capacity;
}

int* JobScheduler::PrintArray()
{
	return print_array;
}

void JobScheduler::PrintArray(int* new_array)
{
	print_array = new_array;
}

uint32_t JobScheduler::LastJob()
{
	return last_job;
}

void JobScheduler::LastJob(uint32_t last_job)
{
	this->last_job = last_job;
}
