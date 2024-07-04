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
	NewUser* usr[2];
	string n_name;
	string u_pswd;
	string newmsgs;

	usr[0] = new Acc((n_name),(u_pswd));
	Chat* c = new Chat ((newmsgs));
	
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
		//usr[0]->set_Pswd((u_pswd));
		usr[0]->Show();
	}

	case 'l':
	{
		std::cout << "введите никнейм " << endl;
		std::cin >> n_name;
		 //if (n_name == c)
		
		std::cout << "введите пароль " << endl;
		std::cin >> u_pswd;
	}
	c->ShowC();
	std::cin >> newmsgs;
	default:
		break;
	}
	
	delete usr[0];
	delete c;
	return 0;
};