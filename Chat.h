#pragma once
#include<iostream>
#include <vector>
#include <string>
#include "Message.h"
using namespace std;
class Chat
{
	vector<Message*> _messages;
public:
	Chat();
	//vector<Message*> GetMessagesForAll();
	//vector<Message*> GetMessagesForUser(string login);
	void AddMessage(string userFrom, string userTo, string text);
	// Вывод всех сообщений из вектора сообщений
	void ViewAllMessages(void);
	// Вывод сообщений для пользователя login из вектора сообщений
	void ViewMessagesForUser(string login);
	// Вывод сообщений адресованых всем пользователям из вектора сообщений
	void ViewMessagesForAllUsers(void);
	~Chat();
};