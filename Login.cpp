#include "Login.h"

int way1(Sotrudnik& sotrudnikk, Admin& adminn) {
	string log, pass;
	int flag = 0, counter = 3;
	while (counter != 0)
	{
		cout << "Вход в систему:\n";
		cout << "Введите логин (Учитывайте регистр): ";
		cin >> log;
		for (int i = 0; i < adminn.diskCount(); i++) {
			flag = 0;
			adminn.diskIn(i);
			if (log == adminn.getLogin()) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "Логин введен неверно, попробуйте снова\n";
			counter--;
			cout << "Осталось " << counter << " попытки(а)\n";
			system("pause");
			system("cls");
			continue;
		}
		else
		{
			cout << "Введите пароль: ";
			char c = 0;
			char str[70];
			int it = 0;
			do
			{
				c = _getch();
				if (c == '\b')
				{
					if (it != 0)
					{
						printf("\b \b");
						it--;
					}
				}
				else if (c == 13)
				{
					str[it] = '\0';
					it++;
				}
				else
				{
					str[it] = c;
					it++;
					printf("*");
				}

			} while (c != 13);
			for (int i = 0; i < strlen(str); i++)
			{
				pass += str[i];
			}
			for (int i = 0; i < adminn.diskCount(); i++) {
				flag = 0;
				adminn.diskIn(i);
				if (pass == adminn.getPassword()) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				system("cls");
				cout << "Пароль введен неверно, попробуйте снова\n";
				pass = "";
				counter--;
				cout << "Осталось " << counter << " попытки(а)\n";
				system("pause");
				system("cls");
				continue;
			}
			else {
				system("cls");
				cout << "Данные введены верно, вход выполнен\n";
				system("pause");
				return 1;
			}
		}
		counter--;
	}
	cout << "Вы использовали слишком много попыток, авторизация прервана\n";
	system("pause");
	exit(1);
}

string way2(Sotrudnik& sotrudnikk)
{
	string log, pass;
	int flag = 0, counter = 3;
	while (counter != 0)
	{
		cout << "Вход в систему:\n";
		cout << "Введите логин (Учитывайте регистр): ";
		cin >> log;
		for (int i = 0; i < sotrudnikk.diskCount(); i++) {
			flag = 0;
			sotrudnikk.diskIn(i);
			if (log == sotrudnikk.getLogin()) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "Логин введен неверно, попробуйте снова\n";
			counter--;
			cout << "Осталось " << counter << " попытки(а)\n";
			system("pause");
			system("cls");
			continue;
		}
		else
		{
			cout << "Введите пароль: ";
			char c = 0;
			char str[70];
			int it = 0;
			do
			{
				c = _getch();
				if (c == '\b')
				{
					if (it != 0)
					{
						printf("\b \b");
						it--;
					}
				}
				else if (c == 13)
				{
					str[it] = '\0';
					it++;
				}
				else
				{
					str[it] = c;
					it++;
					printf("*");
				}

			} while (c != 13);
			for (int i = 0; i < strlen(str); i++)
			{
				pass += str[i];
			}
			for (int i = 0; i < sotrudnikk.diskCount(); i++) {
				flag = 0;
				sotrudnikk.diskIn(i);
				if (pass == sotrudnikk.getPassword()) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				system("cls");
				cout << "Пароль введен неверно, попробуйте снова\n";
				pass = "";
				counter--;
				cout << "Осталось " << counter << " попытки(а)\n";
				system("pause");
				system("cls");
				continue;
			}
			else {
				system("cls");
				cout << "Данные введены верно, вход выполнен\n";
				system("pause");
				return log;
			}
		}
		counter--;
	}
	cout << "Вы использовали слишком много попыток, авторизация прервана\n";
	system("pause");
	exit(1);
}

