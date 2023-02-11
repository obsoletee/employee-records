#pragma once
#include "library.h"
template <class T>
class Account
{
protected:
	T login;
	T password;
public:
	string getLogin();
	string getPassword();
	void putLogin();
	void putPassword();

};