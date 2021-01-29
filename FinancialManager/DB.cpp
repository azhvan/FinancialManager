#include "DB.h"

void DB::DBConnect()
{
	//Data Source = LAPTOP - T88QPDFC; Initial Catalog = FinancialManager; Integrated Security = True
	connStringBuilder = gcnew SqlConnectionStringBuilder();
	connStringBuilder->DataSource = "LAPTOP-T88QPDFC";
	connStringBuilder->InitialCatalog = "FinancialManager";
	connStringBuilder->IntegratedSecurity = true;

	conn = gcnew SqlConnection(Convert::ToString(connStringBuilder));
}

void DB::Insert(DBInfo^ n)
{
	//Incomes_Expenses
	if (n->TransactionAmount != 0)
		try
	{
		DBConnect();

		String^ cmdText = "INSERT INTO Incomes_Expenses(Category, Date, TransactionAmount) VALUES(@CategoryInsert, @DateInsert, @TransactionAmountInsert)";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

		cmd->Parameters->AddWithValue("@CategoryInsert", n->Category);
		cmd->Parameters->AddWithValue("@DateInsert", n->Date);
		cmd->Parameters->AddWithValue("@TransactionAmountInsert", n->TransactionAmount);
		conn->Open();
		cmd->ExecuteNonQuery();
	}
	finally
	{
		if (conn != nullptr) {
			conn->Close();
		}
	}
}

void DB::Select(bool type)
{
	//Incomes_Expenses
	try
	{
		DBInfo^ n = gcnew DBInfo;
		DBConnect();
		if (type == false) {
			n->ExpensesSum = 0;
			String^ cmdText = "SELECT * FROM Incomes_Expenses WHERE Category != '�����'";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			conn->Open();

			SqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read()) {
				n->Category = (reader["Category"]->ToString());
				n->Date = (reader["Date"]->ToString());
				n->TransactionAmount = Convert::ToDouble(reader["TransactionAmount"]->ToString());
				n->ExpensesSum += n->TransactionAmount;

				Console::WriteLine(n->Date + " ���� ������� " + n->TransactionAmount + " ������� � �������i� " + n->Category);
			}
			n->IncomesSum > 0 ?
				Console::WriteLine("�������� ���� ������ �� ���� ��� " + n->ExpensesSum + " �������.") :
				Console::WriteLine("������� �i�����i");
		}
		else {
			n->IncomesSum = 0;
			String^ cmdText = "SELECT * FROM Incomes_Expenses WHERE Category = '�����'";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			conn->Open();

			SqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read()) {
				n->Date = (reader["Date"]->ToString());
				n->TransactionAmount = Convert::ToDouble(reader["TransactionAmount"]->ToString());
				n->IncomesSum += n->TransactionAmount;

				Console::WriteLine(n->Date + " ��� ���i� � " + n->TransactionAmount + " �������.");
			}
			n->IncomesSum > 0 ?
				Console::WriteLine("�������� ���� �����i� �� ���� ��� " + n->IncomesSum + " �������") :
				Console::WriteLine("������ �i�����i");
		}
	}
	finally
	{
		if (conn != nullptr) {
			conn->Close();
		}
	}
}

void DB::InitializationSum()
{
	try
	{
		DBInfo^ n = gcnew DBInfo;
		n->ExpensesSum = 0;
		n->IncomesSum = 0;
		DBConnect();

		String^ cmdText = "SELECT * FROM Incomes_Expenses";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

		conn->Open();

		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read()) {
			n->Category = (reader["Category"]->ToString());
			n->TransactionAmount = Convert::ToDouble(reader["TransactionAmount"]->ToString());
			if (n->Category == "�����")
				n->IncomesSum += n->TransactionAmount;
			else
				n->ExpensesSum += n->TransactionAmount;
		}
	}
	finally
	{
		if (conn != nullptr) {
			conn->Close();
		}
	}
}

void DB::Delete()
{
	try {
		DBInfo^ n = gcnew DBInfo;
		DBConnect();

		String^ cmdText = "DELETE FROM Incomes_Expenses";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

		conn->Open();
		cmd->ExecuteNonQuery();

	}
	finally {
		if (conn != nullptr) {
			conn->Close();
		}
	}
}
