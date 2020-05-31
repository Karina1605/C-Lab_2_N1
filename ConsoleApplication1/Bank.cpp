#include "pch.h"
#include "Bank.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

string Bank:: FileForStoring="BankInfo.txt";
Bank::Bank()
{
}
Bank::Bank(string filename)
{
	LoadFromFile(filename);
}

Bank* Bank::single = nullptr;
Bank* Bank::GetInstanse()
{
	if (single == nullptr)
		single = new Bank(FileForStoring);
	return single;
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


BankAccount* Bank::GetForEdit(unsigned long int Number, string LastName, int Password)
{
	auto it = Clients.find(Number);
	if (it == Clients.end())
		return nullptr;
	if ((*it).second.GetLastName() == LastName && (*it).second.CheckPassword(Password))
		return &((*it).second);
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
void Bank:: PutToFile()
{
	fstream outf;
	outf.open(FileForStoring, ios::out);
	ostream_iterator<BankAccount> out_it(outf);
	auto it = Clients.begin();
	while (it!=Clients.end())
	{
		*out_it = (*it).second;
		//out_it++;
		//BankAccount b = (*it).second;
		//out << b;
		it++;
	}	
	outf.close();
}
//������ �� �����
void Bank:: LoadFromFile(string FileName)
{
	Clients.clear();
	fstream fin;
	fin.open(FileName);
	BankAccount buf;
	istream_iterator<BankAccount> B_it(fin);
	istreambuf_iterator<BankAccount> end();
	while (!fin.eof())
	{
		Clients.emplace((*B_it).GetNumberOfAccount(), (*B_it));
		B_it++;
	}
	
	fin.close();
}

BankAccount Bank::GetByNumber(ulongint number)
{
	auto it = Clients.find(number);
	if (it != Clients.end())
	return (*it).second;
	BankAccount empty;
	empty.SetNumberOfAccount(-1);
	return empty;
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

unsigned long int Bank::GenerateNumber()
{
	unsigned long int n = 0;
	bool stop = false;
	do
	{
		n = rand();
		stop = !this->Search(n);
	} while (!stop);
	return n;
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