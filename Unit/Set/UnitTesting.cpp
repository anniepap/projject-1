#include <iostream>
#include <gtest/gtest.h>
using namespace std;

#include "../../HashSet.h"

TEST(Set, NewElement) {
	HashSet set(10);

	uint32_t id = 5;
	set.add(id);

	ASSERT_EQ(set.contains(id), true);
}

TEST(Set, Contains) {
	HashSet set(10);

	uint32_t id = 5;
	set.add(id);
	set.add(id);

	ASSERT_EQ(set.contains(id), true);
}

TEST(Set, NotInSet) {
	size_t size = 10;
	HashSet set(size);
	for (int i = 0; i < size; ++i)
	{
		ASSERT_EQ(set.contains(i), false);
	}
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}