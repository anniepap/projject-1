#include "Graph.h"
#include "QueueSet.h"

void Graph::insertNode(uint32_t id) {
	out.insertNode(id);
	in.insertNode(id);
}

void Graph::addEdge(uint32_t from, uint32_t to) {
	out.addEdge(from, to);
	in.addEdge(to, from);
}

void Graph::question(uint32_t from, uint32_t to) {
	if (from == to) {
		printf("0\n");
		return;
	}

	ListQueueSet q1;
	ListQueueSet q2;
	ListQueueSet visited;
	q1.push(from);
	size_t lvl = 1;
	
	while (!q1.empty()) {
		while (!q1.empty()) {
			uint32_t i = q1.pop();
			visited.push(i);
			
			Node& node = out.index[i];
			size_t size = node.size;
			size_t offset = node.offset;
			while (offset != NONE)
			{
				list_node& bucket = out.buffer[offset];
				for (size_t i = 0; i < size; ++i) {
					uint32_t j = bucket.neighbor[i];
					if (j == to) {
						printf("%u\n", lvl);
						return;
					}
					if (!visited.find(j))
						q2.push(j);
				}
				offset = bucket.nextListNode;
				size = LIST_NODE_CAPACITY;
			}
		}
		while (!q2.empty()) {
			q1.push(q2.pop());
		}
		lvl++;
	}

	printf("-1\n");
}

void Graph::print(void) {
	printf("OUT EDGES\n");
	out.print();
	printf("IN EDGES\n");
	in.print();
}

/////////////////////////////////////////////////

void Pair::insertNode(uint32_t id) {
	index.insertNode(id);
}

void Pair::addEdge(uint32_t from, uint32_t to) {
	index.insertNode(from);
	index.insertNode(to);

	Node& node = index[from];
	if (buffer.find(node.offset, to, node.size) == true) return;
	if (node.size == LIST_NODE_CAPACITY) {
		node.offset = buffer.allocNewNode(node.offset);
		node.size = 0;
	}

	buffer[node.offset].neighbor[node.size] = to;
	node.size++;
}

void Pair::print(void) {
	for (uint32_t i = 0; i < index.getCapacity(); ++i)
	{
		printf("NODE %lu\n", i);
		Node& node = index[i];
		size_t size = node.size;
		size_t offset = node.offset;
		while (offset != NONE)
		{
			list_node& bucket = buffer[offset];
			printf("\tBUCKET %u:", offset);
			for (size_t i = 0; i < size; ++i)
				printf(" %lu", bucket.neighbor[i]);
			printf("\n");
			offset = bucket.nextListNode;
			size = LIST_NODE_CAPACITY;
		}
	}
}

