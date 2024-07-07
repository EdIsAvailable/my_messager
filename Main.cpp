#include<iostream>
#include <vector>
#include <string>
#include "Acc.h"
#include "Chat.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int user_id = 0;
	Acc* usr[2]; // минммум 2 юзера
	Chat* cht[2];
	string n_name;
	string u_pswd;
	string u_name;
	string newmsgs;

	usr[0] = new Acc((n_name),(u_pswd),(u_name));
	cht[0] = new Chat((newmsgs),(nwadr));
	vector <Acc *> allusrs;
	allusrs.push_back(usr[0]);
	vector <Chat *> allmsgs;
	allmsgs.push_back(cht[0]);
	char switchLogon, switchLogoff;

	
	cout <<"Создать аккаунт введите: 'c'" << endl;
	cout <<"Авторизоваться введите:  'l'" << endl;
	std::cin >> switchLogon;
	switch(switchLogon)
	{
	case 'c':
	{
		std::cout << "придумайте никнейм " << endl;
		std::cin >> n_name;
		usr[0]->set_Acc((n_name));

		std::cout << "создайте пароль " << endl;
		std::cin >> u_pswd;
		usr[0]->set_Pswd((u_pswd));
		usr[0]->Show();

		std::cout << "укажите ваше имя: ";
		std::cin >> u_name;
		usr[0]->set_Acc((n_name));

	
			usr[user_id] = new Acc(n_name, u_pswd, u_name);
			// Следующий пользователь будет с ID+1
			user_id++;
		

		break;
	}
	case 'l':
	{
		std::cout << "введите никнейм " << endl;
		std::cin >> n_name;
		for (int i=0; i < sizeof usr[0]; i++)
		{
			if (n_name == n_name)
			{
				std::cout << "введите пароль " << endl;
				std::cin >> u_pswd;
			
				if (u_pswd == u_pswd)
				{
					// start messeging

			   }
			}
			else
			{
				// переход в начало к авторизуйтесь
			}

		}
		
		break;
	}
		
	cout << "Отправить сообщение: 's'" << endl;
	default:
		break;
	}
	
	delete usr[0];
	delete cht[0];
	return 0;
};