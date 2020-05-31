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
	cout << "������� ����� �����: ";
	cin >> number;
	cout << "������� ������� ���������: ";
	cin >> Lastname;
	getchar();
	cout << "������� ������: ";
	cin >> Password;
	this->CurrentAccount = Bank::GetInstanse()->GetForEdit(number, Lastname, Password);
	if (CurrentAccount == nullptr)
	{
		cout << "������� ������� ���� ��� ��������� �����\n";
		return false;
	}
	return true;
}

void User::TakeAll()
{
	float s = CurrentAccount->GetCurrentSum();
	CurrentAccount->ResetSum();
	cout << "����� " << s << '\n';
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
	cout << "��������: " << CurrentAccount->GetName();
	cout << " �������: " << CurrentAccount->GetPercent();
	cout << " ����� �� ������� �������: " << CurrentAccount->GetAbilityToTakeAPart();
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
		cout << "1.������� � ������������� �����\n";
		cout << "2.������� ����� ����\n";
		cout << "0.�����\n";
		do
		{
			cin >> res;
			if (res < 0 || res>2)
				cout << "������, �� ������ ������ ����� �� 0 �� 2\n";
		} while (res < 0 || res>2);
		return res;
	}
	else
	{
		getchar();
		cout << "1.�������� �����\n";
		cout << "2.����� �����\n";
		cout << "3.����� ���\n";
		cout << "4.������ ������\n";
		cout << "5.�������� ���������� � �����\n";
		cout << "6.������� ����\n";
		cout << "0.�����\n";
		do
		{
			cin >> res;
			if (res < 0 || res>6)
				cout << "������, �� ������ ������ ����� �� 0 �� 6\n";
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
		case 0:cout << "�� ��������";
			break;
		}
	else
	{

		switch (num)
		{
		case 1:
			if (CurrentAccount == nullptr)
				cout << "������� ��������������\n";
			else
			{
				cout << "������� �����: ";
				cin >> buf;
				AddSum(buf);
				cout << "����� ���������, ������� ������: " << CurrentAccount->GetCurrentSum() << "\n";
			}
			
			break;
		case 2:
			if (CurrentAccount == nullptr)
				cout << "������� ��������������\n";
			else
			{
				cout << "������� �����: ";
				cin >> buf;
				TakeSum(buf);
				cout << "������� ������: " << CurrentAccount->GetCurrentSum() << "\n";
			}
			break;
		case 3:
			if (CurrentAccount == nullptr)
				cout << "������� ��������������\n";
			else
			{
				TakeAll();
				cout << "������ �����\n";
			}
			break;
		case 4:
			if (CurrentAccount == nullptr)
				cout << "������� ��������������\n";
			else
				cout<<"������: "<<GetBalance()<<"\n";
			break;
		case 5:
			if (CurrentAccount == nullptr)
				cout << "������� ��������������\n";
			else
				GetInfoAccount();
			break;
		case 6:
			if (CurrentAccount == nullptr)
				cout << "������� ��������������\n";
			else
			{
				CloseAccount();
				cout << "������� ������\n";
			}
			break;
		case 0:
			cout << "�� ��������\n";
			break;
		}
	}
		
}
User::~User()
{
}
