
#include "../Part2/GrailIndex.h"
#include "../Part2/CC.h"
#include "../Part2/SCC.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

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

	int question()
	{
		return graph->question(from, to/*, version*/);	// Prepei na ftiaksoume tis klaseis STATIC kai DYNAMIC graph me moni sunartisi tin question pou tha perilamvanei ta grail ktlp
	}
};

int encode_question(void* question_arg)
{
	return ((question_arguments*) question_arg)->question();	
}

int main(int argc, char** argv) {
	if (argc != 3) return -1;

	Graph graph;
	ifstream myReadFile;
	char graphType[10];
	char com;
	char prevcom = 'A';
	uint32_t current_version = 0;
	uint32_t from;
	uint32_t to;

	myReadFile.open(argv[1]);
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			myReadFile >> from >> to;
			if (!myReadFile.good())
				break;
			graph.addEdge(from, to);
		}
	}
	myReadFile.close();
 	
	// Read Type
	myReadFile.open(argv[2]);
	if (!myReadFile.is_open())
		cerr<<"File can not open"<<endl;
	myReadFile>>graphType;

	JobScheduler job_scheduler(SIZEOFTHREADPOOL);
	uint32_t capacity = ARGARRAYCAPACITY;
	question_arguments** arg_array = new question_arguments*[capacity];
	uint32_t last_arg_array = 0;
	Job cur_job(0, encode_question ,NULL);
	uint32_t cur_id=0;

	// Check Type
	if (strcmp(graphType,"STATIC")==0) {
		SCC components(graph.SizeOfNodes(), graph);
		GrailIndex grail_index(&components);	

		while(!myReadFile.eof()) {
			myReadFile >> com;
			if (com != 'F')
				myReadFile >> from >> to;
			if (com == 'Q'){

				// Add a job to scheduler  -----
				if(last_arg_array>=capacity){
					capacity = 2*capacity;
					arg_array = (question_arguments**) realloc( arg_array, capacity*sizeof(question_arguments*));
				}

				arg_array[last_arg_array] = new question_arguments;
				arg_array[last_arg_array]->graph=&graph;
				arg_array[last_arg_array]->from=from;
				arg_array[last_arg_array]->to=to;
				arg_array[last_arg_array]->version=0;

				cur_job.Id(cur_id);
				cur_job.Arg((void*) arg_array[last_arg_array] );
				job_scheduler.submit_job(&cur_job);
				//  ----------
				cur_id++;
				last_arg_array++;
			}
			if (com=='F')
			{
				job_scheduler.execute_all_jobs();
				job_scheduler.wait_all_tasks_finish();
				job_scheduler.print_all_return_values();
				//job_scheduler.initialize(); mporei na min xreiastei

				for (int i=0; i<last_arg_array; i++)
				{
					delete arg_array[i];
				}
				last_arg_array = 0;
				cur_id = 0;
			}
		}
	}
	else if (strcmp(graphType,"DYNAMIC")==0) {
		CC cc(graph.SizeOfNodes(), &graph);

		while(!myReadFile.eof()) {
			myReadFile>>com;
			if (com != 'F')
				myReadFile >> from >> to;
			if (com == 'A'){
				// Kwdikas Annas ...
				if (prevcom == 'Q') {
					current_version += 1;
				}
				// Telos kwdikas Annies
				graph.addEdge(from, to);	// kainourgia add edge
				cc.insertNewEdge(from, to); // kainourgia insertNewEdge
			}
			if (com == 'Q'){

				// Add a job to scheduler  -----
				/*arg.graph=graph;
				arg.from=from;
				arg.to=to;
				arg.version=current_version;//version pou prepei;

				cur_job.Id(id);
				cur_job.Arg(arg);
				job_scheduler.submit_job(cur_job);*/
				//  ----------	
				cur_id++;
			}
			if (com=='F')
			{
				//job_scheduler.execute_all_jobs();
				//job_scheduler.wait_all_tasks_finish();
				//job_scheduler.print();
				//job_scheduler.initialize(); mporei na min xreiastei
				cur_id = 0;
			}
			prevcom = com;
		}
	}
	myReadFile.close();

	delete[] arg_array;

	return 0;
}

