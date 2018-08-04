#pragma once
//#include "database.h"
#include "DicomFile.h"
#include <cliext/vector>
namespace DicomViewer{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;
	using namespace System::Text;
	using namespace System::IO;
	using namespace cliext;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			//delete db;
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îòêğûòüÔàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ÎòêğûòüÔàéëDICOMToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  çàêğûòüToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  ñîõğàíèòüÊàêToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  jPEGToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bMPToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pNGToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âûéòèToolStripMenuItem;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;






	private:
		//DataBase ^db;
		DicomFile^ dicomFile;
		Bitmap^ image,^currenImage;
		int zoom, lx,ly,cx,cy;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Timer^  timer1;


	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::ToolStripMenuItem^  èçîáğàæåíèåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îòîáğàçèòüÂñåÒåãèToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripMenuItem^  îáùèéÂèäToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button7;


	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button11;

	private: System::ComponentModel::IContainer^  components;
			 /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòêğûòüÔàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÎòêğûòüÔàéëDICOMToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñîõğàíèòüÊàêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->jPEGToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bMPToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pNGToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûéòèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->èçîáğàæåíèåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòîáğàçèòüÂñåÒåãèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îáùèéÂèäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ôàéëToolStripMenuItem,
					this->èçîáğàæåíèåToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->îòêğûòüÔàéëToolStripMenuItem,
					this->çàêğûòüToolStripMenuItem, this->ñîõğàíèòüÊàêToolStripMenuItem, this->âûéòèToolStripMenuItem
			});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(57, 24);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// îòêğûòüÔàéëToolStripMenuItem
			// 
			this->îòêğûòüÔàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ÎòêğûòüÔàéëDICOMToolStripMenuItem });
			this->îòêğûòüÔàéëToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"îòêğûòüÔàéëToolStripMenuItem.Image")));
			this->îòêğûòüÔàéëToolStripMenuItem->Name = L"îòêğûòüÔàéëToolStripMenuItem";
			this->îòêğûòüÔàéëToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->îòêğûòüÔàéëToolStripMenuItem->Text = L"Îòêğûòü ôàéë";
			// 
			// ÎòêğûòüÔàéëDICOMToolStripMenuItem
			// 
			this->ÎòêğûòüÔàéëDICOMToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ÎòêğûòüÔàéëDICOMToolStripMenuItem.Image")));
			this->ÎòêğûòüÔàéëDICOMToolStripMenuItem->Name = L"ÎòêğûòüÔàéëDICOMToolStripMenuItem";
			this->ÎòêğûòüÔàéëDICOMToolStripMenuItem->Size = System::Drawing::Size(233, 26);
			this->ÎòêğûòüÔàéëDICOMToolStripMenuItem->Text = L"Îòêğûòü ôàéë DICOM";
			this->ÎòêğûòüÔàéëDICOMToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îòêğûòüÔàéëDICOMToolStripMenuItem_Click);
			// 
			// çàêğûòüToolStripMenuItem
			// 
			this->çàêğûòüToolStripMenuItem->Enabled = false;
			this->çàêğûòüToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"çàêğûòüToolStripMenuItem.Image")));
			this->çàêğûòüToolStripMenuItem->Name = L"çàêğûòüToolStripMenuItem";
			this->çàêğûòüToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->çàêğûòüToolStripMenuItem->Text = L"Çàêğûòü";
			this->çàêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::çàêğûòüToolStripMenuItem_Click);
			// 
			// ñîõğàíèòüÊàêToolStripMenuItem
			// 
			this->ñîõğàíèòüÊàêToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->jPEGToolStripMenuItem,
					this->bMPToolStripMenuItem, this->pNGToolStripMenuItem
			});
			this->ñîõğàíèòüÊàêToolStripMenuItem->Enabled = false;
			this->ñîõğàíèòüÊàêToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ñîõğàíèòüÊàêToolStripMenuItem.Image")));
			this->ñîõğàíèòüÊàêToolStripMenuItem->Name = L"ñîõğàíèòüÊàêToolStripMenuItem";
			this->ñîõğàíèòüÊàêToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->ñîõğàíèòüÊàêToolStripMenuItem->Text = L"Ñîõğàíèòü êàê";
			// 
			// jPEGToolStripMenuItem
			// 
			this->jPEGToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"jPEGToolStripMenuItem.Image")));
			this->jPEGToolStripMenuItem->Name = L"jPEGToolStripMenuItem";
			this->jPEGToolStripMenuItem->Size = System::Drawing::Size(115, 26);
			this->jPEGToolStripMenuItem->Text = L"JPEG";
			this->jPEGToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::jPEGToolStripMenuItem_Click);
			// 
			// bMPToolStripMenuItem
			// 
			this->bMPToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bMPToolStripMenuItem.Image")));
			this->bMPToolStripMenuItem->Name = L"bMPToolStripMenuItem";
			this->bMPToolStripMenuItem->Size = System::Drawing::Size(115, 26);
			this->bMPToolStripMenuItem->Text = L"BMP";
			this->bMPToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::bMPToolStripMenuItem_Click);
			// 
			// pNGToolStripMenuItem
			// 
			this->pNGToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pNGToolStripMenuItem.Image")));
			this->pNGToolStripMenuItem->Name = L"pNGToolStripMenuItem";
			this->pNGToolStripMenuItem->Size = System::Drawing::Size(115, 26);
			this->pNGToolStripMenuItem->Text = L"PNG";
			this->pNGToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::pNGToolStripMenuItem_Click);
			// 
			// âûéòèToolStripMenuItem
			// 
			this->âûéòèToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âûéòèToolStripMenuItem.Image")));
			this->âûéòèToolStripMenuItem->Name = L"âûéòèToolStripMenuItem";
			this->âûéòèToolStripMenuItem->Size = System::Drawing::Size(184, 26);
			this->âûéòèToolStripMenuItem->Text = L"Âûéòè";
			this->âûéòèToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::âûéòèToolStripMenuItem_Click);
			// 
			// èçîáğàæåíèåToolStripMenuItem
			// 
			this->èçîáğàæåíèåToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->îòîáğàçèòüÂñåÒåãèToolStripMenuItem,
					this->îáùèéÂèäToolStripMenuItem, this->ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem, this->ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem,
					this->îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem, this->îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem
			});
			this->èçîáğàæåíèåToolStripMenuItem->Enabled = false;
			this->èçîáğàæåíèåToolStripMenuItem->Name = L"èçîáğàæåíèåToolStripMenuItem";
			this->èçîáğàæåíèåToolStripMenuItem->Size = System::Drawing::Size(119, 24);
			this->èçîáğàæåíèåToolStripMenuItem->Text = L"Èçîáğàæåíèå";
			// 
			// îòîáğàçèòüÂñåÒåãèToolStripMenuItem
			// 
			this->îòîáğàçèòüÂñåÒåãèToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"îòîáğàçèòüÂñåÒåãèToolStripMenuItem.Image")));
			this->îòîáğàçèòüÂñåÒåãèToolStripMenuItem->Name = L"îòîáğàçèòüÂñåÒåãèToolStripMenuItem";
			this->îòîáğàçèòüÂñåÒåãèToolStripMenuItem->Size = System::Drawing::Size(333, 26);
			this->îòîáğàçèòüÂñåÒåãèToolStripMenuItem->Text = L"Îòîáğàçèòü âñå òåãè";
			this->îòîáğàçèòüÂñåÒåãèToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îòîáğàçèòüÂñåÒåãèToolStripMenuItem_Click);
			// 
			// îáùèéÂèäToolStripMenuItem
			// 
			this->îáùèéÂèäToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"îáùèéÂèäToolStripMenuItem.Image")));
			this->îáùèéÂèäToolStripMenuItem->Name = L"îáùèéÂèäToolStripMenuItem";
			this->îáùèéÂèäToolStripMenuItem->Size = System::Drawing::Size(333, 26);
			this->îáùèéÂèäToolStripMenuItem->Text = L"Îáùèé âèä";
			this->îáùèéÂèäToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îáùèéÂèäToolStripMenuItem_Click);
			// 
			// ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem
			// 
			this->ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem.Image")));
			this->ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem->Name = L"ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem";
			this->ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem->Size = System::Drawing::Size(333, 26);
			this->ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem->Text = L"Ïîâåğíóòü ïî ÷àñîâîé ñòğåëêå";
			this->ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem_Click);
			// 
			// ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem
			// 
			this->ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem.Image")));
			this->ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem->Name = L"ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem";
			this->ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem->Size = System::Drawing::Size(333, 26);
			this->ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem->Text = L"Ïîâåğíóòü ïğîòèâ ÷àñîâîé ñòğåëêè";
			this->ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem_Click);
			// 
			// îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem
			// 
			this->îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem.Image")));
			this->îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem->Name = L"îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem";
			this->îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem->Size = System::Drawing::Size(333, 26);
			this->îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem->Text = L"Îòğàçèòü ïî âåğòèêàëè";
			this->îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem_Click);
			// 
			// îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem
			// 
			this->îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem.Image")));
			this->îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem->Name = L"îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem";
			this->îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem->Size = System::Drawing::Size(333, 26);
			this->îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem->Text = L"Îòğàçèòü ïî ãîğèçîíòàëè";
			this->îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Dicom ôàéëû (*.dcm)|*.dcm";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlText;
			this->pictureBox1->Location = System::Drawing::Point(400, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(949, 955);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(12, 142);
			this->trackBar1->Minimum = -10;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(376, 56);
			this->trackBar1->TabIndex = 6;
			this->trackBar1->Visible = false;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ßğêîñòü";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 191);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Êîíòğàñò";
			this->label2->Visible = false;
			// 
			// trackBar2
			// 
			this->trackBar2->LargeChange = 1;
			this->trackBar2->Location = System::Drawing::Point(12, 223);
			this->trackBar2->Minimum = -10;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(376, 56);
			this->trackBar2->TabIndex = 8;
			this->trackBar2->Visible = false;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// button3
			// 
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(89, 21);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(40, 38);
			this->button3->TabIndex = 10;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(12, 52);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(40, 38);
			this->button4->TabIndex = 11;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->Location = System::Drawing::Point(256, 20);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(39, 38);
			this->button5->TabIndex = 12;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->Location = System::Drawing::Point(176, 21);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(40, 38);
			this->button6->TabIndex = 13;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(1355, 75);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(557, 908);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->Visible = false;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(1778, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 30);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Íàéòè";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(1355, 39);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(417, 30);
			this->textBox1->TabIndex = 17;
			this->textBox1->Visible = false;
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(334, 21);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(39, 37);
			this->button2->TabIndex = 18;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(12, 75);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(1900, 911);
			this->dataGridView2->TabIndex = 19;
			this->dataGridView2->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(-78, 39);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(410, 30);
			this->textBox2->TabIndex = 21;
			this->textBox2->Visible = false;
			// 
			// button7
			// 
			this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button7->Location = System::Drawing::Point(335, 39);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(142, 30);
			this->button7->TabIndex = 20;
			this->button7->Text = L"Íàéòè";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.Image")));
			this->button8->Location = System::Drawing::Point(90, 299);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(42, 42);
			this->button8->TabIndex = 24;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->Location = System::Drawing::Point(270, 299);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(42, 42);
			this->button9->TabIndex = 25;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(152, 271);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 17);
			this->label3->TabIndex = 26;
			this->label3->Text = L"Êàäğ (1 èç 1)";
			this->label3->Visible = false;
			// 
			// button10
			// 
			this->button10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button10.Image")));
			this->button10->Location = System::Drawing::Point(177, 299);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(42, 42);
			this->button10->TabIndex = 27;
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Visible = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button12);
			this->groupBox1->Controls->Add(this->button11);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Location = System::Drawing::Point(3, 31);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(391, 438);
			this->groupBox1->TabIndex = 28;
			this->groupBox1->TabStop = false;
			this->groupBox1->Visible = false;
			// 
			// button12
			// 
			this->button12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button12.Image")));
			this->button12->Location = System::Drawing::Point(219, 390);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(42, 42);
			this->button12->TabIndex = 31;
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Visible = false;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button11
			// 
			this->button11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button11.Image")));
			this->button11->Location = System::Drawing::Point(113, 390);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(42, 42);
			this->button11->TabIndex = 30;
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Visible = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 326);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(144, 17);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Ñêîğîñòü ïğîñìîòğà";
			this->label4->Visible = false;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Ñğåäíÿÿ", L"Áûñòğàÿ", L"Ìåäëåííàÿ" });
			this->comboBox1->Location = System::Drawing::Point(12, 357);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(361, 24);
			this->comboBox1->TabIndex = 19;
			this->comboBox1->Visible = false;
			// 
			// timer2
			// 
			this->timer2->Interval = 3000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(5, 52);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(468, 23);
			this->progressBar1->TabIndex = 29;
			this->progressBar1->Visible = false;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->progressBar1);
			this->groupBox2->Location = System::Drawing::Point(665, 363);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(478, 100);
			this->groupBox2->TabIndex = 30;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Çàãğóçêà";
			this->groupBox2->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 25);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(177, 17);
			this->label5->TabIndex = 30;
			this->label5->Text = L"DICOM ôàéë çàãğóæàåòñÿ";
			this->label5->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 1033);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"DicomViewer";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 
	System::Void îòêğûòüÔàéëDICOMToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	void Repaint();
	void RepaintFirst();
	DataTable^ fillDataTable();

	System::Void label1_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e);
	System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e); 
	System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void jPEGToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void bMPToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void pNGToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void label3_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	System::Void âûéòèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void ïîâåğíóòüÏî×àñîâîéÑòğåëêåToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void ïîâåğíóòüÏğîòèâ×àñîâîéÑòğåëêèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void îòğàçèòüÏîÂåğòèêàëèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void îòğàçèòüÏîÃîğèçîíòàëèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void îòîáğàçèòüÂñåÒåãèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void çàêğûòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void button2_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void îáùèéÂèäToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void button1_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void button7_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void button8_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void button9_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void button10_Click(System::Object^  sender, System::EventArgs^  e); 
	System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e); 
	System::Void button11_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void button12_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void pictureBox1_MouseDown(System::Object^  sender, MouseEventArgs^  e);
	System::Void pictureBox1_MouseMove(System::Object^  sender, MouseEventArgs^  e);
	System::Void pictureBox1_Paint(System::Object^  sender, PaintEventArgs^  e);

};

}
