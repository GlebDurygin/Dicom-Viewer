#pragma once
#include "database.h"

using namespace System::IO;
using namespace System::Diagnostics;



ref class DicomFile {
public:
	explicit DicomFile(System::String^ Path);
	~DicomFile();
	DataBase^ GetDB();
	void SetCount(int i);
	int GetCount();
	
	int GetMaxValue();
private:
	void GetImages(System::String^ Path);
	void SetMaxValue();
private:
	DataBase^ db;
	int count;
	int max_value;
};