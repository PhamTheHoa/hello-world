#ifndef _HEADER_H
#define _HEADER_H
#include<iostream>
#include<fstream>
#include<sstream>
#include <list>
using namespace std;

class Files {
public:
	static list<string> ReadFile(string FileName);
	static void WriteFile(string FileName, list<string> data);
	static list<string> split(string data, char ch);
};

class Bank {
public:
	virtual~Bank();
	static int ViewListBank();
	static string SelectBank(int n);
	virtual bool CheckAccount(string ID,string Pass,string Date) = 0;
};

class VCB:public Bank {
private:
	string file = "VCB.txt";
public:
	VCB();
	virtual bool CheckAccount(string ID, string Pass, string Date);
};

class CreatBank {
public:
	static Bank* Create(string BankName);
};

class AccountZale {
public:
	string ID = "";
	string Pass = "";
	list<Bank*> list;
	//
	AccountZale();
	void AddBank();
	
};
#endif