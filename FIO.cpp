#include "FIO.h"

void FIO<string>::putName() {
	cout << "������� ���: ";
	cin >> FIO::name;
	system("cls");
}
void FIO<string>::putSurname() {
	cout << "������� �������: ";
	cin >> FIO::surname;
	system("cls");
}
void FIO<string>::putPatronymic() {
	cout << "������� ��������: ";
	cin >> FIO::patronymic;
	system("cls");
}
string FIO<string>::getSurname() {
	return surname;
}