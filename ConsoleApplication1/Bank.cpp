#include "pch.h"
#include "Bank.h"
#include<iostream>
#include <fstream>
#include <algorithm>

using namespace std;
Bank::Bank()
{
}

//Сортировка элементов
void Bank::Sort(TypesOfSort type)
{
	//Устанавливаем начальные и конечные итераторы основоного контейнера
	auto f = Clients.begin();
	auto l = Clients.end();
	BankAccount buf;
	//Просто строим новую multimap, тк он реализован как красно-черное дерево, поиск по нему стразу бинарный
	switch (type)
	{
	case LastNameSort:
		while (f!=l)
		{
			buf = (*f).second;
			helpLastName.emplace(buf.GetLastName(), buf);
			++f;
		}
		
	case DateSort:
		while (f != l)
		{
			buf = (*f).second;
			helpDate.emplace(buf.GetOpenDate(), buf);
			++f;
		}
	default:
		break;
	}
}

//2 метода добавления (с вводом и готовым элементом)
void Bank::Add()
{
	BankAccount acc;
	cin >> acc;
	Clients.emplace(acc.GetNumberOfAccount(), acc);
}
void Bank::Add(BankAccount NewAccount)
{
	Clients.emplace(NewAccount.GetNumberOfAccount(),  NewAccount);
}

//Изменить элемент
void Bank::Change(ulongint Number)
{
	//Ищем элемент по номеру счета, если такого нет -выход
	if (Clients.find(Number) == Clients.end())
	{
		cout << "Нет счета с таким номером\n";
		return;
	}
	//Иначе - получаем элемент
	BankAccount buff = Clients.at(Number);
	//Удаляем старый
	Clients.erase(Number);
	//Выбираем изменение
	int change = menu();
	//Вспомогательный переменный
	string ln;
	float sum;
	//Меняем выбранный параметр
	switch (change)
	{
	case 1:
		cout << "Новая фамлия : ";
		cin >> ln;
		buff.SetLastname(ln);
		break;
	case 2:
		cout << "Новая сумма счета : ";
		cin >> sum;
		buff.ResetSum();
		buff.PutSum(sum);
		break;
	case 3:
		cout << "Новый процент : ";
		cin >> sum;
		buff.SetPercents(sum);
		break;
	default:
		cout << "Некорректный номер операции\n";
		break;
	}
	//Перезаписываем обновленный элемент
	Clients.emplace(buff.GetNumberOfAccount(), buff);
}

void Bank::Remove(ulongint Number)
{
	Clients.erase(Number);
}

//Линейный поиск через итератор
bool Bank::Search(Date date)
{
	auto it = Clients.begin();
	bool res = false;
	while (it!=Clients.end() && !res)
	{
		BankAccount b = (*it).second;
		res = (b == date);
		it++;
	}
	return res;
}
bool Bank::Search(string Lastname)
{
	auto it = Clients.begin();
	bool res = false;
	while (it != Clients.end() && !res)
	{
		BankAccount buf = (*it).second;
		res = (buf == Lastname);
		it++;
	}
	return res;
}
bool Bank::Search(ulongint Number)
{
	return (Clients.find(Number)!=Clients.end());
}

//Поиск с предварительной сортировкой
bool Bank:: SearchBinary(Date date)
{
	Sort(DateSort);
	return (helpDate.find(date) != helpDate.end());
}
bool Bank::SearchBinary(string Lastname)
{
	Sort(LastNameSort);
	return (helpLastName.find(Lastname) != helpLastName.end());
}
bool Bank::SearchBinary(ulongint Number)
{
	return Search(Number);
}

//Запись в файл
void Bank:: PutToFile(ostream &out)
{
	auto it = Clients.begin();
	while (it!=Clients.end())
	{
		BankAccount b = (*it).second;
		out << b;
		it++;
	}	
}
//Чтение из файла
void Bank:: LoadFromFile(string FileName)
{
	Clients.clear();
	fstream fin;
	fin.open(FileName, ios::in);
	BankAccount buf;
	while (fin >> buf) {
		Clients.emplace(buf.GetNumberOfAccount(), buf);
	}
		
	fin.close();
}


//Выборка по фамилии
list<BankAccount> Bank::GetAllByName(string LastName) 
{
	Sort(LastNameSort);
	list<BankAccount> res;
	auto r = helpLastName.equal_range(LastName);
	for (auto it = r.first; it != r.second; ++it)
	{
		BankAccount buf = (*it).second;
		res.emplace_back(buf);
	}
		
	return res;
}

//Выборка по дате открытия счета
list<BankAccount> Bank:: GetAllByDate(Date opened) 
{
	Sort(DateSort);
	list<BankAccount> res;
	auto r = helpDate.equal_range(opened);
	for (auto it = r.first; it != r.second; ++it)
	{
		BankAccount buf = (*it).second;
		res.emplace_back(buf);
	}
		
	return res;
}

//Печать всех аккаунтов
void Bank::Print()
{
	auto it = Clients.begin();
	while (it!=Clients.end())
	{
		(*it).second.Print();
		++it;
	}
}
Bank::~Bank()
{
}
//Меню для изменения
int Bank:: menu()
{
	cout << "1.Изменить фамилию владельца\n2.Изменить сумму на счете\n3.Изменить проценты\n";
	int res;
	cin >> res;
	return res;
}