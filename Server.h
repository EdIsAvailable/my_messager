#include "UserRepository.h"

#pragma once
class Server
{
	UserRepository* _userRepo;

public: Server();
		void MainProcess();

private: Acc* ProcessAuthorization();
		 void ProcessChat(Acc* user);
};

