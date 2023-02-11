#include "Account.h"

void Account<string>::putLogin() {
	cout << "¬ведите логин: ";
	cin >> login;
	system("cls");
}
void Account<string>::putPassword() {
	cout << "¬ведите пароль: ";
	cin >> password;
	system("cls");
}

string Account<string>::getLogin() {
	return login;
}
string Account<string>::getPassword() {
	return password;
}