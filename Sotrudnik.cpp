#include "Sotrudnik.h"

// Методы
void Sotrudnik::diskClear() {
	ifstream outfile;
	ofstream infile;
	try {
		outfile.open("sotrudnik.dat", ios::trunc | ios::in | ios::out | ios::binary);
		outfile.seekg(0);//поместить указатель текущей позиции в началофайла
		outfile.close();
		cout << "Файл был очищен\n";
	}
	catch (...) {
		cout << "Не удалось очистить файл" << endl;
		exit(1);
	}
}

int Sotrudnik::diskCount() {//подсчет число людей в файле
	ifstream infile;
	try {
		infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
	}
	catch (...) {

		cout << "Возникла ошибка открытия файла\n";
		exit(1);
	}
	infile.seekg(0, ios::end);//перейти на позицию «0 байт от конца файла»
	return (int)infile.tellg() / sizeof(Sotrudnik);//количество людей
}

void Sotrudnik::diskOut() {
	ofstream outfile;
	try {
		outfile.open("sotrudnik.dat", ios::app | ios::binary | ios::in | ios::out);
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

void Sotrudnik::diskIn(int personNumber) {
	ifstream infile;
	try {
		infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
	}
	catch (...) {
		cout << "Возникла ошибка открытия файла\n";
		exit(1);
	}
	try {
		infile.seekg(personNumber * sizeof(Sotrudnik));
		infile.read((char*)this, sizeof(*this));
	}
	catch (...) {
		cout << "Невозможно прочесть данные из файла\n";
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
			cout << "Возникла ошибка открытия файла\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "Возникла ошибка считывания данных из файла\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
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

	for (int i = personNumber; i < personCount; i++) {
		ifstream infile;
		try {
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "Возникла ошибка открытия файла\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "Возникла ошибка считывания данных из файла\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
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
	remove("sotrudnik.dat");
	if (rename("sotrudnik.dat.temp", "sotrudnik.dat") != 0) {
		cout << "Ошибка переименования файла\n";
	}

}

void Sotrudnik::replace(int personNumber, int personCount, Sotrudnik& s) {
	for (int i = 0; i < personNumber - 1; i++) {
		ifstream infile;
		try {
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "Возникла ошибка открытия файла\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "Возникла ошибка считывания данных из файла\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
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
	s.putID(to_string(personNumber));
	ofstream outfile;
	try {
		outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
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
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "Возникла ошибка открытия файла\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "Возникла ошибка считывания данных из файла\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
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
	remove("sotrudnik.dat");
	if (rename("sotrudnik.dat.temp", "sotrudnik.dat") != 0) {
		cout << "Ошибка переименования файла\n";
	}

}

void Sotrudnik::growUp(int personNumber, int personCount, Sotrudnik& s, int i) {
	for (int i = 0; i < personNumber; i++) {
		ifstream infile;
		try {
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "Возникла ошибка открытия файла\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "Возникла ошибка считывания данных из файла\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
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
	for (int i = personNumber + 1; i < personCount; i++) {
		ifstream infile;
		try {
			infile.open("sotrudnik.dat", ios::binary | ios::in | ios::out);
		}
		catch (...) {
			cout << "Возникла ошибка открытия файла\n";
			exit(1);
		}
		try {
			infile.seekg(i * sizeof(Sotrudnik));
			infile.read((char*)this, sizeof(*this));
		}
		catch (...) {
			cout << "Возникла ошибка считывания данных из файла\n";
			exit(1);
		}
		infile.close();
		ofstream outfile;
		try {
			outfile.open("sotrudnik.dat.temp", ios::app | ios::binary | ios::in | ios::out);
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
	remove("sotrudnik.dat");
	if (rename("sotrudnik.dat.temp", "sotrudnik.dat") != 0) {
		cout << "Ошибка переименования файла\n";
	}
}

void Sotrudnik::swap(Sotrudnik* a, Sotrudnik* b) {
	Sotrudnik temp = *a;
	*a = *b;
	*b = temp;
}

// Получение данных от пользователя
istream& operator>>(istream& s, Sotrudnik& d) {
	int flag;
	Sotrudnik obj;
	// ID сотрудника
	//while (true) {
	//	try {
	//		flag = 0;
	//		cout << "Введите трехнзначный код сотрудника: ";
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
	//			cout << "Вы ввели не трехзначное число\n";
	//			s.ignore(1024, '\n');
	//			system("pause");
	//			system("cls");
	//			continue;
	//		}
	//	}
	//	catch (...) {
	//		cout << "вы ввели не целое число\n";
	//		s.ignore(1024, '\n');
	//		system("pause");
	//		system("cls");
	//		continue;
	//	}
	//}
	cout << "Введите фамилию: ";
	s >> d.surname;
	//system("cls");
	cout << "Введите имя: ";
	s >> d.name;
	//system("cls");
	cout << "Введите отчество: ";
	s >> d.patronymic;
	//system("cls");

	// Телефон сотрудника
	while (true) {
		try {
			cout << "Введите код оператора и номер телефона '+375 (ХХ) ХХХ-ХХ-ХХ': ";
			s >> d.phone;
			if (stoi(d.phone) > 290000000 && stoi(d.phone) < 449999999) {
				//system("cls");
				break;

			}
			else {
				cout << "Вы ввели номер неправильно\n";
				s.ignore(1024, '\n');
				system("pause");
				//system("cls");
				continue;
			}
		}
		catch (...) {
			cout << "Вы ввели не целое число\n";
			s.ignore(1024, '\n');
			system("pause");
			//system("cls");
			continue;
		}
	}
	//system("cls");

	// Должность сотрудника
	while (1) {
		cout << "Выберите должность (доступные варианты приведены ниже):\n";
		cout << "1. JavaScript/Dev\n2. Python/Dev\n3. PHP/Dev\n";
		cout << "Ваш выбор: ";
		int choice;
		choice = InputI();
		if (choice < 1 || choice > 3) {
			cout << "Вы ввели неверное значение, попробуйте снова\n";
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

	// Заработная плата
	while (1) {
		cout << "Введите заработную плату (USD): ";
		s >> d.salary;
		try {
			if (stoi(d.salary) < 1) {
				cout << "Введено нулевое или отрицательное значение, попробуйте снова\n";
				s.ignore(1024, '\n');
				system("pause");
				//system("cls");
				continue;
			}
			break;
		}
		catch (...) {
			cout << "Заработная плата введена неверно\n";
			s.ignore(1024, '\n');
			system("pause");
			//system("cls");
			continue;
		}
	}
	//system("cls");

	//// Логин
	while (true) {
		flag = 0;
		cout << "Введите логин сотрудника: ";
		s >> d.login;
		/*for (int i = 0; i < obj.diskCount(); i++) {
			obj.diskIn(i);
			if (d.login == obj.login) {
				cout << "Сотрудник с таким логином уже существует\n";
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

	// Пароль
	while (true) {
		cout << "Введите пароль: ";
		s >> d.password;
		if (size(d.password) > 10) {
			cout << "Вы ввели слишком длинный пароль. Длина не должна превышать 10 символов\n";
			s.ignore(1024, '\n');
			system("pause");
			//system("cls");
			continue;
		}
		break;
	}

	return s;
}

// Вывод данных на экран
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

		cout << "Возникла ошибка открытия файла\n";
		exit(1);
	}
	if (outfile.fail() == 1) {
		exit(1);
	}
}
