#include "Account.h"

void Account<string>::putLogin() {
	cout << "������� �����: ";
	cin >> login;
	system("cls");
}
void Account<string>::putPassword() {
	cout << "������� ������: ";
	cin >> password;
	system("cls");
}

string Account<string>::getLogin() {
	return login;
}
string Account<string>::getPassword() {
	return password;
}