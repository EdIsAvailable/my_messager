#pragma once
#include "NewUser.h"
using namespace std;
class Acc : public NewUser
{
	//string& _login;
	string _pswd;
	string _name;
public:
	// Конструктор класса Acc создаёт пользователя с ником, паролем и именем
	Acc(string& login, string& pswd, string& name);
	void Show() override;
	const  string get_Pswd() const;
	void set_Pswd(const string pwd);
	/*const  string get_Login() const;
	void set_Login(const string login);*/
	const  string getName() const; // Получить имя пользователя
	void setName(const string name);  // Поменять имя пользователя
	bool CheckPassword(string& pwd);
	~Acc() {};;
};
