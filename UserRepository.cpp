#include "UserRepository.h"
using namespace std;

UserRepository::UserRepository()
{
	//_users = { };
}

void UserRepository::NewUser()
{
	string login, pwd, name;

	//std::cout << "укажите ваше имя: " << endl;
	std::cout << "Enter your name: " << endl;
	std::cin >> name;
	//std::cout << "придумайте никнейм " << endl;
	std::cout << "Enter your login: " << endl;
	std::cin >> login;
	//std::cout << "создайте пароль " << endl;
	std::cout << "Enter password: " << endl;
	std::cin >> pwd;
	Acc* newUser = new Acc(login, pwd, name);
	newUser->Show();

	_users.push_back(newUser);
}

Acc* UserRepository::FindUser(string login)
{
	for (int i = 0; i < sizeof _users; i++)
	{
		Acc* user = _users[i];
		if (user->get_Login() == login)
			return user;
	}

	return NULL;
}

Acc* UserRepository::AuthorizeUser(string login, string pwd)
{
	Acc* user = FindUser(login);

	if (user == NULL)
	{
		std::cout << "No user was found!!!" << endl;
		return NULL;
	}

	if (!(user->CheckPassword(pwd)))
	{
		std::cout << "Wrong password" << endl;
		return NULL;
	}

	return user;
}



