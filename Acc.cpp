#include "Acc.h"
#include <iostream>
using namespace std;
Acc::Acc(string& acc, string& pwd) : NewUser(acc), _pwd(pwd)
{}
void Acc::Show() { cout << "�������  "<< _pwd << endl; }// override