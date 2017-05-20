#pragma once
#include "Cloneble.h"

class Hashable:public Cloneble
{
public:
	virtual unsigned int getHash() = 0;
};