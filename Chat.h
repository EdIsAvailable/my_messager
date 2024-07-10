#pragma once
#include<iostream>
using namespace std;
class Chat
{
	int _src_uid; // UserID отправителя сообщения
	int _dest_uid; // UserID получателя сообщения
	string _message; // Тело сообщения
	string _dateSent; // Время отправки сообщения
   public:
	// Конструктор класса Chat создаёт класс сообщение в котором указываем uid отправителя, uid получатели, тело сообщения и дата/время отправленного сообщения
	Chat(int src_uid, int dest_uid, string message);
	// Показать сообщение, которое хранится в классе
	void ShowC();
	// Проверить получателя сообщения
	const int getDestUid(void);
	// Функция для отправки сообщения
	//void sendMsg(int src_uid, int dest_uid, string _message);
	~Chat() {};
};
