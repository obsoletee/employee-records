#include "Login.h"

int way1(Sotrudnik& sotrudnikk, Admin& adminn) {
	string log, pass;
	int flag = 0, counter = 3;
	while (counter != 0)
	{
		cout << "���� � �������:\n";
		cout << "������� ����� (���������� �������): ";
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
			cout << "����� ������ �������, ���������� �����\n";
			counter--;
			cout << "�������� " << counter << " �������(�)\n";
			system("pause");
			system("cls");
			continue;
		}
		else
		{
			cout << "������� ������: ";
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
				cout << "������ ������ �������, ���������� �����\n";
				pass = "";
				counter--;
				cout << "�������� " << counter << " �������(�)\n";
				system("pause");
				system("cls");
				continue;
			}
			else {
				system("cls");
				cout << "������ ������� �����, ���� ��������\n";
				system("pause");
				return 1;
			}
		}
		counter--;
	}
	cout << "�� ������������ ������� ����� �������, ����������� ��������\n";
	system("pause");
	exit(1);
}

string way2(Sotrudnik& sotrudnikk)
{
	string log, pass;
	int flag = 0, counter = 3;
	while (counter != 0)
	{
		cout << "���� � �������:\n";
		cout << "������� ����� (���������� �������): ";
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
			cout << "����� ������ �������, ���������� �����\n";
			counter--;
			cout << "�������� " << counter << " �������(�)\n";
			system("pause");
			system("cls");
			continue;
		}
		else
		{
			cout << "������� ������: ";
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
				cout << "������ ������ �������, ���������� �����\n";
				pass = "";
				counter--;
				cout << "�������� " << counter << " �������(�)\n";
				system("pause");
				system("cls");
				continue;
			}
			else {
				system("cls");
				cout << "������ ������� �����, ���� ��������\n";
				system("pause");
				return log;
			}
		}
		counter--;
	}
	cout << "�� ������������ ������� ����� �������, ����������� ��������\n";
	system("pause");
	exit(1);
}

