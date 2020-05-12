#pragma once
#include <string>
#include <iostream>

using namespace std;
//Класс даты
class Date
{
private:
	//день, месяц, год
	unsigned short int _dd;
	unsigned short int _mm;
	unsigned int _yyyy;
	//Проврека года на високосность
	bool IsLeapYear();
	//Получить кол-во дней в месяце
	int GetDaysInMonth();
	//Проверка даты на корректность
	bool IsCorrectDate();
public:
	//Констркукторы (по умолч - 01.01.1970)
	Date();
	Date(unsigned short int dd, unsigned short int mm, unsigned int yyyy);
	//Перегрузка операторов сравнения
	bool operator ==(const Date other) const;
	bool operator <(const Date other) const;
	bool operator >(const Date other) const;
	//Ввод новой даты с консоли
	void InputNew();
	
	//Перегрузка операторов поточного ввода-вывода
	friend istream& operator>>(istream& in, Date& date);
	friend ostream& operator<<(ostream& out, const Date& date);
	//Строковое представление даты
	string ToString() const;
	~Date();
};

