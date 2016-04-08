#pragma once
#include "Dinfo.h";
#include "Add.h";
#include <stdio.h>
#include <string.h>
namespace B033040009_11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	static Dinfo *head = NULL;
	static Dinfo *rear = NULL;
	static Dinfo *current = NULL;
	
	int is_empty(Dinfo *dl)
	{
		return (dl == NULL);
	}
	void remove(Dinfo **head, Dinfo **rear , Dinfo **current){
		if((*current) ==(*head)){
			(*head)= (*current)->getnext();
			(*current)->getnext()->setpre((*head));
			delete((*current));
		}
		else if((*current) ==(*rear)){
			(*rear)= (*current)->getpre();
			(*current)->getpre()->setnext((*rear));
			delete((*current));
		}
		else{
			(*current)->getpre()->setnext( (*current)->getnext() );
			(*current)->getnext()->setpre( (*current)->getpre() );
			delete((*current));
		}
	}

	void insert_front(Dinfo **head, Dinfo **rear , string _number, string _name, bool _sex, int _age,string _mail, string _pic, string _address)
	{
		/*
		string number;
		string name;
		bool sex;
		int age
		string mail;
		string address;
		*/

		Dinfo *temp;
		temp = new Dinfo;
		temp->number = _number;
		temp->name = _name;
		temp->sex = _sex;
		temp->age = _age;
		temp->mail = _mail;
		temp->pic = _pic;
		temp->address = _address;

			if(is_empty( (*head) ) && is_empty( (*rear) ))
			{
				(*head) = temp;
				(*head)-> setnext(nullptr);
				(*head)-> setpre(nullptr);
				(*rear) = temp;
				(*rear)-> setnext(nullptr);
				(*rear)-> setpre(nullptr);
			}
			else
			{
				temp -> setnext(*head);
				temp -> setpre(nullptr);
				(*head) -> setpre(temp);
				(*head) = temp;
			}
		 //++count;
	}

	void insert_back(Dinfo **head, Dinfo **rear , string _number, string _name, bool _sex, int _age,string _mail, string _pic, string _address)
	{
		Dinfo *temp;
		temp = new Dinfo;
		temp->number = _number;
		temp->name = _name;
		temp->sex = _sex;
		temp->age = _age;
		temp->mail = _mail;
		temp->pic = _pic;
		temp->address = _address;

			if(is_empty( (*head) ) && is_empty( (*rear) ))
			{
				(*head) = temp;
				(*head)-> setnext(nullptr);
				(*head)-> setpre(nullptr);
				(*rear) = temp;
				(*rear)-> setnext(nullptr);
				(*rear)-> setpre(nullptr);
			}
			else
			{
				temp -> setnext(nullptr);
				temp -> setpre(*rear);
				(*rear) -> setnext(temp);
				(*rear) = temp;
			}
		 //++count;
	}

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
	private: System::Windows::Forms::ToolStripMenuItem^  開啟舊檔ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  儲存舊檔ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  另存新檔ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  功能ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  新增會員ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  尋找會員ToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->檔案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->開啟舊檔ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->儲存舊檔ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->另存新檔ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->功能ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->新增會員ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->尋找會員ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->檔案ToolStripMenuItem, 
				this->功能ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(797, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 檔案ToolStripMenuItem
			// 
			this->檔案ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->開啟舊檔ToolStripMenuItem, 
				this->儲存舊檔ToolStripMenuItem, this->另存新檔ToolStripMenuItem});
			this->檔案ToolStripMenuItem->Name = L"檔案ToolStripMenuItem";
			this->檔案ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->檔案ToolStripMenuItem->Text = L"檔案";
			// 
			// 開啟舊檔ToolStripMenuItem
			// 
			this->開啟舊檔ToolStripMenuItem->Name = L"開啟舊檔ToolStripMenuItem";
			this->開啟舊檔ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->開啟舊檔ToolStripMenuItem->Text = L"開啟舊檔";
			this->開啟舊檔ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::開啟舊檔ToolStripMenuItem_Click);
			// 
			// 儲存舊檔ToolStripMenuItem
			// 
			this->儲存舊檔ToolStripMenuItem->Name = L"儲存舊檔ToolStripMenuItem";
			this->儲存舊檔ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->儲存舊檔ToolStripMenuItem->Text = L"儲存舊檔";
			this->儲存舊檔ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::儲存舊檔ToolStripMenuItem_Click);
			// 
			// 另存新檔ToolStripMenuItem
			// 
			this->另存新檔ToolStripMenuItem->Name = L"另存新檔ToolStripMenuItem";
			this->另存新檔ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
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
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripButton1, 
				this->toolStripButton2});
			this->toolStrip1->Location = System::Drawing::Point(0, 27);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(797, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Enabled = false;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Enabled = false;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"toolStripButton2";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(797, 506);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"通訊錄";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		static int membersum=0,now=1;
		String^ filename;
		System::Windows::Forms::PictureBox^  pictureBox1;
	    System::Windows::Forms::Label^  label1;
	    System::Windows::Forms::Label^  label2;
	    System::Windows::Forms::Label^  label3;
	    System::Windows::Forms::Label^  label4;
	    System::Windows::Forms::Label^  label5;
	    System::Windows::Forms::Label^  label6;
	    System::Windows::Forms::Label^  label7;
	private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
				 toolStripButton2->Enabled = true;
				 --now;
				 current = current->getpre();
				 if(now == 1)
				 toolStripButton1->Enabled = false;
				 
				 this->pictureBox1->Image=Image::FromFile(gcnew String(current->pic.c_str()));
				 this->label1->Text ="學號 : " + gcnew String(current->number.c_str());
				 this->label2->Text ="姓名 : " +gcnew String(current->name.c_str());
				 if(current->sex==true)
					this->label3->Text ="性別 : male";
				 else if(head->sex==false)
					this->label3->Text ="性別 : female";
				 this->label4->Text ="年齡 : "+ current->age.ToString();
				 this->label5->Text ="E-Mail : " + gcnew String(current->mail.c_str());
				 this->label6->Text ="地址 : " + gcnew String(current->address.c_str());
				 this->label7->Text =now.ToString()+"/"+membersum.ToString();
			 }
	private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
				 toolStripButton1->Enabled = true;
				 ++now;
				 current = current->getnext();
				 if(now == membersum)
				 toolStripButton2->Enabled = false;
				 
				 this->pictureBox1->Image=Image::FromFile(gcnew String(current->pic.c_str()));
				 this->label1->Text ="學號 : " + gcnew String(current->number.c_str());
				 this->label2->Text ="姓名 : " +gcnew String(current->name.c_str());
				 if(current->sex==true)
					this->label3->Text ="性別 : male";
				 else if(head->sex==false)
					this->label3->Text ="性別 : female";
				 this->label4->Text ="年齡 : "+ current->age.ToString();
				 this->label5->Text ="E-Mail : " + gcnew String(current->mail.c_str());
				 this->label6->Text ="地址 : " + gcnew String(current->address.c_str());
				 this->label7->Text =now.ToString()+"/"+membersum.ToString();
			 }
