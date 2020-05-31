#pragma once
#include "Date.h"
#include "AccountInfo.h"
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
	AccountInfo *_info;
	
public:
	//������������
	explicit BankAccount() ;
	BankAccount(string Owner, unsigned long int Number, unsigned int Password, Date Opened,
	 	AccountInfo *info, float Sum);
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
	void SetNumberOfAccount(unsigned long int number);
	void ResetSum();
	
	//����-����� �� �������, �������� �������� ��� ��������������� �� �������
	void InputNew();
	void Print();

	//���������� � �����
	string GetName() const
	{
		return _info->GetName();
	}
	float GetPercent() const
	{
		return _info->GetPercents();

	}
	bool GetAbilityToTakeAPart()
	{
		return _info->GetCanTakeAPart();
	}

	//������-�������
	float GetCurrentSum() const;
	Date GetOpenDate() const;
	string GetLastName() const;
	
	unsigned long int GetNumberOfAccount() const;
	
	bool CheckPassword(int pass);
	

	//��������� �������������
	string ToString() const;
	
	//���������� ���������� �����-������
 	friend istream& operator>>(istream &s, BankAccount& BA);
	friend ostream& operator<<(ostream &s, const BankAccount& BA);

	~BankAccount();
};

