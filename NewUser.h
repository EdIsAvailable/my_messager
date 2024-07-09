#pragma once
#include<iostream>
using namespace std;
class NewUser
{	
	const string _acc;
public:
	 NewUser() = default;
	 NewUser(const string& acc) : _acc(acc) {}
	virtual ~NewUser() = default;
	virtual void Show() = 0;
	const  string get_Acc() const;
	void set_Acc(const string acc);
	
};
