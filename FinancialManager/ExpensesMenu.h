#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
class ExpensesMenu
{
	std::wstring
		item0,
		item1,
		item2,
		item3,
		item4,
		item5,
		item6,
		item7;

	const int FocusColor = 4;
	const int StandarColor = 15;
	const int FonColor = 0;

	const int UP = 72;
	const int DOWN = 80;
	const int ENTER = 13;
	const int ESC = 27;
	const int F1 = 59;
public:
	ExpensesMenu();
	~ExpensesMenu();
	int menu();
};

