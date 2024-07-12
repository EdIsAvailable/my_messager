#include "Message.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS для localtime

Message::Message(string userFrom, string userTo, string text) : _userFrom(userFrom), _userTo(userTo), _text(text)
{
    // Определяем переменные для работы с датой и временем
    //time_t t;
    struct tm *t_m;

	// Подготавливаем дату и время
	_now = time(NULL);
	t_m = localtime(&_now);

	// Формируем дату и время отправки сообщения
	string dateSent =" " + std::to_string(t_m->tm_mday) + "-" + std::to_string(t_m->tm_mon+1) + "-" + std::to_string(t_m->tm_year+1900) + 
					" " + std::to_string(t_m->tm_hour) + ":" + std::to_string(t_m->tm_min) + ":" + std::to_string(t_m->tm_sec);
    std::cout << dateSent << endl;
}

Message::~Message()
{
	
}