#include <iostream>
#include <gtest/gtest.h>
using namespace std;

#include "Graph.h"

TEST(InsertTest, Capacity) {
	Graph graph;
	// should double index twice
	graph.insertNode((NODE_INDEX_CAPACITY * 2 * 2) - 1);

	ASSERT_EQ(graph.getOut().getIndex().getCapacity(), NODE_INDEX_CAPACITY * 2 * 2);
	ASSERT_EQ(graph.getIn().getIndex().getCapacity(), NODE_INDEX_CAPACITY * 2 * 2);
}
TEST(InsertTest, NonExistingEdges) {
	Graph graph;
	uint32_t nodeId = NODE_INDEX_CAPACITY - 1;
	graph.insertNode(nodeId);

	ASSERT_EQ(graph.getOut().getIndex().getListHead(nodeId), NONE);
}
TEST(EdgeTest, SingleEdge) {
	Graph graph;
	uint32_t nodeId1 = 0, nodeId2 = 1;
	graph.insertNode(nodeId1);
	graph.insertNode(nodeId2);
	graph.addEdge(nodeId1, nodeId2);

	size_t index = graph.getOut().getIndex().getListHead(nodeId1);
	list_node& ln = graph.getOut().getBuffer()[index];
	//ASSERT_EQ(graph.getOut().getBuffer().find(index, nodeId2, 1), true);
	ASSERT_EQ(ln.neighbor[0], nodeId2);

	size_t index2 = graph.getIn().getIndex().getListHead(nodeId2);
	list_node& ln2 = graph.getIn().getBuffer()[index2];
	ASSERT_EQ(ln.neighbor[0], nodeId1);
}
TEST(EdgeTest, BufferOverflow) {
	Graph graph;
	for (uint32_t i = 1 ; i <= LIST_NODE_CAPACITY ; i++)
		graph.addEdge(0, i);
	graph.addEdge(1, 2);
	graph.addEdge(0, LIST_NODE_CAPACITY + 1);

	size_t index = graph.getOut().getIndex().getListHead(0);
	list_node& ln = graph.getOut().getBuffer()[index];
	ASSERT_NE(ln.nextListNode, NONE); // must have overflow

	list_node& ln2 = graph.getOut().getBuffer()[ln.nextListNode];
	ASSERT_EQ(ln.neighbor[0], LIST_NODE_CAPACITY + 1);

	for (uint32_t i = 0; i <= LIST_NODE_CAPACITY + 1; i++) {
		ASSERT_NE(graph.getOut().getIndex().getListHead(i), ln.nextListNode);
	}
}
TEST(PathTest, OneLenPath) {
	Graph graph;
	graph.addEdge(0,1);
	ASSERT_EQ(graph.question(0,1), 1);
}
TEST(PathTest, NonExistingPath) {
	Graph graph;
	graph.addEdge(0,1);
	ASSERT_EQ(graph.question(1,0), -1);
}
TEST(PathTest, ThreeLenPath) {
	Graph graph;
	graph.addEdge(0,1);
	graph.addEdge(1,2);
	graph.addEdge(2,3);
	ASSERT_EQ(graph.question(0,3), 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}