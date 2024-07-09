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
		~UserRepository();
};

