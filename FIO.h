#pragma once
#include "library.h"
template <class T>
class FIO
{
protected:
	T name;
	T surname;
	T patronymic;
public:

	void putName();
	void putSurname();
	void putPatronymic();
	string getSurname();
};

