#pragma once
#include<iostream>
using namespace std;
class Chat
{
	//string& _chat;
	//string& _adr;
	string _message; // Само сообщение
	int _src_uid; // UserID отправителя сообщения
	int _dest_uid; // UserID получателя сообщения
   public:
	//Chat(string& chat, string& adr);
	Chat(int src_uid, int dest_uid, string message);
	void ShowC();
	// Функция для отправки сообщения
	//void sendMsg(int src_uid, int dest_uid, string _message);
	~Chat() {};
};
