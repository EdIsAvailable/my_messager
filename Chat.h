#pragma once
#include<iostream>
using namespace std;
class Chat
{
	string& _chat;
	string& _adr; // ������� ���� ������� �� ��������� �� � ������ ������ ���������� ������ ������������. ����� ����� ����� "forall"
	bool _p;
public:
	Chat(string& chat, string& adr, bool& p);
	void ShowC();
	~Chat() {};
};
