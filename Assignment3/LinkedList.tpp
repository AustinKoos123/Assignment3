/**************************************************
* Purpose:
*	Default ctor
*
* Entry:
*	Object created using no paramters
*
* Exit:
*	head set to nullptr and numItems set to 0
**************************************************/
template <typename T>
LinkedList<T>::LinkedList() : m_head(nullptr), m_tail(nullptr), m_numItems(0)
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
LinkedList<T>::~LinkedList()
{
	Purge();
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
LinkedList<T>::LinkedList(const LinkedList& copy) : m_head(nullptr), m_tail(nullptr), m_numItems(0)
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
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs)
{
	if (this != &rhs)
	{
		Purge();

		Node<T> *n = rhs.m_head;

		while (n != nullptr)
		{
			T temp = n->GetData();
			Append(&temp);
			n = n->GetNext();
		}
	}

	return *this;
}

/**************************************************
* Purpose:
*	Returns the first node of the list
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	Element at the front of the list is returned
**************************************************/
template <typename T>
const Node<T>& LinkedList<T>::First()
{
	const Node<T> *n = m_head;
	return *n;
}

/**************************************************
* Purpose:
*	Returns the last node of the list
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	Element at the end of the list is returned
**************************************************/
template <typename T>
const Node<T>& LinkedList<T>::Last()
{
	const Node<T> *n = m_tail;
	return *n;
}

/**************************************************
* Purpose:
*	Adds a new node to the front of linked list
*
* Entry:
*	Element to add to the stack
*
* Exit:
*	Head points to the new Node, with element
*	copied to data
**************************************************/
template <typename T>
void LinkedList<T>::Prepend(T* element)
{
	Node<T> *n = new Node<T>(*element);
	n->SetNext(m_head);
	
	if (m_numItems == 0)
	{
		m_head = n;
		m_tail = n;
		m_numItems++;
	}
	else
	{
		m_head->SetPrev(n);
		m_head = n;
		m_numItems++;
	}
}

/**************************************************
* Purpose:
*	Adds a new node to the end of the linked list
*
* Entry:
*	Element to add to the stack
*
* Exit:
*	A new node is added at the end of the list,
*	the data becomes element
**************************************************/
template <typename T>
void LinkedList<T>::Append(T* element)
{
	Node<T> *n = new Node<T>(*element);

	if (m_numItems == 0)
	{
		n->SetNext(m_head);
		m_head = n;
		m_numItems++;
	}
	else if (m_numItems == 1)
	{
		n->SetPrev(m_head);
		m_head->SetNext(n);
		m_tail = n;
		m_numItems++;
	}
	else
	{
		n->SetPrev(m_tail);
		m_tail->SetNext(n);
		m_tail = n;
		m_numItems++;
	}
}

/**************************************************
* Purpose:
*	Returns the element at the front of the list and
*	deletes the first node
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	Data is returned and node is deleted
**************************************************/
template <typename T>
T LinkedList<T>::RemoveFront()
{
	Node<T> *n = m_head;
	T newData = n->GetData();
	m_head = m_head->GetNext();
	m_head->SetPrev(nullptr);
	delete n;
	m_numItems--;

	return newData;
}

/**************************************************
* Purpose:
*	Returns the element at the end of the list and
*	deletes the last node
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	Data is returned and node is deleted
**************************************************/
template <typename T>
T LinkedList<T>::RemoveBack()
{
	Node<T> *n = m_tail;
	T newData = n->GetData();
	m_tail = m_tail->GetPrev();
	m_tail->SetNext(nullptr);
	m_numItems--;

	return newData;
}

/**************************************************
* Purpose:
*	Returns the node at extractNode
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	Data is returned
**************************************************/
template <typename T>
Node<T>& LinkedList<T>::Extract(T extractNode)
{
	Node<T> *n = m_head;

	int numPasses = 0;

	while ((extractNode != n->GetData()) || (numPasses > m_numItems))
	{
		n = n->GetNext();
		numPasses++;
	}
	
	return *n;
}

