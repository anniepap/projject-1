#include <iostream>
#include "SCC.h"
#include "HashStack.h"
#include "StaticGraph.h"

using namespace std;

Component::Component() {
	included_nodes_count = 0;
	included_node_ids = NULL;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void ComponentCursor::iterateStronglyConnectedComponentID(SCC* components) {
	scc = components;
	index = 0;
}

bool ComponentCursor::next_StronglyConnectedComponentID() {
	if ( index == scc->ComponentsCount() - 1 ){
		return false;
	}
	index++;
	return true;
}

Component* ComponentCursor::GetCurrentConnectedComponent(){
	return scc->getComponents()[index];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SCC::SCC(StaticGraph& graph) : graph(graph) {
	capacity = graph.SizeOfNodes();
	components_count = 0;
	components = NULL;
	id_belongs_to_component = (uint32_t*) malloc(sizeof(uint32_t)*capacity);
	
	estimateStronglyConnectedComponents(graph.getOut());
	CreateHyperGraph(graph.getOut());
}

uint32_t SCC::ComponentsCount() {
	return components_count;
}

Component** SCC::getComponents() {
	return components;
}

Graph& SCC::getHyperGraph() {
	return hyper_graph;
}

void SCC::increaseComponents() {
	components_count++;
	components = (Component**) realloc(components, sizeof(Component*)*components_count);
	components[components_count - 1] = new Component();
}

void SCC::addNodeToComponent(uint32_t nodeId) {
	Component* c = components[components_count - 1];
	c->included_nodes_count++;
	c->included_node_ids = (uint32_t*) realloc(c->included_node_ids, sizeof(uint32_t)*c->included_nodes_count);
	c->included_node_ids[c->included_nodes_count - 1] = nodeId;

	id_belongs_to_component[nodeId] = components_count - 1;
}

void SCC::CreateHyperGraph(Pair& pair){
	PairCursor pc(&pair);
	uint32_t to;
	uint32_t comp_to;
	for (uint32_t i = 0; i < components_count; i++) {
		for (uint32_t j=0; j < components[i]->included_nodes_count; j++){
			pc.init(components[i]->included_node_ids[j]);
			while (pc.next(&to)){
				if ((comp_to=findNodeStronglyConnectedComponentID(to)) != i){
					hyper_graph.addEdge(i, comp_to);
				}
			}
		}
	}
}

void SCC::print() {
	for (uint32_t i = 0; i < components_count; ++i) {
		cout << "component:";
		for (uint32_t j = 0; j < components[i]->included_nodes_count; ++j)
			cout << ' ' << components[i]->included_node_ids[j];
		cout << endl;
	}

	for (uint32_t i = 0; i < capacity; ++i)
		cout << i << " -> " << id_belongs_to_component[i] << endl;
}

SCC::~SCC() {
	destroyStronglyConnectedComponents();
}

void SCC::destroyStronglyConnectedComponents() {
	for (uint32_t i = 0; i < components_count; ++i) {
		free(components[i]->included_node_ids);
		delete components[i];
	}
	free(components);
	free(id_belongs_to_component);
	components_count = 0;
}

uint32_t SCC::findNodeStronglyConnectedComponentID(uint32_t nodeId) {
	return id_belongs_to_component[nodeId];
}

long SCC::estimateShortestPathStronglyConnectedComponents(uint32_t source_node, uint32_t target_node) {
	uint32_t source_scc_id = findNodeStronglyConnectedComponentID(source_node);
	uint32_t target_scc_id = findNodeStronglyConnectedComponentID(target_node);

	if (source_scc_id != target_scc_id)
		return -1;
	else
		return graph.question(source_node, target_node, this, source_scc_id);
}

void SCC::estimateStronglyConnectedComponents(Pair& pair) {
	uint32_t index = 1;

	TarNode* table = new TarNode[capacity];
	for (size_t i = 0; i < capacity; ++i) {
		table[i].index = 0;
		table[i].lowlink = 0;
		table[i].onStack = false;
		table[i].pc = NULL;
		table[i].caller = NULL;
	}

	HashStack tarjanStack(capacity);

	for (size_t id = 0; id < capacity; ++id) {
		if (table[id].index == 0) { // Simulate the dfs search that recursion is doing
			TarNode& u = table[id];
			u.index = index;
			u.lowlink = index;
			index++;
			u.pc = new PairCursor(&pair);
			u.pc->init(id);
			tarjanStack.push(id);
			u.caller = NULL;
			u.onStack = true;
			TarNode* last = &u;
			while (true) {
				uint32_t wid;
				if (last->pc->next(&wid)) {
					TarNode& w = table[wid];
					if (w.index == 0) {
						w.index = index;
						w.lowlink = index;
						index++;
						w.pc = new PairCursor(&pair);
						w.pc->init(wid);
						tarjanStack.push(wid);
						w.caller = last;
						w.onStack = true;
						last = &w;
					}
					else if (w.onStack) {
						if (w.index < last->lowlink)
							last->lowlink = w.index;
					}
				}
				else {
					if (last->lowlink == last->index) {
						uint32_t tid;
						TarNode* top;

						increaseComponents();
						do {
							tid = tarjanStack.pop();
							top = &table[tid];
							top->onStack = false;
							addNodeToComponent(tid);
						} while (top != last);
					}

					if (last->caller == NULL) break;
					
					TarNode* newLast = last->caller;
					if (last->lowlink < newLast->lowlink)
						newLast->lowlink = last->lowlink;
					last = newLast;
				}
			}
		}
	}

	for (size_t i = 0; i < capacity; ++i) {
		delete table[i].pc;
	}
	delete[] table;
}
