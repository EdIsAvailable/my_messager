#include "Acc.h"
#include <iostream>
using namespace std;
Acc::Acc(string& acc, string& pswd) : NewUser(acc), _pswd(pswd)
{}
void Acc::Show (){ cout <<"������ "<< _pswd << endl; }
const  string Acc::get_Pswd() const
{
	return _pswd;
}
void Acc::set_Pswd(const string pswd)
{
	_pswd = pswd;
}
const  string NewUser::get_Acc() const
{
	return _acc;
}
void NewUser::set_Acc(const string acc)
{
	//_acc = acc;
	cout << "�������:  " << _acc<< endl;
}
