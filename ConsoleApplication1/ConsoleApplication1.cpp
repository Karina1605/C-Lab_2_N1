// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include"Bank.h"

using namespace std;

//Запись в файл выборки записей
void outputSomeRecords(list<BankAccount>&elems)
{
	cout << "Вывести на экран (1) или в файл (2)?\n";
	int res;
	cin >> res;
	auto it = elems.begin();
	string Filename;
	fstream f;
	switch (res) {
	case 1:
		while (it != elems.end())
		{
			cout << (*it) << '\n';
			++it;
		}
		break;
	case 2:
		getchar();
		cout << "Имя файла : ";
		getline(cin, Filename);
		f.open(Filename, ios::out);
		while (it != elems.end())
		{
			f << (*it) << '\n';
			++it;
		}
		f.close();
		break;
	}
}


//Основное меню
int menu()
{
	cout << "1.Загрузить данные из файла\n";
	cout << "2.Добавить аккаунт\n";
	cout << "3.Изменить аккаунт\n";
	cout << "4.Удалить аккаунт\n";
	cout << "5.Проверить, есть ли аккаунт с заданным номером договора\n";
	cout << "6.Проверить, есть ли аккаунт с заданной фамилией владельца\n";
	cout << "7.Проверить, есть ли аккаунт с заданной датой открытия \n";
	cout << "8.Проверить, есть ли аккаунт с заданным номером договора бинарным поиском\n";
	cout << "9.Проверить, есть ли аккаунт с заданной фамилией владельца бинарным поиском\n";
	cout << "10.Проверить, есть ли аккаунт с заданной датой открытия бинарным поиском\n";
	cout << "11.Выбрать все аккаунты с заданной фамилией владельца\n";
	cout << "12.Выбрать все аккаунты с заданной датой открытия\n";
	cout << "13.Записать все в файл\n";
	cout << "14.Вывести на экран все пользователей\n";
	cout << "15.Выход\n";
	int res;
	cin >> res;
	getchar();
	return res;
}


int main()
{
	Bank bank;
	BankAccount account;
	Date date;
	setlocale(LC_ALL, "russian");
	int action;
	ulongint Number;
	string Searching;
	ofstream fout;
	list<BankAccount> res;
	do {
		action = menu();
		switch (action)
		{
		case 1:
			cout << "Имя файла : ";
			getline(cin, Searching);
			bank.LoadFromFile(Searching);
			//bank.PutToFile(cout);
			break;
		case 2:
			account.InputNew();
			bank.Add(account);
			break;
		case 3:
			cout << "Номер счета : ";
			cin >> Number;
			bank.Change(Number);
			break;
		case 4:
			cout << "Номер счета : ";
			cin >> Number;
			bank.Remove(Number);
			break;
		case 5:
			cout << "Номер счета : ";
			cin >> Number;
			if (bank.Search(Number))
				cout << "Есть договор с таким номером\n";
			else
				cout << "Нет договора с таким номером\n";
			break;
		case 6:
			cout << "Фамилия владельца : ";
			getline(cin, Searching);
			if (bank.Search(Searching))
				cout << "Есть договор с такой фамилией владельца\n";
			else
				cout << "Нет договора с такой фамилией владельца\n";
			break;
		case 7:
			cout << "Дата открытия : ";
			cin >> date;
			if (bank.Search(date)) 
				cout << "Есть договор с такой датой открытия\n";
			else
				cout << "Нет договора с такой датой открытия\n";
			break;
		case 8:
			cout << "Номер счета : ";
			cin >> Number;
			if (bank.SearchBinary(Number))
				cout << "Есть договор с таким номером\n";
			else
				cout << "Нет договора с таким номером\n";
			break;
			break;
		case 9:
			cout << "Фамилия владельца : ";
			getline(cin, Searching);
			if (bank.SearchBinary(Searching))
				cout << "Есть договор с такой фамилией владельца\n";
			else
				cout << "Нет договора с такой фамилией владельца\n";
			break;
		case 10:
			cout << "Дата открытия : ";
			cin >> date;
			if (bank.SearchBinary(date))
				cout << "Есть договор с такой датой открытия\n";
			else
				cout << "Нет договора с такой датой открытия\n";
			break;
		case 11:
			cout << "Фамилия владельца : ";
			getline(cin, Searching);
			res = bank.GetAllByName(Searching);
			outputSomeRecords(res);
			break;
		case 12:
			cout << "Дата открытия счета : ";
			cin >> date;
			res = bank.GetAllByDate(date);
			outputSomeRecords(res);
			break;
		case 13:
			cout << "Имя файла : ";
			getline(cin, Searching);
			fout.open(Searching, ios::out);
			bank.PutToFile(fout);
			fout.close();
			cout << "Информация записана\n";
			break;
		case 14:
			bank.Print();
			break;
		case 15:
			cout << "До свидания\n";
			break;
		default:
			cout << "Вы должны ввести число от 1 до 14\n";
			break;
		}
	} while (action != 15);
	getchar();
}

