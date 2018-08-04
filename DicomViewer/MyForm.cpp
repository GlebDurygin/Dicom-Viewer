#include "MyForm.h"
namespace DicomViewer {
	using namespace System;
	using namespace System::Windows::Forms;

	System::Void MyForm::îòêðûòüÔàéëDICOMToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	openFileDialog1->Filter = "DICOM files(*.dcm)|*.dcm";
	progressBar1->Value = 25;
	label5->Text = "DICOM ôàéë çàãðóæàåòñÿ";
	timer2->Start();
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		lx = 0;
		ly = 0;
		cx = 0;
		cy = 0;
		//zoom = 1;
		timer2->Stop();
		dicomFile = gcnew DicomFile(openFileDialog1->FileName);
		progressBar1->Increment(15);
		DataTable ^table = fillDataTable();
		progressBar1->Increment(10);
		label5->Text = "Åùå ÷óòü-÷óòü...";
		if (dicomFile->GetMaxValue() == 1)
		{
			button8->Enabled = false;
			button9->Enabled = false;
			button10->Enabled = false;
			comboBox1->Enabled = false;
		}
		else
		{
			button8->Enabled = false;
			button9->Enabled = true;
			button10->Enabled = true;
			comboBox1->Enabled = true;
			comboBox1->SelectedIndex = 0;
			comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;
		}
		progressBar1->Increment(20);
		//Repaint();
		RepaintFirst();
		dataGridView1->DataSource = table;
		dataGridView2->DataSource = table;
		dataGridView2->Columns[0]->Visible = false;
		dataGridView1->Columns[0]->Visible = false;
		dataGridView1->Columns[2]->Visible = false;
		dataGridView1->Columns[3]->Visible = false;
		dataGridView1->Columns[4]->Visible = false;
		dataGridView1->Columns[5]->Visible = false;
		dataGridView1->Columns[6]->Visible = false;
		dataGridView2->Visible = false;

