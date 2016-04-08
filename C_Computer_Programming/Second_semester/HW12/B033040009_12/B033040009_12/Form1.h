#pragma once

#include "PHOTO.h";
#include "Add.h";
#include "Database.h";

namespace B033040009_12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	Database data;
	Database data1;
	Database data2;
	Node *list;
	int sort;
	int page;
	int showmode;
	int tabpage;

	/// <summary>
	/// Form1 ���K�n
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  �ɮ�ToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ToolStripMenuItem^  �}������ToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  �x�s�ɮ�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �t�s�s��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �\��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �s�W�|��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �M��|��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �s��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �s�W�s��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �R���s��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �C�����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �浧���ToolStripMenuItem;

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边
		/// �ק�o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�ɮ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�}������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�x�s�ɮ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�t�s�s��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�\��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�s�W�|��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�M��|��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�s��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�s�W�s��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�R���s��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�C�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�浧���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->�ɮ�ToolStripMenuItem, 
				this->�\��ToolStripMenuItem, this->�s��ToolStripMenuItem, this->���ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(959, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �ɮ�ToolStripMenuItem
			// 
			this->�ɮ�ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->�}������ToolStripMenuItem, 
				this->�x�s�ɮ�ToolStripMenuItem, this->�t�s�s��ToolStripMenuItem});
			this->�ɮ�ToolStripMenuItem->Name = L"�ɮ�ToolStripMenuItem";
			this->�ɮ�ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->�ɮ�ToolStripMenuItem->Text = L"�ɮ�";
			// 
			// �}������ToolStripMenuItem
			// 
			this->�}������ToolStripMenuItem->Name = L"�}������ToolStripMenuItem";
			this->�}������ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->�}������ToolStripMenuItem->Text = L"�}������";
			this->�}������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�}������ToolStripMenuItem_Click);
			// 
			// �x�s�ɮ�ToolStripMenuItem
			// 
			this->�x�s�ɮ�ToolStripMenuItem->Name = L"�x�s�ɮ�ToolStripMenuItem";
			this->�x�s�ɮ�ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->�x�s�ɮ�ToolStripMenuItem->Text = L"�x�s�ɮ�";
			this->�x�s�ɮ�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�x�s�ɮ�ToolStripMenuItem_Click);
			// 
			// �t�s�s��ToolStripMenuItem
			// 
			this->�t�s�s��ToolStripMenuItem->Name = L"�t�s�s��ToolStripMenuItem";
			this->�t�s�s��ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->�t�s�s��ToolStripMenuItem->Text = L"�t�s�s��";
			this->�t�s�s��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�t�s�s��ToolStripMenuItem_Click);
			// 
			// �\��ToolStripMenuItem
			// 
			this->�\��ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�s�W�|��ToolStripMenuItem, 
				this->�M��|��ToolStripMenuItem});
			this->�\��ToolStripMenuItem->Name = L"�\��ToolStripMenuItem";
			this->�\��ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->�\��ToolStripMenuItem->Text = L"�\��";
			// 
			// �s�W�|��ToolStripMenuItem
			// 
			this->�s�W�|��ToolStripMenuItem->Name = L"�s�W�|��ToolStripMenuItem";
			this->�s�W�|��ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->�s�W�|��ToolStripMenuItem->Text = L"�s�W�|��";
			this->�s�W�|��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�s�W�|��ToolStripMenuItem_Click);
			// 
			// �M��|��ToolStripMenuItem
			// 
			this->�M��|��ToolStripMenuItem->Name = L"�M��|��ToolStripMenuItem";
			this->�M��|��ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->�M��|��ToolStripMenuItem->Text = L"�M��|��";
			this->�M��|��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�M��|��ToolStripMenuItem_Click);
			// 
			// �s��ToolStripMenuItem
			// 
			this->�s��ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�s�W�s��ToolStripMenuItem, 
				this->�R���s��ToolStripMenuItem});
			this->�s��ToolStripMenuItem->Name = L"�s��ToolStripMenuItem";
			this->�s��ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->�s��ToolStripMenuItem->Text = L"�s��";
			// 
			// �s�W�s��ToolStripMenuItem
			// 
			this->�s�W�s��ToolStripMenuItem->Name = L"�s�W�s��ToolStripMenuItem";
			this->�s�W�s��ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->�s�W�s��ToolStripMenuItem->Text = L"�s�W�s��";
			// 
			// �R���s��ToolStripMenuItem
			// 
			this->�R���s��ToolStripMenuItem->Name = L"�R���s��ToolStripMenuItem";
			this->�R���s��ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->�R���s��ToolStripMenuItem->Text = L"�R���s��";
			// 
			// ���ToolStripMenuItem
			// 
			this->���ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�C�����ToolStripMenuItem, 
				this->�浧���ToolStripMenuItem});
			this->���ToolStripMenuItem->Name = L"���ToolStripMenuItem";
			this->���ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->���ToolStripMenuItem->Text = L"���";
			// 
			// �C�����ToolStripMenuItem
			// 
			this->�C�����ToolStripMenuItem->Name = L"�C�����ToolStripMenuItem";
			this->�C�����ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->�C�����ToolStripMenuItem->Text = L"�C�����";
			this->�C�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�C�����ToolStripMenuItem_Click);
			// 
			// �浧���ToolStripMenuItem
			// 
			this->�浧���ToolStripMenuItem->Name = L"�浧���ToolStripMenuItem";
			this->�浧���ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->�浧���ToolStripMenuItem->Text = L"�浧���";
			this->�浧���ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�浧���ToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 34);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(960, 440);
			this->tabControl1->TabIndex = 1;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::tabControl1_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Size = System::Drawing::Size(952, 411);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"�q�T��1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Size = System::Drawing::Size(952, 411);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"�q�T��2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(959, 472);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"�q�T��";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		String^ file1;
		String^ file2;
		array<Label^>^ label;
		Label^ showpage;
		PictureBox^ picture;
		ToolStrip^ toolStrip1;
		DataGridView^ dataGridView1;
		ComboBox^ comboBox1;
		String^ s;

		void data_paint(Node* list,TabPage^ tabPage)
		{
			tabPage->Controls->Clear();
			
			/*�إ�ComboBox*/
			comboBox1 = gcnew ComboBox();
			comboBox1->Location = Point(500,20);
			comboBox1->Items->Add("�|���s��");
			comboBox1->Items->Add("�ʧO");
			comboBox1->Items->Add("�~��");	
			comboBox1->SelectedItem = s;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			tabPage->Controls->Add(comboBox1);
			sort = 1;
			
			/*�إ�Label*/
			Label^ l = gcnew Label();
			l->Text = "�ƧǡG";
			l->AutoSize = true;
			l->Location = System::Drawing::Point(460, 23); 
			tabPage->Controls->Add(l);
			
					 
			/*�إ�DataGridView*/
			dataGridView1 =gcnew DataGridView();
			dataGridView1->Location = Point(10,50);
			//dataGridView1->Size =System::Drawing::Size(500,100);
			dataGridView1->AutoSize=true;
			dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			dataGridView1->RowHeadersVisible = false;
			dataGridView1->AllowUserToAddRows = false;
			tabPage->Controls->Add(dataGridView1);
			dataGridView1->Columns->Add("number","number");
			dataGridView1->Columns->Add("name","name");
			dataGridView1->Columns->Add("sex","sex");
			dataGridView1->Columns->Add("old","old");
			dataGridView1->Columns->Add("mail","mail");
			dataGridView1->Columns->Add("address","address");
			dataGridView1->Columns[0]->ReadOnly = true;
			dataGridView1->Columns[1]->ReadOnly = true;
			dataGridView1->Columns[2]->ReadOnly = true;
			dataGridView1->Columns[3]->ReadOnly = true;
			dataGridView1->Columns[4]->ReadOnly = true;
			dataGridView1->Columns[5]->ReadOnly = true;
			dataGridView1->Columns[1]->Width=50;
			dataGridView1->Columns[2]->Width=50;
			dataGridView1->Columns[3]->Width=50;
			dataGridView1->Columns[4]->Width=100;
			dataGridView1->Columns[5]->Width=150;

			DataGridViewButtonColumn ^photo=gcnew DataGridViewButtonColumn();
			photo->HeaderText="photo";
			photo->Text="photo";
			photo->UseColumnTextForButtonValue=true;
			dataGridView1->CellClick +=gcnew DataGridViewCellEventHandler(this,&Form1::photomember_CellClick);
			dataGridView1->Columns->Add(photo);
			dataGridView1->Columns[6]->Width=50;
				
			DataGridViewButtonColumn ^mod=gcnew DataGridViewButtonColumn();
			mod->HeaderText="modify";
			mod->Text="modify";
			mod->UseColumnTextForButtonValue=true;
			//dataGridView1->CellClick +=gcnew DataGridViewCellEventHandler(this,&Form1::modifymember_CellClick);
			dataGridView1->Columns->Add(mod);
			dataGridView1->Columns[7]->Width=50;
					 
			DataGridViewButtonColumn ^del=gcnew DataGridViewButtonColumn();
			del->HeaderText="delete";
			del->Text="delete";
			del->UseColumnTextForButtonValue=true;
			dataGridView1->CellClick+=gcnew DataGridViewCellEventHandler(this,&Form1::delmember_CellClick);
			dataGridView1->Columns->Add(del);
			dataGridView1->Columns[8]->Width=50;
			while(list!=nullptr)
			{
				String ^s=gcnew String(list->sex == true ? "male" :"female");
				dataGridView1->Rows->Add("B0"+(list->number).ToString(),gcnew String((list->name).c_str()),s,(list->old).ToString(),gcnew String((list->mail).c_str()),gcnew String((list->address).c_str()));
				list = list->next;
			}
			page = 1;
		}
	
		void label_paint(Node* list, TabPage^ tabPage)
		{
			tabPage->Controls->Clear();
			toolStrip1 = gcnew ToolStrip();
			toolStrip1->Location = System::Drawing::Point(0, 24);
			toolStrip1->AutoSize = true;
			toolStrip1->TabIndex = 1;
			tabPage->Controls->Add(toolStrip1);
			
			ToolStripButton^ toolStripButton1 = gcnew ToolStripButton();
			toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			toolStripButton1->Text = L"<";
			toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			toolStrip1->Items->Add(toolStripButton1);

			ToolStripButton^ toolStripButton2 = gcnew ToolStripButton();
			toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			toolStripButton2->Text = L">";
			toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			toolStrip1->Items->Add(toolStripButton2);

			/*�إ�Label*/
			label[0]->Text = "�Ǹ��GB0"+(list->number).ToString();
			label[1]->Text = "�m�W�G"+gcnew String((list->name).c_str());
			String ^s=gcnew String(list->sex == true ? "male" :"female");
			label[2]->Text = "�ʧO�G"+s;
			label[3]->Text = "�~�֡G"+(list->old).ToString();
			label[4]->Text = "E-Mail�G"+gcnew String((list->mail).c_str());
			label[5]->Text = "�a�}�G"+gcnew String((list->address).c_str());
			for(int i=0;i<6;i++)
			{
				label[i]->Font = (gcnew System::Drawing::Font(L"�L�n������", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				label[i]->AutoSize = true;
				label[i]->Location = Point(350, 70+40*i);
				tabPage->Controls->Add(label[i]);
			}
			
			Bitmap^ img = gcnew Bitmap(gcnew String((list->filename).c_str()));
			picture->Image = img;
			picture->Location = Point(50, 50);
			picture->Size = System::Drawing::Size(250, 250);
			picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			tabPage->Controls->Add(picture);
			
			showpage->Text = page.ToString() + "/" + (tabControl1->SelectedIndex==0 ? data1.getCount() : data2.getCount()).ToString();
			showpage->Location = Point(600, 30);
			showpage->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			tabPage->Controls->Add(showpage);
		}

		void control_paint(int show, int tab, Node* list)
		{
			if(show == 1)
			{
				if(tab == 0)
					data_paint(list,tabPage1);
				else
					data_paint(list,tabPage2);
			}
			else
			{
				if(tab == 0)
					label_paint(list,tabPage1);
				else
					label_paint(list,tabPage2);
			}
		}


private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				showpage = gcnew Label();
				label =  gcnew array<Label^> (6);
				for(int i=0;i<6;i++)
					label[i] = gcnew Label();
				picture = gcnew PictureBox();
				sort = 1;
				page = 1;
				showmode = 1;
				tabpage = 0;



			}
private: System::Void �}������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			
			openFileDialog1->Filter = "��r���(*.txt) |*.txt";
			if(openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				int nowtap = tabControl1->SelectedIndex;
				
		
				
				tabControl1->SelectedIndex==0 ? data1.clear() :data2.clear();
				StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName,System::Text::Encoding::GetEncoding("BIG5"));
				tabControl1->SelectedIndex==0 ? file1 = openFileDialog1->FileName : file2 = openFileDialog1->FileName;
				String^ filesite;
				array<String^>^ site = (tabControl1->SelectedIndex==0 ? file1 : file2)->Split('\\');
				for(int i=0;i<site->Length-1;i++)
				{
					filesite += site[i];
					filesite += "\\";
				}
				while(reader->Peek() > -1)
				{
					String^ line =reader->ReadLine();
					//���Φr��
					array<String^>^ s = line->Split(' ');
					array<String^>^ s1 = s[1]->Split('B');
					int tab = Convert::ToInt32(s[0]);
					int num = Convert::ToInt32(s1[1]);
					int old = Convert::ToInt32(s[4]);
					bool sex;
					if(s[3]->Equals("female"))
						sex = false;
					else
						sex = true;
					string name = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s[2])).ToPointer();
					string mail = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s[5])).ToPointer();
					string filename = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(filesite + s[6])).ToPointer();
					string address = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s[7])).ToPointer();
					
					if(tab == 1)
						data1.push(tab,num,name,old,sex,mail,filename,address);
					if(tab == 2)
						data2.push(tab,num,name,old,sex,mail,filename,address);
				}
				tabControl1->SelectedIndex==0 ? data1.sort(sort) : data2.sort(sort);		
				tabControl1->SelectedIndex==0 ? list = data1.getList() : list = data2.getList();
			     control_paint(showmode,tabControl1->SelectedIndex,list);

				reader->Close();

			 }
		 }
