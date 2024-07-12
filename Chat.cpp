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

Chat::~Chat() {};