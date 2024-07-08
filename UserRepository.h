#include <vector>
#include <string>
#include "Acc.h"


#pragma once
class UserRepository
{
	vector<Acc*> _users;
public:  UserRepository();
		void NewUser();
		Acc* FindUser(string login);
		Acc* AuthorizeUser(string login, string pwd);
};

