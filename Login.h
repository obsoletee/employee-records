#pragma once
#pragma once
#include "Admin.h"
#include "checkup.h"
#include "library.h"
#include "Sotrudnik.h"

int way1(Sotrudnik& sotrudnikk, Admin& adminn); // ������� ����������� ������
string way2(Sotrudnik& sotrudnikk); // ������� ����������� ������������
int logMenu(); // ��������� ���� � ������� ������� �����
int admMenu(Sotrudnik& sotrudnikk, Admin& adminn); // ���� ������
int sotMenu(Sotrudnik& sotrudnikk, string login);