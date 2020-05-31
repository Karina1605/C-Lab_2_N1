#include "pch.h"
#include "AccountInfoManager.h"
#include<iterator>
#include <iostream>
#include <fstream>
using namespace std;

string AccountInfoManager:: FileForStoring = "AccountTypeManager.txt";
AccountInfoManager::AccountInfoManager()
{
}
AccountInfoManager* AccountInfoManager::MainManger = nullptr;

AccountInfoManager::AccountInfoManager(string FileName)
{
	LoadFromFile(FileName);
}

AccountInfoManager* AccountInfoManager::GetInstanse()
{
	if (MainManger == nullptr)
		MainManger = new AccountInfoManager(FileForStoring);
	return MainManger;
}

void AccountInfoManager:: PutToFile()
{
	fstream out;
	out.open(FileForStoring, ios::out);
	for (auto it = typesOfAccount.begin(); it != typesOfAccount.end(); it++)
		out << **it;	
	out.close();
}
void AccountInfoManager::LoadFromFile(string FileName)
{
	ifstream f;
	f.open(FileName);
	AccountInfo buf;
	while (f >> buf)
	{
		AccountInfo* next = new AccountInfo(buf);
		typesOfAccount.insert(next);
	}
}
void AccountInfoManager::AddNew(string Name, float Percent, bool CanTakeAPart)
{
	for (int i = 1; i < Name.length(); ++i)
		Name[i] = tolower(Name[i]);
	Name[0] = toupper(Name[0]);
	AccountInfo* info= new AccountInfo (Name, Percent, CanTakeAPart);
	typesOfAccount.insert(info);
}
AccountInfoManager::~AccountInfoManager()
{
}
AccountInfo* AccountInfoManager::Chose()
{
	auto it = typesOfAccount.begin();
	int i = 1;
	for (; it != typesOfAccount.end(); ++i, ++it)
		cout << i << ". " << (*it)->GetName() << '\n';
	int pos;
	cout << "¬ведите вид счета (число от 1 до " << i-1 << ")\n";
	do
	{
		cin >> pos;
		if (pos<1 || pos>=i)
			cout << "ќшибка, вы должны ввести число от 1 до " << i-1 << "\n";
	} while (pos<1 || pos>=i);
	auto it1 = typesOfAccount.begin();
	for (int j = 0; j < pos-1; ++j, ++it1);
	cout << "found\n";
	return *it1;
}

AccountInfo* AccountInfoManager::FindByName(string name)
{
	auto it = typesOfAccount.begin();
	while (it != typesOfAccount.end() && (*it)->GetName() != name)
		it++;
	if (it == typesOfAccount.end())
		return nullptr;
	return *it;
}