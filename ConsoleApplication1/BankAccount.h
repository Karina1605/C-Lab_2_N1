#pragma once
#include "Date.h"
#include "AccountInfo.h"
#include<string>
using namespace std;



//Класс одного аккаунта
class BankAccount
{
private:
	unsigned long int _numberOfCount;   // Номер счета
	unsigned int _password;				// Пароль
	string _ownerLastName;				// Фамилия владельца
	float _sum;							// Сумма на счете
	Date _opened;						// Дата открытия
	AccountInfo *_info;
	
public:
	//Конструкторы
	explicit BankAccount() ;
	BankAccount(string Owner, unsigned long int Number, unsigned int Password, Date Opened,
	 	AccountInfo *info, float Sum);
 	//Операторы сравнения (по дате и фамилии) 
	bool operator == (const string other) const;
	bool operator == (const Date other) const;
	bool operator <(const Date other) const;
	bool operator >(const Date other) const;
	bool operator <(const string otherLastName) const;
	bool operator >(const string otherLastName) const;
	
	//Методы-сеттеры
	void ResetPassword(unsigned int New);
	void SetLastname(string NewLastname);
	void PutSum(float Sum);
	void TakeSum(float Sum);
	void SetNumberOfAccount(unsigned long int number);
	void ResetSum();
	
	//Ввод-вывод на консоль, вынесены отдельно для удобочитаемости на консоли
	void InputNew();
	void Print();

	//информация о счете
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

	//Методы-геттеры
	float GetCurrentSum() const;
	Date GetOpenDate() const;
	string GetLastName() const;
	
	unsigned long int GetNumberOfAccount() const;
	
	bool CheckPassword(int pass);
	

	//Строковое представление
	string ToString() const;
	
	//Перегрузка операторов ввода-вывода
 	friend istream& operator>>(istream &s, BankAccount& BA);
	friend ostream& operator<<(ostream &s, const BankAccount& BA);

	~BankAccount();
};

