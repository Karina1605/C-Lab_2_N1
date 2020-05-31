#pragma once
#include"AccountInfo.h"
#include<string>
#include<sstream>
#include<set>

using namespace std;
class AccountInfoManager
{
public:
		
	void AddNew(string Name, float Percent, bool CanTakeAPart);
	static AccountInfoManager *GetInstanse();
	void PutToFile();
	AccountInfo* Chose();
	AccountInfo* FindByName(string name);
	~AccountInfoManager();
private:
	
	static string FileForStoring;
	AccountInfoManager();
	AccountInfoManager(string FileName);
	AccountInfoManager(const AccountInfoManager&) =delete;
	AccountInfoManager& operator = (AccountInfoManager&) =delete;

	void LoadFromFile(string FileName);

	friend istream& operator>>(istream &s, AccountInfo& BA);
	friend ostream& operator<<(ostream &s, const AccountInfo& BA);


	set<AccountInfo*> typesOfAccount;
	static AccountInfoManager *MainManger;
	
};

