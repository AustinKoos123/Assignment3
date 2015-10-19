#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::endl;

int main()
{
	LinkedList<int> list;
	int num = 5;
	int num1 = 6;
	int num2 = 7;

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