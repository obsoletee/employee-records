#pragma once
#include "checkup.h"
#include "library.h"
#include "Account.h"

class Admin : public Account<string>
{
public:

	// �������
	void diskOut(); // ������ � ����
	void diskIn(int personNumber); // ��������� ������ �� �����
	int diskCount();
	void edit(int personNumber, int personCount, Admin& s); // �������������� ������
	void diskClear();
	void diskCheck();
	friend istream& operator>>(istream& s, Admin& d);
	//friend ostream& operator<<(ostream& s, Admin& d);
};

