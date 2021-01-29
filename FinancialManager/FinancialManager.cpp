#include "Methods.h"
#include "Menu.h"
#include "ExpensesMenu.h"

Menu menu;
ExpensesMenu expensesMenu;

int wmain(int argc, wchar_t* argv[], wchar_t* envp[])
{
	DB db;
	allLocale();

	while (1) {
		unsigned int option = menu.menu();

		if (option == 0) {
			DBInfo^ n = gcnew DBInfo();
			std::wcout << L"Введіть свої доходи: " << std::endl;
			long double incomes = inputDoubleNumber();
			n->TransactionAmount = incomes;
			n->Category = "Дохід";
			n->Date = date();
			db.Insert(n);
		}
		else if (option == 1)
		{
			bool exit = 1;
			while (exit) {
				long double expenses;
				DBInfo^ n = gcnew DBInfo();
				unsigned int ExpensesOption = expensesMenu.menu();
				switch (ExpensesOption)
				{
				case 0:
					std::wcout << L"Введіть свої витрати на продукти: " << std::endl;
					expenses = inputDoubleNumber();
					n->TransactionAmount = expenses;
					n->Category = "Продукти";
					n->Date = date();
					db.Insert(n);
					break;
				case 1:
					std::wcout << L"Введіть свої витрати на їжу поза домом: " << std::endl;
					expenses = inputDoubleNumber();
					n->TransactionAmount = expenses;
					n->Category = "Їжа поза домом";
					n->Date = date();
					db.Insert(n);
					break;
				case 2:
					std::wcout << L"Введіть свої витрати на транспорт: " << std::endl;
					expenses = inputDoubleNumber();
					n->TransactionAmount = expenses;
					n->Category = "Транспорт";
					n->Date = date();
					db.Insert(n);
					break;
				case 3:
					std::wcout << L"Введіть свої витрати на покупки: " << std::endl;
					expenses = inputDoubleNumber();
					n->TransactionAmount = expenses;
					n->Category = "Покупки";
					n->Date = date();
					db.Insert(n);
					break;
				case 4:
					std::wcout << L"Введіть свої витрати на домашнє господарство: " << std::endl;
					expenses = inputDoubleNumber();
					n->TransactionAmount = expenses;
					n->Category = "Домашнє господарство";
					n->Date = date();
					db.Insert(n);
					break;
				case 5:
					std::wcout << L"Введіть свої витрати на розваги: " << std::endl;
					expenses = inputDoubleNumber();
					n->TransactionAmount = expenses;
					n->Category = "Розваги";
					n->Date = date();
					db.Insert(n);
					break;
				case 6:
					std::wcout << L"Введіть свої витрати на різні послуги: " << std::endl;
					expenses = inputDoubleNumber();
					n->TransactionAmount = expenses;
					n->Category = "Послуги";
					n->Date = date();
					db.Insert(n);
					break;
				case 7:
					exit = 0;
					break;
				}
			}
		}
		else if (option == 2) {
			std::wcout << L"Ваші доходи: " << std::endl;
			db.Select(true);
			_wsystem(L"pause");
		}
		else if (option == 3)
		{
			std::wcout << L"Ваші витрати: " << std::endl;
			db.Select(false);
			_wsystem(L"pause");
		}
		else if (option == 4)
		{
			DBInfo^ n = gcnew DBInfo();
			db.InitializationSum();
			Console::WriteLine("У вас залишилося коштiв: " + (n->IncomesSum - n->ExpensesSum));
			_wsystem(L"pause");
		}
		else if (option == 5)
		{
			db.Delete();
			std::wcout << L"Ваші дані очищено" << std::endl;
			_wsystem(L"pause");
		}
		else if (option == 6)
		{
			break;
		}
	}

	return 0;
}