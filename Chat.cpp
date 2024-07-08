#include "Chat.h"
#include <iostream>
using namespace std;

Chat::Chat(string& chat, string& adr, bool& p) : _chat(chat), _adr(adr), _p(p) {}

void Chat::ShowC() { cout << "чат: " << _chat << endl; }