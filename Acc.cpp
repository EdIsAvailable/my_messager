#include "Acc.h"
#include <iostream>
using namespace std;

Acc::Acc(string& login, string& pswd, string& name) : NewUser(login), _pswd(pswd), _name(name)
{}
void Acc::Show() { cout << "Пароль " << _pswd << endl; }
const  string Acc::get_Pswd() const
{
	return _pswd;
}
void Acc::set_Pswd(const string pwd)
{
	//check if null then throw
	if (pwd == " ")
		throw ("не введён пароль");
		

	_pswd = pwd;
}
bool Acc::CheckPassword(string& pwd)
{
	return _pswd == pwd;
}

