#include "Chat.h"
#include <iostream>
using namespace std;

Chat::Chat() {}
//Chat::Chat(vector<Message*> _messages) : _messages(messages) {}

//Chat::Chat(vector<Message*> GetMessagesForAll) : _GetMessagesForAll{}

//Chat::vector<Message*> GetMessagesForUser(string login){}

void Chat::AddMessage(string userFrom, string userTo, string text) 
{
    _messages.push_back(new Message(userFrom, userTo, text));
    //cout << "чат: " << msg << endl;
}

void Chat::ViewAllMessages(void)
{
	int msgId = (int)_messages.size();
	cout << "Всего сообщений в базе: " << msgId << endl;

	// Количество сообщений равно количеству зарегистрированных пользователей в данном тесте
	while (msgId--) {  // Обратный отсчёт
		_messages[msgId]->Show();  // Выводим содержимое вектора сообщений
	}
}
void Chat::ViewMessagesForUser(string login)
{
	// Вывод сообщений для пользователя login из вектора сообщений
	int msgId = (int)_messages.size();
	// Количество сообщений равно количеству зарегистрированных пользователей в данном тесте
	while (msgId--) {  // Обратный отсчёт
		if(_messages[msgId]->getUserTo() == login)
			_messages[msgId]->Show(); // Выводим содержимое вектора сообщений
	}
}
// Вывод сообщений адресованых всем пользователям из вектора сообщений
void Chat::ViewMessagesForAllUsers(void)
{
	// Вывод сообщений для пользователя login из вектора сообщений
	int msgId = (int)_messages.size();
	// Количество сообщений равно количеству зарегистрированных пользователей в данном тесте
	while (msgId--) {  // Обратный отсчёт
		if (_messages[msgId]->getUserTo() == "ALL")
			_messages[msgId]->Show(); // Выводим содержимое вектора сообщений
	}
}
Chat::~Chat() {};