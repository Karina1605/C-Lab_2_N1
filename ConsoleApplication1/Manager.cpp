#include "pch.h"
#include "Manager.h"
#include "AccountInfoManager.h"
#include"Bank.h"
#include<list>
#include<fstream>

Manager::Manager()
{
}
void Manager::EditAccountInfo()
{
	AccountInfo* editintg = AccountInfoManager::GetInstanse()->Chose();
	cout << "in edit, found " << editintg->GetName()<<"\n";
	int pos = 0;
	int p;
	string name;
	float buf;
	do
	{
		cout << "1.�������� �������� ���� ������\n";
		cout << "2.�������� ������� �� ������\n";
		cout << "3.�������� ����������� ���������� ������ �����\n";
		cout << "0.���������\n";
		do
		{
			cin >> pos;
			if (pos < 0 || pos>3)
				cout << "������, �� ������ ������ ����� �� 0 �� 3\n";
		} while (pos < 0 || pos>3);
		switch (pos)
		{
		case 1:
			cout<< "����� �������� ����: ";
			cin >> name;
			getchar();
			editintg->SetName(name);
			break;
		case 2:
			cout << "������� ����� �������: ";
			cin >> buf;
			editintg->SetPercent(buf);
			break;
		case 3:
			cout << "1.����� ������� �������\n";
			cout << "2.������ ������� �������\n";
			do
			{
				cin >> p;
				if (p < 1 || p>2)
					cout << "������� ����� �� 1 �� 2\n";
			} while (p < 1 || p>2);
			editintg->SetCanTakeAPart(p == 1);
			break;
		default:
			break;
		}
	} while (pos != 0);
}
list<BankAccount> Manager::GetAllByName(string Name)
{
	list<BankAccount> res = Bank::GetInstanse()->GetAllByName(Name);
	return res;
}
list<BankAccount> Manager::GetAllByDate(Date date)
{
	list<BankAccount>res = Bank::GetInstanse()->GetAllByDate(date);
	return res;
}
BankAccount Manager:: FindByNumber(unsigned long int Number)
{
	BankAccount res = Bank::GetInstanse()->GetByNumber(Number);
	return res;
}

void Manager:: PerformAction(int num) 
{
	list<BankAccount> accounts;
	Date searching;
	BankAccount acc;
	string lastname;
	float percents;
	bool CanTakeAPart;
	int buf;
	ulongint number;
	switch (num)
	{
	case 1:
		EditAccountInfo();
		break;
	case 2:
		cout << "�������� �����: ";
		cin >> lastname;
		getchar();
		cout << "�������: ";
		cin >> percents;
		cout << "����� ������� ����� ����� (1 - ��, 0 - ���): ";
		cin >> buf;
		CanTakeAPart = buf == 1;
		AccountInfoManager::GetInstanse()->AddNew(lastname, percents, CanTakeAPart);
		break;
	case 3:
		Bank::GetInstanse()->Print();
		break;
	case 4:
		searching.InputNew();
		accounts = GetAllByDate(searching);
		outputSomeRecords(accounts);
		break;
	case 5:
		cout << "�������: ";
		cin >> lastname;
		getchar();
		accounts = GetAllByName(lastname);
		outputSomeRecords(accounts);
		break;
	case 6:
		cout << "����� �����: ";
		cin >> number;
		acc = FindByNumber(number);
		if (acc.GetNumberOfAccount() == -1)
			cout << "��� ����� � ����� �������\n";
		else
			acc.Print();
		break;
	case 0:
		cout << "�� ��������\n";
		break;
	default:
		break;
	}

}
int Manager::GetNumberOfAction()
{
	cout << "1.������������� ���� ������\n";
	cout << "2.�������� ����� ��� �����\n";
	cout << "3.����������� ��� �����\n";
	cout << "4.����� ��� ����� � �������� ����� ��������\n";
	cout << "5.����� ��� ����� � �������� �������� ���������\n";
	cout << "6.����� ���� �� ������\n";
	cout << "0.�����\n";
	int res = 0;
	do
	{
		cin >> res;
		if (res < 0 || res>6)
			cout << "������, �� ������ ������ ����� �� 0 �� 6\n";
	} while (res < 0 || res>6);
	return res;
}

void Manager:: outputSomeRecords(list<BankAccount>&elems)
{
	cout << "������� �� ����� (1) ��� � ���� (2)?\n";
	int res;
	cin >> res;
	auto it = elems.begin();
	string Filename;
	fstream f;
	switch (res) {
	case 1:
		while (it != elems.end())
		{
			cout << (*it) << '\n';
			++it;
		}
		break;
	case 2:
		getchar();
		cout << "��� ����� : ";
		getline(cin, Filename);
		f.open(Filename, ios::out);
		while (it != elems.end())
		{
			f << (*it) << '\n';
			++it;
		}
		f.close();
		break;
	}
}


Manager::~Manager()
{
}
