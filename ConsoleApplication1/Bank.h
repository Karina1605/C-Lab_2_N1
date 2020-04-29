#pragma once
#include"BankAccount.h"
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <iterator>
using ulongint = unsigned long int;
using namespace std;
//���������� ��� ��������, �� �������� �����������
enum TypesOfSort
{
	LastNameSort, DateSort
};

//����� �����
class Bank
{
private:
	//������ ��������� map, �� � ����� ������ ������ ���������, ���� ����� �������������
	map<ulongint, BankAccount> Clients;
	//��������������� ���������� ��� ���������� �� ������� � ���� ��������
	multimap<string, BankAccount> helpLastName;
	multimap<Date, BankAccount>helpDate;
	//����������
	void Sort(TypesOfSort type);
	//���� ��������� ������ ��������
	int menu();
public:
	//�����������
	Bank();
	//���������� �����
	void Add();
	void Add(BankAccount NewAccount);
	
	//�������� ��������� �����
	void Change(ulongint Number);
	
	//������� ����
	void Remove(ulongint Number);
	
	//�������� ����� �� ������-���� ��������
	bool Search(Date date);
	bool Search(string LastName);
	bool Search(ulongint Number);
	
	//�������� ����� � ��������������� ����������
	bool SearchBinary(Date date);
	bool SearchBinary(string LastName);
	bool SearchBinary(ulongint Number);
	
	//������ �� �����
	void Print();
	
	//������� ���� ���������, ���������� �� ��������, ������ ��������� ������� �� ������, �� �� ������������
	list<BankAccount> GetAllByName(string LastName);
	list<BankAccount> GetAllByDate(Date opened);
	
	//�������� �� �����/������ � ����
	void PutToFile(ostream &out);
	void LoadFromFile(string FileName);
	
	
	~Bank();
};

