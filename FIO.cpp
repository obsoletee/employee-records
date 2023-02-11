#include "FIO.h"

void FIO<string>::putName() {
	cout << "¬ведите им€: ";
	cin >> FIO::name;
	system("cls");
}
void FIO<string>::putSurname() {
	cout << "¬ведите фамилию: ";
	cin >> FIO::surname;
	system("cls");
}
void FIO<string>::putPatronymic() {
	cout << "¬ведите отчество: ";
	cin >> FIO::patronymic;
	system("cls");
}
string FIO<string>::getSurname() {
	return surname;
}