private: System::Void �x�s�ɮ�ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			StreamWriter^ sw = gcnew StreamWriter(tabControl1->SelectedIndex==0 ? file1 : file2,false,System::Text::Encoding::GetEncoding("BIG5"));
			tabControl1->SelectedIndex==0 ? data1.sort(sort) : data2.sort(sort);		
			tabControl1->SelectedIndex==0 ? list = data1.getList() : list = data2.getList();
			while(list!=nullptr)
			{
				String ^s=gcnew String(list->sex == true ? "male" :"female");
				String^ filesite = gcnew String((list->filename).c_str());
				array<String^>^ files = filesite->Split('\\');
				sw->WriteLine("B0"+(list->number).ToString()+" "+gcnew String((list->name).c_str())+" "+s+" "+(list->old).ToString()+" "+gcnew String((list->mail).c_str())+" "+files[files->Length-1]+" "+gcnew String((list->address).c_str()));
				list = list->next;
			}
			sw->Close();

		 }
private: System::Void �t�s�s��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


			 saveFileDialog1->Filter = "��r���(*.txt) |*.txt";
			 saveFileDialog1->Title="Select";
			 //�x�s�ɮ�
			 if(saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName,false,System::Text::Encoding::GetEncoding("BIG5"));
				 
				 tabControl1->SelectedIndex==0 ? data1.sort(sort) : data2.sort(sort);		
				 tabControl1->SelectedIndex==0 ? list = data1.getList() : list = data2.getList();
				 while(list!=nullptr)
				 {
					 String ^s=gcnew String(list->sex == true ? "male" :"female");
					 String^ filesite = gcnew String((list->filename).c_str());
					 array<String^>^ files = filesite->Split('\\');
					 sw->WriteLine("B0"+(list->number).ToString()+" "+gcnew String((list->name).c_str())+" "+s+" "+(list->old).ToString()+" "+gcnew String((list->mail).c_str())+" "+files[files->Length-1]+" "+gcnew String((list->address).c_str()));
					 list = list->next;
				 }
				 sw->Close();
			 }

		 }
