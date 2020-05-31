#pragma once
#include<string>
using namespace std;
class Person
{
public:
	Person();
	~Person();
	virtual void PerformAction(int num)=0;
	void Work();
protected:
	virtual int GetNumberOfAction()=0;
};