		comboBox1->Visible = true;
		//dataGridView3->Visible = true;
		èçîáðàæåíèåToolStripMenuItem->Enabled = true;
		çàêðûòüToolStripMenuItem->Enabled = true;
		ñîõðàíèòüÊàêToolStripMenuItem->Enabled = true;
		îáùèéÂèäToolStripMenuItem->Enabled = false;
		dataGridView1->Visible = true;
		pictureBox1->Visible = true;
		label1->Visible = true;
		label2->Visible = true;
		label3->Visible = true;
		label4->Visible = true;
		trackBar1->Visible = true;
		trackBar2->Visible = true;
		textBox1->Visible = true;
		button1->Visible = true;
		button2->Visible = true;
		button3->Visible = true;
		button4->Visible = true;
		button5->Visible = true;
		button6->Visible = true;
		button8->Visible = true;
		button9->Visible = true;
		button10->Visible = true;
		button11->Visible = true;
		button12->Visible = true;
		groupBox1->Visible = true;
		progressBar1->Increment(20);
		progressBar1->Visible = false;
		groupBox2->Visible = false;
		label5->Visible = false;

	}
};

	void MyForm::Repaint()
	{
		//image = gcnew Bitmap(Directory::GetCurrentDirectory() + "\\." + dicomFile->GetCount() + ".bmp");
		currenImage = gcnew Bitmap(image, image->Width*zoom, image->Height*zoom);
		int width = currenImage->Width;
		int height = currenImage->Height;
		double brightness = trackBar1->Value;
		double contrast = (100.0 + trackBar2->Value * 10) / 100.0;
		contrast = contrast*contrast;
		for (int x = 0; x < width; ++x)
			for (int y = 0; y < height; ++y)
			{
				Color curr = currenImage->GetPixel(x, y);
				double r = curr.R + (brightness * 255 / 10);
				r = r / 255.0;
				r = r - 0.5;
				r = r * contrast;
				r = r + 0.5;
				r = r * 255;
				if (r < 0) r = 0;
				if (r > 255) r = 255;
				double g = curr.G + (brightness * 255 / 10);
				g = g / 255.0;
				g = g - 0.5;
				g = g * contrast;
				g = g + 0.5;
				g = g * 255;
				if (g < 0) g = 0;
				if (g > 255) g = 255;
				double b = curr.B + (brightness * 255 / 10);
				b = b / 255.0;
				b = b - 0.5;
				b = b * contrast;
				b = b + 0.5;
				b = b * 255;
				if (b < 0) b = 0;
				if (b > 255) b = 255;
				Color color = Color::FromArgb((int)r, (int)g, (int)b);
				currenImage->SetPixel(x, y, color);
			}
		//currenImage = image;
		//zoom = 1;
		//label3->Text = "Êàäð (" + (dicomFile->GetCount() + 1) + " èç " + dicomFile->GetMaxValue() + ")";
		/*int width = image->Width;
		int height = image->Height;
		double brightness = trackBar1->Value;
		double contrast = (100.0 + trackBar2->Value * 10) / 100.0;
		contrast = contrast*contrast;
		for (int x = 0; x < width; ++x)
			for (int y = 0; y < height; ++y)
			{
				Color curr = image->GetPixel(x, y);
				double r = curr.R + (brightness * 255 / 10);
				r = r / 255.0;
				r = r - 0.5;
				r = r * contrast;
				r = r + 0.5;
				r = r * 255;
				if (r < 0) r = 0;
				if (r > 255) r = 255;
				double g = curr.G + (brightness * 255 / 10);
				g = g / 255.0;
				g = g - 0.5;
				g = g * contrast;
				g = g + 0.5;
				g = g * 255;
				if (g < 0) g = 0;
				if (g > 255) g = 255;
				double b = curr.B + (brightness * 255 / 10);
				b = b / 255.0;
				b = b - 0.5;
				b = b * contrast;
				b = b + 0.5;
				b = b * 255;
				if (b < 0) b = 0;
				if (b > 255) b = 255;
				Color color = Color::FromArgb((int)r, (int)g, (int)b);
				image->SetPixel(x, y, color);
			}
		currenImage = image;*/
		//pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		pictureBox1->Invalidate();
	};

	void MyForm::RepaintFirst()
	{
		image = gcnew Bitmap(Directory::GetCurrentDirectory() + "\\." + dicomFile->GetCount() + ".bmp");
		label3->Text = "Êàäð (" + (dicomFile->GetCount() + 1) + " èç " + dicomFile->GetMaxValue() + ")";
		int width = image->Width;
		int height = image->Height;
		zoom = 1;
		//while (((width*zoom) <= pictureBox1->Width) && ((height*zoom) <= pictureBox1->Height))
		//{
		//	zoom += 1;
		//}
		if ((width*zoom) <= pictureBox1->Width && (height*zoom) <= pictureBox1->Height)
		{
			cx = (pictureBox1->Width - width*zoom-1) / 2;
			cy = (pictureBox1->Height - height*zoom-1) / 2;
		}
		width = (image->Width*zoom);
		height = (image->Height*zoom);
		currenImage = gcnew Bitmap(image, width, height);
		pictureBox1->Invalidate();
		/*currenImage = image;
		pictureBox1->Invalidate();*/
		/*double brightness = trackBar1->Value;
		double contrast = (100.0 + trackBar2->Value * 10) / 100.0;
		contrast = contrast*contrast;
		for (int x = 0; x < width; ++x)
			for (int y = 0; y < height; ++y)
			{
				Color curr = image->GetPixel(x, y);
				double r = curr.R + (brightness * 255 / 10);
				r = r / 255.0;
				r = r - 0.5;
				r = r * contrast;
				r = r + 0.5;
				r = r * 255;
				if (r < 0) r = 0;
				if (r > 255) r = 255;
				double g = curr.G + (brightness * 255 / 10);
				g = g / 255.0;
				g = g - 0.5;
				g = g * contrast;
				g = g + 0.5;
				g = g * 255;
				if (g < 0) g = 0;
				if (g > 255) g = 255;
				double b = curr.B + (brightness * 255 / 10);
				b = b / 255.0;
				b = b - 0.5;
				b = b * contrast;
				b = b + 0.5;
				b = b * 255;
				if (b < 0) b = 0;
				if (b > 255) b = 255;
				Color color = Color::FromArgb((int)r, (int)g, (int)b);
				image->SetPixel(x, y, color);
			}*/
	};

	DataTable^ MyForm::fillDataTable() {
		DataTable ^table;
		try
		{
			DataColumn ^column;
			DataRow ^row;
			table = gcnew DataTable();
			vector<String^>^ nameColumns = gcnew vector<String^>();
			SQLiteDataReader ^reader = dicomFile->GetDB()->GetAllData();
			for (int i = 0; i < reader->FieldCount; i++) {
				nameColumns->push_back(reader->GetName(i));
				column = gcnew DataColumn(nameColumns->at(i), String::typeid);
				table->Columns->Add(column);
			}
			while (reader->Read()) {
				row = table->NewRow();
				for (int i = 0; i < reader->FieldCount; i++) {
					row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
					reader->GetValue(i)->ToString();
				}
				table->Rows->Add(row);
			}
			dataGridView1->RowHeadersVisible = false;
			dataGridView2->RowHeadersVisible = false;
		}
		catch (Exception ^e)
		{
			MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
		}
		return table;
	};

	System::Void MyForm::label1_Click(System::Object^  sender, System::EventArgs^  e) {};
	System::Void MyForm::trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		Repaint();
	};
	System::Void MyForm::trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
		Repaint();
	};
	System::Void MyForm::button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Bitmap^ image = gcnew Bitmap(pictureBox1->Image);
		//image->RotateFlip(RotateFlipType::Rotate90FlipNone);
		currenImage->RotateFlip(RotateFlipType::Rotate90FlipNone);
		pictureBox1->Invalidate();
		//pictureBox1->Image = image;
		//currenImage = image;
	};

	System::Void MyForm::button4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Bitmap^ image = gcnew Bitmap(pictureBox1->Image);
		//image->RotateFlip(RotateFlipType::Rotate270FlipNone);
		currenImage->RotateFlip(RotateFlipType::Rotate270FlipNone);
		pictureBox1->Invalidate();
		//pictureBox1->Image = image;
		//currenImage = image;
	};
	
	System::Void MyForm::button5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Bitmap^ image = gcnew Bitmap(pictureBox1->Image);
		//image->RotateFlip(RotateFlipType::RotateNoneFlipX);
		currenImage->RotateFlip(RotateFlipType::RotateNoneFlipX);
		pictureBox1->Invalidate();
		//pictureBox1->Image = image;
		//currenImage = image;
	};
	
	System::Void MyForm::button6_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Bitmap^ image = gcnew Bitmap(pictureBox1->Image);
		//image->RotateFlip(RotateFlipType::RotateNoneFlipY);
		currenImage->RotateFlip(RotateFlipType::RotateNoneFlipY);
		pictureBox1->Invalidate();
		//pictureBox1->Image = image;
		//currenImage = image;
	};

	System::Void MyForm::jPEGToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		saveFileDialog1->InitialDirectory = "C:\"";
		saveFileDialog1->RestoreDirectory = true;
		saveFileDialog1->FileName = openFileDialog1->SafeFileName->Remove(openFileDialog1->SafeFileName->IndexOf(".")) + ".jpg";
		saveFileDialog1->DefaultExt = "jpg";
		saveFileDialog1->Filter = "jpg images (*.jpg)|*.jpg";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			currenImage->Save(saveFileDialog1->OpenFile(), System::Drawing::Imaging::ImageFormat::Jpeg);
		}
	};

	System::Void MyForm::bMPToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		saveFileDialog1->InitialDirectory = "C:\"";
		saveFileDialog1->RestoreDirectory = true;
		saveFileDialog1->FileName = openFileDialog1->SafeFileName->Remove(openFileDialog1->SafeFileName->IndexOf(".")) + ".bmp";
		saveFileDialog1->DefaultExt = "bmp";
		saveFileDialog1->Filter = "bmp images (*.bmp)|*.bmp";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			currenImage->Save(saveFileDialog1->OpenFile(), System::Drawing::Imaging::ImageFormat::Bmp);
		}
	};

	System::Void MyForm::pNGToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		saveFileDialog1->InitialDirectory = "C:\"";
		saveFileDialog1->RestoreDirectory = true;
		saveFileDialog1->FileName = openFileDialog1->SafeFileName->Remove(openFileDialog1->SafeFileName->IndexOf(".")) + ".png";
		saveFileDialog1->DefaultExt = "png";
		saveFileDialog1->Filter = "png images (*.png)|*.png";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			currenImage->Save(saveFileDialog1->OpenFile(), System::Drawing::Imaging::ImageFormat::Png);
		}
	}
	System::Void MyForm::label3_Click(System::Object^  sender, System::EventArgs^  e) {}
	
	System::Void MyForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (dicomFile->GetCount() + 1 == dicomFile->GetMaxValue())
		{
			timer1->Stop();
			button9->Enabled = false;
		}
		else {
			dicomFile->SetCount(dicomFile->GetCount() + 1);
			RepaintFirst();
		}
	};

	System::Void MyForm::âûéòèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	System::Void MyForm::ïîâåðíóòüÏî×àñîâîéÑòðåëêåToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//Bitmap^ image = gcnew Bitmap(pictureBox1->Image);
		//image->RotateFlip(RotateFlipType::Rotate90FlipNone);
		currenImage->RotateFlip(RotateFlipType::Rotate90FlipNone);
		pictureBox1->Invalidate();
		//pictureBox1->Image = image;
		//currenImage = image;
	}
	System::Void MyForm::ïîâåðíóòüÏðîòèâ×àñîâîéÑòðåëêèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//Bitmap^ image = gcnew Bitmap(pictureBox1->Image);
		//image->RotateFlip(RotateFlipType::Rotate270FlipNone);
		currenImage->RotateFlip(RotateFlipType::Rotate270FlipNone);
		pictureBox1->Invalidate();
		//pictureBox1->Image = image;
		//currenImage = image;
	}
	System::Void MyForm::îòðàçèòüÏîÂåðòèêàëèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//Bitmap^ image = gcnew Bitmap(pictureBox1->Image);
		//image->RotateFlip(RotateFlipType::RotateNoneFlipY);
		currenImage->RotateFlip(RotateFlipType::RotateNoneFlipY);
		pictureBox1->Invalidate();
		//pictureBox1->Image = image;
		//currenImage = image;
	}
	System::Void MyForm::îòðàçèòüÏîÃîðèçîíòàëèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//Bitmap^ image = gcnew Bitmap(pictureBox1->Image);
		//image->RotateFlip(RotateFlipType::RotateNoneFlipX);
		currenImage->RotateFlip(RotateFlipType::RotateNoneFlipX);
		pictureBox1->Invalidate();
		//pictureBox1->Image = image;
		//currenImage = image;
	}
	System::Void MyForm::îòîáðàçèòüÂñåÒåãèToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Visible = false;
		label1->Visible = false;
		label2->Visible = false;
		label3->Visible = false;
		label4->Visible = false;
		trackBar1->Visible = false;
		trackBar2->Visible = false;
		button2->Visible = false;
		button3->Visible = false;
		button4->Visible = false;
		button5->Visible = false;
		button6->Visible = false;
		button8->Visible = false;
		button9->Visible = false;
		button10->Visible = false;
		button11->Visible = false;
		button12->Visible = false;
		îáùèéÂèäToolStripMenuItem->Enabled = true;
		ïîâåðíóòüÏî×àñîâîéÑòðåëêåToolStripMenuItem->Enabled = false;
		ïîâåðíóòüÏðîòèâ×àñîâîéÑòðåëêèToolStripMenuItem->Enabled = false;
		îòðàçèòüÏîÂåðòèêàëèToolStripMenuItem->Enabled = false;
		îòðàçèòüÏîÃîðèçîíòàëèToolStripMenuItem->Enabled = false;
		îòîáðàçèòüÂñåÒåãèToolStripMenuItem->Enabled = false;
		dataGridView1->Visible = false;
		dataGridView2->Visible = true;
		//dataGridView3->Visible = false;
		button1->Visible = false;
		textBox1->Visible = false;
		button7->Visible = true;
		textBox2->Visible = true;
		groupBox1->Visible = false;
	};

	System::Void MyForm::çàêðûòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Visible = false;
		label1->Visible = false;
		label2->Visible = false;
		label3->Visible = false;
		label4->Visible = false;
		trackBar1->Visible = false;
		trackBar2->Visible = false;
		button2->Visible = false;
		button3->Visible = false;
		button4->Visible = false;
		button5->Visible = false;
		button6->Visible = false;
		button8->Visible = false;
		button9->Visible = false;
		button10->Visible = false;
		button11->Visible = false;
		button12->Visible = false;
		èçîáðàæåíèåToolStripMenuItem->Enabled = false;
		dataGridView1->Visible = false;
		dataGridView2->Visible = false;
		//dataGridView3->Visible = false;
		button1->Visible = false;
		textBox1->Visible = false;
		button7->Visible = false;
		textBox2->Visible = false;
		groupBox1->Visible = false;
		çàêðûòüToolStripMenuItem->Enabled = false;
		ñîõðàíèòüÊàêToolStripMenuItem->Enabled = false;
		dicomFile->GetDB()->closeDataBase();
		//db->closeDataBase();
		// Äîáàâèòü îñâîáîæäåíèå ïàìÿòè ó picturebox è gridview
	}
	System::Void MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Visible = false;
		label1->Visible = false;
		label2->Visible = false;
		label3->Visible = false;
		label4->Visible = false;
		trackBar1->Visible = false;
		trackBar2->Visible = false;
		button2->Visible = false;
		button3->Visible = false;
		button4->Visible = false;
		button5->Visible = false;
		button6->Visible = false;
		button8->Visible = false;
		button9->Visible = false;
		button10->Visible = false;
		button11->Visible = false;
		button12->Visible = false;
		îáùèéÂèäToolStripMenuItem->Enabled = true;
		ïîâåðíóòüÏî×àñîâîéÑòðåëêåToolStripMenuItem->Enabled = false;
		ïîâåðíóòüÏðîòèâ×àñîâîéÑòðåëêèToolStripMenuItem->Enabled = false;
		îòðàçèòüÏîÂåðòèêàëèToolStripMenuItem->Enabled = false;
		îòðàçèòüÏîÃîðèçîíòàëèToolStripMenuItem->Enabled = false;
		îòîáðàçèòüÂñåÒåãèToolStripMenuItem->Enabled = false;
		dataGridView1->Visible = false;
		dataGridView2->Visible = true;
		//dataGridView3->Visible = false;
		button1->Visible = false;
		textBox1->Visible = false;
		button7->Visible = true;
		textBox2->Visible = true;
		groupBox1->Visible = false;
	}
	System::Void MyForm::îáùèéÂèäToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Visible = true;
		label1->Visible = true;
		label2->Visible = true;
		label3->Visible = true;
		label4->Visible = true;
		trackBar1->Visible = true;
		trackBar2->Visible = true;
		textBox1->Visible = true;
		button2->Visible = true;
		button3->Visible = true;
		button4->Visible = true;
		button5->Visible = true;
		button6->Visible = true;
		button8->Visible = true;
		button9->Visible = true;
		button10->Visible = true;
		button11->Visible = true;
		button12->Visible = true;
		groupBox1->Visible = true;
		îáùèéÂèäToolStripMenuItem->Enabled = false;
		ïîâåðíóòüÏî×àñîâîéÑòðåëêåToolStripMenuItem->Enabled = true;
		ïîâåðíóòüÏðîòèâ×àñîâîéÑòðåëêèToolStripMenuItem->Enabled = true;
		îòðàçèòüÏîÂåðòèêàëèToolStripMenuItem->Enabled = true;
		îòðàçèòüÏîÃîðèçîíòàëèToolStripMenuItem->Enabled = true;
		îòîáðàçèòüÂñåÒåãèToolStripMenuItem->Enabled = true;
		dataGridView1->Visible = true;
		dataGridView2->Visible = false;
		//dataGridView3->Visible = true;
		button1->Visible = true;
		textBox1->Visible = true;
		button7->Visible = false;
		textBox2->Visible = false;
	};
	
	System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ str = textBox1->Text;
		SQLiteDataReader ^reader;
		DataTable ^table;
		if (str == "")
		{
			reader = dicomFile->GetDB()->GetAllData();
			//reader = db->GetAllData();
		}
		else
		{
			reader = dicomFile->GetDB()->FindRecords(str);
			//reader = db->FindRecords(str);
		}
		try
		{
			DataColumn ^column;
			DataRow ^row;
			table = gcnew DataTable();
			vector<String^>^ nameColumns = gcnew vector<String^>();
			for (int i = 0; i < reader->FieldCount; i++) {
				nameColumns->push_back(reader->GetName(i));
				column = gcnew DataColumn(nameColumns->at(i), String::typeid);
				table->Columns->Add(column);
			}
			while (reader->Read()) {
				row = table->NewRow();
				for (int i = 0; i < reader->FieldCount; i++) {
					row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
					reader->GetValue(i)->ToString();
				}
				table->Rows->Add(row);
			}
			dataGridView1->DataSource = table;
		}
		catch (Exception ^e)
		{
			MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
		}
	}
	System::Void MyForm::button7_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ str = textBox2->Text;
		SQLiteDataReader ^reader;
		DataTable ^table;
		if (str == "")
		{
			reader = dicomFile->GetDB()->GetAllData();
			//reader = db->GetAllData();
		}
		else
		{
			reader = dicomFile->GetDB()->FindRecords(str);
			//reader = db->FindRecords(str);
		}
		try
		{
			DataColumn ^column;
			DataRow ^row;
			table = gcnew DataTable();
			vector<String^>^ nameColumns = gcnew vector<String^>();
			for (int i = 0; i < reader->FieldCount; i++) {
				nameColumns->push_back(reader->GetName(i));
				column = gcnew DataColumn(nameColumns->at(i), String::typeid);
				table->Columns->Add(column);
			}
			while (reader->Read()) {
				row = table->NewRow();
				for (int i = 0; i < reader->FieldCount; i++) {
					row[nameColumns->at(i)] = reader->GetValue(i)->ToString();
					reader->GetValue(i)->ToString();
				}
				table->Rows->Add(row);
			}
		dataGridView2->DataSource = table;
		}	
		catch (Exception ^e)
		{
			MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception While Displaying MyTable ...");
		}
	};
	System::Void MyForm::button8_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dicomFile->GetCount() == dicomFile->GetMaxValue() - 1)
			button9->Enabled = true;
		if (dicomFile->GetCount() == 1)
			button8->Enabled = false;
		if (dicomFile->GetCount() != 0)
		{
			dicomFile->SetCount(dicomFile->GetCount() - 1);
			RepaintFirst();
		}
	};
	System::Void MyForm::button9_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dicomFile->GetCount() == 0)
			button8->Enabled = true;
		if (dicomFile->GetCount() == dicomFile->GetMaxValue() - 2)
			button9->Enabled = false;
		if (dicomFile->GetCount() != dicomFile->GetMaxValue() - 1)
		{
			dicomFile->SetCount(dicomFile->GetCount() + 1);
			RepaintFirst();
		}
	};

	System::Void MyForm::button10_Click(System::Object^  sender, System::EventArgs^  e) {
		dicomFile->SetCount(0);
		RepaintFirst();
		if (comboBox1->SelectedIndex == 0)
		{
			timer1->Interval = 500;
		}
		else if (comboBox1->SelectedIndex == 1)
		{
			timer1->Interval = 10;
		}
		else
		{
			timer1->Interval = 1000;
		}
		timer1->Start();
		button8->Enabled = true;
	};
	System::Void MyForm::timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		groupBox2->Visible = true;
		progressBar1->Visible = true;
		label5->Visible = true;
	};
	System::Void MyForm::button11_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Normal;
		if (zoom != 9)
		{
			zoom += 1;
			int widthZoom = (image->Width*zoom);
			int heightZoom = (image->Height*zoom);
			//currenImage = gcnew Bitmap(image, widthZoom, heightZoom);
			currenImage = gcnew Bitmap(currenImage, widthZoom, heightZoom);
			pictureBox1->Invalidate();
		}
	}
	System::Void MyForm::button12_Click(System::Object^  sender, System::EventArgs^  e)
	{
		pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Normal;
		if (zoom != 1)
		{
			zoom -= 1;
			int widthZoom = image->Width*zoom;
			int heightZoom = image->Width*zoom;
			//currenImage = gcnew Bitmap(image, widthZoom, heightZoom);
			currenImage = gcnew Bitmap(currenImage, widthZoom, heightZoom);
			pictureBox1->Invalidate();
		}
		
	}
	System::Void MyForm::pictureBox1_MouseDown(System::Object ^ sender, MouseEventArgs ^ e)
	{
		lx = e->X;
		ly = e->Y;
	}
	System::Void MyForm::pictureBox1_MouseMove(System::Object ^ sender, MouseEventArgs ^ e)
	{
		if (pictureBox1->Capture)
		{
			int dx = e->X - lx;
			int dy = e->Y - ly;
			cx += dx;
			cy += dy;
			lx = e->X;
			ly = e->Y;
			pictureBox1->Invalidate();
		}
	}
	System::Void MyForm::pictureBox1_Paint(System::Object ^ sender, PaintEventArgs ^ e)
	{
		//e->Graphics->DrawImageUnscaled(image, cx, cy);
		e->Graphics->DrawImage(currenImage, cx, cy);
		//e->Graphics->DrawImageUnscaled(pictureBox1->Image, cx, cy);
	}
}