#pragma once
#include<iostream>
using namespace std;
class NewUser
{
protected: string _login;
public:
	NewUser() = default;
	NewUser(const string& login) : _login(login) {}
	virtual ~NewUser() = default;
	virtual void Show() = 0;
	const  string get_Login() const;
	void set_Login(const string login);

};
