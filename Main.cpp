#include<iostream>
#include <vector>
#include <string>
#include "Acc.h"
#include "Chat.h"
#include "Server.h"
using namespace std;

Server* _server;

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int curr_user = 0;
	//Acc* userRepository[2]; // минммум 2 юзера
	Chat* chatRepository[2];
	string n_name;
	string u_pswd;
	string u_name;
	string newmsgs;
	string nwadr;
	bool r = false;
	bool pp = false;
	//userRepository[0] = new Acc((n_name), (u_pswd), (u_name));
	//chatRepository[0] = new Chat((newmsgs), (nwadr), (pp));
	char switchLogon, switchLogoff;

	_server = new Server();
	_server->MainProcess();


	//delete userRepository[0];
	delete chatRepository[0];
	return 0;
};


