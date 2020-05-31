#pragma once
#include<string>
using namespace std;

class AccountInfo
{
private:
	string Name;
	float Percent;
	bool CanTakeAPart;
public:
	AccountInfo(string Name, float Percent, bool CanTakeAPart);
	AccountInfo();
	string GetName() const;
	float GetPercents() const;
	bool GetCanTakeAPart() const;

	void SetName(string newName);
	void SetPercent(float newPercent);
	void SetCanTakeAPart(bool newCanTakeAPart);

	bool operator == (const AccountInfo& other);
	bool operator == (const string& other);
	friend istream& operator>>(istream &s, AccountInfo& AI);
	friend ostream& operator<<(ostream &s, const AccountInfo& AI);
	string ToString() const;
	
	~AccountInfo();
};