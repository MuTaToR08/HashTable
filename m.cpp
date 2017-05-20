#include <iostream>
#include "Hastable.h"
#include "HashString.h"
#include "Hashable.h"

void main()
{
	Table<int> hashT(20);
	hashT.Add(500, HashString ("test1") );
	hashT.Add(600, HashString("test5"));
	hashT.Add(700, HashString("test2"));
	hashT.Add(800, HashString("test1"));
	hashT.Add(900, HashString("test10"));//На удивление колизия с test5
	hashT.Del(HashString("test10"));
	try {
		std::cout << hashT[HashString("test1")].GetData() << std::endl;
		std::cout << hashT[HashString("test5")].GetData() << std::endl;
		std::cout << hashT[HashString("test2")].GetData() << std::endl;
		std::cout << hashT[HashString("test10")].GetData() << std::endl;
	}catch(int a)
	{
		std::cout << "error";
	}

	std::cin.get();
}