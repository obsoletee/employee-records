#pragma once
#pragma once
#include "Admin.h"
#include "checkup.h"
#include "library.h"
#include "Sotrudnik.h"

int way1(Sotrudnik& sotrudnikk, Admin& adminn); // Процесс авторизации админа
string way2(Sotrudnik& sotrudnikk); // Процесс авторизации пользователя
int logMenu(); // Стартовое меню я выбором способа входа
int admMenu(Sotrudnik& sotrudnikk, Admin& adminn); // Меню админа
int sotMenu(Sotrudnik& sotrudnikk, string login);