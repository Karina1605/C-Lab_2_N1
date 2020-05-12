#pragma once
#include <string>
#include <iostream>

using namespace std;
//����� ����
class Date
{
private:
	//����, �����, ���
	unsigned short int _dd;
	unsigned short int _mm;
	unsigned int _yyyy;
	//�������� ���� �� ������������
	bool IsLeapYear();
	//�������� ���-�� ���� � ������
	int GetDaysInMonth();
	//�������� ���� �� ������������
	bool IsCorrectDate();
public:
	//������������� (�� ����� - 01.01.1970)
	Date();
	Date(unsigned short int dd, unsigned short int mm, unsigned int yyyy);
	//���������� ���������� ���������
	bool operator ==(const Date other) const;
	bool operator <(const Date other) const;
	bool operator >(const Date other) const;
	//���� ����� ���� � �������
	void InputNew();
	
	//���������� ���������� ��������� �����-������
	friend istream& operator>>(istream& in, Date& date);
	friend ostream& operator<<(ostream& out, const Date& date);
	//��������� ������������� ����
	string ToString() const;
	~Date();
};

