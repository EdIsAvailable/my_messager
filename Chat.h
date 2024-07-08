#pragma once
#include<iostream>
using namespace std;
class Chat
{
	string& _chat;
	string& _adr; // булевый флаг наверно не получится тк в вектор должны однотипные данные передаваться. Метка будет адрес "forall"
	bool _p;
public:
	Chat(string& chat, string& adr, bool& p);
	void ShowC();
	~Chat() {};
};
