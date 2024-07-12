#pragma once
#include "NewUser.h"
using namespace std;
class Acc : public NewUser
{
	//string& _login;
	string _pswd; // Пароль пользователя
	string _name; // Имя пользователя
	int _lastReadMsg; // Последнее прочитанное сообщение из вектора сообщений
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
	void setLastReadMsg(const int lastReadMsg); // Устанавливаем номер последнего прочитанного сообщения
	const int getLastReadMsg(void); // Получить номер последнего прочитанного сообщения
	~Acc() {}; // Деструктор класса
};
