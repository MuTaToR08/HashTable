#pragma once

class Cloneble
{
public:
	virtual Cloneble* clone() = 0;
	virtual bool operator==(Cloneble&) = 0;
};