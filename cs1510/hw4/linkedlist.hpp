//Dylan Elznic
//CS 1510 Section 1B

#include <iostream>
using namespace std;

template<typename T>
class LinkedList;

//Big 3 Member Functions

template<typename T>
const LinkedList<T>&  LinkedList<T>::operator= (const LinkedList<T>& rhs)
{
	if(this != &rhs)
	{
		clear();
		int i = rhs.size();
		int k = 0;
		LinkedList<T>* r = getFirstPtr();
		const LinkedList<T>* q = &rhs;
		
		while(k < i)
		{
			T temp = q -> m_data;
			insert (temp, r);
			k++;
			r = r -> m_next;
			q = q->m_next;
		}
	}
	
	return *this;
}


template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
	LinkedList<T> *p = this;
	const LinkedList<T> *q = &rhs;
	T *a;
	a = new T[rhs.size()];
	for(int k = (rhs.size() - 1); k > -1; k--)
	{
		a[k] = q -> m_data;
		q = q -> m_next;
	}
	for(int i = 0; i < rhs.size(); i++)
	{
		insert_front(a[i]);
	}
	int j = 0;
	while(j<rhs.size())
	{
		p = p->m_next;
		j++;
	}
	p-> m_next = NULL;
	delete []a;
}

//Basic Accessor Operations
template<typename T>
int LinkedList<T>::size() const
{
	const LinkedList<T>* r = this;
	int count = 0;
	
	while(r -> m_next != NULL)
	{
		r = r -> m_next;
		count++;
	}
	
	return count;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
	if(this == NULL)
	return true;
	
	return true;
}

template<typename T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
	LinkedList<T>* r = this;
	
	if(r -> m_next == NULL)
	{
		cout <<"!!-- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty list"<< endl;
	}
	
	return r;
}

template<typename T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
	LinkedList<T>* r = this;
	
	if(r -> m_next == NULL)
	{
		cout <<"!!-- ERROR : PANIC in LINKEDLIST.getLasttPtr() - empty list"<< endl;
		return NULL;
	}
	
	else
	{
		while(r -> m_next -> m_next != NULL)
		{
			r = r -> m_next;
		}
		
		return r;
	}
	
}

template<typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
	LinkedList<T>* r = this;
	int count = 0;
	
	while(count < i && r -> m_next != NULL)
	{
		r = r -> m_next;
		count++;
	}
	
	if(r -> m_next != NULL)
	{
		return r;
	}
	else
	{
		cout <<"!!-- ERROR : PANIC in LINKEDLIST.getAtPtr() - invalid index"<< endl;
		return NULL;
	}
}


//Basic Mutator Operations
template<typename T>
void LinkedList<T>::clear()
{
	LinkedList<T>* p = this;
	
	while(m_next != NULL)
	{
		p = m_next;
		m_next = p -> m_next;
		delete p;
	}
	
	return;
}

template<typename T>
void LinkedList<T>::insert_front(const T& x)
{
	LinkedList<T>* p = this;
	LinkedList<T>* temp;
	temp = new LinkedList<T>;
	
temp -> m_data = p -> m_data;
temp -> m_next = p -> m_next;

p -> m_next = temp;
p -> m_data = x;

return;
}

template<typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
	LinkedList<T>* temp = new LinkedList;
	temp -> m_data = pos -> m_data;
	temp -> m_next = pos -> m_next;
	pos -> m_data = x;
	pos -> m_next = temp;
	
	return;
}

template<typename T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
	LinkedList<T>* temp = pos -> m_next;
	pos -> m_data = temp -> m_data;
	pos -> m_next = temp -> m_next;
	delete temp;
	
	return;
}

//Complex Operations

template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
	const LinkedList<T>* lhsNode = this;
	const LinkedList<T>* rhsNode = &rhs;
	
	while(rhsNode -> m_next != NULL)
	{
		if(lhsNode -> m_next == NULL)
		{
			return false;
		}
		if(lhsNode -> m_data == rhsNode -> m_data)
		{
			lhsNode = lhsNode -> m_next;
			rhsNode = rhsNode -> m_next;
		}
		else
		{
			return false;
		}
	}
	if(lhsNode -> m_next != NULL)
	{
		return false;
	}
	
	return true;
}

template<typename T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
	LinkedList<T>* r = this;
	
	while(r -> m_next != NULL && r -> m_data != x)
	{
		r = r -> m_next;
	}
	
	if(r -> m_data == NULL)
	{
		return NULL;
	}
	
	return r;
}

template<typename T>
void LinkedList<T>::reverse()
{
	int i = size();
	T* temp = new T[i];
	
	LinkedList<T>* p = this;
	int k = 0;
	while(p -> m_next != NULL)
	{
		temp[k] = p -> m_data;
		k++;
		p = p -> m_next;
	}
	
	p = this;
	k--;
	while(k >= 0)
	{
		p -> m_data = temp[k];
		k--;
		p = p -> m_next;
	}
	
	delete []temp;
	temp = NULL;
	
	return;
}


template<typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
	const LinkedList<T>* q = &xlist;
	LinkedList<T>* r = getLastPtr();
	r = r -> m_next;
	int i = size();
	int k = xlist.size();
	
	while(size() < (i+k))
	{
		insert(q->m_data, r);
		q = q->m_next;
		r = r -> m_next;
	}
	
	return;
}
