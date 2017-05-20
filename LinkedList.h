#pragma once
#include "List.h"
#include "Exception.h"

template<class E>
struct LinkedNode
{
	E data;
	LinkedNode *next;
	LinkedNode() { data = E(); next = nullptr; };
	LinkedNode(LinkedNode* e)
	{
		if (e != nullptr)
			data = e->data;
	}
};

template<class E>
class LinkedList :
	public List<E>
{
private:


	LinkedNode<E> *head, *tail;
	size_t count;
public:

	LinkedList():count(0)
	{
		head = tail = nullptr;
	}

	virtual ~LinkedList()
	{
		if (head == 0)
			return;
		LinkedNode<E> *tmp ;
		LinkedNode<E> *next = head;
		do {

			tmp = next->next;
			delete next;
			next = tmp;
		} while (next != head);
	}
	LinkedNode<E>* getStart() { if (head == nullptr)throw 15; return head; }
	bool isEnd(LinkedNode<E>* e) { return e == tail; }
	virtual void add(E& e);
	virtual E* toArray();
	virtual E* get(E& e)
	{
		int i = indexOf(e);
		if (i < 0)
			throw 555;
		return &get(i);
	}


	virtual bool contains(E& e);
	virtual E& get(size_t index);
	virtual int indexOf(E& e);
	virtual bool isEmpty();
	virtual void remove(size_t index);
	virtual void set(size_t index, E& e);
	virtual size_t size();
	virtual void clear();
	LinkedList<E>& operator=(LinkedList& r)
	{
		if (r.head == nullptr)
			return *this;
		count = r.count;
		
		LinkedNode<E> *tmp;
		LinkedNode<E> *next = r.head;
		head = new LinkedNode<E>(r.head);
		LinkedNode<E> *prev = head;
		do {
			tmp = next->next;
			prev->next = new LinkedNode<E>(tmp);
			next = tmp;
			prev = prev->next;
		} while (next != r.head);
		tail = prev;
		tail->next = head;
		return *this;
	}
	//*/

};

template<class E>
void LinkedList<E>::add(E& e)
{
	LinkedNode<E> *tmp = new LinkedNode<E>;
	tmp->data = e;
	if (head == nullptr)
	{
		head = tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tmp;
	}
	tmp->next = head;
	++count;
}

template<class E>
E * LinkedList<E>::toArray()
{
	E *tmp = new E[count];
	if (count == 0)
		return tmp;

	size_t counter = 0;
	for (LinkedNode<E> *i = head; counter < count; i = i->next,counter++)
	{
		tmp[counter] = i->data;
	}

	return tmp;
}

template<class E>
bool LinkedList<E>::contains(E& e)
{
	bool ret = false;
	size_t counter = 0;
	for (LinkedNode<E> *i = head; counter < count; i = i->next, counter++)
	{
		if (i->data == e)
		{
			ret = true;
			break;
		}
	}
	return ret;
}

template<class E>
E& LinkedList<E>::get(size_t index)
{
	if (index > count)
		throw INDEX_ERROR_EXCEPTION;
	size_t counter = 0;
	for (LinkedNode<E> *i = head; counter < count; i = i->next, counter++)
	{
		if (counter == index)
		{
			return i->data;
		}
	}
	throw UNKONW_EXCEPTION;
}

template<class E>
int LinkedList<E>::indexOf(E& e)
{
	size_t counter = 0;
	for (LinkedNode<E> *i = head; counter < count; i = i->next, counter++)
	{
		if (i->data == e)
		{
			return counter;
		}
	}
	return -1;
}

template<class E>
inline bool LinkedList<E>::isEmpty()
{
	return count == 0;
}

template<class E>
void LinkedList<E>::remove(size_t index)
{
	if (index > count)
		throw INDEX_ERROR_EXCEPTION;

	if (count == 1)
	{
		delete head;
		head = tail = nullptr;
		count = 0;
		return;
	}

	LinkedNode<E> *prev = head;
	size_t counter = 0;
	for (LinkedNode<E> *i = head; counter < count; i = i->next, counter++)
	{
		if (counter == index)
		{
			if (i == head)
			{
				head = head->next;
				delete tail->next;
				tail->next = head;
				break;
			}
			if (i == tail)
			{
				tail = prev;
				delete tail->next;
				tail->next = head;
				break;
			}
			if (i != tail && i != head)
			{
				prev->next = i->next;
				delete i;
			}
			break;
		}
		prev = i;
	}
	--count;
}

template<class E>
void LinkedList<E>::set(size_t index, E& e)
{
	if (index > count)
		throw INDEX_ERROR_EXCEPTION;
	size_t counter = 0;
	for (LinkedNode<E> *i = head; counter < count; i = i->next, counter++)
	{
		if (counter == index)
		{
			i->data = e;
		}
	}
}

template<class E>
inline size_t LinkedList<E>::size()
{
	return count;
}

template<class E>
inline void LinkedList<E>::clear()
{
	LinkedNode<E> *tmp;
	LinkedNode<E> *next = head;
	do
	{
		tmp = next->next;
		delete next;
		next = tmp;

	} while (next != head);
	head = tail = 0;
	count = 0;
}