private: System::Void �s�W�|��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 Add^ addform = gcnew Add();
			 addform->StartPosition = FormStartPosition::CenterParent;
			 addform->ShowDialog();
			 
			 while(1)
			 {	 
				if(addform->success == false)
				{
					break;
				}
				array<String^>^ s1;
				s1 = addform->textBox1->Text->Split('B');
				int num = Convert::ToInt32(s1[1]);
				if(data.dubnum(num))
				{
					 MessageBox::Show("���� !! �s�����ơI");
					 addform->ShowDialog();
					 continue;
				}
				
				else if(addform->success)
				{
					int tab;
					tab = tabControl1->SelectedIndex ;
					int old;
					try
					{
						old = Convert::ToInt32(addform->textBox3->Text);
					}
					catch(...)
					{
						 MessageBox::Show("�~�ֿ�J���~�I");
						 addform->ShowDialog();
						 continue;
					}
					bool sex;
					if(addform->radioButton2->Checked)
						sex = false;
					else
						sex = true;
					const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(addform->textBox2->Text)).ToPointer();
					string name = chars;
					chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(addform->textBox4->Text)).ToPointer();
					string mail = chars;
					chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(addform->textBox5->Text)).ToPointer();
					string address = chars;
					chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(addform->textBox6->Text)).ToPointer();
					string filename = chars;
					
					tabControl1->SelectedIndex==0 ? data1.push(tab,num,name,old,sex,mail,filename,address) : data2.push(tab,num,name,old,sex,mail,filename,address);
					page = 1;
					tabControl1->SelectedIndex==0 ? data1.sort(sort) : data2.sort(sort);		
					tabControl1->SelectedIndex==0 ? list = data1.getList() : list = data2.getList();
					control_paint(showmode,tabControl1->SelectedIndex,list);
					
					break;
				}
				
			 }
			 

		 }
