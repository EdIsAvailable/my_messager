#pragma once
#include<iostream>
using namespace std;

class Chat
{
	//string& _chat;
	//string& _adr; // ������� ���� ������� �� ��������� �� � ������ ������ ���������� ������ ������������. ����� ����� ����� "forall"
	//bool _p;
	string _message; // ���� ���������
	int _src_uid; // UserID ����������� ���������
	int _dest_uid; // UserID ���������� ���������
	string _dateSent; // ����� �������� ���������
public:
	// ����������� ������ Chat ������ ����� ��������� � ������� ��������� uid �����������, uid ����������, ���� ��������� � ���� � ����� ������������� ���������
	Chat(int src_uid, int dest_uid, string message, string dateSent); 
	//Chat(string& chat, string& adr, bool& p);

	// �������� ���������, ������� �������� � ������
	void ShowC();

	// ������� ��� �������� ���������
	//void sendMsg(int src_uid, int dest_uid, string _message);
	~Chat() {};
};
