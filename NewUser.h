#pragma once
#include<iostream>
using namespace std;
class NewUser
{	
	const string& _acc;
public:
	NewUser() = default;
	NewUser(const string& acc) : _acc(acc) {
		
	}
	virtual ~NewUser()=default;
	void virtual Show()
	{
		cout << _acc;
	}
	
};
