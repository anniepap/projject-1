
#include "../Part2/GrailIndex.h"
#include "../Part2/CC.h"
#include "../Part2/SCC.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "Job.h"
#include "JobScheduler.h"

using namespace std;

struct question_arguments
{
	Graph graph;
	uint32_t from;
	uint32_t to;
	uint32_t version;
};

void* encode_question(void* question_arg)
{
	struct question_arguments* arguments = (struct question_arguments*) question_arg;
	//arguments->graph.question(arguments->from, arguments->to, arguments->version);	// Prepei na ftiaksoume tis klaseis STATIC kai DYNAMIC graph me moni sunartisi tin question pou tha perilamvanei ta grail ktlp
	return NULL;
}

int main(int argc, char** argv) {
	if (argc != 3) return -1;
	
	Graph graph;
	ifstream myReadFile;
	char graphType[10];
	char com;
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

	//JobScheduler job_scheduler(SIZEOFTHREADPOOL);
	//struct question_arguments arg;
	//Job cur_job(0,&question_arguments,NULL);
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
				/*arg.graph=graph;
				arg.from=from;
				arg.to=to;
				arg.version=0;

				cur_job.Id(cur_id);
				cur_job.Arg(arg);
				job_scheduler.submit_job(cur_job);*/
				//  ----------
				//cur_id++;
			}
			if (com=='F')
			{
				return 0;
				//job_scheduler.execute_all_jobs();
				//job_scheduler.wait_all_tasks_finish();
				//job_scheduler.print();
				//job_scheduler.initialize(); mporei na min xreiastei
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
				// ...
				
				graph.addEdge(from, to);	// kainourgia add edge
				cc.insertNewEdge(from, to); // kainourgia insertNewEdge
			}
			if (com == 'Q'){

				// Kwdikas Annas ....
				// ...

				// Add a job to scheduler  -----
				/*arg.graph=graph;
				arg.from=from;
				arg.to=to;
				arg.version=//version pou prepei;

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
		}
	}

	myReadFile.close();

	return 0;
}

