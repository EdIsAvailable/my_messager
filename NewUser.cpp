#include "NewUser.h"
#include <iostream>
using namespace std;

// Получить логин пользователя
const  string NewUser::getLogin() const
{
	return _login;
}
// Установить и вывести логин пользователя
void NewUser::setLogin(const string login)
{
	_login = login; 
	cout << "Логин:  " << _login << endl;
}
