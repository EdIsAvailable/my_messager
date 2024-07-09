#include "Message.h"
Message::Message(string userFrom, string userTo, string text) : _userFrom(userFrom), _userTo(userTo), _text(text)
{ }

Message::~Message()
{
	
}