int logMenu()
{
	int choice;
	while (true) {
		system("cls");
		cout << "�������� ����������� ��������: " << endl;
		cout << "1. ���� ��� ������ ��������������" << endl;
		cout << "2. ���� ��� ������ ����������" << endl;
		cout << "3. ����� �� ���������" << endl;
		cout << "��� �����: ";
		choice = InputI();
		system("cls");
		if (choice < 1 || choice > 3) { cout << "�� ����� �������� �����, ���������� ��� ���\n"; continue; }
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
			cout << "���� ��������������:\n";
			cout << "1. �������� ����������\n";
			cout << "2. ������� ���������� ����������\n";
			cout << "3. ������� ���� �����������\n";
			cout << "4. ������������� ������ ������ ����������\n";
			cout << "5. ����� ����������\n";
			cout << "6. ���������� �����������\n";
			cout << "7. ���������� �����������\n";
			cout << "8. ������� ������ � ���� ����������� �� �����\n";
			cout << "9. ������� ���� ���������������\n";
			cout << "10. �������� ������ ��������������\n";
			cout << "11. �����\n";
			cout << "��� �����: ";
			choice = InputI();
			if (choice < 1 || choice > 11) {
				cout << "�� ����� �������� �����, ���������� ��� ���\n";
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
					cout << "������� ������ � ����������:\n";
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
					sotrudnikk.putWorkLevel("�� ������(�)");
					sotrudnikk.diskOut();
					cout << "������ ������ �� ��� ����� ����������? (y/n): ";
					cin >> ch;
				} while (ch == 'y' || ch == 'Y');
				system("pause");
				break;
			}
			catch (...) {
				cout << "�������� ������" << endl;
				system("pause");
				return 1;
			}
		case 2:
			try {
				system("cls");
				n = sotrudnikk.diskCount();
				if (n == 0) {
					cout << "���� ����\n"; system("pause"); break;
				}
				tableHeader();
				for (int j = 0; j < n; j++) {
					sotrudnikk.diskIn(j);
					cout << sotrudnikk;
				}
				cout << "\n������� ID ������� ����������: ";
				index = InputI();
				while (index < 1 || index > 1 + n) {
					cout << "�� ����� �������� ������, ���������� �����: ";
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
					cout << "��������� � ��������� ID �� ������\n";
					system("pause");
					break;
				}
				cout << "\n��������� ��������� ����� ������:\n";
				tableHeader();
				cout << sotrudnikk;
				cout << endl;
				flag = 1;
				do {
					cout << "�����������? (y/n): ";

					cin >> ch;
					if (ch == 'y' || ch == 'Y') {
						break;
					}
					else if (ch == 'n' || ch == 'N') {
						flag = 0;
						break;
					}
					else {
						cout << "������ �������� ������, ���������� ��� ���";
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
						cout << "��������� ��� ������\n";
						system("pause");
						break;
					}
					sotrudnikk.targetDel(index, n, sotrudnikk);
					system("cls");
					cout << "��������� ��� ������\n";
					system("pause");
					break;
				}
			}
			catch (...) {
				cout << "�������� ������" << endl;
				system("pause");
				return 1;
			}
		case 3:
			try {
				system("cls");
				cout << "�� �������, ��� ������ ������� ��� ������? (y/n): ";
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
				cout << "�������� ������" << endl;
				system("pause");
				return 1;
			}
		case 4:
			try {
				try {
					system("cls");
					n = sotrudnikk.diskCount();
					if (n == 0) {
						cout << "���� ����\n"; system("pause"); break;
					}
					tableHeader();
					for (int j = 0; j < n; j++) {
						sotrudnikk.diskIn(j);
						cout << sotrudnikk;
					}
				}
				catch (...) {
					cout << "�������� ������" << endl;
					system("pause");
					break;
				}
				cout << "\n������� ID ������� ����������: ";
				index = InputI();
				while (index < 1 || index > 1 + n) {
					cout << "�� ����� �������� ������, ���������� ��� ���: ";
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
					cout << "��������� � ��������� ID �� ������\n";
					system("pause");
					break;
				}
				cout << "��������� ���������:\n";
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
				cout << "�������� ������" << endl;
				system("pause");
				return 1;
			}
		case 5:
			try {
				system("cls");
				n = sotrudnikk.diskCount();
				if (n == 0) {
					cout << "���� ����\n"; system("pause"); break;
				}
				while (1) {
					system("cls");
					cout << "��������, �� ������ �������� ����� ������������� ����� ����������:\n";
					cout << "1. �������\n2. ���������\n3. ������� ��������\n4. ������\n";
					cout << "��� �����: ";
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
					cout << "������� ������� ���������� (���������� �������!): ";
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
						cout << "\n����� ��������\n";
						system("pause");
						break;
					}
					else {
						system("cls");
						cout << "���������� �� �������\n";
					}
					system("pause");
					break;
				case 2:
					while (1) {
						cout << "�������� ��������� (��������� �������� ��������� ����):\n";
						cout << "1. JavaScript/Dev\n2. Python/Dev\n3. PHP/Dev\n";
						cout << "��� �����: ";
						choice = InputI();
						if (choice < 1 || choice > 3) {
							cout << "�� ����� �������� ��������, ���������� �����\n";
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
						cout << "\n����� ��������\n";
						system("pause");
						break;
					}
					else {
						system("cls");
						cout << "���������� �� �������\n";
						system("pause");
						break;
					}
				case 3:
					while (true) {
						cout << "������� ������� ����������� (0-3) ����������: ";
						lvl = InputI();
						if (lvl < 0 || lvl > 3) {
							cout << "������� ����� �� 0 �� 3\n";
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
							if (sotrudnikk.getWorkLevel() == "�� ������(�)") {
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
						cout << "\n����� ��������\n";
						system("pause");
						break;
					}
					else {
						system("cls");
						cout << "���������� �� �������\n";
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
				cout << "\n�������� ������" << endl;
				system("pause");
				break;
			}
		case 6:
			try {
				system("cls");
				n = sotrudnikk.diskCount();
				if (n == 0) {
					cout << "���� ����\n"; system("pause"); break;
				}
				while (1) {
					system("cls");
					cout << "��������, �� ������ �������� ����� ������������� ���������� ����������:\n";
					cout << "1. ����������������� �����\n2. ��������\n3. ������\n";
					cout << "��� �����: ";
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
					cout << "��������������� �������\n";
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
					cout << "��������������� �������\n";
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
				cout << "\n�������� ������" << endl;
				system("pause");
				break;
			}
		case 7:
			try {
				system("cls");
				n = sotrudnikk.diskCount();
				if (n == 0) {
					cout << "���� ����\n"; system("pause"); break;
				}
				while (1) {
					system("cls");
					cout << "��������, �� ������ �������� ����� ������������� ����������:\n";
					cout << "1. ��������\n2. ������� �����������\n3. ������\n";
					cout << "��� �����: ";
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
							cout << "������� �������� ���������� ����\n";
							cout << "������ �����: ";
							cin >> val1;
							if (stoi(val1) < 0) {
								cout << "�������� ����, ���������� ��� ���\n";
								system("pause");
								continue;
							}
							cout << "������� �����: ";
							cin >> val2;
							if (stoi(val2) < 0 || stoi(val2) < stoi(val1)) {
								cout << "�������� ����, ���������� ��� ���\n";
								system("pause");
								continue;
							}
							break;
						}
						catch (...) {
							cout << "������� ����� �����\n";
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
							cout << "������� �������� ������� �����������\n";
							cout << "������ �����: ";
							cin >> val1;
							if (stoi(val1) < 0 || stoi(val1) > 3) {
								cout << "�������� ����, ���������� ��� ���\n";
								system("pause");
								continue;
							}
							cout << "������� �����: ";
							cin >> val2;
							if (stoi(val2) < 0 || stoi(val2) < stoi(val1)) {
								cout << "�������� ����, ���������� ��� ���\n";
								system("pause");
								continue;
							}
							break;
						}
						catch (...) {
							cout << "������� ����� �����\n";
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
								if (sotrudnikk.getWorkLevel() == "�� ������(�)") {
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
				cout << "\n�������� ������" << endl;
				system("pause");
				break;
			}
		case 8:
			try {
				system("cls");
				if (sotrudnikk.diskCount() == 0) {
					cout << "���� ����\n"; system("pause"); break;
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
				cout << "�������� ������" << endl;
				system("pause");
				return 1;
			}
		case 9:
			try {
				system("cls");
				adminn.diskClear();
				cout << "��� �������� �������, ������ ��������� �����������\n";
				system("pause");
				exit(0);
			}
			catch (...) {
				cout << "�������� ������" << endl;
				system("pause");
				return 1;
			}
		case 10:
			try {
				system("cls");
				adminn.diskClear();
				system("cls");
				cin >> adminn;
				cout << "������ ������� ���������������\n";
				system("pause");
				system("cls");
				break;
			}
			catch (...) {
				cout << "�������� ������" << endl;
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
			cout << "���� ������������:\n";
			cout << "1. �������\n";
			cout << "2. ������������� ������ �������\n";
			cout << "3. ������ ��������\n";
			cout << "4. ������� �������\n";
			cout << "5. �����\n";
			choice = InputI();
			if (choice < 1 || choice > 5) {
				cout << "�� ����� �������� �����, ���������� ��� ���\n";
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
						cout << "��� �������:\n\n";
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
				cout << "�������� ������\n";
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
							cout << "��� �������:\n\n";
							tableHeader();
							cout << sotrudnikk;
							cout << "\n�� �������, ��� ������ ��������������� ������? (y/n): ";
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
						cout << "������ ���������������, ������� � �������, ����� ������� ���������\n";
						system("pause");
						system("cls");
						break;
					}
					break;
				}
				break;
			}
			catch (...) {
				cout << "�������� ������\n";
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
				if (sotrudnikk.getWorkLevel() == "�� ������(�)") {
					loading();
					cout << "\n�������� ���������, �������� ��������\n";
					system("pause");
					sotrudnikk.growUp(num, sotrudnikk.diskCount(), sotrudnikk, 1);
					system("cls");
					break;
				}
				else if (sotrudnikk.getWorkLevel() == "Level_1") {
					loading();
					cout << "\n�������� ���������, �������� ��������\n";
					system("pause");
					sotrudnikk.growUp(num, sotrudnikk.diskCount(), sotrudnikk, 2);
					system("cls");
					break;
				}
				else if (sotrudnikk.getWorkLevel() == "Level_2") {
					loading();
					cout << "\n�������� ���������, �������� ��������\n";
					system("pause");
					sotrudnikk.growUp(num, sotrudnikk.diskCount(), sotrudnikk, 3);
					system("cls");
					break;
				}
				else {
					cout << "��������� ����������� ������, ���������� �������� ����������\n";
					system("pause");
					break;
				}
			}
			catch (...) {
				cout << "�������� ������" << endl;
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
						cout << "��� ������� ����� ������:\n\n";
						tableHeader();
						cout << sotrudnikk;
						do {
							cout << "�����������? (y/n): ";

							cin >> ch;
							if (ch == 'y' || ch == 'Y') {
								break;
							}
							else if (ch == 'n' || ch == 'N') {
								flag = 0;
								break;
							}
							else {
								cout << "������ �������� ������, ���������� ��� ���";
							}
						} while (1);
						if (flag == 0) {
							break;
						}
						else {
							if (sotrudnikk.diskCount() == 1) {
								system("cls");
								sotrudnikk.diskClear();
								cout << "��������� ��� ������\n";
								system("cls");
								system("pause");
								return 0;
							}
							sotrudnikk.targetDel(stoi(sotrudnikk.getID()), sotrudnikk.diskCount(), sotrudnikk);
							system("cls");
							cout << "��������� ��� ������\n";
							system("pause");
							return 0;
						}
					}
				}
				system("cls");
				break;
			}
			catch (...) {
				cout << "�������� ������" << endl;
				system("pause");
				return 1;
			}
		case 5:
			return 0;
		}
	}
}
