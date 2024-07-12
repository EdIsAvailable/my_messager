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
	int msgId = _messages.size();
	cout << "Всего сообщений в базе: " << msgId << endl;

	// Количество сообщений равно количеству зарегистрированных пользователей в данном тесте
	while (msgId--) {  // Обратный отсчёт
		_messages[msgId]->Show();  // Выводим содержимое вектора сообщений
	}
}

Chat::~Chat() {};