private: System::Void 開啟舊檔ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			  head = NULL;
			  rear = NULL;
			  membersum=0;
			  now = 1;
			  String ^ line;
			  toolStripButton1->Enabled = false;
				 StreamReader^ sr;
				 OpenFileDialog^ open=gcnew OpenFileDialog();
				 open->Filter="Texture |*.txt";
				 open->Title="選擇檔案";

				 if(open->ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 sr=gcnew StreamReader(open->FileName,System::Text::Encoding::GetEncoding("big5"));
					 filename = open->FileName;
					 while(3){
						 if(sr->EndOfStream){
							 break;
						 }
						 /*
						 string number;
						 string name;
						 bool sex;
						 int age;
						 string mail;
						 string pic;
						 string address;
						 */
						 line = sr -> ReadLine();
						 String^ seperator = " ";
						 array<Char>^ sep = seperator -> ToCharArray();
						 array<String^>^ split = line -> Split(sep);
						 string number;
						 string name;
						 bool sex;	
						 int age;
						 string mail;
						 string pic;
						 string address;

						 MarshalString ( split[0], number );
						 MarshalString ( split[1], name );
						 if (split[2] == "male")
								sex = true;
						 else
								sex = false;
						 age = Convert::ToInt32(split[3]);
						 MarshalString ( split[4], mail );
						 MarshalString ( split[5], pic );
						 MarshalString ( split[6], address );

						 insert_back(&head, &rear , number, name, sex, age, mail, pic, address);
						
						 membersum++;
					 }
				 }
				 sr->Close();

				 
				 toolStripButton2->Enabled = true;
				 this->pictureBox1->Image=Image::FromFile(gcnew String(head->pic.c_str()));
				 this->label1->Text ="學號 : " + gcnew String(head->number.c_str());
				 this->label2->Text ="姓名 : " +gcnew String(head->name.c_str());
				 if(head->sex==true)
					this->label3->Text ="性別 : male";
				 else if(head->sex==false)
					this->label3->Text ="性別 : female";
				 this->label4->Text ="年齡 : "+ head->age.ToString();
				 this->label5->Text ="E-Mail : " + gcnew String(head->mail.c_str());
				 this->label6->Text ="地址 : " + gcnew String(head->address.c_str());
				 this->label7->Text =now.ToString()+"/"+membersum.ToString();
				 current = head;
		 }

		 
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1->Location = System::Drawing::Point(2, 100);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(255, 230);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			this->Controls->Add(this->pictureBox1);
			
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label1->Location = System::Drawing::Point(270, 100);
			this->label1->Name = L"label1";
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label1->Size = System::Drawing::Size(200, 20);
			this->label1->TabIndex = 0;
			this->Controls->Add(this->label1);
			
			
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label2->Location = System::Drawing::Point(270, 142);
			this->label2->Name = L"label2";
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label2->Size = System::Drawing::Size(200, 20);
			this->label2->TabIndex = 0;
			this->Controls->Add(this->label2);
			
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label3->Location = System::Drawing::Point(270, 184);
			this->label3->Name = L"label3";
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label3->Size = System::Drawing::Size(200, 20);
			this->label3->TabIndex = 0;
			this->Controls->Add(this->label3);
			
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label4->Location = System::Drawing::Point(270, 226);
			this->label4->Name = L"label4";
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label4->Size = System::Drawing::Size(200, 20);
			this->label4->TabIndex = 0;
			this->Controls->Add(this->label4);

			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label5->Location = System::Drawing::Point(270, 268);
			this->label5->Name = L"label5";
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label5->Size = System::Drawing::Size(200, 20);
			this->label5->TabIndex = 0;
			this->Controls->Add(this->label5);

			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label6->Location = System::Drawing::Point(270, 310);
			this->label6->Name = L"label6";
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label6->Size = System::Drawing::Size(200, 20);
			this->label6->TabIndex = 0;
			this->Controls->Add(this->label6);

			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label7->Location = System::Drawing::Point(550, 100);
			this->label7->Name = L"label7";
			this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label7->Size = System::Drawing::Size(200, 20);
			this->label7->TabIndex = 0;
			this->Controls->Add(this->label7);
		 }
