#include "Person.h"
#include <string.h>
#pragma warning(disable:4996)

Person::Person(int ID, char *name)
{
	this->p_ID = ID;
	this->p_name = strdup(name);
}
Person::Person(Person & other)
{
	this->p_ID = other.p_ID;
	this->p_name = strdup(other.p_name);
}
//----------------------------------------------------//
Person::~Person()
{
	delete[] p_name;
}

const int Person::getID() const
{
	return this->p_ID;
}

void Person::setID(const int id)
{
	this->p_ID = id;
}

void Person::setName(const char * name)
{
	this->p_name = strdup(name);
}
