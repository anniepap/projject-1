#include <iostream>


#include "../Part3/Job.h"


using namespace std;

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
	arguments->graph.question(arguments->from, arguments->to, arguments->version);	// Prepei na ftiaksoume tis klaseis STATIC kai DYNAMIC graph me moni sunartisi tin question pou tha perilamvanei ta grail ktlp
	return NULL;
}

main(int argc, char** argv){

	struct question_arguments arg;
	arg.graph=graph;
	arg.from=from;
	arg.to=to;
	arg.version=0;

	Job jb(7,&encode_question,)
	

}