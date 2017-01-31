
#include "../Part2/StaticGraph.h"
#include "../Part2/DynamicGraph.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <ctime>

#include "Job.h"
#include "JobScheduler.h"

#define ARGARRAYCAPACITY 1024

using namespace std;

struct question_arguments
{
	Graph* graph;
	uint32_t from;
	uint32_t to;
	uint32_t version;

	long int question()
	{
		return graph->question(from, to, version);	
	}
};

long int encode_question(void* question_arg)
{
	return ((question_arguments*) question_arg)->question();	
}

int main(int argc, char** argv) {
	if (argc != 3) return -1;
	
	srand((unsigned int)time(NULL));
	Graph* graph;
	ifstream firstFile(argv[1]);
	ifstream secondFile(argv[2]);
	char graphType[10];
	char com;
	uint32_t from;
	uint32_t to;
	char prevcom = 'A';
	uint32_t current_version = 0;

	if (!firstFile.is_open() || !secondFile.is_open()){
		cerr<<"File can not open"<<endl;
		return 1;
	}

	// Read Type
	secondFile>>graphType;
	if (strcmp(graphType,"STATIC")==0){
		graph = new StaticGraph();
	}
	else{
		graph = new DynamicGraph();
	}

	// Read Graph
	if (firstFile.is_open()) {
		while (!firstFile.eof()) {
			firstFile >> from >> to;
			if (!firstFile.good())
				break;
			graph->Graph::addEdge(from, to);
		}
	}
	firstFile.close();
 	
	graph->init();

	// Initialize Scheduler
	JobScheduler job_scheduler(SIZEOFTHREADPOOL);
	uint32_t capacity = ARGARRAYCAPACITY;
	question_arguments** arg_array = (question_arguments**) malloc( capacity * sizeof(question_arguments) );

	// Initialize Job
	Job cur_job(encode_question);
	uint32_t cur_id=0;

	// Read Type
	while(!secondFile.eof()) {
		secondFile >> com;
		if (com != 'F') {
			secondFile >> from >> to;

			if (com == 'A'){
				if (prevcom == 'Q') {
					current_version += 1;
				}
				graph->addEdge(from, to, current_version);	// kainourgia add edge
			}
			else if (com == 'Q') {
				// Add a job to scheduler  -----
				if (cur_id>=capacity) {
					capacity <<= 1;
					arg_array = (question_arguments**) realloc( arg_array, capacity*sizeof(question_arguments*));
				}

				arg_array[cur_id] = new question_arguments;
				arg_array[cur_id]->graph=graph;
				arg_array[cur_id]->from=from;
				arg_array[cur_id]->to=to;
				arg_array[cur_id]->version=current_version;

				cur_job.Id(cur_id);
				cur_job.Arg((void*) arg_array[cur_id]);
				job_scheduler.submit_job(&cur_job);
				//  ----------
				cur_id++;
			}
		}
		else {
			job_scheduler.execute_all_jobs(cur_id);
			job_scheduler.wait_all_tasks_finish();
			job_scheduler.print_all_return_values();
			//job_scheduler.initialize(); mporei na min xreiastei

			for (uint32_t i=0; i<cur_id; i++)
			{
				delete arg_array[i];
			}
			cur_id = 0;
		}
		prevcom = com;
	}

	secondFile.close();

	free(arg_array);
	delete graph;

	return 0;
}

