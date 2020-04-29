#pragma once
#include "Date.h"
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
	float _percents;					// Проценты
	
public:
	//Конструкторы
	explicit BankAccount() ;
	BankAccount(string Owner, unsigned long int Number, unsigned int Password, Date Opened,
		float Percents, float Sum);
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
	void ResetSum();
	
	//Ввод-вывод на консоль, вынесены отдельно для удобочитаемости на консоли
	void InputNew();
	void Print();

	//Методы-геттеры
	float GetCurrentSum() const;
	float GetPercents() const;
	Date GetOpenDate() const;
	string GetLastName() const;
	unsigned long int GetNumberOfAccount() const;
	void SetPercents(float set);
	
	//Строковое представление
	string ToString() const;
	
	//Перегрузка операторов ввода-вывода
 	friend istream& operator>>(istream &s, BankAccount& BA);
	friend ostream& operator<<(ostream &s, BankAccount& BA);

	~BankAccount();
};

