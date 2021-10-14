#include "Header.h"

list<string> Files::ReadFile(string FileName)
{
	//test 
	//
	 
	list<string> lines;
	string line="";
	fstream f;
	if (f.is_open()) {
		f.close();
	}
	f.open(FileName);
	if (f.is_open()) {
		cout << "Ket Noi Thanh Cong" << endl;
		do {
			getline(f, line);
			lines.push_back(line);
		} while (!f.eof());
	}
	else {
		cout << "Ket Noi that bai"<<endl;
	}
	f.close();
	return lines;
}

void Files::WriteFile(string FileName, list<string> data)
{
	fstream f;
	if (f.is_open()) {
		f.close();
	}
	f.open(FileName,fstream::app);
	if (f.is_open()) {
		cout << " Mo Thanh Cong" << endl;
		for (list<string>::iterator i = data.begin();i != data.end();++i) {
			f << *i;
		}
	}
	else {
		cout << "Mo that bai" << endl;
	}
	f.close();
}

list<string> Files::split(string data, char ch)
{ 
	list<string> features;
	string fea = "";
	stringstream line;
	if (data != "") {
		line << data;
		while (getline(line, fea, ch)) {
			features.push_back(fea);
		}
	}
	return features;
}

Bank::~Bank()
{
}

int Bank::ViewListBank()
{
	cout << "LIST BANK"<<endl;
	cout << "1.VietComBank" << endl;
	cout << "2.AriBank" << endl;
	return 2;//them thi return ve so ngan hang
}

string Bank::SelectBank(int n)
{
	int x;
	do{
		//system("cls");
		cout << "lua chon ngan hang: ";
		cin >> x;
		if (x<0 || x>n) {
			cout << "Loi!!";
			
		}
		else {
			if (x == 1)return "VietComBank";
		}
	} while (x<0 || x>n);
	return "";
}

VCB::VCB()
{
}


bool VCB::CheckAccount(string ID, string Pass, string Date)
{
	list<string>feature;
	list<string>AccountBank;
	AccountBank = Files::ReadFile(this->file);
	for (list<string>::iterator i = AccountBank.begin();i != AccountBank.end();++i) {
		
			feature = Files::split(*i, '|');
			list<string>::iterator i0 = next(feature.begin(), 0);
			list<string>::iterator i1 = next(feature.begin(), 1);
			list<string>::iterator i2 = next(feature.begin(), 2);
			if (*i0 == ID && *i1 == Pass && *i2 == Date) {
				return true;
			
		}
	}
	return false;
}

Bank* CreatBank::Create(string BankName)
{
	Bank* bank=NULL;
	if (BankName == "VietComBank") {
		bank = new VCB();
	}
	if (BankName == "AriBank") {
		bank = new VCB();
	}
	return bank;
}

AccountZale::AccountZale()
{
}

void AccountZale::AddBank()
{
	string idCard = "";
	string pass = "";
	string date = "";
	Bank* bank;
	cout << "LINK BANK" << endl;
	bank=CreatBank::Create(Bank::SelectBank(Bank::ViewListBank()));
	cout << "input idCard: ";
	cin >> idCard;
	cout << "input pass: ";
	cin >> pass;
	cout << "input date: ";
	cin >> date;
	if (bank->CheckAccount(idCard, pass, date) == true) {
		this->list.push_back(bank);
	}
	else {
		cout << "ACCOUNT NOT EXIST !!!" << endl;
	}
}

AB::AB()
{
}

bool AB::CheckAccount(string ID, string Pass, string Date)
{
	return false;
}
