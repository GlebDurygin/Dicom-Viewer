#pragma once

#include <io.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cliext/vector>

#define DATABASE_HOSTNAME           "DataBaseTags.db"
#define TABLE_TAGS                  "TableTags"
#define TABLE_FILES                 "TableFiles"
#define RECORD_NAME                 "Name"
#define RECORD_TAGLEFT				"TagLeft"
#define RECORD_TAGRIGHT				"TagRigth"
#define RECORD_VR					"VR"
#define RECORD_VM					"VM"
#define RECORD_LENGTH				"Length"
#define RECORD_VALUE                "Value"

using namespace System::Text;
using namespace System::Data::SQLite;


ref class DataBase
{
public:
	explicit DataBase();
	~DataBase();
	void connectToDataBase();
	//void insertIntoTable(std::vector<std::string> vector);
	//void insertIntoTable(cliext::vector<System::String^>^ v);
	void insertInTable(System::String^ name, System::String^ tl,System::String^ tr, System::String^ vr, System::String^ vm, System::String^ length, System::String^ value);
	SQLiteDataReader^ GetAllData();
	//void ConvertDataToDB(std::fstream file);
	void InsertAllDataToDB(System::String^ data);
	SQLiteDataReader^ FindRecords(System::String^ name);
	void closeDataBase();
	int GetNumberOfFrames();
private:
	//void closeDataBase();
	void createRecordTable();
	void InsertRecord(System::String^ str);
	//std::string EditStringValue(std::string str);
	System::String^ EditStringValue(System::String^ str);
	//std::string EditStringLength(std::string str);
	System::String^ EditStringLength(System::String^ str);
private:
	SQLiteConnection^ db;
};