int logMenu()
{
	int choice;
	while (true) {
		system("cls");
		cout << "Выберите необходимую операцию: " << endl;
		cout << "1. Вход под именем администратора" << endl;
		cout << "2. Вход под именем сотрудника" << endl;
		cout << "3. Выйти из программы" << endl;
		cout << "Ваш выбор: ";
		choice = InputI();
		system("cls");
		if (choice < 1 || choice > 3) { cout << "Вы ввели неверное число, попробуйте еще раз\n"; continue; }
		else { break; }
	}
	return choice;
}

int admMenu(Sotrudnik& sotrudnikk, Admin& adminn) {
	while (1) {

		int lvl, choice, index, n, flag = 0, a, counter = 1;
		char ch;
		string surname;
		vector<Sotrudnik> vector;
		while (1) {
			system("cls");
			cout << "Меню администратора:\n";
			cout << "1. Добавить сотрудника\n";
			cout << "2. Удалить выбранного сотрудника\n";
			cout << "3. Удалить всех сотрудников\n";
			cout << "4. Редактировать личные данные сотрудника\n";
			cout << "5. Поиск сотрудника\n";
			cout << "6. Сортировка сотрудников\n";
			cout << "7. Фильтрация сотрудников\n";
			cout << "8. Вывести данные о всех сотрудниках на экран\n";
			cout << "9. Удалить всех администраторов\n";
			cout << "10. Изменить данные администратора\n";
			cout << "11. Выход\n";
			cout << "Ваш выбор: ";
			choice = InputI();
			if (choice < 1 || choice > 11) {
				cout << "Вы ввели неверное число, попробуйте еще раз\n";
				continue;
			}
			else { break; }
		}
		switch (choice) {
		case 1:
			try {
				do {
					int counter = 1;
					system("cls");
					cout << "Введите данные о сотруднике:\n";
					for (int i = 0; i < sotrudnikk.diskCount(); i++) {
						sotrudnikk.diskIn(i);
						if (stoi(sotrudnikk.getID()) == counter) {
							counter++;
							continue;
						}
						else {
							break;
						}
					}
					sotrudnikk.putID(to_string(counter));
					cin >> sotrudnikk;

					//sotrudnikk.putID(to_string(1 + sotrudnikk.diskCount()));
					sotrudnikk.putWorkLevel("Не обучен(а)");
					sotrudnikk.diskOut();
					cout << "Ввести данные об еще одном сотруднике? (y/n): ";
					cin >> ch;
				} while (ch == 'y' || ch == 'Y');
				system("pause");
				break;
			}
			catch (...) {
				cout << "Возникла ошибка" << endl;
				system("pause");
				return 1;
			}
		case 2:
			try {
				system("cls");
				n = sotrudnikk.diskCount();
				if (n == 0) {
					cout << "Файл пуст\n"; system("pause"); break;
				}
				tableHeader();
				for (int j = 0; j < n; j++) {
					sotrudnikk.diskIn(j);
					cout << sotrudnikk;
				}
				cout << "\nВведите ID нужного сотрудника: ";
				index = InputI();
				while (index < 1 || index > 1 + n) {
					cout << "Вы ввели неверный индекс, попробуйте снова: ";
					index = InputI();
				}
				for (int i = 0; i < sotrudnikk.diskCount(); i++) {
					sotrudnikk.diskIn(i);
					if (stoi(sotrudnikk.getID()) == index) {
						break;
					}
					if (i == sotrudnikk.diskCount() - 1) {
						flag = 1;
					}
				}
				system("cls");
				if (flag == 1) {
					cout << "Сотрудник с введенным ID не найден\n";
					system("pause");
					break;
				}
				cout << "\nВыбранный сотрудник будет удален:\n";
				tableHeader();
				cout << sotrudnikk;
				cout << endl;
				flag = 1;
				do {
					cout << "Потдвертить? (y/n): ";

					cin >> ch;
					if (ch == 'y' || ch == 'Y') {
						break;
					}
					else if (ch == 'n' || ch == 'N') {
						flag = 0;
						break;
					}
					else {
						cout << "Введен неверный символ, попробуйте еще раз";
					}
				} while (1);
				if (flag == 0) {
					break;
				}
				else {
					if (sotrudnikk.diskCount() == 1) {
						system("cls");
						sotrudnikk.diskClear();
						system("cls");
						cout << "Сотрудник был удален\n";
						system("pause");
						break;
					}
					sotrudnikk.targetDel(index, n, sotrudnikk);
					system("cls");
					cout << "Сотрудник был удален\n";
					system("pause");
					break;
				}
			}
			catch (...) {
				cout << "Возникла ошибка" << endl;
				system("pause");
				return 1;
			}
		case 3:
			try {
				system("cls");
				cout << "Вы уверены, что хотите удалить все записи? (y/n): ";
				cin >> ch;
				if (ch == 'Y' || ch == 'y') {
					system("cls");
					sotrudnikk.diskClear();
					system("pause");
					break;
				}
				break;
			}
			catch (...) {
				cout << "Возникла ошибка" << endl;
				system("pause");
				return 1;
			}
		case 4:
			try {
				try {
					system("cls");
					n = sotrudnikk.diskCount();
					if (n == 0) {
						cout << "Файл пуст\n"; system("pause"); break;
					}
					tableHeader();
					for (int j = 0; j < n; j++) {
						sotrudnikk.diskIn(j);
						cout << sotrudnikk;
					}
				}
				catch (...) {
					cout << "Возникла ошибка" << endl;
					system("pause");
					break;
				}
				cout << "\nВведите ID нужного сотрудника: ";
				index = InputI();
				while (index < 1 || index > 1 + n) {
					cout << "Вы ввели неверный индекс, попробуйте еще раз: ";
					index = InputI();
				}
				for (int i = 0; i < sotrudnikk.diskCount(); i++) {
					sotrudnikk.diskIn(i);
					if (stoi(sotrudnikk.getID()) == index) {
						break;
					}
					if (i == sotrudnikk.diskCount() - 1) {
						flag = 1;
					}
				}
				system("cls");
				if (flag == 1) {
					cout << "Сотрудник с введенным ID не найден\n";
					system("pause");
					break;
				}
				cout << "Выбранный сотрудник:\n";
				tableHeader();
				cout << sotrudnikk;
				cout << endl;
				system("pause");
				system("cls");
				sotrudnikk.replace(index, n, sotrudnikk);
				system("pause");
				break;
			}
			catch (...) {
				cout << "Возникла ошибка" << endl;
				system("pause");
				return 1;
			}
		case 5:
			try {
				system("cls");
				n = sotrudnikk.diskCount();
				if (n == 0) {
					cout << "Файл пуст\n"; system("pause"); break;
				}
				while (1) {
					system("cls");
					cout << "Выберите, по какому критерию будет производиться поиск сотрудника:\n";
					cout << "1. Фамилия\n2. Должность\n3. Уровень обучения\n4. Отмена\n";
					cout << "Ваш выбор: ";
					a = InputI();
					if (a < 1 || a > 4) {
						system("cls");
						continue;
					}
					break;
				}
				system("cls");
				switch (a) {
				case 1:
					int counter;
					cout << "Введите фамилию сотрудника (Учитывайте регистр!): ";
					cin >> surname;
					system("cls");
					flag = 1;
					tableHeader();
					for (int i = 0; i < sotrudnikk.diskCount(); i++) {
						sotrudnikk.diskIn(i);
						if (sotrudnikk.getSurname() == surname) {
							cout << sotrudnikk;
							flag = 0;
						}
					}
					if (flag != 1) {
						cout << "\nПоиск завершен\n";
						system("pause");
						break;
					}
					else {
						system("cls");
						cout << "Совпадений не найдено\n";
					}
					system("pause");
					break;
				case 2:
					while (1) {
						cout << "Выберите должность (доступные варианты приведены ниже):\n";
						cout << "1. JavaScript/Dev\n2. Python/Dev\n3. PHP/Dev\n";
						cout << "Ваш выбор: ";
						choice = InputI();
						if (choice < 1 || choice > 3) {
							cout << "Вы ввели неверное значение, попробуйте снова\n";
							system("pause");
							system("cls");
							continue;
						}
						break;
					}
					system("cls");
					switch (choice) {
					case 1:
						tableHeader();
						for (int i = 0; i < sotrudnikk.diskCount(); i++) {
							sotrudnikk.diskIn(i);
							if (sotrudnikk.getJobTitle() == "JavaScript/Dev") {
								cout << sotrudnikk;
								flag = 1;
							}
						}
						break;
					case 2:
						tableHeader();
						for (int i = 0; i < sotrudnikk.diskCount(); i++) {
							sotrudnikk.diskIn(i);
							if (sotrudnikk.getJobTitle() == "Python/Dev") {
								cout << sotrudnikk;
								flag = 1;
							}
						}
						break;
					case 3:
						tableHeader();
						for (int i = 0; i < sotrudnikk.diskCount(); i++) {
							sotrudnikk.diskIn(i);
							if (sotrudnikk.getJobTitle() == "PHP/Dev") {
								cout << sotrudnikk;
								flag = 1;
							}
						}
						break;
					}
					if (flag != 0) {
						cout << "\nПоиск завершен\n";
						system("pause");
						break;
					}
					else {
						system("cls");
						cout << "Совпадений не найдено\n";
						system("pause");
						break;
					}
				case 3:
					while (true) {
						cout << "Введите уровень обученности (0-3) сотрудника: ";
						lvl = InputI();
						if (lvl < 0 || lvl > 3) {
							cout << "Введите число от 0 до 3\n";
							system("pause");
							system("cls");
							continue;
						}
						break;
					}
					switch (lvl) {
					case 0:
						tableHeader();
						for (int i = 0; i < sotrudnikk.diskCount(); i++) {
							sotrudnikk.diskIn(i);
							if (sotrudnikk.getWorkLevel() == "Не обучен(а)") {
								cout << sotrudnikk;
								flag = 1;
							}
						}
						break;
					case 1:
						tableHeader();
						for (int i = 0; i < sotrudnikk.diskCount(); i++) {
							sotrudnikk.diskIn(i);
							if (sotrudnikk.getWorkLevel() == "Level_1") {
								cout << sotrudnikk;
								flag = 1;
							}
						}
						break;
					case 2:
						tableHeader();
						for (int i = 0; i < sotrudnikk.diskCount(); i++) {
							sotrudnikk.diskIn(i);
							if (sotrudnikk.getWorkLevel() == "Level_2") {
								cout << sotrudnikk;
								flag = 1;
							}
						}
						break;
					case 3:
						tableHeader();
						for (int i = 0; i < sotrudnikk.diskCount(); i++) {
							sotrudnikk.diskIn(i);
							if (sotrudnikk.getWorkLevel() == "Level_3") {
								cout << sotrudnikk;
								flag = 1;
							}
						}
						break;
					}
					if (flag != 0) {
						cout << "\nПоиск завершен\n";
						system("pause");
						break;
					}
					else {
						system("cls");
						cout << "Совпадений не найдено\n";
						system("pause");
						break;
					}
				case 4:
					system("cls");
					break;
				}
				break;
			}
			catch (...) {
				cout << "\nВозникла ошибка" << endl;
				system("pause");
				break;
			}
		case 6:
			try {
				system("cls");
				n = sotrudnikk.diskCount();
				if (n == 0) {
					cout << "Файл пуст\n"; system("pause"); break;
				}
				while (1) {
					system("cls");
					cout << "Выберите, по какому критерию будет производиться сортировка сотрудника:\n";
					cout << "1. Идентификационный номер\n2. Зарплата\n3. Отмена\n";
					cout << "Ваш выбор: ";
					a = InputI();
					if (a < 1 || a > 3) {
						system("cls");
						continue;
					}
					break;
				}
				system("cls");
				switch (a) {
				case 1:
					for (int i = 0; i < sotrudnikk.diskCount(); i++) {
						sotrudnikk.diskIn(i);
						vector.push_back(sotrudnikk);
					}
					for (int i = 0; i < vector.size() - 1; i++) {
						for (int j = 0; j < vector.size() - i - 1; j++) {
							if (stoi(vector.at(j).getID()) > stoi(vector.at(j + 1).getID())) {
								swap(vector.at(j), vector.at(j + 1));
							}
						}
					}
					sotrudnikk.diskClear();
					for (int i = 0; i < vector.size(); i++) {
						vector.at(i).diskOut();
					}
					system("cls");
					cout << "Отсортированная таблица\n";
					tableHeader();
					for (int i = 0; i < sotrudnikk.diskCount(); i++) {
						sotrudnikk.diskIn(i);
						cout << sotrudnikk;

					}
					system("pause");
					vector.clear();
					break;
				case 2:
					for (int i = 0; i < sotrudnikk.diskCount(); i++) {
						sotrudnikk.diskIn(i);
						vector.push_back(sotrudnikk);
					}
					for (int i = 0; i < vector.size() - 1; i++) {
						for (int j = 0; j < vector.size() - i - 1; j++) {
							if (stoi(vector.at(j).getSalary()) > stoi(vector.at(j + 1).getSalary())) {
								swap(vector.at(j), vector.at(j + 1));
							}
						}
					}
					sotrudnikk.diskClear();
					for (int i = 0; i < vector.size(); i++) {
						vector.at(i).diskOut();
					}
					system("cls");
					cout << "Отсортированная таблица\n";
					tableHeader();
					for (int i = 0; i < sotrudnikk.diskCount(); i++) {
						sotrudnikk.diskIn(i);
						cout << sotrudnikk;

					}
					system("pause");
					vector.clear();
					break;
				case 3:
					system("cls");
					break;
				}
				break;
			}
			catch (...) {
				cout << "\nВозникла ошибка" << endl;
				system("pause");
				break;
			}
		case 7:
			try {
				system("cls");
				n = sotrudnikk.diskCount();
				if (n == 0) {
					cout << "Файл пуст\n"; system("pause"); break;
				}
				while (1) {
					system("cls");
					cout << "Выберите, по какому критерию будет производиться фильтрация:\n";
					cout << "1. Зарплата\n2. Уровень обученности\n3. Отмена\n";
					cout << "Ваш выбор: ";
					a = InputI();
					if (a < 1 || a > 4) {
						system("cls");
						continue;
					}
					break;
				}
				string val1, val2;
				switch (a) {
				case 1:
					while (1) {
						try {
							system("cls");
							cout << "Введите диапазон заработных плат\n";
							cout << "Нижний порог: ";
							cin >> val1;
							if (stoi(val1) < 0) {
								cout << "Неверный ввод, попробуйте еще раз\n";
								system("pause");
								continue;
							}
							cout << "Верхний порог: ";
							cin >> val2;
							if (stoi(val2) < 0 || stoi(val2) < stoi(val1)) {
								cout << "Неверный ввод, попробуйте еще раз\n";
								system("pause");
								continue;
							}
							break;
						}
						catch (...) {
							cout << "Введите целое число\n";
							system("pause");
							continue;
						}
					}
					system("cls");
					tableHeader();
					for (int i = 0; i < sotrudnikk.diskCount(); i++) {
						sotrudnikk.diskIn(i);
						if (stoi(sotrudnikk.getSalary()) >= stoi(val1) && stoi(sotrudnikk.getSalary()) <= stoi(val2)) {
							cout << sotrudnikk;
						}
					}
					system("pause");
					break;
				case 2:
					while (1) {
						try {
							system("cls");
							cout << "Введите диапазон уровней обученности\n";
							cout << "Нижний порог: ";
							cin >> val1;
							if (stoi(val1) < 0 || stoi(val1) > 3) {
								cout << "Неверный ввод, попробуйте еще раз\n";
								system("pause");
								continue;
							}
							cout << "Верхний порог: ";
							cin >> val2;
							if (stoi(val2) < 0 || stoi(val2) < stoi(val1)) {
								cout << "Неверный ввод, попробуйте еще раз\n";
								system("pause");
								continue;
							}
							break;
						}
						catch (...) {
							cout << "Введите целое число\n";
							system("pause");
							continue;
						}
					}
					system("cls");
					tableHeader();
					for (int i = stoi(val1); i <= stoi(val2); i++) {
						for (int j = 0; j < sotrudnikk.diskCount(); j++) {
							sotrudnikk.diskIn(j);
							if (i == 0) {
								if (sotrudnikk.getWorkLevel() == "Не обучен(а)") {
									cout << sotrudnikk;
								}
							}
							if (i == 1) {
								if (sotrudnikk.getWorkLevel() == "Level_1") {
									cout << sotrudnikk;
								}
							}
							if (i == 2) {
								if (sotrudnikk.getWorkLevel() == "Level_2") {
									cout << sotrudnikk;
								}
							}
							if (i == 3) {
								if (sotrudnikk.getWorkLevel() == "Level_3") {
									cout << sotrudnikk;
								}
							}
						}
					}
					system("pause");
					break;
				case 3:
					system("cls");
					break;
				}
				break;
			}
			catch (...) {
				cout << "\nВозникла ошибка" << endl;
				system("pause");
				break;
			}
		case 8:
			try {
				system("cls");
				if (sotrudnikk.diskCount() == 0) {
					cout << "Файл пуст\n"; system("pause"); break;
				}
				tableHeader();
				for (int j = 0; j < sotrudnikk.diskCount(); j++) {
					sotrudnikk.diskIn(j);
					cout << sotrudnikk;
				}
				system("pause");
				break;
			}
			catch (...) {
				cout << "Возникла ошибка" << endl;
				system("pause");
				return 1;
			}
		case 9:
			try {
				system("cls");
				adminn.diskClear();
				cout << "Все аккаунты удалены, сессия вынуждена завершиться\n";
				system("pause");
				exit(0);
			}
			catch (...) {
				cout << "Возникла ошибка" << endl;
				system("pause");
				return 1;
			}
		case 10:
			try {
				system("cls");
				adminn.diskClear();
				system("cls");
				cin >> adminn;
				cout << "Данные успешно отредактированы\n";
				system("pause");
				system("cls");
				break;
			}
			catch (...) {
				cout << "Возникла ошибка" << endl;
				system("pause");
				return 1;
			}
		case 11:
			return 0;
		}
	}
}

