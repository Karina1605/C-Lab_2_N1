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

//Перегрузка операторов сравнения
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

//Сеттеры
void BankAccount::ResetPassword(unsigned int New)
{
	_password = New;
	cout << "Пароль изменен\n";

}
void BankAccount::SetLastname(string NewLastname)
{
	_ownerLastName = NewLastname;
	cout << "Фамилия изменена\n";
}
void BankAccount::PutSum(float Sum)
{
	_sum += Sum;
	cout << "Сумма счета обновлена\n";
}
void BankAccount::TakeSum(float Sum)
{
	if (Sum > _sum)
		cout << "Сумма, которую вы хотите снять, слишком велика\n";
	else
		_sum -= Sum;
}

//Геттеры
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
	cout << "Фамилия : ";
	cin >> this->_ownerLastName;
	getchar();
	cout << "Номер счета : ";
	cin >> this->_numberOfCount;
	cout << "Пароль : ";
	cin >> this->_password;
	cout << "Дата открытия : ";
	this->_opened.InputNew();
	cout << "Сумма : ";
	cin >> this->_sum;
	cout << "Проценты : ";
	cin >> this->_percents;
}
void BankAccount:: Print()
{
	
	cout << "Фамилия : "<< this->_ownerLastName<<'\n';
	cout << "Номер счета : "<< this->_numberOfCount << '\n';
	cout << "Пароль : "<< this->_password << '\n';
	cout << "Дата открытия : "<< this->_opened.ToString() << '\n';
	cout << "Сумма : "<< this->_sum << '\n';
	cout << "Проценты : "<< this->_percents << "\n\n";
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
