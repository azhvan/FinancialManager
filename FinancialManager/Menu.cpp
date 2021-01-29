#include "Menu.h"


Menu::Menu()
{
	this->item0 = L"  Ввести доходи\n",
		this->item1 = L"  Ввести витрати\n",
		this->item2 = L"  Переглянути список доходів\n",
		this->item3 = L"  Переглянути список витрат\n",
		this->item4 = L"  Переглянути загальний залишок коштів\n",
		this->item5 = L"  Очистити всі дані\n",
		this->item6 = L"  Завершити роботу\n";
}


Menu::~Menu()
{
}

int Menu::menu()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char code = 0;
	int pos = 0;
	do {
		system("cls");
		std::wcout << L"Виберіть потрібну для вас дію\n" << std::endl;
		pos = (pos + 7) % 7;
		// 1 item menu
		if (pos == 0) {
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | FocusColor));
			std::wcout << L"->" << item0;
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | StandarColor));
		}
		else {
			std::wcout << item0;
		}
		// 2 item menu
		if (pos == 1) {
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | FocusColor));
			std::wcout << L"->" << item1;
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | StandarColor));
		}
		else {
			std::wcout << item1;
		}
		// 3 item menu
		if (pos == 2) {
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | FocusColor));
			std::wcout << L"->" << item2;
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | StandarColor));
		}
		else {
			std::wcout << item2;
		}
		// 4 item menu
		if (pos == 3) {
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | FocusColor));
			std::wcout << L"->" << item3;
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | StandarColor));
		}
		else {
			std::wcout << item3;
		}
		// 5 item menu
		if (pos == 4) {
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | FocusColor));
			std::wcout << L"->" << item4;
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | StandarColor));
		}
		else {
			std::wcout << item4;
		}
		// 6 item menu
		if (pos == 5) {
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | FocusColor));
			std::wcout << L"->" << item5;
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | StandarColor));
		}
		else {
			std::wcout << item5;
		}
		// 7 item menu
		if (pos == 6) {
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | FocusColor));
			std::wcout << L"->" << item6;
			SetConsoleTextAttribute(hConsole, (WORD)((FonColor << 4) | StandarColor));
		}
		else {
			std::wcout << item6;
		}

		Sleep(100);
		code = _getch();
		if (code == UP) pos--;
		if (code == DOWN) pos++;
		if (code == F1) {
			_wsystem(L"cls");
			std::wcout << L"Використовуйте клавіші вверх та вниз для переміщення по програмі." << std::endl
				<< L"Використовуйте клавішу Enter для вибору пункту меню." << std::endl;
			system("pause");
		}
	} while (code != ENTER);
	_wsystem(L"cls");
	return pos;
}
