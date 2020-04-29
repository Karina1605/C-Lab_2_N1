#include "pch.h"
#include "Bank.h"
#include<iostream>
#include <fstream>
#include <algorithm>

using namespace std;
Bank::Bank()
{
}

//���������� ���������
void Bank::Sort(TypesOfSort type)
{
	//������������� ��������� � �������� ��������� ���������� ����������
	auto f = Clients.begin();
	auto l = Clients.end();
	BankAccount buf;
	//������ ������ ����� multimap, �� �� ���������� ��� ������-������ ������, ����� �� ���� ������ ��������
	switch (type)
	{
	case LastNameSort:
		while (f!=l)
		{
			buf = (*f).second;
			helpLastName.emplace(buf.GetLastName(), buf);
			++f;
		}
		
	case DateSort:
		while (f != l)
		{
			buf = (*f).second;
			helpDate.emplace(buf.GetOpenDate(), buf);
			++f;
		}
	default:
		break;
	}
}

//2 ������ ���������� (� ������ � ������� ���������)
void Bank::Add()
{
	BankAccount acc;
	cin >> acc;
	Clients.emplace(acc.GetNumberOfAccount(), acc);
}
void Bank::Add(BankAccount NewAccount)
{
	Clients.emplace(NewAccount.GetNumberOfAccount(),  NewAccount);
}

//�������� �������
void Bank::Change(ulongint Number)
{
	//���� ������� �� ������ �����, ���� ������ ��� -�����
	if (Clients.find(Number) == Clients.end())
	{
		cout << "��� ����� � ����� �������\n";
		return;
	}
	//����� - �������� �������
	BankAccount buff = Clients.at(Number);
	//������� ������
	Clients.erase(Number);
	//�������� ���������
	int change = menu();
	//��������������� ����������
	string ln;
	float sum;
	//������ ��������� ��������
	switch (change)
	{
	case 1:
		cout << "����� ������ : ";
		cin >> ln;
		buff.SetLastname(ln);
		break;
	case 2:
		cout << "����� ����� ����� : ";
		cin >> sum;
		buff.ResetSum();
		buff.PutSum(sum);
		break;
	case 3:
		cout << "����� ������� : ";
		cin >> sum;
		buff.SetPercents(sum);
		break;
	default:
		cout << "������������ ����� ��������\n";
		break;
	}
	//�������������� ����������� �������
	Clients.emplace(buff.GetNumberOfAccount(), buff);
}

void Bank::Remove(ulongint Number)
{
	Clients.erase(Number);
}

//�������� ����� ����� ��������
bool Bank::Search(Date date)
{
	auto it = Clients.begin();
	bool res = false;
	while (it!=Clients.end() && !res)
	{
		BankAccount b = (*it).second;
		res = (b == date);
		it++;
	}
	return res;
}
bool Bank::Search(string Lastname)
{
	auto it = Clients.begin();
	bool res = false;
	while (it != Clients.end() && !res)
	{
		BankAccount buf = (*it).second;
		res = (buf == Lastname);
		it++;
	}
	return res;
}
bool Bank::Search(ulongint Number)
{
	return (Clients.find(Number)!=Clients.end());
}

//����� � ��������������� �����������
bool Bank:: SearchBinary(Date date)
{
	Sort(DateSort);
	return (helpDate.find(date) != helpDate.end());
}
bool Bank::SearchBinary(string Lastname)
{
	Sort(LastNameSort);
	return (helpLastName.find(Lastname) != helpLastName.end());
}
bool Bank::SearchBinary(ulongint Number)
{
	return Search(Number);
}

//������ � ����
void Bank:: PutToFile(ostream &out)
{
	auto it = Clients.begin();
	while (it!=Clients.end())
	{
		BankAccount b = (*it).second;
		out << b;
		it++;
	}	
}
//������ �� �����
void Bank:: LoadFromFile(string FileName)
{
	Clients.clear();
	fstream fin;
	fin.open(FileName, ios::in);
	BankAccount buf;
	while (fin >> buf) {
		Clients.emplace(buf.GetNumberOfAccount(), buf);
	}
		
	fin.close();
}


//������� �� �������
list<BankAccount> Bank::GetAllByName(string LastName) 
{
	Sort(LastNameSort);
	list<BankAccount> res;
	auto r = helpLastName.equal_range(LastName);
	for (auto it = r.first; it != r.second; ++it)
	{
		BankAccount buf = (*it).second;
		res.emplace_back(buf);
	}
		
	return res;
}

//������� �� ���� �������� �����
list<BankAccount> Bank:: GetAllByDate(Date opened) 
{
	Sort(DateSort);
	list<BankAccount> res;
	auto r = helpDate.equal_range(opened);
	for (auto it = r.first; it != r.second; ++it)
	{
		BankAccount buf = (*it).second;
		res.emplace_back(buf);
	}
		
	return res;
}

//������ ���� ���������
void Bank::Print()
{
	auto it = Clients.begin();
	while (it!=Clients.end())
	{
		(*it).second.Print();
		++it;
	}
}
Bank::~Bank()
{
}
//���� ��� ���������
int Bank:: menu()
{
	cout << "1.�������� ������� ���������\n2.�������� ����� �� �����\n3.�������� ��������\n";
	int res;
	cin >> res;
	return res;
}