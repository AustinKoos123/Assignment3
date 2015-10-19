/**************************************************
* Purpose:
*	Default ctor
*
* Entry:
*	Object created using no paramters
*
* Exit:
*	m_next and m_prev set to nullptr
**************************************************/
template <typename T>
Node<T>::Node() : m_next(nullptr), m_prev(nullptr)
{

}

/**************************************************
* Purpose:
*	One arg ctor
*
* Entry:
*	Object created using one paramter
*
* Exit:
*	m_data set to arg and m_next and m_prev set
*	to nullptr
**************************************************/
template <typename T>
Node<T>::Node(const T& arg) : m_data(arg), m_next(nullptr), m_prev(nullptr)
{

}

/**************************************************
* Purpose:
*	dtor
*
* Entry:
*	Object to be destroyed
*
* Exit:
*	Object is destroyed
**************************************************/
template <typename T>
Node<T>::~Node()
{
	m_next = nullptr;
	m_prev = nullptr;
}

/**************************************************
*	Purpose:	Copy constructor
*
*   Entry:		Object passed or returned by value or an
*				object instantiated with another object
*
*   Exit:		this object will be a copy of copy
*
**************************************************/
template <typename T>
Node<T>::Node(const Node& arg) : m_data(arg.m_data), m_next(nullptr)
{

}

/*************************************************
*	  Purpose:		Operator= function
*
*     Entry:		Object assigned to another object
*
*     Exit:			this object will be a copy of rhs
*
***************************************************/
template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.GetData();
		m_next = rhs.GetNext();
		m_prev = rhs.GetPrev();
	}

	return *this;
}

/**************************************************
* Purpose:
*	Returns m_next
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_next returned
**************************************************/
template <typename T>
Node<T>* Node<T>::GetNext()
{
	return m_next;
}

/**************************************************
* Purpose:
*	Returns m_prev
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_prev returned
**************************************************/
template <typename T>
Node<T>* Node<T>::GetPrev()
{
	return m_prev;
}

/**************************************************
* Purpose:
*	Sets m_next to nextNode
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_next set to nextNode
**************************************************/
template <typename T>
void Node<T>::SetNext(Node<T> *nextNode)
{
	m_next = nextNode;
}

/**************************************************
* Purpose:
*	Sets m_prev to prevNode
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_prev set to nextNode
**************************************************/
template <typename T>
void Node<T>::SetPrev(Node<T> *prevNode)
{
	m_prev = prevNode;
}

/**************************************************
* Purpose:
*	Returns m_data
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_data returned
**************************************************/
template <typename T>
T Node<T>::GetData()
{
	return m_data;
}

/**************************************************
* Purpose:
*	Sets m_data to newData
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_data set to newData
**************************************************/
template <typename T>
void Node<T>::SetData(T newData)
{
	m_data = newData;
}