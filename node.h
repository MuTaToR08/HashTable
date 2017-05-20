#ifndef _NODE_H_
#define _NODE_H_
#include "Cloneble.h"


template <class DATA>
class Node
{
protected:
	Cloneble* k;
	DATA val;
public:
	Cloneble& GetKey();
	DATA GetData();
	void SetKey(Cloneble& k_);
	void SetVal(DATA val_);
	bool isused = false;
};

template <class DATA>
Cloneble& Node<DATA>::GetKey()
{
	return *k;
}
template <class DATA>
DATA Node<DATA>::GetData()
{
	return val;
}
template <class DATA>
void Node<DATA>::SetKey(Cloneble& k_)
{
	k = k_.clone();
}
template <class DATA>
void Node<DATA>::SetVal(DATA val_)
{
	val = val_;
}

#endif //_NODE_H_