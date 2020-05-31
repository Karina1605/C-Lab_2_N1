#include "pch.h"
#include "Person.h"


Person::Person()
{
}

void Person::Work()
{
	int i = 0;
	do
	{
		i = GetNumberOfAction();
		PerformAction(i);
	} while (i != 0);
}

Person::~Person()
{
}