int sotMenu(Sotrudnik& sotrudnikk, string login)
{
	int choice, index, n, flag = 0, a, counter = 1;
	char ch;
	while (1) {
		while (1) {
			system("cls");
			cout << "Меню пользователя:\n";
			cout << "1. Профиль\n";
			cout << "2. Редактировать данные профиля\n";
			cout << "3. Пройти обучение\n";
			cout << "4. Удалить профиль\n";
			cout << "5. Выход\n";
			choice = InputI();
			if (choice < 1 || choice > 5) {
				cout << "Вы ввели неверное число, попробуйте еще раз\n";
				continue;
			}
			else { break; }
		}
		switch (choice) {
		case 1:
			try {
				system("cls");
				for (int i = 0; i < sotrudnikk.diskCount(); i++) {
					sotrudnikk.diskIn(i);
					if (sotrudnikk.getLogin() == login) {
						cout << "Ваш профиль:\n\n";
						tableHeader();
						cout << sotrudnikk;
						system("pause");
						break;
					}
				}
				system("cls");
				break;
			}
			catch (...) {
				cout << "Возникла ошибка\n";
				system("pause");
				system("cls");
				return 0;
			}
		case 2:
			try {
				while (true) {
					system("cls");
					for (int i = 0; i < sotrudnikk.diskCount(); i++) {
						sotrudnikk.diskIn(i);
						if (sotrudnikk.getLogin() == login) {
							cout << "Ваш профиль:\n\n";
							tableHeader();
							cout << sotrudnikk;
							cout << "\nВы уверены, что хотите отредактировать данные? (y/n): ";
							cin >> ch;
							if (ch == 'Y' || ch == 'y') {
								flag = 1;
							}
							system("pause");
							break;
						}
					}
					if (flag == 1) {
						system("cls");
						sotrudnikk.replace(stoi(sotrudnikk.getID()), sotrudnikk.diskCount(), sotrudnikk);
						system("cls");
						cout << "Данные отредактированы, зайдите в профиль, чтобы увидеть изменения\n";
						system("pause");
						system("cls");
						break;
					}
					break;
				}
				break;
			}
			catch (...) {
				cout << "Возникла ошибка\n";
				system("pause");
				system("cls");
				return 0;
			}
		case 3:
			try {
				int num = 0;
				system("cls");
				for (num; num < sotrudnikk.diskCount(); num++) {
					sotrudnikk.diskIn(num);
					if (sotrudnikk.getLogin() == login) {
						break;
					}
				}
				if (sotrudnikk.getWorkLevel() == "Не обучен(а)") {
					loading();
					cout << "\nОбучение завершено, зарплата повышена\n";
					system("pause");
					sotrudnikk.growUp(num, sotrudnikk.diskCount(), sotrudnikk, 1);
					system("cls");
					break;
				}
				else if (sotrudnikk.getWorkLevel() == "Level_1") {
					loading();
					cout << "\nОбучение завершено, зарплата повышена\n";
					system("pause");
					sotrudnikk.growUp(num, sotrudnikk.diskCount(), sotrudnikk, 2);
					system("cls");
					break;
				}
				else if (sotrudnikk.getWorkLevel() == "Level_2") {
					loading();
					cout << "\nОбучение завершено, зарплата повышена\n";
					system("pause");
					sotrudnikk.growUp(num, sotrudnikk.diskCount(), sotrudnikk, 3);
					system("cls");
					break;
				}
				else {
					cout << "Сотрудник максимально обучен, дальнейшее обучение невозможно\n";
					system("pause");
					break;
				}
			}
			catch (...) {
				cout << "Возникла ошибка" << endl;
				system("pause");
				return 1;
			}
		case 4:
			try {
				flag = 1;
				system("cls");
				for (int i = 0; i < sotrudnikk.diskCount(); i++) {
					sotrudnikk.diskIn(i);
					if (sotrudnikk.getLogin() == login) {
						cout << "Ваш профиль будет удален:\n\n";
						tableHeader();
						cout << sotrudnikk;
						do {
							cout << "Потдвертить? (y/n): ";

							cin >> ch;
							if (ch == 'y' || ch == 'Y') {
								break;
							}
							else if (ch == 'n' || ch == 'N') {
								flag = 0;
								break;
							}
							else {
								cout << "Введен неверный символ, попробуйте еще раз";
							}
						} while (1);
						if (flag == 0) {
							break;
						}
						else {
							if (sotrudnikk.diskCount() == 1) {
								system("cls");
								sotrudnikk.diskClear();
								cout << "Сотрудник был удален\n";
								system("cls");
								system("pause");
								return 0;
							}
							sotrudnikk.targetDel(stoi(sotrudnikk.getID()), sotrudnikk.diskCount(), sotrudnikk);
							system("cls");
							cout << "Сотрудник был удален\n";
							system("pause");
							return 0;
						}
					}
				}
				system("cls");
				break;
			}
			catch (...) {
				cout << "Возникла ошибка" << endl;
				system("pause");
				return 1;
			}
		case 5:
			return 0;
		}
	}
}
