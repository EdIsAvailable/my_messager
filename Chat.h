#pragma once
#include<iostream>
using namespace std;
class Chat
{
	//string& _chat;
	//string& _adr;
	string _message; // Тело сообщения
	int _src_uid; // UserID отправителя сообщения
	int _dest_uid; // UserID получателя сообщения
	string _dateSent; // Время отправки сообщения
   public:
	//Chat(string& chat, string& adr);
	Chat(int src_uid, int dest_uid, string message, string dateSent);
	void ShowC();
	// Функция для отправки сообщения
	//void sendMsg(int src_uid, int dest_uid, string _message);
	~Chat() {};
};
