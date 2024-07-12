#include "UserRepository.h"
#include"Chat.h"

#pragma once
class Server
{
	UserRepository* _userRepo;
	Chat* _msgRepo;

public: Server();
		void MainProcess();

private: Acc* ProcessAuthorization();
		 void ProcessChat(Acc* user);
};

