#include "database.h"

DataBase::DataBase()
{
	db = gcnew SQLiteConnection();
}

DataBase::~DataBase()
{
	db->Close();
}


void DataBase::connectToDataBase()
{
	db->CreateFile(DATABASE_HOSTNAME);
	db->ConnectionString = "Data Source=" + DATABASE_HOSTNAME;
	db->Open();
	this->createRecordTable();
}

void DataBase::closeDataBase()
{
	db->Close();
}

void DataBase::createRecordTable()
{
	SQLiteCommand ^command = db->CreateCommand();
	command->CommandText = "CREATE TABLE "+ TABLE_TAGS +" (id INTEGER PRIMARY KEY AUTOINCREMENT, "
		+ RECORD_NAME + " VARCHAR(255) NOT NULL,"
		+ RECORD_TAGLEFT + " VARCHAR(10) NOT NULL,"
		+ RECORD_TAGRIGHT + " VARCHAR(10) NOT NULL,"
		+ RECORD_VR + " VARCHAR(5) NOT NULL,"
		+ RECORD_VM + " INTEGER NOT NULL,"
		+ RECORD_LENGTH + " VARCHAR(5) NOT NULL,"
		+ RECORD_VALUE + " TEXT NOT NULL);";
	SQLiteDataReader ^reader = command->ExecuteReader();
}

//void DataBase::insertIntoTable(std::vector<std::string> vector)
//{
//	SQLiteCommand ^command = db->CreateCommand();
//	StringBuilder ^sb = gcnew StringBuilder();
//	sb->Append("VALUES ('");
//	System::String^ str = gcnew System::String(vector[0].c_str());
//	sb->Append(str);
//	sb->Append("', '");
//	str = gcnew System::String(vector[1].c_str());
//	sb->Append(str);
//	sb->Append("' , '");
//	str = gcnew System::String(vector[2].c_str());
//	sb->Append(str);
//	sb->Append("', '");
//	str = gcnew System::String(vector[3].c_str());
//	sb->Append(str);
//	sb->Append("' , ");
//	str = gcnew System::String(vector[4].c_str());
//	sb->Append(str);
//	sb->Append(", ");
//	str = gcnew System::String(vector[5].c_str()); 
//	sb->Append(str);
//	sb->Append(", '");
//	str = gcnew System::String(vector[6].c_str());
//	sb->Append(str);
//	sb->Append("');");
//	command->CommandText = "INSERT INTO " + TABLE_TAGS + " ( "
//		+ RECORD_NAME + ", "
//		+ RECORD_TAGLEFT + ", "
//		+ RECORD_TAGRIGHT + ", "
//		+ RECORD_VR + ", "
//		+ RECORD_VM + ", "
//		+ RECORD_LENGTH + ", "
//		+ RECORD_VALUE + " ) "+sb->ToString();
//	command->ExecuteNonQuery();
//}

//void DataBase::insertIntoTable(cliext::vector<System::String^> ^v)
//{
//	SQLiteCommand ^command = db->CreateCommand();
//	StringBuilder ^sb = gcnew StringBuilder();
//	sb->Append("VALUES ('");
//	//sb->Append(vector->at(0));
//	sb->Append("', '");
//	//sb->Append(vector->at(1));
//	sb->Append("' , '");
//	//sb->Append(vector->at(2));
//	sb->Append("', '");
//	//sb->Append(vector->at(3));
//	sb->Append("' , ");
//	//sb->Append(vector->at(4));
//	sb->Append(", ");
//	//sb->Append(vector->at(5));
//	sb->Append(", '");
//	//sb->Append(vector->at(6));
//	sb->Append("');");
//	command->CommandText = "INSERT INTO " + TABLE_TAGS + " ( "
//		+ RECORD_NAME + ", "
//		+ RECORD_TAGLEFT + ", "
//		+ RECORD_TAGRIGHT + ", "
//		+ RECORD_VR + ", "
//		+ RECORD_VM + ", "
//		+ RECORD_LENGTH + ", "
//		+ RECORD_VALUE + " ) " + sb->ToString();
//	command->ExecuteNonQuery();
//}

void DataBase::insertInTable(System::String ^ name, System::String ^ tl, System::String ^ tr, System::String ^ vr, System::String ^ vm, System::String ^ length, System::String ^ value)
{
	SQLiteCommand ^command = db->CreateCommand();
	StringBuilder ^sb = gcnew StringBuilder();
	sb->Append("VALUES ('");
	sb->Append(name);
	sb->Append("', '");
	sb->Append(tl);
	sb->Append("' , '");
	sb->Append(tr);
	sb->Append("', '");
	sb->Append(vr);
	sb->Append("' , ");
	sb->Append(vm);
	sb->Append(", '");
	sb->Append(length);
	sb->Append("', '");
	sb->Append(value);
	sb->Append("');");
	command->CommandText = "INSERT INTO " + TABLE_TAGS + " ( "
		+ RECORD_NAME + ", "
		+ RECORD_TAGLEFT + ", "
		+ RECORD_TAGRIGHT + ", "
		+ RECORD_VR + ", "
		+ RECORD_VM + ", "
		+ RECORD_LENGTH + ", "
		+ RECORD_VALUE + " ) " + sb->ToString();
	command->ExecuteNonQuery();
}

