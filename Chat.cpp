#include "Chat.h"
#include <iostream>
using namespace std;

//Chat::Chat(string& chat, string& adr) :  _chat(chat), _adr(adr) {};
Chat::Chat(int src_uid, int dest_uid, string message) :  _src_uid(src_uid), _dest_uid(dest_uid), _message(message) {};
//void Chat::ShowC() { cout << "чат: " <<_chat << endl; }
void Chat::ShowC() { cout << "чат: " <<_message << " отправитель: " << _src_uid << " получатель: " << _dest_uid << endl; }
//void Chat::sendMsg(int& src_uid, int& dest_uid, string& _message) {};