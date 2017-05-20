#pragma once
#include <iostream>
#include "Hashable.h"
#include "Cloneble.h"

class HashString : public Hashable
{
private:
	std::string str;
public:
	HashString(){}
	HashString(HashString& st):str(st.str) {};
	HashString(std::string& st) :str(st) {};
	HashString(const char* st) :str(st) {};
	bool operator ==(Cloneble& r){

		HashString t = dynamic_cast<HashString&>(r);
		
		return str == t.str;
	}
	char operator[](size_t index) { return str[index]; };
	virtual unsigned int getHash()
	{
		unsigned int hash = 2139062143;
		for (size_t i = 0; i < str.size(); i++)
			hash = 37 * hash + str[i];
		return hash;
	}
	HashString& operator=(HashString& st)
	{
		str = st.str;
	}
	HashString* clone()
	{
		HashString* newhashst = new HashString(*this);

		return newhashst;
	}

};
	