#pragma once
#include "library.h"
#include "checkup.h"
#include "FIO.h"
#include "Account.h"
#include "Info.h"

class Sotrudnik : public FIO<string>, public Info<string>, public Account<string>
{
public:
	// Работа с файлами
	void diskClear(); // Очистка файла
	int diskCount(); // Подсчет количества сотрудников в файле
	void diskOut(); // Запись в файл
	void diskIn(int personNumber); // Получение данных из файла
	void targetDel(int personNumber, int personCount, Sotrudnik& s); // Удаление сотрудника
	void replace(int personNumber, int personCount, Sotrudnik& s);
	void growUp(int personNumber, int personCount, Sotrudnik& s, int i);
	void swap(Sotrudnik* a, Sotrudnik* b);
	void diskCheck();
	// Переопределение операторов
	friend istream& operator>>(istream& s, Sotrudnik& d);
	friend ostream& operator<<(ostream& s, Sotrudnik& d);
};