#pragma once
#include "Date.h"
#include<string>
using namespace std;
//����� ������ ��������
class BankAccount
{
private:
	unsigned long int _numberOfCount;   // ����� �����
	unsigned int _password;				// ������
	string _ownerLastName;				// ������� ���������
	float _sum;							// ����� �� �����
	Date _opened;						// ���� ��������
	float _percents;					// ��������
	
public:
	//������������
	explicit BankAccount() ;
	BankAccount(string Owner, unsigned long int Number, unsigned int Password, Date Opened,
		float Percents, float Sum);
 	//��������� ��������� (�� ���� � �������) 
	bool operator == (const string other) const;
	bool operator == (const Date other) const;
	bool operator <(const Date other) const;
	bool operator >(const Date other) const;
	bool operator <(const string otherLastName) const;
	bool operator >(const string otherLastName) const;
	
	//������-�������
	void ResetPassword(unsigned int New);
	void SetLastname(string NewLastname);
	void PutSum(float Sum);
	void TakeSum(float Sum);
	void ResetSum();
	
	//����-����� �� �������, �������� �������� ��� ��������������� �� �������
	void InputNew();
	void Print();

	//������-�������
	float GetCurrentSum() const;
	float GetPercents() const;
	Date GetOpenDate() const;
	string GetLastName() const;
	unsigned long int GetNumberOfAccount() const;
	void SetPercents(float set);
	
	//��������� �������������
	string ToString() const;
	
	//���������� ���������� �����-������
 	friend istream& operator>>(istream &s, BankAccount& BA);
	friend ostream& operator<<(ostream &s, BankAccount& BA);

	~BankAccount();
};

