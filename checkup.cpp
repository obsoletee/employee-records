#include "checkup.h"

float InputF() {
	string str;
	while (true) {
		cin >> str;
		try {
			int num = stof(str);
			break;
		}
		catch (invalid_argument e) {
			cout << "�� ����� �� ����� �����, ��������� ����: ";
			continue;
		}
	}
	return stof(str);
}

int InputI() {
	string str;
	while (true) {
		cin >> str;
		try {
			long int num = stoi(str);
			break;
		}
		catch (invalid_argument e) {
			cout << "�� ����� �� ����� �����, ��������� ����: ";
			continue;
		}
	}
	return stoi(str);
}

void tableHeader() {
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|   ID   ";
	cout << "|      ���      ";
	cout << "|    �������    ";
	cout << "|      ���������      ";
	cout << "|    �/�    ";
	cout << "|  �����������  ";
	cout << "|    �����    ";
	cout << "|    ������   |";
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
}

void loading() {
	int perc = 0;
	while (perc < 100) {
		system("cls");
		perc += rand() % 5;
		if (perc > 100) {
			perc = 100;
		}
		cout << "���������, ���� ��������� ���������: " << perc << "%";
		Sleep(100);
	}
}
