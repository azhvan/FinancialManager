#pragma once
#include <iostream>
#include "DBInfo.h"
using namespace System;
using namespace Data;
using namespace Data::SqlClient;
ref class DB
{
	SqlConnection^ conn;
	SqlConnectionStringBuilder^ connStringBuilder;

	void DBConnect();
public:
	void Insert(DBInfo^);

	void Select(bool);

	void InitializationSum();

	void Delete();
};

