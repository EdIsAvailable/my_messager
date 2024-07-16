#include "NewUser.h"
#include <iostream>
#include<algorithm>
using namespace std;

NewUser::NewUser(const string& login)
{
	this->setLogin(login);
}

// Получить логин пользователя
const  string NewUser::getLogin() const
{
	return _login;
}

// Установить и вывести логин пользователя
void NewUser::setLogin(const string login)
{
	if (!checkSymbols(login))
	{
		throw  "Содержится недопустимый символ";
	}
	_login = login;
}

// Ограничение для вводимых символов
void NewUser::TestFunctor::operator()(char ch)
{
	if (stringIsCorrect && !((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A') || (ch <= '9' && ch >= '0') || (ch == ' ')))
		stringIsCorrect = false;
}

//  Проверить на соответствие символы в логине
bool NewUser::checkSymbols(const string some_string)
{
	TestFunctor functor;
	for_each(some_string.begin(), some_string.end(), functor);

	return functor.stringIsCorrect;
}
