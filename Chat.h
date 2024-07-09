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
	vector<Message*> GetMessagesForAll();
	vector<Message*> GetMessagesForUser(string login);
	void AddMessage(Message* msg);

	~Chat();
};