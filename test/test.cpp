#include <gtest/gtest.h>
#include "Example.h"

TEST(ListPalindrome, EmptyList)
{
	List <int> node(NULL);
	EXPECT_TRUE(isPalindrome(&node));
}

TEST(ListPalindrome, OneNode)
{
	List <int> node(3);
	EXPECT_TRUE(isPalindrome(&node));
}

TEST(ListPalindrome, IntPalindrome)
{
	const int nodes_count = 5;
	List <int> nodes[nodes_count];
	int vals[nodes_count] = { 1,2,3,2,1 };
	for (int i = 0; i < nodes_count - 1; ++i)
	{
		nodes[i].next = &(nodes[i + 1]);
		nodes[i].data = vals[i];
	}

	nodes[nodes_count - 1] = vals[nodes_count - 1];

	EXPECT_TRUE(isPalindrome(nodes));
}

TEST(ListPalindrome, Not_IntPalindrome)
{
	const int nodes_count = 5;
	List <int> nodes[nodes_count];
	for (int i = 0; i < nodes_count - 1; ++i)
	{
		nodes[i].next = &(nodes[i + 1]);
		nodes[i].data = i + 1;
	}

	EXPECT_FALSE(isPalindrome(nodes));
}

TEST(ListPalindrome, CharPalindrome)
{
	const int nodes_count = 6;
	List <char> nodes[nodes_count];
	char vals[nodes_count] = "ABCBA";
	for (int i = 0; i < nodes_count - 1; ++i)
	{
		nodes[i].next = &(nodes[i + 1]);
		nodes[i].data = vals[i];
	}

	nodes[nodes_count - 1] = vals[nodes_count - 1];

	EXPECT_TRUE(isPalindrome(nodes));
}

TEST(ListPalindrome, Not_CharPalindrome)
{
	const int nodes_count = 5;
	List <char> nodes[nodes_count];
	char vals[nodes_count] = "ABAB";
	for (int i = 0; i < nodes_count - 1; ++i)
	{
		nodes[i].next = &(nodes[i + 1]);
		nodes[i].data = vals[i];
	}

	nodes[nodes_count - 1] = vals[nodes_count - 1];

	EXPECT_FALSE(isPalindrome(nodes));
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}