#include "NewUser.h"
#include <iostream>
using namespace std;


const  string NewUser::get_Login() const
{
	return _login;
}
void NewUser::set_Login(const string acc)
{

	cout << "�������:  " << _login << endl;
}
