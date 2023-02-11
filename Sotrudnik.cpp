#include "Sotrudnik.h"

// ������
void Sotrudnik::diskClear() {
	ifstream outfile;
	ofstream infile;
	try {
		outfile.open("sotrudnik.dat", ios::trunc | ios::in | ios::out | ios::binary);
		outfile.seekg(0);//��������� ��������� ������� ������� � �����������
		outfile.close();
		cout << "���� ��� ������\n";
	}
	catch (...) {
		cout << "�� ������� �������� ����" << endl;
		exit(1);
	}
}

int Sotrudnik::diskCount() {//������� ����� ����� � �����
	ifstream infile;
	try {
		infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
	}
	catch (...) {

		cout << "�������� ������ �������� �����\n";
		exit(1);
	}
	infile.seekg(0, ios::end);//������� �� ������� �0 ���� �� ����� �����
	return (int)infile.tellg() / sizeof(Sotrudnik);//���������� �����
}

void Sotrudnik::diskOut() {
	ofstream outfile;
	try {
		outfile.open("sotrudnik.dat", ios::app | ios::binary | ios::in | ios::out);
	}
	catch (...) {

		cout << "�������� ������ �������� �����\n";
		exit(1);
	}
	try {
		outfile.write((char*)this, sizeof(*this));
	}
	catch (...) {
		cout << "�������� ������ ������ � ����\n";
		exit(1);
	}
}

void Sotrudnik::diskIn(int personNumber) {
	ifstream infile;
	try {
		infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
	}
	catch (...) {
		cout << "�������� ������ �������� �����\n";
		exit(1);
	}
	try {
		infile.seekg(personNumber * sizeof(Sotrudnik));
		infile.read((char*)this, sizeof(*this));
	}
	catch (...) {
		cout << "���������� �������� ������ �� �����\n";
		exit(1);
	}
}

