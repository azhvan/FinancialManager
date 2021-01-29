#pragma once
using namespace System;
ref class DBInfo
{
public:
	static String^ category;

	static property String^ Category
	{
		String^ get()
		{
			return category;
		}
		void set(String^ value)
		{
			category = value;
		}
	}

	static String^ date;
	static property String^ Date
	{
		String^ get()
		{
			return date;
		}
		void set(String^ value)
		{
			date = value;
		}
	}

	static double transactionAmount;
	static property double TransactionAmount
	{
		double get()
		{
			return transactionAmount;
		}
		void set(double value)
		{
			transactionAmount = value;
		}
	}

	static double incomesSum;
	static property double IncomesSum
	{
		double get()
		{
			return incomesSum;
		}
		void set(double value)
		{
			incomesSum = value;
		}
	}

	static double expensesSum;
	static property double ExpensesSum
	{
		double get()
		{
			return expensesSum;
		}
		void set(double value)
		{
			expensesSum = value;
		}
	}
};

