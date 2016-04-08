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
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
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
	private: System::Windows::Forms::ToolStripMenuItem^  檔案ToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ToolStripMenuItem^  開啟舊檔ToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  儲存檔案ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  另存新檔ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  功能ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  新增會員ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  尋找會員ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  群組ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  新增群組ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  刪除群組ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  顯示ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  列表顯示ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  單筆顯示ToolStripMenuItem;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->檔案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->開啟舊檔ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->儲存檔案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->另存新檔ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->功能ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->新增會員ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->尋找會員ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->群組ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->新增群組ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->刪除群組ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->顯示ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->列表顯示ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->單筆顯示ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->檔案ToolStripMenuItem, 
				this->功能ToolStripMenuItem, this->群組ToolStripMenuItem, this->顯示ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(959, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 檔案ToolStripMenuItem
			// 
			this->檔案ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->開啟舊檔ToolStripMenuItem, 
				this->儲存檔案ToolStripMenuItem, this->另存新檔ToolStripMenuItem});
			this->檔案ToolStripMenuItem->Name = L"檔案ToolStripMenuItem";
			this->檔案ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->檔案ToolStripMenuItem->Text = L"檔案";
			// 
			// 開啟舊檔ToolStripMenuItem
			// 
			this->開啟舊檔ToolStripMenuItem->Name = L"開啟舊檔ToolStripMenuItem";
			this->開啟舊檔ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->開啟舊檔ToolStripMenuItem->Text = L"開啟舊檔";
			this->開啟舊檔ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::開啟舊檔ToolStripMenuItem_Click);
			// 
			// 儲存檔案ToolStripMenuItem
			// 
			this->儲存檔案ToolStripMenuItem->Name = L"儲存檔案ToolStripMenuItem";
			this->儲存檔案ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->儲存檔案ToolStripMenuItem->Text = L"儲存檔案";
			this->儲存檔案ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::儲存檔案ToolStripMenuItem_Click);
			// 
			// 另存新檔ToolStripMenuItem
			// 
			this->另存新檔ToolStripMenuItem->Name = L"另存新檔ToolStripMenuItem";
			this->另存新檔ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->另存新檔ToolStripMenuItem->Text = L"另存新檔";
			this->另存新檔ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::另存新檔ToolStripMenuItem_Click);
			// 
			// 功能ToolStripMenuItem
			// 
			this->功能ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->新增會員ToolStripMenuItem, 
				this->尋找會員ToolStripMenuItem});
			this->功能ToolStripMenuItem->Name = L"功能ToolStripMenuItem";
			this->功能ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->功能ToolStripMenuItem->Text = L"功能";
			// 
			// 新增會員ToolStripMenuItem
			// 
			this->新增會員ToolStripMenuItem->Name = L"新增會員ToolStripMenuItem";
			this->新增會員ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->新增會員ToolStripMenuItem->Text = L"新增會員";
			this->新增會員ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::新增會員ToolStripMenuItem_Click);
			// 
			// 尋找會員ToolStripMenuItem
			// 
			this->尋找會員ToolStripMenuItem->Name = L"尋找會員ToolStripMenuItem";
			this->尋找會員ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->尋找會員ToolStripMenuItem->Text = L"尋找會員";
			this->尋找會員ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::尋找會員ToolStripMenuItem_Click);
			// 
			// 群組ToolStripMenuItem
			// 
			this->群組ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->新增群組ToolStripMenuItem, 
				this->刪除群組ToolStripMenuItem});
			this->群組ToolStripMenuItem->Name = L"群組ToolStripMenuItem";
			this->群組ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->群組ToolStripMenuItem->Text = L"群組";
			// 
			// 新增群組ToolStripMenuItem
			// 
			this->新增群組ToolStripMenuItem->Name = L"新增群組ToolStripMenuItem";
			this->新增群組ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->新增群組ToolStripMenuItem->Text = L"新增群組";
			// 
			// 刪除群組ToolStripMenuItem
			// 
			this->刪除群組ToolStripMenuItem->Name = L"刪除群組ToolStripMenuItem";
			this->刪除群組ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->刪除群組ToolStripMenuItem->Text = L"刪除群組";
			// 
			// 顯示ToolStripMenuItem
			// 
			this->顯示ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->列表顯示ToolStripMenuItem, 
				this->單筆顯示ToolStripMenuItem});
			this->顯示ToolStripMenuItem->Name = L"顯示ToolStripMenuItem";
			this->顯示ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->顯示ToolStripMenuItem->Text = L"顯示";
			// 
			// 列表顯示ToolStripMenuItem
			// 
			this->列表顯示ToolStripMenuItem->Name = L"列表顯示ToolStripMenuItem";
			this->列表顯示ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->列表顯示ToolStripMenuItem->Text = L"列表顯示";
			this->列表顯示ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::列表顯示ToolStripMenuItem_Click);
			// 
			// 單筆顯示ToolStripMenuItem
			// 
			this->單筆顯示ToolStripMenuItem->Name = L"單筆顯示ToolStripMenuItem";
			this->單筆顯示ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->單筆顯示ToolStripMenuItem->Text = L"單筆顯示";
			this->單筆顯示ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::單筆顯示ToolStripMenuItem_Click);
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
			this->tabPage1->Text = L"通訊錄1";
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
			this->tabPage2->Text = L"通訊錄2";
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
			this->Text = L"通訊錄";
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
			
			/*建立ComboBox*/
			comboBox1 = gcnew ComboBox();
			comboBox1->Location = Point(500,20);
			comboBox1->Items->Add("會員編號");
			comboBox1->Items->Add("性別");
			comboBox1->Items->Add("年齡");	
			comboBox1->SelectedItem = s;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			tabPage->Controls->Add(comboBox1);
			sort = 1;
			
			/*建立Label*/
			Label^ l = gcnew Label();
			l->Text = "排序：";
			l->AutoSize = true;
			l->Location = System::Drawing::Point(460, 23); 
			tabPage->Controls->Add(l);
			
					 
			/*建立DataGridView*/
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

			/*建立Label*/
			label[0]->Text = "學號：B0"+(list->number).ToString();
			label[1]->Text = "姓名："+gcnew String((list->name).c_str());
			String ^s=gcnew String(list->sex == true ? "male" :"female");
			label[2]->Text = "性別："+s;
			label[3]->Text = "年齡："+(list->old).ToString();
			label[4]->Text = "E-Mail："+gcnew String((list->mail).c_str());
			label[5]->Text = "地址："+gcnew String((list->address).c_str());
			for(int i=0;i<6;i++)
			{
				label[i]->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
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
			showpage->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
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
private: System::Void 開啟舊檔ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			
			openFileDialog1->Filter = "文字文件(*.txt) |*.txt";
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
					//分割字串
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
private: System::Void 儲存檔案ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

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
private: System::Void 另存新檔ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


			 saveFileDialog1->Filter = "文字文件(*.txt) |*.txt";
			 saveFileDialog1->Title="Select";
			 //儲存檔案
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
private: System::Void 新增會員ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

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
					 MessageBox::Show("失敗 !! 編號重複！");
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
						 MessageBox::Show("年齡輸入有誤！");
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
private: System::Void 尋找會員ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void 列表顯示ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 tabControl1->SelectedIndex==0 ? data1.sort(sort) : data2.sort(sort);		
			 tabControl1->SelectedIndex==0 ? list = data1.getList() : list = data2.getList();
			 showmode = 1;
			 control_paint(showmode,tabControl1->SelectedIndex,list);

		 }
private: System::Void 單筆顯示ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

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
	comboBox1 執行
*/
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 if( comboBox1->SelectedItem == "會員編號")
			 {
			 	sort = 1;
				s = "會員編號";
			 }
			 else if( comboBox1->SelectedItem == "性別")
			 {
			 	sort = 2;
				s = "性別";
			 }
			 else if( comboBox1->SelectedItem == "年齡")
			 {
			 	sort = 3;
				s = "年齡";
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
	Delete按鈕執行
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

