/**************************************************
* Purpose:
*	Default ctor
*
* Entry:
*	Object created using no paramters
*
* Exit:
*	m_node set to nullptr
**************************************************/
template <typename T>
Iterator<T>::Iterator() : m_node(nullptr)
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
Iterator<T>::~Iterator()
{
	m_node = nullptr;
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
Iterator<T>::Iterator(const Iterator<T>& copy) : m_node(nullptr)
{
	*this = copy;
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
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& rhs)
{
	if (this != &rhs)
	{
		m_node = rhs.m_node;
	}

	return *this;
}

/**************************************************
* Purpose:
*	Sets m_node to node
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_node set to node
**************************************************/
template <typename T>
void Iterator<T>::SetIterator(Node<T> *node)
{
	m_node = node;
}

/**************************************************
* Purpose:
*	Preincrement operator.  Moves m_node to next 
*	and returns this
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_node moved to next
**************************************************/
template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
	m_node = m_node->GetNext();

	return *this;
}

/**************************************************
* Purpose:
*	Postincrement operator.  Copies and incrememnts 
*	this, returns the copy
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_node moved to next, copy node returned
**************************************************/
template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator<T> newIt = *this;
	++*this;

	return newIt;
}

/**************************************************
* Purpose:
*	Predecrement operator.  Moves m_node to next
*	and returns this
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_node moved to prev
**************************************************/
template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
	m_node = m_node->GetPrev();

	return *this;
}

/**************************************************
* Purpose:
*	Postdecrement operator.  Copies and decrements
*	this, returns the copy
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	m_node moved to prev, copy node returned
**************************************************/
template <typename T>
Iterator<T> Iterator<T>::operator--(int)
{
	Iterator<T> newIt = *this;
	--*this;

	return newIt;
}