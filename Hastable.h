#ifndef _HT_H_
#define _HT_H_

#include "node.h"
#include "Hashable.h"

template <class DATA>
class Table
{
protected:
	int size; //общий размер
	int count;//текущее число записей
	int p; // смещение
	Node<DATA>* mas; // данные
	int Hash(Hashable& K);
public:
Table(int size_ = 1,int p_ =11); // конструктор
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
	Node<DATA>* tmp = new Node<DATA>[size];
	for (int i = 0; i < size; i++)
		tmp[i] = mas[i];

	delete[] mas;
	tmp = mas;
}
};

template <class DATA>
Table<DATA>::Table(int size_, int p_)
{
	size = size_;
	count = 0;
	p = p_;
	mas = new Node<DATA>[size];
}

template <class DATA>
Table<DATA>::Table(Table& ht)
{
	size=ht.size;
	count=ht.count;
	p=ht.p;
	mas=new Node<DATA>[ht.size];
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
	do
	{
		
	if(mas[index].GetKey()==K)
		return mas[index];
	else
		index+=p;
	} while (index != HashIndex);
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
	mas = new Node<DATA>[ht.size];
	for (int i = 0; i<ht.size; ++i)
		mas[i] = ht.mas[i];
	return *this;
}

template <class DATA>
void Table<DATA>::Add(DATA val_, Hashable& k_)
{
	int index=Hash(k_);
	int HashIndex=index;
	do
	{
		
	if(mas[index].isused==false || (mas[index].isused == true && k_ == mas[index].GetKey()))
	{
		mas[index].SetKey(k_);
		mas[index].SetVal(val_);
		mas[index].isused = true;
		return;

	}
	else
		index+=p;
	} while (index != HashIndex);

}

template<class DATA>
void Table<DATA>::Del(Hashable& k_)
{
	 int index = Hash(K);
	 int HashIndex = index;
	 do
	 {

		 if (mas[index].GetKey() == k_)
		 {
			 mas[index].SetKey(k_);
			 mas[index].SetVal(val_);
			 mas[index].isused = false;
			 return;

		 }
		 else
			 index += p;
	 } while (index != HashIndex)

}


#endif