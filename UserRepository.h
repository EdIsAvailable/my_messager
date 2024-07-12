#pragma once
#include <vector>
#include <string>
#include "Acc.h"

class UserRepository
{
	vector<Acc*> _users;
public:  UserRepository();
		Acc* NewUser();
		Acc* FindUser(string login);
		Acc* AuthorizeUser(string login, string pwd);
		int getSize(); // Получить количество зарегистрированных пользователей
		void UsersList(void); // Вывод списка зарегистрированных пользователей
		~UserRepository();
};

