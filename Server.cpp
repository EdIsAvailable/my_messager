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
		/*cout << "Создать аккаунт введите: 'c'" << endl;
		cout << "Авторизоваться введите:  'l'" << endl;*/
		cout << "(C) Create account:" << endl;
		cout << "(A) Authorization:" << endl;
		cout << "(E) Exit:" << endl;
		std::cin >> menuOption;
		switch (menuOption)
		{
		case 'C':
		case 'c':
		{
			_userRepo->NewUser();
			break;
		}
		case 'A':
		case 'a':
		{
			Acc* user = ProcessAuthorization();
			if (user == NULL)
				continue; //vozmojno nujno dobaviti siuda eshio odin break, glavnoe shtob on ne vyhodil iz tsykla

			ProcessChat(user);
			break;
		}
		case 'E':
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
		std::cout << "Wrong user or password" << endl;
		return NULL;
	}

	return user;
}

void Server::ProcessChat(Acc* user)
{

}