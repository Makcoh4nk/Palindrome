#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

template <class T>
struct List
{
	T data;
	List *next;

	List(T x = 0) : data(x), next(0) {}
};

template <class T>
bool isPalindrome(List <T> *head)
{
	int size = 0;
	List <T> *node = head;

	if (node->next != NULL)
	{
		while (node != NULL)
		{
			if (node->data == '\0') break;
			size++;
			node = node->next;
		}
	}
	else return true;

	int offset = size - 1;

	for (int i = 0; i < size / 2; ++i)
	{
		node = head;
		for (int j = 0; j < offset; ++j)
			node = node->next;

		if (node->data != head->data)
			return false;

		head = head->next;
		offset -= 2;
	}

	return true;
}