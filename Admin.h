#pragma once
#include "checkup.h"
#include "library.h"
#include "Account.h"

class Admin : public Account<string>
{
public:

	// Геттеры
	void diskOut(); // Запись в файл
	void diskIn(int personNumber); // Получение данных из файла
	int diskCount();
	void edit(int personNumber, int personCount, Admin& s); // Редактирование данных
	void diskClear();
	void diskCheck();
	friend istream& operator>>(istream& s, Admin& d);
	//friend ostream& operator<<(ostream& s, Admin& d);
};