//void DataBase::insertInTable(System::String^ name, System::String^ tl, System::String^ tr, System::String^ vr, System::String^ vm, System::String^ length, System::String^ value);
//{
//	SQLiteCommand ^command = db->CreateCommand();
//	StringBuilder ^sb = gcnew StringBuilder();
//	sb->Append("VALUES ('");
//	//sb->Append(vector->at(0));
//	sb->Append("', '");
//	//sb->Append(vector->at(1));
//	sb->Append("' , '");
//	//sb->Append(vector->at(2));
//	sb->Append("', '");
//	//sb->Append(vector->at(3));
//	sb->Append("' , ");
//	//sb->Append(vector->at(4));
//	sb->Append(", ");
//	//sb->Append(vector->at(5));
//	sb->Append(", '");
//	//sb->Append(vector->at(6));
//	sb->Append("');");
//	command->CommandText = "INSERT INTO " + TABLE_TAGS + " ( "
//		+ RECORD_NAME + ", "
//		+ RECORD_TAGLEFT + ", "
//		+ RECORD_TAGRIGHT + ", "
//		+ RECORD_VR + ", "
//		+ RECORD_VM + ", "
//		+ RECORD_LENGTH + ", "
//		+ RECORD_VALUE + " ) " + sb->ToString();
//	command->ExecuteNonQuery();
//}

SQLiteDataReader^ DataBase::GetAllData()
{
	SQLiteCommand ^cmdSelect = db->CreateCommand();
	cmdSelect->CommandText = "SELECT * FROM "+TABLE_TAGS+";";
	SQLiteDataReader ^reader = cmdSelect->ExecuteReader();
	return reader;
}

void DataBase::InsertAllDataToDB(System::String^ data)
{
	while (data->IndexOf("(") != -1)
	{
		data = data->Substring(data->IndexOf("("));
		if (data->Substring(data->IndexOf("(")+1,1)=="0" || data->Substring(data->IndexOf("(") + 1, 1) == "7" || data->Substring(data->IndexOf("(") + 1, 1) == "f")
			InsertRecord(data->Substring(0, data->IndexOf("\r\n")));
		else
		{
			data = data->Remove(data->IndexOf("("), 1);
		}
		data = data->Substring(data->IndexOf("\r\n") + 2);
	}
}

void DataBase::InsertRecord(System::String^ sub)
{
	cliext::vector<System::String^>^ vector = gcnew cliext::vector<System::String^>();
	System::String ^ V = sub->Substring(sub->IndexOf(" # ") + 1, sub->Length - sub->IndexOf(" # ") - 1);
	vector->push_back(V->Substring(V->IndexOf(",") + 4, V->Length - V->IndexOf(",") - 4));										//Name
	vector->push_back("0x" + sub->Substring(sub->IndexOf("(") + 1, 4));															//TagLeft
	vector->push_back("0x" + sub->Substring(sub->IndexOf(",") + 1, 4));															//TagRight
	vector->push_back(sub->Substring(sub->IndexOf(")") + 2, 2));																//VR
	vector->push_back(V->Substring(V->IndexOf(",") + 2, 1));																	//VM
	vector->push_back(EditStringLength(V->Substring(V->IndexOf(" ") + 1, V->IndexOf(",") - 2)));								//Length
	vector->push_back(EditStringValue(sub->Substring(sub->IndexOf(")") + 5, sub->IndexOf(" # ") - 5 - sub->IndexOf(")"))));	//Value
	insertInTable(vector->at(0), vector->at(1), vector->at(2), vector->at(3), vector->at(4), vector->at(5), vector->at(6));
}

System::String^ DataBase::EditStringValue(System::String^ str)
{
	int i = str->IndexOf("(");
	if (i != -1) str = str->Remove(i, 1);
	i = str->IndexOf(")");
	if (i != -1) str = str->Remove(i, 1);
	i = str->IndexOf("[");
	if (i != -1) str = str->Remove(i, 1);
	i = str->IndexOf("]");
	if (i != -1) str = str->Remove(i, 1);
	i = str->IndexOf("=");
	if (i != -1) str = str->Remove(i, 1);
	i = str->IndexOf("\0");
	if (i != -1) str = str->Remove(i, 1);
	i = str->IndexOf("'");
	while (i != -1)
	{
		str = str->Remove(i, 1);
		i = str->IndexOf("'");
	}
	return str;
}
System::String^ DataBase::EditStringLength(System::String^ str)
{
	int i = str->IndexOf(" ");
	while (i != -1)
	{
		str = str->Remove(i, 1);
		i = str->IndexOf(" ");
	}
	return str;
}

SQLiteDataReader^ DataBase::FindRecords(System::String^ name)
{
	SQLiteCommand ^cmdSelect = db->CreateCommand();
	cmdSelect->CommandText = "SELECT * FROM " + TABLE_TAGS + " WHERE "+ RECORD_NAME+ " LIKE '%"+name +"%'";
	SQLiteDataReader ^reader = cmdSelect->ExecuteReader();
	return reader;
}

int DataBase::GetNumberOfFrames()
{
	SQLiteCommand ^cmdSelect = db->CreateCommand();
	cmdSelect->CommandText = "SELECT " + RECORD_VALUE + " FROM " + TABLE_TAGS + " WHERE " + RECORD_NAME + " = 'NumberOfFrames'";
	SQLiteDataReader ^reader = cmdSelect->ExecuteReader();
	System::String^ value = "";
	while (reader->Read()) {
		value = reader->GetValue(0)->ToString();
		value = value->Trim();
	}
	if (value == "") return 1;
	else {
		int i = int::Parse(value);
		return(i);
	}
	//return 0;
}