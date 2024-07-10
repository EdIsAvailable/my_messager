#pragma once
#include "NewUser.h"
using namespace std;
class Acc : public NewUser
{	
	string _pswd; // Пароль пользователя
	string _name; // Имя пользователя
	int lastReadMsg; // Последнее прочитанное сообщение из вектора сообщений
public:
	// Конструктор класса Acc создаёт пользователя с ником, паролем и именем
	Acc(string acc, string pswd, string name);
	void Show() override;
	const  string get_Pswd() const; // Получить текущий пароль пользователя
	void set_Pswd(const string pswd); // Поменять пароль пользователя
	~Acc() {}; // Деструктор класса
};