private: System::Void 新增會員ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Add^ add = gcnew Add;
			 add->ShowDialog();
			 if(add->check == 1){
				string number;
				string name;
				bool sex;	
				int age;
				string mail;
				string pic;
				string address;

				MarshalString ( add->_number, number );
				MarshalString ( add->_name, name );
				sex = add->_sex;
				age = add->_age;
				MarshalString ( add->_mail, mail );
				MarshalString ( add->_pic, pic );
				MarshalString ( add->_address, address );

				insert_back(&head, &rear , number, name, sex, age, mail, pic, address);
				membersum++;
				this->label7->Text =now.ToString()+"/"+membersum.ToString();
				toolStripButton2->Enabled = true;
			 }
		 }
private: System::Void 儲存舊檔ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 StreamWriter^ sw = gcnew StreamWriter(filename,false);
					/*
					string number;
					string name;
					bool sex;	
					int age;
					string mail;
					string pic;
					string address;
					*/

					current = head;
					while(current != NULL){
					String^ number_out = gcnew String((current->number).c_str());
					String^ name_out = gcnew String((current->name).c_str());
					String^ gender_out;
					if(current -> sex == true)
						gender_out = "male";
					else
						gender_out = "female";
					String^ age_out = gcnew String(Convert::ToString(current->age));
					String^ mail_out = gcnew String((current->mail).c_str());
					String^ pic_out = gcnew String((current->pic).c_str());
					String^ address_out = gcnew String((current->address).c_str());
					
					String^ output = gcnew String(number_out + " " + name_out + " " + gender_out + " " + age_out + " " + mail_out + " " + pic_out + " " + address_out);
					sw->WriteLine(output);
					current = current->getnext();
					}

					sw->Close();
		 }
private: System::Void 另存新檔ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ saveD = gcnew SaveFileDialog();
				saveD->InitialDirectory = "c:\\";
				saveD->Filter = "Texture File|*.txt"; //檔案限制類型
				saveD->Title = "Select a File";       //視窗標題
				if(saveD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					StreamWriter^ sw = gcnew StreamWriter(saveD->FileName);
					Dinfo *current = head;

					while(current != NULL){
					String^ number_out = gcnew String((current->number).c_str());
					String^ name_out = gcnew String((current->name).c_str());
					String^ gender_out;
					if(current -> sex == true)
						gender_out = "male";
					else
						gender_out = "female";
					String^ age_out = gcnew String(Convert::ToString(current->age));
					String^ mail_out = gcnew String((current->mail).c_str());
					String^ pic_out = gcnew String((current->pic).c_str());
					String^ address_out = gcnew String((current->address).c_str());
					
					String^ output = gcnew String(number_out + " " + name_out + " " + gender_out + " " + age_out + " " + mail_out + " " + pic_out + " " + address_out);
					sw->WriteLine(output);
					current = current->getnext();
					}

					sw->Close();
				}
		 }
};
}

