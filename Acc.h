#pragma once
#include "NewUser.h"
using namespace std;
class Acc : public NewUser
{	
	string& _pswd;
public:  
	Acc(string& acc, string& pswd);
	void Show() override;
	const  string get_Pswd() const;
	void set_Pswd(const string pswd);
	~Acc() {};;


};

