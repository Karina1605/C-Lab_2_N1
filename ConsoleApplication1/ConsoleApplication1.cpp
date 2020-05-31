#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include"Bank.h"
#include"Person.h"
#include"User.h"
#include"Manager.h"
#include"AccountInfoManager.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	AccountInfoManager *manager = AccountInfoManager::GetInstanse();
	Bank *bank = Bank::GetInstanse();
	//cout << "All\n";
	Person *person=nullptr;
	int action;
	cout << "Выберите режим\n1.Сотрудник\n2.Клиент\n3.Выйти\n";
	do
	{
		cin >> action;
		if (action < 1 || action>3)
			cout << "Ошибка, вы должны ввести число от 1 до 3\n";
	} while (action < 1 || action>3);
	switch (action)
	{
	case 1:
		person = new Manager();
		person->Work();
		break;
	case 2:
		person = new User();
		person->Work();
		break;
	case 3:
		cout << "До свидания\n";
		break;
	default:
		break;
	}

	bank->PutToFile();
	manager->PutToFile();
	delete bank;
	delete manager;
	getchar();
}

