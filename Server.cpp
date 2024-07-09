#include "Server.h"

Server::Server()
{
	_userRepo = new UserRepository();
};

void Server::MainProcess()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");

	bool process = true;
	char menuOption;
	do {
		cout << "Создать аккаунт введите: 'c'" << endl;
		cout << "Авторизоваться введите:  'a'" << endl;
		cout << "Выход: 'e'" << endl;
		std::cin >> menuOption;
		switch (menuOption)
		{
		case 'c':
		{
			Acc* newUser =  _userRepo->NewUser();

			//добавить в вектор чатов
			break;
		}
		case 'a':
		{
			Acc* user = ProcessAuthorization();
			if (user == NULL)
				continue; //сюда возможно нужно добавить кщё один break, чтобы не было выхода из цикла

			ProcessChat(user);
			break;
		}
		case 'e': {
			process = false;
			break;
		}
		}

		cout << endl;
	} while (process);
};

Acc* Server::ProcessAuthorization()
{
	string login, pwd;
	std::cout << "введите никнейм " << endl;
	std::cin >> login;
	std::cout << "введите пароль " << endl;
	std::cin >> pwd;

	Acc* user = _userRepo->AuthorizeUser(login, pwd);

	if (user == NULL)
	{
		std::cout << "неверно введён пароль" << endl;
		return NULL;
	}

	return user;
}

void Server::ProcessChat(Acc* user)
{

}