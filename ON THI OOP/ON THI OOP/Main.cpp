#include<iostream>;
#include"Header.h";
using namespace std;
int main() {
	AccountZale* T_Hoa = new AccountZale();
	T_Hoa->ID = "Bobo0103";
	T_Hoa->Pass = "bobo";
	T_Hoa->AddBank();

	AccountZale* _Hoa = new AccountZale();
	_Hoa->ID = "Bbo0103";
	_Hoa->Pass = "bbo";
	_Hoa->AddBank();
	return 0;
}