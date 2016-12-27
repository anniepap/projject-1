
#include "JobScheduler.h"

void* ThreadWork(void* arg){
	JobScheduler* job_scheduler = (JobScheduler*)arg;
/*	Job cur_job;
	int res;
	while(1)
	{
		pthread_mutex_lock( &(job_scheduler->q_mutex) ) ;
			if (job_scheduler->q.IsEmpty())
			{
				pthread_mutex_unlock( &(job_scheduler->queue_mutex) );
				return NULL;
			}
			
			cur_job=job_scheduler->q.pop();
		pthread_mutex_unlock( &(job_scheduler->queue_mutex) );

		printlist[cur_job.Id()]=cur_job.execute();
	}*/
	return NULL;
}

JobScheduler::JobScheduler(int execution_threads):execution_threads(execution_threads)
{
	//q	initialize
	tids= new pthread_t[execution_threads];
//	printlist
	pthread_mutex_init( &q_mutex , NULL ) ;

}

JobScheduler::~JobScheduler()
{
	pthread_mutex_destroy( &q_mutex ) ;
	//q	delete if new exists
	delete[] tids;
	//printlist
}

void JobScheduler::submit_job(Job* j)
{
	// q.push(j);
	// auksise kai to count tis ouras
}

void JobScheduler::execute_all_jobs( )
{
	for(int i=0; i<execution_threads; i++ )
	{
		pthread_create(tids+i , NULL , ThreadWork , NULL );
	}
}

void JobScheduler::wait_all_tasks_finish()
{
	for(int i=0;i<execution_threads;i++)
		pthread_join(tids[i], NULL);
}

