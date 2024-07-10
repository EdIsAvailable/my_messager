#include "Chat.h"
#include <string>
#include <time.h>
#include <iostream>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS для localtime
using namespace std;

// Конструктор класса Chat создаёт класс сообщение в котором указываем uid отправителя, uid получатели, тело сообщения и дата и время отправленного сообщения
Chat::Chat(int src_uid, int dest_uid, string message) :  _src_uid(src_uid), _dest_uid(dest_uid), _message(message)
{
    // Определяем переменные для работы с датой и временем
   	time_t t;
	struct tm *t_m;

	// Подготавливаем дату и время
	t = time(NULL);
	t_m = localtime(&t);

	// Формируем дату и время отправки сообщения
	_dateSent =" " + std::to_string(t_m->tm_mday) + "-" + std::to_string(t_m->tm_mon+1) + "-" + std::to_string(t_m->tm_year+1900) + 
					" " + std::to_string(t_m->tm_hour) + ":" + std::to_string(t_m->tm_min) + ":" + std::to_string(t_m->tm_sec);
};

// Показать сообщение, которое хранится в классе
void Chat::ShowC() { cout << "чат: " << _message << " отправитель: " << _src_uid << " получатель: " << _dest_uid << " отправлено: " << _dateSent << endl; }
// Проверить получателя сообщения
const int Chat::getDestUid(void)
{
    return _dest_uid;
}
//void Chat::sendMsg(int& src_uid, int& dest_uid, string& _message) {};
