#include <iostream>
#include <gtest/gtest.h>
using namespace std;

#include "../../Graph.h"

TEST(EdgeTest, SingleEdge) {
	Graph graph;

	uint32_t nodeId1 = 0, nodeId2 = 1;
	graph.addEdge(nodeId1, nodeId2);

	ASSERT_EQ(graph.getOut().find(nodeId2, nodeId1), true);
	ASSERT_EQ(graph.getIn().find(nodeId1, nodeId2), true);
}

TEST(EdgeTest, BufferOverflow) {
	Graph graph;

	uint32_t nodeId = 0;
	for (uint32_t i = 1; i <= LIST_NODE_CAPACITY; i++)
		graph.addEdge(nodeId, i);

	graph.addEdge(1, 2);
	graph.addEdge(nodeId, LIST_NODE_CAPACITY + 1);

	size_t index = graph.getOut().getIndex().getListHead(0);
	ASSERT_EQ(graph.getOut().getIndex()[nodeId].count, 2);
	ASSERT_EQ(graph.getOut().getIndex()[nodeId].size, 1);
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