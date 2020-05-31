#include "pch.h"
#include "AccountInfo.h"
#include<string>
#include<sstream>

using namespace std;
AccountInfo::AccountInfo()
{
}

AccountInfo::AccountInfo(string Name, float Percent, bool CanTakeAPart) :Name(Name), Percent(Percent), CanTakeAPart(CanTakeAPart)
{}

string AccountInfo :: GetName() const { return Name; }
float AccountInfo:: GetPercents() const { return Percent; }
bool AccountInfo:: GetCanTakeAPart() const { return CanTakeAPart; }

void AccountInfo::SetName(string newName) { Name = newName; }
void AccountInfo::SetPercent(float newPercent) { Percent = newPercent; }
void AccountInfo::SetCanTakeAPart(bool newCanTakeAPart) { CanTakeAPart = newCanTakeAPart; }

bool AccountInfo:: operator == (const AccountInfo& other)
{
	return this->Name == other.Name;
}
bool AccountInfo:: operator == (const string& other)
{
	return this->Name == other;
}

istream& operator>>(istream &s, AccountInfo& AI)
{
	s >> AI.Name;
	s >> AI.Percent;
	s >> AI.CanTakeAPart;
	return s;
}
ostream& operator<<(ostream &s, const AccountInfo& AI)
{
	s << AI.ToString();
	return s;
}
string AccountInfo::ToString() const
{
	stringstream r;
	r << Name << " " << Percent << " " << CanTakeAPart;
	return r.str();
}

AccountInfo::~AccountInfo()
{
}
