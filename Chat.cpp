#include "Chat.h"
#include <iostream>
using namespace std;

//Chat::Chat(string& chat, string& adr) :  _chat(chat), _adr(adr) {};
Chat::Chat(int src_uid, int dest_uid, string message, string dateSent) :  _src_uid(src_uid), _dest_uid(dest_uid), _message(message), _dateSent(dateSent) {};
//void Chat::ShowC() { cout << "чат: " <<_chat << endl; }
void Chat::ShowC() { cout << "чат: " <<_message << " отправитель: " << _src_uid << " получатель: " << _dest_uid << " отправлено: " << _dateSent << endl; }
//void Chat::sendMsg(int& src_uid, int& dest_uid, string& _message) {};
