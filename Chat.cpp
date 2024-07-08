#include "Chat.h"
#include <iostream>
using namespace std;

// Конструктор класса Chat создаёт класс сообщение в котором указываем uid отправителя, uid получатели, тело сообщения и дата и время отправленного сообщения
Chat::Chat(int src_uid, int dest_uid, string message, string dateSent) : _src_uid(src_uid), _dest_uid(dest_uid), _message(message), _dateSent(dateSent) {};
//Chat::Chat(string& chat, string& adr, bool& p) : _chat(chat), _adr(adr), _p(p) {}

// Показать сообщение, которое хранится в классе
void Chat::ShowC() { cout << "чат: " << _message << " отправитель: " << _src_uid << " получатель: " << _dest_uid << " отправлено: " << _dateSent << endl; }
//void Chat::ShowC() { cout << "чат: " << _chat << endl; }

//void Chat::sendMsg(int& src_uid, int& dest_uid, string& _message) {};
