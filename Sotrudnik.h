#pragma once
#include "library.h"
#include "checkup.h"
#include "FIO.h"
#include "Account.h"
#include "Info.h"

class Sotrudnik : public FIO<string>, public Info<string>, public Account<string>
{
public:
	// ������ � �������
	void diskClear(); // ������� �����
	int diskCount(); // ������� ���������� ����������� � �����
	void diskOut(); // ������ � ����
	void diskIn(int personNumber); // ��������� ������ �� �����
	void targetDel(int personNumber, int personCount, Sotrudnik& s); // �������� ����������
	void replace(int personNumber, int personCount, Sotrudnik& s);
	void growUp(int personNumber, int personCount, Sotrudnik& s, int i);
	void swap(Sotrudnik* a, Sotrudnik* b);
	void diskCheck();
	// ��������������� ����������
	friend istream& operator>>(istream& s, Sotrudnik& d);
	friend ostream& operator<<(ostream& s, Sotrudnik& d);
};