/**************************************************
* Purpose:
*	Deletes all the nodes in a LinkedList
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	All nodes are deleted from this
**************************************************/
template <typename T>
void LinkedList<T>::Purge()
{
	while (m_numItems > 0)
	{
		Node<T> *n = m_head;
		m_head = m_head->GetNext();
		
		if (m_numItems > 1)
		{
			m_head->SetPrev(nullptr);
		}
		
		delete n;
		n = nullptr;
		m_numItems--;
	}
}

/**************************************************
* Purpose:
*	Returns the number of nodes in the list
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	numItems is returned
**************************************************/
template <typename T>
int LinkedList<T>::Size()
{
	return m_numItems;
}

/**************************************************
* Purpose:
*	Sets numItems to num
*
* Entry:
*	Function called from invoking object
*
* Exit:
*	numItems set to num
**************************************************/
template <typename T>
void LinkedList<T>::SetSize(int num)
{
	m_numItems = num;
}

/**************************************************
* Purpose:
*	Returns true if numItems == 0, false otherwise
*
* Entry:
*	Function called by invoking object
*
* Exit:
*	True returned if numItems == 0, false otherwise
**************************************************/
template <typename T>
bool LinkedList<T>::isEmpty()
{
	bool retValue = false;
	if (m_numItems == 0)
	{
		retValue = true;
	}

	return retValue;
}

/**************************************************
* Purpose:
*	Inserts node after the node containing value
*
* Entry:
*	Function called by invoking object
*
* Exit:
*	Node inserted into the list.  If there were no
*	items in the list, node is added to the front
**************************************************/
template <typename T>
void LinkedList<T>::InsertAfter(T value, T *node)
{
	Node<T> *n = m_head;
	Node<T> *nn = new Node<T>(*node);

	if (m_numItems == 0)
	{
		m_head = nn;
		m_tail = nn;
	}
	else if (m_numItems == 1)
	{
		nn->SetPrev(m_head);
		m_head->SetNext(nn);
		m_tail = nn;
		m_numItems++;
	}
	else
	{
		int numPasses = 0;

		while ((value != n->GetData()) || (numPasses > m_numItems))
		{
			n = n->GetNext();
			numPasses++;
		}

		nn->SetPrev(n);
		nn->SetNext(n->GetNext());

		n->SetNext(nn);
		n->GetNext()->GetNext()->SetPrev(nn);
	}

	m_numItems++;
}

/**************************************************
* Purpose:
*	Inserts node before the node containing value
*
* Entry:
*	Function called by invoking object
*
* Exit:
*	Node inserted into the list.  If there were no 
*	items in the list, node is added to the front
**************************************************/
template <typename T>
void LinkedList<T>::InsertBefore(T value, T *node)
{
	Node<T> *n = m_head;
	Node<T> *nn = new Node<T>(*node);

	if (m_numItems == 0)
	{
		m_head = nn;
	}
	else if (m_numItems == 1)
	{
		nn->SetNext(m_head);
		m_head->SetPrev(nn);
		m_head = nn;
	}
	else
	{
		int numPasses = 0;

		while ((value != n->GetData()) || (numPasses > m_numItems))
		{
			n = n->GetNext();
			numPasses++;
		}

		n = n->GetPrev();

		nn->SetPrev(n);
		nn->SetNext(n->GetNext());

		n->SetNext(nn);
		n->GetNext()->SetPrev(nn);
	}

	m_numItems++;
}

/**************************************************
* Purpose:
*	Returns an Iterator at the beginning of the list
*
* Entry:
*	Function called by invoking object
*
* Exit:
*	Iterator returned
**************************************************/
template <typename T>
Iterator<T> LinkedList<T>::Begin()
{
	Iterator<T> newIt;

	newIt.SetIterator(m_head);

	return newIt;
}

/**************************************************
* Purpose:
*	Returns an Iterator at the end of the list
*
* Entry:
*	Function called by invoking object
*
* Exit:
*	Iterator returned
**************************************************/
template <typename T>
Iterator<T> LinkedList<T>::End()
{
	Iterator<T> newIt;

	newIt.SetIterator(m_tail);

	return newIt;
}