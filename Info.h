#pragma once
#include "library.h"
#include "checkup.h"
template <class T>
class Info
{
protected:
	T ID;
	T phone;
	T jobTitle;
	T salary;
	T workLevel;
public:
	void putID(string str);
	void putPhone();
	void putJobTitle();
	void putSalary(string str);
	void putWorkLevel(string str);
	string getID();
	string getWorkLevel();
	string getSalary();
	string getJobTitle();
};