void Sotrudnik::targetDel(int personNumber, int personCount, Sotrudnik& s) {
	for (int i = 0; i < personNumber - 1; i++) {
		ifstream infile;
		try {
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ���������� ������ �� �����\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			outfile.write((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ������ � ����\n";
			exit(1);
		}
		outfile.close();
	}

	for (int i = personNumber; i < personCount; i++) {
		ifstream infile;
		try {
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ���������� ������ �� �����\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			outfile.write((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ������ � ����\n";
			exit(1);
		}
		outfile.close();
	}
	remove("sotrudnik.dat");
	if (rename("sotrudnik.dat.temp", "sotrudnik.dat") != 0) {
		cout << "������ �������������� �����\n";
	}

}

void Sotrudnik::replace(int personNumber, int personCount, Sotrudnik& s) {
	for (int i = 0; i < personNumber - 1; i++) {
		ifstream infile;
		try {
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ���������� ������ �� �����\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			outfile.write((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ������ � ����\n";
			exit(1);
		}
		outfile.close();
	}
	cin >> s;
	s.putID(to_string(personNumber));
	ofstream outfile;
	try {
		outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
	}
	catch (...) {
		cout << "�������� ������ �������� �����\n";
		exit(1);
	}
	try {
		outfile.write((char*)this, sizeof(*this));
	}
	catch (...) {
		cout << "�������� ������ ������ � ����\n";
		exit(1);
	}
	outfile.close();
	for (int i = personNumber; i < personCount; i++) {
		ifstream infile;
		try {
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ���������� ������ �� �����\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			outfile.write((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ������ � ����\n";
			exit(1);
		}
		outfile.close();
	}
	remove("sotrudnik.dat");
	if (rename("sotrudnik.dat.temp", "sotrudnik.dat") != 0) {
		cout << "������ �������������� �����\n";
	}

}

void Sotrudnik::growUp(int personNumber, int personCount, Sotrudnik& s, int i) {
	for (int i = 0; i < personNumber; i++) {
		ifstream infile;
		try {
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ���������� ������ �� �����\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			outfile.write((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ������ � ����\n";
			exit(1);
		}
		outfile.close();
	}
	s.diskIn(personNumber);
	int add;
	s.putWorkLevel("Level_" + to_string(i));
	add = (stoi(s.getSalary()) / 100 * (rand() % 25 + 5));
	s.putSalary(to_string(stoi(s.getSalary()) + add));
	ofstream outfile;
	try {
		outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
	}
	catch (...) {
		cout << "�������� ������ �������� �����\n";
		exit(1);
	}
	try {
		outfile.write((char*)this, sizeof(*this));
	}
	catch (...) {
		cout << "�������� ������ ������ � ����\n";
		exit(1);
	}
	outfile.close();
	for (int i = personNumber + 1; i < personCount; i++) {
		ifstream infile;
		try {
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ���������� ������ �� �����\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "�������� ������ �������� �����\n";
			exit(1);
		}
		try {
			outfile.write((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "�������� ������ ������ � ����\n";
			exit(1);
		}
		outfile.close();
	}
	remove("sotrudnik.dat");
	if (rename("sotrudnik.dat.temp", "sotrudnik.dat") != 0) {
		cout << "������ �������������� �����\n";
	}
}

void Sotrudnik::swap(Sotrudnik* a, Sotrudnik* b) {
	Sotrudnik temp = *a;
	*a = *b;
	*b = temp;
}

// ��������� ������ �� ������������
istream& operator>>(istream& s, Sotrudnik& d) {
	int flag;
	Sotrudnik obj;
	// ID ����������
	//while (true) {
	//	try {
	//		flag = 0;
	//		cout << "������� ������������ ��� ����������: ";
	//		s >> d.ID;
	//		if (stoi(d.ID) > 99 && stoi(d.ID) < 1000) {
	//			system("cls");
	//			/*for (int i = 0; i < obj.diskCount(); i++) {
	//				obj.diskIn(i);
	//				if (d.ID == obj.ID) {
	//					d.ID += obj.diskCount();
	//					break;
	//				}
	//			}*/
	//			break;
	//		}
	//		else {
	//			cout << "�� ����� �� ����������� �����\n";
	//			s.ignore(1024, '\n');
	//			system("pause");
	//			system("cls");
	//			continue;
	//		}
	//	}
	//	catch (...) {
	//		cout << "�� ����� �� ����� �����\n";
	//		s.ignore(1024, '\n');
	//		system("pause");
	//		system("cls");
	//		continue;
	//	}
	//}
	cout << "������� �������: ";
	s >> d.surname;
	//system("cls");
	cout << "������� ���: ";
	s >> d.name;
	//system("cls");
	cout << "������� ��������: ";
	s >> d.patronymic;
	//system("cls");

	// ������� ����������
	while (true) {
		try {
			cout << "������� ��� ��������� � ����� �������� '+375 (��) ���-��-��': ";
			s >> d.phone;
			if (stoi(d.phone) > 290000000 && stoi(d.phone) < 449999999) {
				//system("cls");
				break;

			}
			else {
				cout << "�� ����� ����� �����������\n";
				s.ignore(1024, '\n');
				system("pause");
				//system("cls");
				continue;
			}
		}
		catch (...) {
			cout << "�� ����� �� ����� �����\n";
			s.ignore(1024, '\n');
			system("pause");
			//system("cls");
			continue;
		}
	}
	//system("cls");

	// ��������� ����������
	while (1) {
		cout << "�������� ��������� (��������� �������� ��������� ����):\n";
		cout << "1. JavaScript/Dev\n2. Python/Dev\n3. PHP/Dev\n";
		cout << "��� �����: ";
		int choice;
		choice = InputI();
		if (choice < 1 || choice > 3) {
			cout << "�� ����� �������� ��������, ���������� �����\n";
			system("pause");
			//system("cls");
			continue;
		}
		switch (choice) {
		case 1:
			d.jobTitle = "JavaScript/Dev";
			break;
		case 2:
			d.jobTitle = "Python/Dev";
			break;
		case 3:
			d.jobTitle = "PHP/Dev";
			break;
		}
		break;
	}
	//system("cls");

	// ���������� �����
	while (1) {
		cout << "������� ���������� ����� (USD): ";
		s >> d.salary;
		try {
			if (stoi(d.salary) < 1) {
				cout << "������� ������� ��� ������������� ��������, ���������� �����\n";
				s.ignore(1024, '\n');
				system("pause");
				//system("cls");
				continue;
			}
			break;
		}
		catch (...) {
			cout << "���������� ����� ������� �������\n";
			s.ignore(1024, '\n');
			system("pause");
			//system("cls");
			continue;
		}
	}
	//system("cls");

	//// �����
	while (true) {
		flag = 0;
		cout << "������� ����� ����������: ";
		s >> d.login;
		/*for (int i = 0; i < obj.diskCount(); i++) {
			obj.diskIn(i);
			if (d.login == obj.login) {
				cout << "��������� � ����� ������� ��� ����������\n";
				s.ignore(1024, '\n');
				system("pause");
				system("cls");
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			continue;
		}*/
		break;
	}

	// ������
	while (true) {
		cout << "������� ������: ";
		s >> d.password;
		if (size(d.password) > 10) {
			cout << "�� ����� ������� ������� ������. ����� �� ������ ��������� 10 ��������\n";
			s.ignore(1024, '\n');
			system("pause");
			//system("cls");
			continue;
		}
		break;
	}

	return s;
}

// ����� ������ �� �����
ostream& operator<<(ostream& s, Sotrudnik& d) {
	s << "|   " << d.ID.substr(0, 5) << setw(7 - size(d.ID));
	s << "| " << d.surname.substr(0, 8) << setw(2) << d.name.substr(0, 1) << "." << setw(2) << d.patronymic.substr(0, 1) << "." << setw(10 - size(d.surname));
	s << "| " << "+375" << d.phone.substr(0, 10) << setw(12 - size(d.phone));
	s << "| " << d.jobTitle.substr(0, 20) << setw(22 - size(d.jobTitle));
	s << "| " << d.salary.substr(0, 6) << " USD" << setw(8 - size((d.salary)));
	s << "| " << d.workLevel.substr(0, 14) << setw(16 - size(d.workLevel));
	s << "| " << d.login.substr(0, 12) << setw(14 - size(d.login));
	s << "| " << "****" << setw(9) << "|";
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	return s;
}

void Sotrudnik::diskCheck() {
	ofstream outfile;
	try {
		outfile.open("sotrudnik.dat", ios::app | ios::binary | ios::in | ios::out);
	}
	catch (...) {

		cout << "�������� ������ �������� �����\n";
		exit(1);
	}
	if (outfile.fail() == 1) {
		exit(1);
	}
}
