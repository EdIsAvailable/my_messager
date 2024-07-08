#pragma once
#include<iostream>
using namespace std;
class Chat
{
	string& _chat;
   public:
	Chat(string& chat, string& adr, bool& p);
	void ShowC();
	~Chat() {};
};
