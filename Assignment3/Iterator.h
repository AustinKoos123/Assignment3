#ifndef NODE_H
#define NODE_H
#include "Node.h"

/************************************************************************
* Class: Iterator
*
* Constructors:
*	Iterator()
*		m_node initialized to nullptr
*
*	Iterator(const Iterator& arg)
*		Copy constructor
*
* Destructor:
*	~Iterator()
*		Sets m_node to nullptr
*
* Methods:
*	Iterator& operator= (const Iterator& rhs)
*		If this and rhs are not the same, copies rhs to this
*
*	void SetIterator(Node<T> *node);
*		Sets m_node to node
*
*	Iterator<T>& operator++();
*		Moves m_node to the next node in the list
*
*	Iterator<T> operator++(int);
*		Moves m_node to the next node in the list
*
*	Iterator<T>& operator--();
*		Moves m_node to the previous node in the list
*
*	Iterator<T> operator--(int);
*		Moves m_node to the previous node in the list
*
*************************************************************************/
template <typename T>
class Iterator
{
public:
	//Default ctor
	Iterator();

	//Copy ctor
	Iterator(const Iterator<T>& copy);

	//Dtor
	~Iterator();

	//Copies rhs to this
	Iterator<T>& operator=(const Iterator<T>& rhs);

	//Sets m_node to node
	void SetIterator(Node<T> *node);

	//Moves m_node to the next node in the list
	Iterator<T>& operator++();

	//Moves m_node to the next node in the list
	Iterator<T> operator++(int);
	
	//Moves m_node to the previous node in the list
	Iterator<T>& operator--();

	//Moves m_node to the previous node in the list
	Iterator<T> operator--(int);

private:
	Node<T> *m_node;			//Current node
};

#include"Iterator.tpp"

#endif