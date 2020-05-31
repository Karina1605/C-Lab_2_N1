#pragma once
#include"BankAccount.h"
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <iterator>
using ulongint = unsigned long int;
using namespace std;
//Передаются как параметр, по которому сортировать
enum TypesOfSort
{
	LastNameSort, DateSort
};

//Класс банка
class Bank
{
private:
	//Выбран контейнер map, тк в банке номера счетов уникальны, плюс сразу отсортировано
	map<ulongint, BankAccount> Clients;
	//Вспомогательные контейнеры для сортировки по фамилии и дате открытия
	multimap<string, BankAccount> helpLastName;
	multimap<Date, BankAccount>helpDate;
	//Сортировка
	void Sort(TypesOfSort type);
	//Меню изменения одного элемента
	int menu();
	static Bank* single;
	//Конструктор
	Bank();
	Bank(const Bank&) = delete;
	Bank& operator = (Bank&) = delete;
	Bank(string fileName);
	
	static string FileForStoring;
	

	void LoadFromFile(string FileName);
public:
	
	unsigned long int GenerateNumber();
	static Bank* GetInstanse();
	//Добавление счета
	void Add();
	void Add(BankAccount NewAccount);
	
	//Изменить параметры счета
	void Change(ulongint Number);
	
	//Удалить счет
	void Remove(ulongint Number);
	
	//Линейный поиск по какому-либо критерию
	bool Search(Date date);
	bool Search(string LastName);
	bool Search(ulongint Number);
	
	//Бинарный поиск в отсортированном контейнере
	bool SearchBinary(Date date);
	bool SearchBinary(string LastName);
	bool SearchBinary(ulongint Number);
	
	//Печать на экран
	void Print();
	
	//Выборки всех элементов, подходящих по критерию, нельзя сосавлять выборки по номеру, тк он единственный
	list<BankAccount> GetAllByName(string LastName);
	list<BankAccount> GetAllByDate(Date opened);
	BankAccount GetByNumber(ulongint number);
	//Загрузка из файла/Запись в файл
	void PutToFile();
	~Bank();
	BankAccount* GetForEdit(unsigned long int Number, string LastName, int Password);
};

