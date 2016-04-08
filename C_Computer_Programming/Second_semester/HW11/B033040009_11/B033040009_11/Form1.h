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
	private: System::Windows::Forms::ToolStripMenuItem^  �}������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �x�s����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �t�s�s��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �\��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �s�W�|��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �M��|��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�ɮ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�}������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�x�s����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�t�s�s��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�\��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�s�W�|��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�M��|��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�ɮ�ToolStripMenuItem, 
				this->�\��ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(797, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �ɮ�ToolStripMenuItem
			// 
			this->�ɮ�ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->�}������ToolStripMenuItem, 
				this->�x�s����ToolStripMenuItem, this->�t�s�s��ToolStripMenuItem});
			this->�ɮ�ToolStripMenuItem->Name = L"�ɮ�ToolStripMenuItem";
			this->�ɮ�ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->�ɮ�ToolStripMenuItem->Text = L"�ɮ�";
			// 
			// �}������ToolStripMenuItem
			// 
			this->�}������ToolStripMenuItem->Name = L"�}������ToolStripMenuItem";
			this->�}������ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->�}������ToolStripMenuItem->Text = L"�}������";
			this->�}������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�}������ToolStripMenuItem_Click);
			// 
			// �x�s����ToolStripMenuItem
			// 
			this->�x�s����ToolStripMenuItem->Name = L"�x�s����ToolStripMenuItem";
			this->�x�s����ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->�x�s����ToolStripMenuItem->Text = L"�x�s����";
			this->�x�s����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�x�s����ToolStripMenuItem_Click);
			// 
			// �t�s�s��ToolStripMenuItem
			// 
			this->�t�s�s��ToolStripMenuItem->Name = L"�t�s�s��ToolStripMenuItem";
			this->�t�s�s��ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
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
			this->Text = L"�q�T��";
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
				 this->label1->Text ="�Ǹ� : " + gcnew String(current->number.c_str());
				 this->label2->Text ="�m�W : " +gcnew String(current->name.c_str());
				 if(current->sex==true)
					this->label3->Text ="�ʧO : male";
				 else if(head->sex==false)
					this->label3->Text ="�ʧO : female";
				 this->label4->Text ="�~�� : "+ current->age.ToString();
				 this->label5->Text ="E-Mail : " + gcnew String(current->mail.c_str());
				 this->label6->Text ="�a�} : " + gcnew String(current->address.c_str());
				 this->label7->Text =now.ToString()+"/"+membersum.ToString();
			 }
	private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
				 toolStripButton1->Enabled = true;
				 ++now;
				 current = current->getnext();
				 if(now == membersum)
				 toolStripButton2->Enabled = false;
				 
				 this->pictureBox1->Image=Image::FromFile(gcnew String(current->pic.c_str()));
				 this->label1->Text ="�Ǹ� : " + gcnew String(current->number.c_str());
				 this->label2->Text ="�m�W : " +gcnew String(current->name.c_str());
				 if(current->sex==true)
					this->label3->Text ="�ʧO : male";
				 else if(head->sex==false)
					this->label3->Text ="�ʧO : female";
				 this->label4->Text ="�~�� : "+ current->age.ToString();
				 this->label5->Text ="E-Mail : " + gcnew String(current->mail.c_str());
				 this->label6->Text ="�a�} : " + gcnew String(current->address.c_str());
				 this->label7->Text =now.ToString()+"/"+membersum.ToString();
			 }
private: System::Void �}������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			  head = NULL;
			  rear = NULL;
			  membersum=0;
			  now = 1;
			  String ^ line;
			  toolStripButton1->Enabled = false;
				 StreamReader^ sr;
				 OpenFileDialog^ open=gcnew OpenFileDialog();
				 open->Filter="Texture |*.txt";
				 open->Title="����ɮ�";

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
				 this->label1->Text ="�Ǹ� : " + gcnew String(head->number.c_str());
				 this->label2->Text ="�m�W : " +gcnew String(head->name.c_str());
				 if(head->sex==true)
					this->label3->Text ="�ʧO : male";
				 else if(head->sex==false)
					this->label3->Text ="�ʧO : female";
				 this->label4->Text ="�~�� : "+ head->age.ToString();
				 this->label5->Text ="E-Mail : " + gcnew String(head->mail.c_str());
				 this->label6->Text ="�a�} : " + gcnew String(head->address.c_str());
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
			this->label1->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12));
			this->label1->Size = System::Drawing::Size(200, 20);
			this->label1->TabIndex = 0;
			this->Controls->Add(this->label1);
			
			
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label2->Location = System::Drawing::Point(270, 142);
			this->label2->Name = L"label2";
			this->label2->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12));
			this->label2->Size = System::Drawing::Size(200, 20);
			this->label2->TabIndex = 0;
			this->Controls->Add(this->label2);
			
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label3->Location = System::Drawing::Point(270, 184);
			this->label3->Name = L"label3";
			this->label3->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12));
			this->label3->Size = System::Drawing::Size(200, 20);
			this->label3->TabIndex = 0;
			this->Controls->Add(this->label3);
			
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label4->Location = System::Drawing::Point(270, 226);
			this->label4->Name = L"label4";
			this->label4->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12));
			this->label4->Size = System::Drawing::Size(200, 20);
			this->label4->TabIndex = 0;
			this->Controls->Add(this->label4);

			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label5->Location = System::Drawing::Point(270, 268);
			this->label5->Name = L"label5";
			this->label5->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12));
			this->label5->Size = System::Drawing::Size(200, 20);
			this->label5->TabIndex = 0;
			this->Controls->Add(this->label5);

			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label6->Location = System::Drawing::Point(270, 310);
			this->label6->Name = L"label6";
			this->label6->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12));
			this->label6->Size = System::Drawing::Size(200, 20);
			this->label6->TabIndex = 0;
			this->Controls->Add(this->label6);

			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label7->Location = System::Drawing::Point(550, 100);
			this->label7->Name = L"label7";
			this->label7->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12));
			this->label7->Size = System::Drawing::Size(200, 20);
			this->label7->TabIndex = 0;
			this->Controls->Add(this->label7);
		 }
private: System::Void �s�W�|��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void �x�s����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void �t�s�s��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ saveD = gcnew SaveFileDialog();
				saveD->InitialDirectory = "c:\\";
				saveD->Filter = "Texture File|*.txt"; //�ɮ׭�������
				saveD->Title = "Select a File";       //�������D
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

