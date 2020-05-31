#pragma once
#include "Person.h"
#include "Date.h"
#include"BankAccount.h"
#include <list>
using namespace std;
class Manager : public Person
{
public:
	Manager();
	void PerformAction(int num) override;
	
	~Manager();
private:
	int GetNumberOfAction() override;
	void EditAccountInfo();
	list<BankAccount> GetAllByName(string Name);
	list<BankAccount> GetAllByDate(Date date);
	BankAccount FindByNumber(unsigned long int Number);
	void outputSomeRecords(list<BankAccount>&elems);
};

