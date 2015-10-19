/*********************************************************************************************
*Author:					Austin Koos
*Date Created:				10/17/2015
*Last Modification Date:	10/18/2015
*Lab Number:				CST 211 Assignment 3
*Filename:					main.cpp
*
*Overview:
*	Tests the functionality of the templated LinkedList class.  Makes use of all the member 
*	functions and constructors.
*
*Input:
*
*
*Output:
*	isEmpty function boolean value displayed to console
*
***********************************************************************************************/
#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::endl;

int main()
{
	LinkedList<int> list;
	LinkedList<double> listDouble;
	int num = 5;
	int num1 = 6;
	int num2 = 7;

	double doub = 1.0;
	double doub2 = 2.0;
	double doub3 = 3.0;

	listDouble.Prepend(&doub);
	listDouble.Prepend(&doub2);
	listDouble.Prepend(&doub3);

	list.Prepend(&num);

	list.InsertBefore(num, &num1);

	list.Append(&num2);

	const Node<int> node = list.First();

	const Node<int> node1 = list.Last();

	LinkedList<int> list1(list);

	list1.InsertAfter(num1, &num2);

	Iterator<int> newItBegin = list.Begin();
	Iterator<int> newItEnd = list.End();

	newItBegin++;
	++newItBegin;
	
	newItEnd--;
	--newItEnd;

	Iterator<int> newItBeginCopy(newItBegin);

	newItEnd.SetIterator(&list.Extract(num2));

	num = list.RemoveFront();
	num1 = list.RemoveBack();

	cout << list.isEmpty() << endl;

	return 0;
}