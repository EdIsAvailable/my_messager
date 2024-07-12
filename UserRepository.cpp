#include "UserRepository.h"
using namespace std;

UserRepository::UserRepository()
{
	//_users = { };
}

Acc* UserRepository::NewUser()
{
	string login, pwd, name;

	std::cout << "Введите имя: " << endl;
	std::cin >> name;
	std::cout << "Придумайте логин: " << endl;
	std::cin >> login;
	std::cout << "Создайте пароль: " << endl;
	std::cin >> pwd;
	Acc* newUser = new Acc(login, pwd, name);
	newUser->Show();

	_users.push_back(newUser);

	return newUser;
}

Acc* UserRepository::FindUser(string login)
{
	for (size_t i = 0; i < _users.size(); i++)
	{
		//Acc* user = _users[i];
		//if (user->get_Login() == login)
		if (_users[i]->get_Login() == login)
			return _users[i];
	}

	return NULL;
}

Acc* UserRepository::AuthorizeUser(string login, string pwd)
{
	Acc* user = FindUser(login);

	if (user == NULL)
	{
		std::cout << "Пользователь не найден!!!" << endl;
		return NULL;
	}

	if (!(user->CheckPassword(pwd)))
	{
		std::cout << "Неправильный пароль" << endl;
		return NULL;
	}

	return user;
}

UserRepository::~UserRepository()
{
	_users.clear();
}



