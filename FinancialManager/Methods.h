#pragma once
#include <time.h>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include "DB.h"
using namespace System;

void change_IO_to_Unicode();

void add_font();

void allLocale();

String^ date();

bool checkCorrectInput(std::string);

long double inputDoubleNumber();