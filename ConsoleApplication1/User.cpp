#include "pch.h"
#include "User.h"
#include"Bank.h"
#include "AccountInfoManager.h"
#include<iostream>

using namespace std;

User::User()
{
	CurrentAccount = nullptr;
}


void User::AddSum(float sum)
{
	CurrentAccount->PutSum(sum);
}
bool User::LogIn()
{
	unsigned long int number;
	string Lastname;
	int Password;
	cout << "Введите номер счета: ";
	cin >> number;
	cout << "Введите фамилию владельца: ";
	cin >> Lastname;
	getchar();
	cout << "Введите пароль: ";
	cin >> Password;
	this->CurrentAccount = Bank::GetInstanse()->GetForEdit(number, Lastname, Password);
	if (CurrentAccount == nullptr)
	{
		cout << "Неверно введено одно или несколько полей\n";
		return false;
	}
	return true;
}

void User::TakeAll()
{
	float s = CurrentAccount->GetCurrentSum();
	CurrentAccount->ResetSum();
	cout << "Снято " << s << '\n';
}
void User::CreateAccount()
{
	CurrentAccount = new BankAccount();
	unsigned long int number = Bank::GetInstanse()->GenerateNumber();
	CurrentAccount->SetNumberOfAccount(number);
	CurrentAccount->InputNew();

	Bank::GetInstanse()->Add(*CurrentAccount);
}

void User::GetInfoAccount()
{
	cout << "Название: " << CurrentAccount->GetName();
	cout << " Процент: " << CurrentAccount->GetPercent();
	cout << " Можно ли снимать частями: " << CurrentAccount->GetAbilityToTakeAPart();
	cout << '\n';
}
void User::CloseAccount()
{
	Bank::GetInstanse()->Remove(CurrentAccount->GetNumberOfAccount());
	CurrentAccount = nullptr;
}
void User::TakeSum(float sum)
{
	CurrentAccount->TakeSum(sum);
}
float User::GetBalance()
{
	return CurrentAccount->GetCurrentSum();
}

int User::GetNumberOfAction()
{
	int res = 0;
	if (CurrentAccount == nullptr)
	{
		cout << "1.Перейти к существующему счету\n";
		cout << "2.Открыть новый счет\n";
		cout << "0.выход\n";
		do
		{
			cin >> res;
			if (res < 0 || res>2)
				cout << "Ошибка, вы должны ввести число от 0 до 2\n";
		} while (res < 0 || res>2);
		return res;
	}
	else
	{
		getchar();
		cout << "1.Положить сумму\n";
		cout << "2.Снять сумму\n";
		cout << "3.Снять все\n";
		cout << "4.Узнать баланс\n";
		cout << "5.Получить информацию о счете\n";
		cout << "6.Закрыть счет\n";
		cout << "0.Выйти\n";
		do
		{
			cin >> res;
			if (res < 0 || res>6)
				cout << "Ошибка, вы должны ввести число от 0 до 6\n";
		} while (res < 0 || res>6);
		return res;
	}

}
void User::PerformAction(int num)
{
	float buf;
	if (CurrentAccount == nullptr)
		switch (num)
		{
		case 1: LogIn();
			break;
		case 2:
			CreateAccount();
			break;
		case 0:cout << "До свидания";
			break;
		}
	else
	{

		switch (num)
		{
		case 1:
			if (CurrentAccount == nullptr)
				cout << "Аккаунт недействителен\n";
			else
			{
				cout << "Введите сумму: ";
				cin >> buf;
				AddSum(buf);
				cout << "Сумма добавлена, текущий баланс: " << CurrentAccount->GetCurrentSum() << "\n";
			}
			
			break;
		case 2:
			if (CurrentAccount == nullptr)
				cout << "Аккаунт недействителен\n";
			else
			{
				cout << "Введите сумму: ";
				cin >> buf;
				TakeSum(buf);
				cout << "Текущий баланс: " << CurrentAccount->GetCurrentSum() << "\n";
			}
			break;
		case 3:
			if (CurrentAccount == nullptr)
				cout << "Аккаунт недействителен\n";
			else
			{
				TakeAll();
				cout << "Деньги сняты\n";
			}
			break;
		case 4:
			if (CurrentAccount == nullptr)
				cout << "Аккаунт недействителен\n";
			else
				cout<<"Баланс: "<<GetBalance()<<"\n";
			break;
		case 5:
			if (CurrentAccount == nullptr)
				cout << "Аккаунт недействителен\n";
			else
				GetInfoAccount();
			break;
		case 6:
			if (CurrentAccount == nullptr)
				cout << "Аккаунт недействителен\n";
			else
			{
				CloseAccount();
				cout << "Аккаунт закрыт\n";
			}
			break;
		case 0:
			cout << "До свидания\n";
			break;
		}
	}
		
}
User::~User()
{
}
