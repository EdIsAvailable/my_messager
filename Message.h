#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#pragma once
class Message
{
	string _userFrom, _userTo, _text; //тут добавить геттеры
	time_t _now;
public:
	Message(string userFrom, string userTo, string text); // Конструктор 
	void Show(void); // Вывод содержимого сообщения
	~Message();
};

