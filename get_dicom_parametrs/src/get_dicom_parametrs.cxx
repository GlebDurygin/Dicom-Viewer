#include "get_dicom_parametrs.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk\dcmimage\dicoimg.h"
#include "dcmtk\dcmjpeg\dipijpeg.h"
#include <map>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main()
{
	//unsigned long N;
	//STARTUPINFO si;
	//PROCESS_INFORMATION pi;
	//map <string, string> Tags;

	DcmFileFormat fileformat;
	string path = "";
	ifstream in("C:\\Users\\Tatyana\\Documents\\DCMTK\\Projects\\DCMTK_Viewer\\Dicom_Viewer\\DicomFileViewer\\DicomParametrs.txt");
	//in >> path;
	getline(in, path);
	in.clear();
	in.close();
	//OFCondition status = fileformat.loadFile("C:\\Users\\Tatyana\\Documents\\DCMTK\\Projects\\DCMTK_Viewer\\get_dicom_parametrs\\bin\\Debug\\abdominal.dcm");
	OFCondition status = fileformat.loadFile(path.data());
   if (status.good())
   {
      OFString patientsParametrs[8];
	  //string Tags[8];
	  
	  fileformat.getDataset()->findAndGetOFString(DCM_PatientName, patientsParametrs[0]);
	  fileformat.getDataset()->findAndGetOFString(DCM_PatientBirthDate, patientsParametrs[1]);
	  fileformat.getDataset()->findAndGetOFString(DCM_PatientID, patientsParametrs[2]);
	  fileformat.getDataset()->findAndGetOFString(DCM_PatientSex, patientsParametrs[3]);
	  fileformat.getDataset()->findAndGetOFString(DCM_InstanceCreationDate, patientsParametrs[4]);
	  fileformat.getDataset()->findAndGetOFString(DCM_InstanceCreationTime, patientsParametrs[5]);
	  fileformat.getDataset()->findAndGetOFString(DCM_Modality, patientsParametrs[6]);
	  fileformat.getDataset()->findAndGetOFString(DCM_TransferSyntaxUID, patientsParametrs[7]);
	  fileformat.getDataset()->findAndGetOFString(DCM_AbortFlag, patientsParametrs[7]);
	  for (int i = 0; i < 8; i++)
	  {
		  if (patientsParametrs[i] == "") patientsParametrs[i] = "no information";
	  }

	  ofstream fileout("C:\\Users\\Tatyana\\Documents\\DCMTK\\Projects\\DCMTK_Viewer\\Dicom_Viewer\\DicomFileViewer\\DicomParametrs.txt");
	  fileout << "PatientName : " << patientsParametrs[0].data() << endl;
	  fileout << "PatientBirthDate : " << patientsParametrs[1].data() << endl;
	  fileout << "PatientID : " << patientsParametrs[2].data() << endl;
	  fileout << "PatientSex : " << patientsParametrs[3].data() << endl;
	  fileout << "InstanceCreationDate : " << patientsParametrs[4].data() << endl;
	  fileout << "InstanceCreationTime : " << patientsParametrs[5].data() << endl;
	  fileout << "Modality : " << patientsParametrs[6].data() << endl;
	  fileout << "TransferSyntaxUID : " << patientsParametrs[7].data();
	  fileout.close();

   }else{
      cerr << "Error: cannot read DICOM file (" << status.text() << ")" << endl;
   }

   return 0;
}