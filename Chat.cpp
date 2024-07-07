#include "Chat.h"
#include <iostream>
using namespace std;

Chat::Chat(string& chat, string& adr) :  _chat(chat), _adr(adr){}

void Chat::ShowC() { cout << "чат: " <<_chat << endl; }