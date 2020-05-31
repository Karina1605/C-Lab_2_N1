#include "pch.h"
#include "Date.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//����������� �����������
Date::Date()
{
	_dd = 1;
	_mm = 1;
	_yyyy = 1970;
}
//�����������, ������������� ����������
Date::Date(unsigned short int dd, unsigned short int mm, unsigned int yyyy)
{
	if (yyyy < 1970 || yyyy>2020)
		throw exception("Incorrect date");
	_yyyy = yyyy;
	if (mm == 0 || mm > 12)
		throw exception("Incorrect date");
	_mm = mm;
	int countOfDays = GetDaysInMonth();
	if (dd == 0 || dd > countOfDays)
		throw exception("Incorrect date");
	_dd = dd;
}
//��������� ���������
bool Date :: operator ==(const Date other) const
{
	return (_dd == other._dd) && (_mm == other._mm) && (_yyyy == other._yyyy);
}
bool Date:: operator <(const Date other) const
{
	if (_yyyy < other._yyyy)
		return true;
	if (_yyyy == other._yyyy)
	{
		if (_mm < other._mm)
			return true;
		if (_mm == other._mm)
			if (_dd < other._dd)
				return true;
		return false;
	}
	return false;
}
bool Date :: operator >(const Date other) const
{
	return !(*this < other);
}
//����������
Date::~Date()
{
}
//��������������� ������ ��� �������� ������������ ����
bool Date::IsLeapYear()
{
	return (_yyyy % 4 == 0 || (_yyyy % 100 == 0 && _yyyy % 400 != 0));
}
int Date::GetDaysInMonth()
{
	switch (_mm)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return 20 + IsLeapYear();
	default:
		return 0;
	}
}
bool Date::IsCorrectDate() {
	return (_yyyy >= 2000 && _mm >= 1 && _mm <= 12 && _dd >= 1 && _dd << GetDaysInMonth());
}

/*int Date:: operator - (const Date& other) const
{
	Date buf;
	if ((*this) < other)
		throw exception("������ ������� �� ������� ���� �������");
	buf = *this;
	int previousDays = buf.GetDaysInMonth() - buf._dd;
	while ( buf._yyyy!=other._yyyy && buf._mm!=other._mm)
	{
		days += buf.GetDaysInMonth() - previousDays; 
		if (buf._mm == 12)
		{
			buf._yyyy++;
			buf._mm = 1;
		}
		else
			buf._mm++;
	}
}*/

//��������� ������������� ����
string Date::ToString() const
{
	stringstream str;
	if (_dd < 10)
		str << '0';
	str << _dd << '.';
	if (_mm < 10)
		str << '0';
	str << _mm << '.';
	str << _yyyy;
	return str.str();
}
//���������� ���������� ���������� �����-������
istream& operator>>(istream& in, Date& date)
{
	char s;
	in >> date._dd;
	in >> s;
	in >> date._mm;
	in >> s;
	in >> date._yyyy;
	return in;
}
ostream& operator<<(ostream& out, const Date& date)
{
	out << date.ToString();
	return out;
}
//���� ����� ���� � �������
void Date::InputNew() 
{
	cout << "���� : ";
	cin >> this->_dd;
	cout << "����� : ";
	cin >> this->_mm;
	cout << "��� : ";
	cin >> this->_yyyy;
}


