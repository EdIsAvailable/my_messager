#include<iostream>
#include <vector>
#include <string>
#include "Acc.h"
#include "Chat.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	vector <string> allusrs;
	vector <string> allmsgs;
	// User ID
	int user_id = 0;
	Acc* usr[20]; // Пока максимальный UserID = 20
	Chat* cht[2];
	string n_name;
	string u_pswd;
	string u_name;
	string newmsgs;

	//usr[0] = new Acc((n_name),(u_pswd),(u_name));
	cht[0] = new Chat((newmsgs));
	
	char switchLogon, switchLogoff;

	// Здесь надо организовать цикл основной логики программы
	cout <<"Создать аккаунт введите: 'c'" << endl;
	cout <<"Авторизоваться введите:  'l'" << endl;
	cout <<"Отправить сообщение: 's'" << endl;
	std::cin >> switchLogon;
	switch(switchLogon)
	{
	case 'c':
	{
		std::cout << "придумайте никнейм " << endl;
		std::cin >> n_name;
		//usr[0]->set_Acc((n_name));

		std::cout << "создайте пароль " << endl;
		std::cin >> u_pswd;
		//usr[0]->set_Pswd((u_pswd));
		//usr[0]->Show();

		std::cout << "ваше имя: ";
		std::cin >> u_name;
		//usr[0]->set_Acc((n_name));

		if (user_id<20)
		{
			usr[user_id] = new Acc(n_name, u_pswd, u_name);
			// Следующий пользователь будет с ID+1
			user_id++;
		} else { 
			// Надо увеличить массив пользователей!
		}

		break;
	}
	case 'l':
	{
		std::cout << "введите никнейм " << endl;
		std::cin >> n_name;
		 //if (n_name == c)
		
		std::cout << "введите пароль " << endl;
		std::cin >> u_pswd;

		break;
	}
	case 's':
	{
		cht[0]->ShowC();
		std::cin >> newmsgs;
		
		break;
	}
	default:
		break;
	}
	
	delete usr[0];
	delete cht[0];
	return 0;
};