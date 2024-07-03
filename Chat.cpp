#include "Chat.h"
#include <iostream>
using namespace std;

Chat::Chat(string& chat) :  _chat(chat){}

void Chat::ShowC() { cout << "чат: " <<_chat << endl; }