#include "Chat.h"
#include <iostream>
using namespace std;

//Chat::Chat(vector<Message*> _messages) : _messages(messages) {}

//Chat::Chat(vector<Message*> GetMessagesForAll) : _GetMessagesForAll{}

//Chat::vector<Message*> GetMessagesForUser(string login){}

void Chat::AddMessage(Message* msg) { cout << "чат: " << msg << endl; }

Chat::~Chat() {};