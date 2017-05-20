#ifndef _HT_H_
#define _HT_H_

#include "node.h"
#include "Hashable.h"
#include "LinkedList.h"

template <class DATA>
class Table
{
protected:
	int size; //общий размер
	int count;//текущее число записей
	LinkedList<Node<DATA>>* mas; // данные
	int Hash(Hashable& K);
public:
Table(int size_ = 1); // конструктор
Table(Table& ht);
~Table();
Node<DATA>& operator[](Hashable& k_);
Table& operator=(Table& ht);
void Add(DATA val_, Hashable& k_);
void Del(Hashable& k_);
void resize(size_t size)
{
	if (this->size == size)
		return;
	int last_used = 0;
	for (int i = 0; i < this->size; i++)
		if (mas[index].isused == true)
			last_used = i;
	if (size < i)
		throw 200;
	LinkedList<Node<DATA>>* tmp = new LinkedList<Node<DATA>>[size];
	for (int i = 0; i < size; i++)
		tmp[i] = mas[i];

	delete[] mas;
	tmp = mas;
}
};

template <class DATA>
Table<DATA>::Table(int size_)
{
	size = size_;
	count = 0;
	mas = new LinkedList<Node<DATA>>[size];
}

template <class DATA>
Table<DATA>::Table(Table& ht)
{
	size=ht.size;
	count=ht.count;
	mas=new LinkedList<Node<DATA>>[ht.size];
	for(int i=0; i<ht.size;++i)
		mas[i]=ht.mas[i];

}

template <class DATA>
Table<DATA>::~Table()
{
	delete[] mas;
	size=0;
	count=0;
}

template <class DATA>
int Table<DATA>:: Hash(Hashable& K)
{
	return (K.getHash())% size;

}
template <class DATA>
Node<DATA>& Table<DATA>::operator[](Hashable& K)
{
	int index=Hash(K);
	int HashIndex=index;
	
	try {
		LinkedNode<Node<DATA>> *list = mas[index].getStart();
		do {
			
			if (list->data.GetKey() == K)
				return list->data;
			list = list->next;
		
		} while (!mas[index].isEnd(list));
	}
	catch (int e)
	{}
	throw 2222;
}

template<class DATA>
Table<DATA>& Table<DATA>::operator=(Table<DATA> & ht)
{
	size = ht.size;
	count = ht.count;
	p = ht.p;
	if (mas != 0)
		delete[] mas;
	mas = new LinkedNode<Node<DATA>>[ht.size];
	for (int i = 0; i<ht.size; ++i)
		mas[i] = ht.mas[i];
	return *this;
}

template <class DATA>
void Table<DATA>::Add(DATA val_, Hashable& k_)
{
	int index=Hash(k_);
	Node<DATA> tmp(k_,val_);
	
	try {
		Node<DATA>* find=mas[index].get(tmp);
		find->SetVal(val_);
	}
	catch (int e) {
		mas[index].add(tmp);
	}
	
}

template<class DATA>
void Table<DATA>::Del(Hashable& k_)
{
	int index = Hash(k_);
	Node<DATA> tmp(k_);

	try {
		int find = mas[index].indexOf(tmp);
		if (find >= 0)
			mas[index].remove(find);
	}
	catch (int e) {
	}
}


#endif