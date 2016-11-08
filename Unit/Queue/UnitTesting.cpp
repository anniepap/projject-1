#include <iostream>
#include <gtest/gtest.h>
using namespace std;

#include "../../ArrayQueueSet.h"

TEST(QueueSet, FullTest) {
	ArrayQueueSet set(10);

	ASSERT_EQ(set.empty(), true);

	int size = 5;
	for (int i = 0; i < size; ++i)
	{
		ASSERT_EQ(set.getVisited(i), false);
	}

	for (int i = 0; i < size; ++i)
	{
		set.push(i);
	}

	ASSERT_EQ(set.empty(), false);
	ASSERT_EQ(set.getSize(), size);

	for (int i = 0; i < size; ++i)
	{
		ASSERT_EQ(set.pop(), i);
	}

	ASSERT_EQ(set.empty(), true);

	for (int i = 0; i < size; ++i)
	{
		ASSERT_EQ(set.getVisited(i), true);
	}
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}