#include "DicomFile.h"

DicomFile::DicomFile(System::String^ Path)
{
	count = 0;
	//max_value = 10;
	Process^ cmd = gcnew Process();
	cmd->StartInfo = gcnew ProcessStartInfo("cmd");
	cmd->StartInfo->UseShellExecute = false;
	cmd->StartInfo->CreateNoWindow = true;
	cmd->StartInfo->ErrorDialog = true;
	cmd->StartInfo->RedirectStandardOutput = true;
	cmd->StartInfo->RedirectStandardInput = true;
	cmd->StartInfo->RedirectStandardError = true;
	cmd->Start();
	StreamWriter^ cin = cmd->StandardInput;
	StreamReader^ cout = cmd->StandardOutput;
	cin->WriteLine("dcmdump " + Path);
	cin->Close();
	System::String^ str = cout->ReadToEnd();
	cout->Close();
	str = str->Substring(str->IndexOf("# Dicom"));
	str = str->Substring(0, str->IndexOf(" PixelData\r\n") + 12);
	GetImages(Path);
	db = gcnew DataBase();
	db->connectToDataBase();
	db->InsertAllDataToDB(str);
	SetMaxValue();
	cmd->Close();
}

void DicomFile::GetImages(System::String^ Path)
{
	Process^ cmd = gcnew Process();
	cmd->StartInfo = gcnew ProcessStartInfo("cmd");
	cmd->StartInfo->UseShellExecute = false;
	cmd->StartInfo->CreateNoWindow = true;
	cmd->StartInfo->ErrorDialog = true;
	cmd->StartInfo->RedirectStandardOutput = true;
	cmd->StartInfo->RedirectStandardInput = true;
	cmd->StartInfo->RedirectStandardError = true;
	cmd->Start();
	StreamWriter^ cin = cmd->StandardInput;
	cin->WriteLine("dcmj2pnm +Fa " + Path+ " +obt "+Directory::GetCurrentDirectory()+"\\");
	cin->Close();
	cmd->Close();
}

DicomFile::~DicomFile()
{
	delete db;
}

DataBase^ DicomFile::GetDB()
{
	return db;
}

void DicomFile::SetCount(int i)
{
	count = i;
}
int DicomFile::GetCount()
{
	return count;
}
void DicomFile::SetMaxValue()
{
	max_value = db->GetNumberOfFrames();
}
int DicomFile::GetMaxValue()
{
	return max_value;
}

