#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Iterator.h"

/************************************************************************
* Class: LinkedList
*
* Constructors:
*	LinkedList()
*		head set to nullptr and numItems to 0
*
*	LinkedList(const LinkedList& copy)
*		Copy constructor
*
* Destructor:
*	~LinkedList()
*		Deletes all the nodes in the linked list
*
* Methods:
*	LinkedList& operator= (const LinkedList& rhs)
*		If this and rhs are not the same, copies rhs to this
*
*	T& Front()
*		Returns data at the front of the list
*
*	T& Back()
*		Returns the data at the back of the list
*
*	void Prepend(T* element)
*		Adds an element to the front of the list
*
*	void Append(T* element)
*		Adds an element to the back of the list
*
*	T RemoveFront()
*		Returns and deletes the element at the front of the list
*
*	T RemoveBack()
*		Returns and deletes the element at the back of the list
*
*	Node<T>& Extract(T extractNode)
*		Returns the node containing the data extractNode
*
*	void Purge()
*		Deletes all the nodes in the linked list
*
*	int Size()
*		Returns numItems
*
*	void SetSize(int num)
*		Sets numItems to num
*
*	bool isEmpty()
*		If the list is empty, returns true.  Otherwise, returns false
*	
*	void InsertAfter(T value, T *node)
*		Inserts node after the node containing value
*
*	void InsertBefore(T value, T *node)
*		Inserts node before the node containing value
*
*	Iterator<T> Begin()
*		Returns an Iterator at the beginning of the list
*
*	Iterator<T> End();
*		Returns an Iterator at the end of the list
*
*************************************************************************/

template <typename T>
class LinkedList {

public:
	//Default ctor
	LinkedList();

	//Dtor
	~LinkedList();

	//Copy ctor
	LinkedList(const LinkedList& copy);

	//Overloaded = operator
	LinkedList& operator= (const LinkedList& rhs);

	//Returns element at the front of the list
	const Node<T>& First();

	//Returns element at the back of the list
	const Node<T>& Last();

	//Adds an element to the front of the list
	void Prepend(T* element);

	//Adds an element to the back of the list
	void Append(T* element);

	//Returns and deletes the element at the front of the list
	T RemoveFront();

	//Returns and deletes the element at the back of the list
	T RemoveBack();

	//Returns the data at node element
	Node<T>& Extract(T extractNode);

	//Deletes all nodes in the list
	void Purge();

	//Returns numItems 
	int Size();

	//Sets numItems to num
	void SetSize(int num);

	//Returns true if list is empty, false otherwise
	bool isEmpty();

	//Inserts node after the node containing value
	void InsertAfter(T value, T *node);

	//Inserts node before the node containing value
	void InsertBefore(T value, T *node);

	//Returns an Iterator at the beginning of the list
	Iterator<T> Begin();

	//Returns an Iterator at the end of the list
	Iterator<T> End();

private:
	Node<T> *m_head;		//First node in the list
	Node<T> *m_tail;		//Last node in the list
	int m_numItems;			//Number of nodes in the list
};

#include "LinkedList.tpp"

#endif
