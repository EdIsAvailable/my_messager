#include "Acc.h"
#include <iostream>
using namespace std;

Acc::Acc(string& login, string& pswd, string& name) : NewUser(login), _pswd(pswd), _name(name), _lastReadMsg(0)
{}
void Acc::Show()
{
	cout << "Пароль " << _pswd << endl; // Выводим на экран пароль пользователя
}
const  string Acc::getPswd() const
{
	return _pswd; // Получить пароль пользователя
}
void Acc::setPswd(const string pwd)
{
	//check if null then throw
	if (pwd == " ")
		std::cout << "не введён пароль" << std::endl;
	
	_pswd = pwd; // Установить пароль пользователя
}
bool Acc::CheckPassword(string& pwd)
{
	return _pswd == pwd; // Проверить пароль пользователя, верный или нет
}

const string Acc::getName() const
{
	return _name; // Получить имя пользователя
}

void Acc::setName(const string name)
{
	//check if null then throw
	if (name.size() == 0)
		throw ("укажите имя");

	_name = name;  // Поменять имя пользователя
}

void Acc::setLastReadMsg(const int lastReadMsg)
{
	_lastReadMsg = lastReadMsg; // Устанавливаем номер последнего прочитанного сообщения
}
const int Acc::getLastReadMsg(void)
{
	return _lastReadMsg; // Получить номер последнего прочитанного сообщения
}
