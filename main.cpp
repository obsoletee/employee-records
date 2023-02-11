#include "library.h"
#include "checkup.h"
#include "Sotrudnik.h"
#include "Admin.h"
#include "Login.h"
int main() {
	srand(time(0));
	system("color d");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Sotrudnik sotrudnikk;
	Admin adminn;
	//�������� ������������� ����� ������
	while (true) {
		ifstream iff("admin.dat");
		if (iff.fail() == true) iff.open("admin.dat", ios::trunc | ios::binary | ios::in | ios::out);
		iff.close();
		break;
	}
	//�������� ������������� ����� �����������
	while (true) {
		ifstream iff("sotrudnik.dat");
		if (iff.fail() == true) iff.open("sotrudnik.dat", ios::trunc | ios::binary | ios::in | ios::out);
		iff.close();
		break;
	}//�������� ������������� ����� �����������
	//�������� TEMP ������
	while (true) {
		ifstream iff("sotrudnik.dat.temp");
		if (iff.fail() == false) remove("sotrudnik.dat.temp");
		break;
	}//�������� ������������� ����� �����������
	int choice = 0;
	string login;
	while (choice != 4) {
		choice = logMenu();
		switch (choice) {
		case 1:
			if (adminn.diskCount() == 0) {
				cout << "��� ��� ������ ����, ����������, �����������������:\n";
				cin >> adminn;
				adminn.diskOut();
				cout << "����������� ������ �������, ���� ������ ���������\n";
				system("pause");
			}
			system("cls");
			if (way1(sotrudnikk, adminn) == 0) {
				break;
			}
			while (true) {
				if (admMenu(sotrudnikk, adminn) == 1) {
					cout << "�������� ������, ���������� ��� ���\n";
					continue;
				}
				break;
			}
			break;
		case 2:
			if (sotrudnikk.diskCount() == 0) {
				cout << "�� ��� �� �������� �� ������ ����������, ���������� ������� ������� ��� ������������� � �������� ������ � �����������\n\n";
				system("pause");
				break;
			}
			system("cls");
			login = way2(sotrudnikk);
			if (login == "1") {
				cout << "�������� ������, ���������� ��� ���\n";
				break;
			}
			while (true) {
				if (sotMenu(sotrudnikk, login) == 1) {
					cout << "�������� ������, ���������� ��� ���\n";
					continue;
				}
				break;
			}
			break;
		case 3:
			exit(0);
		}
	}
}