private: System::Void �M��|��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void �C�����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 tabControl1->SelectedIndex==0 ? data1.sort(sort) : data2.sort(sort);		
			 tabControl1->SelectedIndex==0 ? list = data1.getList() : list = data2.getList();
			 showmode = 1;
			 control_paint(showmode,tabControl1->SelectedIndex,list);

		 }
private: System::Void �浧���ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

             tabControl1->SelectedIndex==0 ? data1.sort(sort) : data2.sort(sort);		
			 tabControl1->SelectedIndex==0 ? list = data1.getList() : list = data2.getList();
			 showmode = 2;
			 control_paint(showmode,tabControl1->SelectedIndex,list);
		 }


private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(page == 1)
			 {
			 }
			 else
			 {
				 list = list->prev;
				 page--;
			 }			 
			 control_paint(showmode,tabControl1->SelectedIndex,list);

		 }
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(list->next == nullptr)
			 {
			 }
			 else
			 {
				 list = list->next;
				 page++;
			 }
			 control_paint(showmode,tabControl1->SelectedIndex,list);
		 }

/*
	comboBox1 ����
*/
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 if( comboBox1->SelectedItem == "�|���s��")
			 {
			 	sort = 1;
				s = "�|���s��";
			 }
			 else if( comboBox1->SelectedItem == "�ʧO")
			 {
			 	sort = 2;
				s = "�ʧO";
			 }
			 else if( comboBox1->SelectedItem == "�~��")
			 {
			 	sort = 3;
				s = "�~��";
			 }

             tabControl1->SelectedIndex==0 ? data1.sort(sort) : data2.sort(sort);		
			 tabControl1->SelectedIndex==0 ? list = data1.getList() : list = data2.getList();
			 control_paint(showmode,tabControl1->SelectedIndex,list);
		}

