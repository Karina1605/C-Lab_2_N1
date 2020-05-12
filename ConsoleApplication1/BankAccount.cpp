#include "pch.h"
#include "BankAccount.h"
#include<iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <cstddef>

using namespace std;
BankAccount::BankAccount()
{
}
BankAccount::BankAccount(string Owner, unsigned long int Number, unsigned int Password, Date Opened,
	float Percents, float Sum)
{
	_ownerLastName = Owner;
	_numberOfCount = Number;
	_password = Password;
	_opened = Opened;
	_percents = Percents;
	_sum = Sum;
}

//���������� ���������� ���������
bool BankAccount:: operator == (const string other) const
{
	return(!_ownerLastName.compare(other));
}
bool BankAccount:: operator == (const Date other) const
{
	return (_opened == other);
}
bool BankAccount:: operator <(const Date other) const
{
	return	_opened < other;
}
bool BankAccount:: operator >(const Date other) const
{
	return _opened > other;
}
bool BankAccount:: operator <(const  string otherLastName) const
{
	return _ownerLastName < otherLastName;
}
bool BankAccount:: operator >(const string otherLastName)const
{
	return _ownerLastName > otherLastName;
}

//�������
void BankAccount::ResetPassword(unsigned int New)
{
	_password = New;
	cout << "������ �������\n";

}
void BankAccount::SetLastname(string NewLastname)
{
	_ownerLastName = NewLastname;
	cout << "������� ��������\n";
}
void BankAccount::PutSum(float Sum)
{
	_sum += Sum;
	cout << "����� ����� ���������\n";
}
void BankAccount::TakeSum(float Sum)
{
	if (Sum > _sum)
		cout << "�����, ������� �� ������ �����, ������� ������\n";
	else
		_sum -= Sum;
}

//�������
float BankAccount::GetCurrentSum() const
{
	return _sum;
}
float BankAccount::GetPercents() const
{
	return _percents;
}
Date BankAccount::GetOpenDate() const
{
	return _opened;
}
string BankAccount::GetLastName() const
{
	return _ownerLastName;
}
unsigned long int BankAccount::GetNumberOfAccount() const
{
	return _numberOfCount;
}


string BankAccount::ToString() const
{
	stringstream res;
	res << _ownerLastName << " " << _numberOfCount << " " << _opened.ToString();
	return res.str();
}

istream& operator>>(istream &s, BankAccount &BA)
{
	s >>BA._ownerLastName;
	s >>BA._numberOfCount;
	s >>BA._password;
	s >>BA._opened;
	s >>BA._sum;
	s >>BA._percents;
	//do
	//{
//
	//} while (s.get() != '\n');
	
	//string c;
	//s >> c;
	return s;
}
ostream& operator<<(ostream &s, const BankAccount& BA)
{ 
	s <<BA._ownerLastName<<" ";
	s <<BA._numberOfCount<<" ";
	s <<BA._password<<" ";
	s <<BA._opened<<" ";
	s << BA._sum << " ";
	s <<BA._percents<<"\n";
	return s;
}

void BankAccount::InputNew()
{
	cout << "������� : ";
	cin >> this->_ownerLastName;
	getchar();
	cout << "����� ����� : ";
	cin >> this->_numberOfCount;
	cout << "������ : ";
	cin >> this->_password;
	cout << "���� �������� : ";
	this->_opened.InputNew();
	cout << "����� : ";
	cin >> this->_sum;
	cout << "�������� : ";
	cin >> this->_percents;
}
void BankAccount:: Print()
{
	
	cout << "������� : "<< this->_ownerLastName<<'\n';
	cout << "����� ����� : "<< this->_numberOfCount << '\n';
	cout << "������ : "<< this->_password << '\n';
	cout << "���� �������� : "<< this->_opened.ToString() << '\n';
	cout << "����� : "<< this->_sum << '\n';
	cout << "�������� : "<< this->_percents << "\n\n";
}

void BankAccount ::ResetSum()
{
	_sum = 0;
}
void BankAccount ::SetPercents(float set)
{
	_percents = set;
}

BankAccount::~BankAccount()
{
}
