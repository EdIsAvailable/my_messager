#include<iostream>
#include <vector>
#include <string>
#include "Acc.h"
#include "Chat.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	vector <string> myvec;
	NewUser* usr[2];
	string g;
	string h;
	usr[0] = new Acc((g), (h));
	string f;
	Chat* c = new Chat ((f));
	c->ShowC();
	usr[0]->Show();
	char switchLogon, switchLogoff, n_name, u_pswd, newmsgs;
	cout <<"������� ������� �������: 'c'" << endl;
	cout <<"�������������� �������:  'l'" << endl;
	std::cin >> switchLogon;
	switch(switchLogon)
	{
	case 'c':
	{
		std::cout << "���������� ������� " << endl;
		std::cin >> n_name;
		std::cout << "�������� ������ " << endl;
		std::cin >> u_pswd;
		
	}

	case 'l':
	{
		std::cout << "������� ������� " << endl;
		std::cin >> n_name;
		std::cout << "������� ������ " << endl;
		std::cin >> u_pswd;
	}
	default:
		break;
	}
	
	delete usr[0];
	delete c;
	return 0;
};