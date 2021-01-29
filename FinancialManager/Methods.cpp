#include "Methods.h"

void change_IO_to_Unicode()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);
}

void add_font()
{
	system("mode con cols=75 lines=20"); //размер окна, вывод нужного количества строк в консоль
	HANDLE  hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD  size{ 100,100 };
	SetConsoleScreenBufferSize(hout, size);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 8;
	cfi.dwFontSize.Y = 14;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(hout, false, &cfi);
}

void allLocale()
{
	system("title Financial Manager              Версія 1.0");
	change_IO_to_Unicode();
	add_font();
}

String^ date()
{
	String^ d;
	time_t t;
	tm* tk;
	int year, month, day;
	time(&t);
	tk = localtime(&t);

	day = tk->tm_mday;
	if (day < 10) d = L"0" + Convert::ToString(day) + L".";
	else d = Convert::ToString(day) + L".";

	month = 1 + tk->tm_mon;
	if (month < 10) d += L"0" + Convert::ToString(month) + L".";
	else d += Convert::ToString(month) + L".";

	year = 1900 + tk->tm_year;
	d += Convert::ToString(year);
	return d;
}

long double inputDoubleNumber() {
	long double result = 0;
	int char_code;
	std::string buffer = "";
	bool dot = false;
	do {
		char_code = _getch();
		if (char_code == 8 && !buffer.empty()) {
			if (buffer.back() == L'.') dot = false;
			buffer.pop_back();
			std::wcout << (char)char_code << L' ' << (char)char_code;
		}
		if ((char_code > 47 && char_code < 58 || char_code == 46) && buffer.length() < 20) {
			if (char_code == 46 && dot == true) continue;
			if (char_code == 46) dot = true;
			buffer += (char)char_code;
			std::wcout << (char)char_code;
		}
	} while (char_code != 13);
	std::wcout << std::endl;
	result = strtold(buffer.c_str(), NULL);
	return result;
}