private: System::Void tabControl1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 page = 1;
			 if(tabControl1->SelectedIndex==0 && data1.getList() != nullptr)
			 {
				 list = data1.getList();
				 control_paint(showmode,tabControl1->SelectedIndex,list);
			 }
			 else if(tabControl1->SelectedIndex==1 && data2.getList() != nullptr)
			 {
				 list = data2.getList();
				 control_paint(showmode,tabControl1->SelectedIndex,list);
			 }
		 }


private: System::Void photomember_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 
			 if (e->ColumnIndex == 6)
			 {
				 int row = e->RowIndex;
				 Node *current = list;

				 PHOTO^ photoform = gcnew PHOTO();
				 
				 for(int i=0;i<row;i++)
					 current = current->next;

				 Bitmap^ img = gcnew Bitmap(gcnew String((current->filename).c_str()));
				 photoform->pictureBox1->Image = img;
				 photoform->StartPosition = FormStartPosition::CenterParent ;
				 photoform->ShowDialog();
			 }
	 
		 }

/*
	Delete���s����
*/			
private: System::Void delmember_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 
			 if (e->ColumnIndex == 8)
			 {
				 int row = e->RowIndex;
				 String^ s = System::Convert::ToString(dataGridView1->Rows[row]->Cells[0]->Value);
				 array<String^>^ s1 = s->Split('B');				
				 int num = Convert::ToInt32(s1[1]);

				 tabControl1->SelectedIndex==0 ? data1.deletenode(num) : data2.deletenode(num);
				 tabControl1->SelectedIndex==0 ? data1.sort(sort) : data2.sort(sort);		
				 tabControl1->SelectedIndex==0 ? list = data1.getList() : list = data2.getList();
				 control_paint(showmode,tabControl1->SelectedIndex,list);
			 }

		 }


};
}

