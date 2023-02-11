#include "Info.h"

void Info<string>::putPhone() {
	while (1) {
		cout << "������� ��� ��������� � ����� �������� '+375 (��) ���-��-��':\n";
		cout << "��� ���������: ";
		string code;
		cin >> code;
		if (code != "29" && code != "33" && code != "44") {
			cout << "��� ��������� ������ �������, ���������� ����� (���������� ���� ����������: '29', '33', '44')\n";
			system("pause");
			system("cls");
			continue;
		}
		else {
			cout << "����� ��������: ";
			string num;
			cin >> num;
			if (stoi(num) < 1000000 || stoi(num) > 9999999) {
				cout << "����� �������� ������ �������, ���������� ����� (����� �������� ������ ��������� ����� 7 ����)\n";
				system("pause");
				system("cls");
				continue;
			}
			Info<string>::phone = code + num;
			break;
		}
	}
	system("cls");
}
void Info<string>::putJobTitle() {
	while (1) {
		cout << "�������� ��������� (��������� �������� ��������� ����):\n";
		cout << "1. JavaScript/Dev\n2. Python/Dev\n3. PHP/Dev\n";
		cout << "��� �����: ";
		int choice;
		choice = InputI();
		if (choice < 1 || choice > 3) {
			cout << "�� ����� �������� ��������, ���������� �����\n";
			system("pause");
			system("cls");
			continue;
		}
		switch (choice) {
		case 1:
			jobTitle = "JavaScript/Dev";
			break;
		case 2:
			jobTitle = "Python/Dev";
			break;
		case 3:
			jobTitle = "PHP/Dev";
			break;
		}
		break;
	}
	system("cls");
}
void Info<string>::putSalary(string str) {
	this->salary = str;
}
void Info<string>::putID(string str) {
	this->ID = str;
}
void Info<string>::putWorkLevel(string str) {
	this->workLevel = str;
}
string Info<string>::getID() {
	return ID;
}
string Info<string>::getWorkLevel() {
	return workLevel;
}
string Info<string>::getSalary() {
	return salary;
}
string Info<string>::getJobTitle() {
	return jobTitle;
}