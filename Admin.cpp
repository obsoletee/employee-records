#include "Admin.h"

void Admin::diskOut() {
	ofstream outfile;
	try {
		outfile.open("admin.dat", ios::app | ios::binary | ios::in | ios::out);
	}
	catch (...) {

		cout << "Возникла ошибка открытия файла\n";
		exit(1);
	}
	try {
		outfile.write((char*)this, sizeof(*this));
	}
	catch (...) {
		cout << "Возникла ошибка записи в файл\n";
		exit(1);
	}
}

void Admin::diskIn(int personNumber) {
	ifstream infile;
	try {
		infile.open("admin.dat", ios::binary | ios::in | ios::out);
	}
	catch (...) {
		cout << "Возникла ошибка открытия файла\n";
		exit(1);
	}
	try {
		infile.seekg(personNumber * sizeof(Admin));
		infile.read((char*)this, sizeof(*this));
	}
	catch (...) {
		cout << "Невозможно прочесть данные из файла\n";
		exit(1);
	}
}

void Admin::diskClear() {
	ifstream outfile;
	ofstream infile;
	try {
		infile.open("admin.dat", ios::trunc | ios::in | ios::out | ios::binary);
		cout << "Файл был очищен\n";
		infile.close();
	}
	catch (...) {
		cout << "Не удалось очистить файл" << endl;
		exit(1);
	}
}

int Admin::diskCount() {//подсчет число людей в файле
	ifstream infile;
	try {
		infile.open("admin.dat", ios::binary | ios::in | ios::out);
	}
	catch (...) {

		cout << "Возникла ошибка открытия файла\n";
		exit(1);
	}
	infile.seekg(0, ios::end);//перейти на позицию «0 байт от конца файла»
	return (int)infile.tellg() / sizeof(Admin);//количество людей
}

void Admin::edit(int personNumber, int personCount, Admin& s) {
	for (int i = 0; i < personNumber - 1; i++) {
		ifstream infile;
		try {
			infile.open("admin.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "Возникла ошибка открытия файла\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Admin));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "Возникла ошибка считывания данных из файла\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("admin.dat.temp", ios::app | ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "Возникла ошибка открытия файла\n";
			exit(1);
		}
		try {
			outfile.write((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "Возникла ошибка записи в файл\n";
			exit(1);
		}
		outfile.close();
	}
	cin >> s;
	ofstream outfile;
	try {
		outfile.open("admin.dat.temp", ios::app | ios::binary | ios::in | ios::out);
	}
	catch (...) {
		cout << "Возникла ошибка открытия файла\n";
		exit(1);
	}
	try {
		outfile.write((char*)this, sizeof(*this));
	}
	catch (...) {
		cout << "Возникла ошибка записи в файл\n";
		exit(1);
	}
	outfile.close();
	for (int i = personNumber; i < personCount; i++) {
		ifstream infile;
		try {
			infile.open("admin.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "Возникла ошибка открытия файла\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Admin));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "Возникла ошибка считывания данных из файла\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("admin.dat.temp", ios::app | ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "Возникла ошибка открытия файла\n";
			exit(1);
		}
		try {
			outfile.write((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "Возникла ошибка записи в файл\n";
			exit(1);
		}
		outfile.close();
	}
	remove("admin.dat");
	if (rename("admin.dat.temp", "admin.dat") != 0) {
		cout << "Ошибка переименования файла\n";
	}

}

// Получение данных от пользователя
istream& operator>>(istream& s, Admin& d) {
	int flag;
	Admin obj;
	cout << "Cоздайте данные для входа в аккаунт:\n";
	flag = 0;
	cout << "Логин: ";
	s >> d.login;
	cout << "Пароль: ";
	cin >> d.password;
	cout << endl;
	d.diskOut();
	system("pause");
	system("cls");
	return s;
}

// Вывод данных на экран
//ostream& operator<<(ostream& s, Sotrudnik& d) {
//	s << "| " << d.name << setw(17 - size(d.name));
//	s << "| " << d.surname << setw(19 - size(d.surname));
//	s << "| " << d.patronymic << setw(19 - size(d.patronymic));
//	s << fixed << setprecision(2) << "| " << d.averageGrade << setw(19 - size((to_string(((float)d.averageGrade)))));
//	s << "| " << d.faculty << setw(18 - size(d.faculty));
//	s << "| " << d.specialization << setw(22 - size(d.specialization));
//	cout << "|";
//	cout << "------------------------------------------------------------------------------------------------------------------------\n";
//	return s;
//}

void Admin::diskCheck() {
	ofstream outfile;
	try {
		outfile.open("admin.dat", ios::app | ios::binary | ios::in | ios::out);
	}
	catch (...) {

		cout << "Возникла ошибка открытия файла\n";
		exit(1);
	}
	if (outfile.fail() == 1) {
		exit(1);
	}
}