#pragma once
#include "Person.h"
#include "BankAccount.h"
class User : public Person
{
public:
	User();
	
	void PerformAction(int num) override;
	~User();
private:
	BankAccount* CurrentAccount;
	bool LogIn();
	void CreateAccount();


	void GetInfoAccount();

	void AddSum(float sum);
	void TakeSum(float sum);
	void TakeAll();

	float GetBalance();

	void CloseAccount();

	int GetNumberOfAction() override;
	
};

