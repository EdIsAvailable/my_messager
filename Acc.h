#pragma once
#include "NewUser.h"
using namespace std;
class Acc : public NewUser
{	
	string& _pwd;
public:  
	Acc(string& acc, string& pwd);
	void Show() override;
~Acc() {};
};

