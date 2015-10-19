//Had to comment out the include guard, didn't work properly for some reason
//#ifndef NODE_H
#define NODE_H

/************************************************************************
* Class: Node
*
* Constructors:
*	Node()
*		m_next and m_prev initialized to nullptr
*
*	Node(const T& arg)
*		m_data initialized to arg and m_next and m_prev to nullptr
*
*	Node(const Node& arg)
*		Copy constructor
*
* Destructor:
*	~Node()
*		Sets m_next and m_prev to nullptr
*
* Methods:
*	Node& operator= (const Node& rhs)
*		If this and rhs are not the same, copies rhs to this
*
*	Node<T>* GetNext()
*		Returns m_next
*
*	Node<T>* GetPrev()
*		Returns m_prev
*
*	void SetNext(Node<T> *nextNode)
*		Sets m_next to nextNode
*
*	void SetPrev(Node<T> *prevNode)
*		Sets m_prev to prevNode
*
*	T GetData()
*		Returns m_data
*
*	void SetData(T newData)
*		Sets m_data to newData
*
*************************************************************************/
template <typename T>
class Node
{
public:
	//Default ctor
	Node();

	//One arg ctor
	Node(const T& arg);

	//Dtor
	~Node();

	//Copy ctor
	Node(const Node& arg);

	//Copies rhs to this
	Node<T>& operator=(const Node<T>& rhs);

	//Returns m_next
	Node<T>* GetNext();

	//Returns m_prev
	Node<T>* GetPrev();

	//Sets m_next to nextNode
	void SetNext(Node<T> *nextNode);

	//Sets m_prev to prevNode
	void SetPrev(Node<T> *prevNode);

	//Returns m_data
	T GetData();

	//Sets m_data to newData
	void SetData(T newData);

private:
	T m_data;				//Holds the node data
	Node<T> *m_next;		//Address of the next node
	Node<T> *m_prev;		//Address of the previous node
};

#include "Node.tpp"

//#endif