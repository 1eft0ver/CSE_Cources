#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
namespace B033040009_8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	struct Dnode
	{
		int data;
		struct Dnode *next;
		struct Dnode *prev;
	};

	Dnode *head;
	Dnode *rear;
	int count = 0;
	string output = "";

	void system_to_std ( String ^ s, string& os ) 
	{
    using namespace Runtime::InteropServices;
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	string itos(int value)
	{
    std::ostringstream oss;
    oss << value;
    return oss.str();
	}

	int is_empty(Dnode *dl)
	{
		return (dl == NULL);
	}

	void insert_front(Dnode **head, Dnode **rear , int n)
	{
		Dnode *temp;
		temp = new Dnode;
		temp -> data = n;
			if(is_empty( (*head) ) && is_empty( (*rear) ))
			{
				(*head) = temp;
				(*head)-> next = NULL;
				(*head)-> prev = NULL;
				(*rear) = temp;
				(*rear)-> next = NULL;
				(*rear)-> prev = NULL;
			}
			else
			{
				temp -> next = (*head);
				temp -> prev = NULL;
				(*head) -> prev = temp;
				(*head) = temp;
			}
		 ++count;
	}

	void insert_back(Dnode **head, Dnode **rear , int n)
	{
		Dnode *temp;
		temp = new Dnode;
		temp -> data = n;
			if(is_empty( (*head) ) && is_empty( (*rear) ))
			{
				(*head) = temp;
				(*head)-> next = NULL;
				(*head)-> prev = NULL;
				(*rear) = temp;
				(*rear)-> next = NULL;
				(*rear)-> prev = NULL;
			}
			else
			{
				temp -> next = NULL;
				temp -> prev = (*rear);
				(*rear) -> next = temp;
				(*rear) = temp;
			}
		 ++count;
	}

	int delete_data(Dnode **head, Dnode **rear , int n){
		int found = 0;
		if((*head) == NULL || (*rear) == NULL)
			return -1;
		
		else{
			Dnode *current = (*head);
			while(current != NULL){
				if (current->data == n){
					found = 1;
					if(current == (*head)){
						Dnode *temp = (*head);
						(*head) = (*head) -> next;
						(*head) -> prev = NULL;
						delete temp;
						return n;
					}

					else if(current == (*rear)){
						Dnode *temp = (*rear);
						(*rear) = (*rear) -> prev;
						(*rear) -> next = NULL;
						delete temp;
						return n;
					}

					else{
						Dnode *temp = current;
						current = current -> prev;
						current -> next = temp -> next;
						current = temp -> next;
						current -> prev = temp -> prev;
						delete temp;
						return n;
					}
				}
			current = current -> next;
			}

			if(found != 1)
				return -1;
		}
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
	private: System::Windows::Forms::ToolStripMenuItem^  Ū���ɮ�LToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �x�s�ɮ�SToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �u��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �U�@�BNToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �C����CToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �r����FToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

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
			this->Ū���ɮ�LToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�x�s�ɮ�SToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�u��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�C����CToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�r����FToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�U�@�BNToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->�ɮ�ToolStripMenuItem, 
				this->�u��ToolStripMenuItem, this->�U�@�BNToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(694, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �ɮ�ToolStripMenuItem
			// 
			this->�ɮ�ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->Ū���ɮ�LToolStripMenuItem, 
				this->�x�s�ɮ�SToolStripMenuItem});
			this->�ɮ�ToolStripMenuItem->Name = L"�ɮ�ToolStripMenuItem";
			this->�ɮ�ToolStripMenuItem->Size = System::Drawing::Size(69, 23);
			this->�ɮ�ToolStripMenuItem->Text = L"�ɮ�(&F)";
			// 
			// Ū���ɮ�LToolStripMenuItem
			// 
			this->Ū���ɮ�LToolStripMenuItem->Name = L"Ū���ɮ�LToolStripMenuItem";
			this->Ū���ɮ�LToolStripMenuItem->Size = System::Drawing::Size(157, 24);
			this->Ū���ɮ�LToolStripMenuItem->Text = L"Ū���ɮ�(&L)";
			this->Ū���ɮ�LToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::Ū���ɮ�LToolStripMenuItem_Click);
			// 
			// �x�s�ɮ�SToolStripMenuItem
			// 
			this->�x�s�ɮ�SToolStripMenuItem->Enabled = false;
			this->�x�s�ɮ�SToolStripMenuItem->Name = L"�x�s�ɮ�SToolStripMenuItem";
			this->�x�s�ɮ�SToolStripMenuItem->Size = System::Drawing::Size(157, 24);
			this->�x�s�ɮ�SToolStripMenuItem->Text = L"�x�s�ɮ�(&S)";
			this->�x�s�ɮ�SToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�x�s�ɮ�SToolStripMenuItem_Click);
			// 
			// �u��ToolStripMenuItem
			// 
			this->�u��ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�C����CToolStripMenuItem, 
				this->�r����FToolStripMenuItem});
			this->�u��ToolStripMenuItem->Name = L"�u��ToolStripMenuItem";
			this->�u��ToolStripMenuItem->Size = System::Drawing::Size(69, 23);
			this->�u��ToolStripMenuItem->Text = L"�u��(&T)";
			// 
			// �C����CToolStripMenuItem
			// 
			this->�C����CToolStripMenuItem->Enabled = false;
			this->�C����CToolStripMenuItem->Name = L"�C����CToolStripMenuItem";
			this->�C����CToolStripMenuItem->Size = System::Drawing::Size(158, 24);
			this->�C����CToolStripMenuItem->Text = L"�C����(&C)";
			this->�C����CToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�C����CToolStripMenuItem_Click);
			// 
			// �r����FToolStripMenuItem
			// 
			this->�r����FToolStripMenuItem->Enabled = false;
			this->�r����FToolStripMenuItem->Name = L"�r����FToolStripMenuItem";
			this->�r����FToolStripMenuItem->Size = System::Drawing::Size(158, 24);
			this->�r����FToolStripMenuItem->Text = L"�r����(&F)";
			this->�r����FToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�r����FToolStripMenuItem_Click);
			// 
			// �U�@�BNToolStripMenuItem
			// 
			this->�U�@�BNToolStripMenuItem->Enabled = false;
			this->�U�@�BNToolStripMenuItem->Name = L"�U�@�BNToolStripMenuItem";
			this->�U�@�BNToolStripMenuItem->Size = System::Drawing::Size(88, 23);
			this->�U�@�BNToolStripMenuItem->Text = L"�U�@�B(&N)";
			this->�U�@�BNToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�U�@�BNToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"�з���", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(12, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"��e����B�J :";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(212, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(469, 25);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(24, 96);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(657, 365);
			this->textBox2->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 473);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L" ";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		StreamReader^ sr;
	private: System::Void Ū���ɮ�LToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ openD = gcnew OpenFileDialog();
				 openD->Filter = "Texture File|*.txt"; //�ɮ׭�������
				 openD->Title = "Select a File";       //�������D
				 if(openD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 sr = gcnew StreamReader(openD->FileName);
					 �x�s�ɮ�SToolStripMenuItem->Enabled = true;
					 �C����CToolStripMenuItem->Enabled = true;
					 �r����FToolStripMenuItem->Enabled = true;
					 �U�@�BNToolStripMenuItem->Enabled = true;

				 }

			 }
private: System::Void �x�s�ɮ�SToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ saveD = gcnew SaveFileDialog();
				saveD->InitialDirectory = "c:\\";
				saveD->Filter = "Texture File|*.txt"; //�ɮ׭�������
				saveD->Title = "Select a File";       //�������D
				if(saveD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					StreamWriter^ sw = gcnew StreamWriter(saveD->FileName);
					String^ str = gcnew String(output.c_str());
					sw->WriteLine(str);
					sw->Close();
				}
		 }
private: System::Void �C����CToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ColorDialog^ ColorD = gcnew ColorDialog;
			 if(ColorD->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				textBox2->ForeColor = ColorD->Color;
			 }
		 }
private: System::Void �r����FToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 FontDialog^ FontD = gcnew FontDialog;
			 if(FontD->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				textBox2->Font = FontD->Font;
			 }
		 }
private: System::Void �U�@�BNToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 string line, command, num;
			 if ( sr->Peek() >= 0 ){
				string temp;
				system_to_std(sr->ReadLine(), temp);
				line = temp;

				stringstream ss(line);
			 
				if(getline(ss,temp,' '))
					command = temp;
					ss >> temp;
					 num = temp;

				if(command == "delete"){
					//textBox1->Text = "delete";
					int result;
					result = delete_data(&head, &rear , atoi(num.c_str()));
					if(result == -1){
						textBox1->Text = "Not Found";
					}

					else{
						String^ str = gcnew String(num.c_str());
						textBox1->Text = "Delete " + str + "���\";
						textBox2->Clear();
						output = "";
							Dnode *current = head;
							while(current != NULL){
								if(current -> next != NULL){
								output += itos(current->data) + "<->";
								}
								else{
									output += itos(current->data);
								}
								current = current -> next;
							}
							str = gcnew String(output.c_str());
							textBox2->Text = str;
					}
				}

				else if(command == "insertfront"){
					//textBox1->Text = "insertfront";
					insert_front(&head, &rear , atoi(num.c_str()));
					String^ str = gcnew String(num.c_str());
					textBox1->Text = "insert front " + str + "���\";

					if(count == 1){
						output = num;
						String^ str = gcnew String(output.c_str());
						textBox2->Text = str;
					}

					else{
						output = num + "<->" + output;
						String^ str = gcnew String(output.c_str());
						textBox2->Text = str;
					}
				}

				else if(command == "insertback"){
					//textBox1->Text = "insertback";
					insert_back(&head, &rear , atoi(num.c_str()));
					String^ str = gcnew String(num.c_str());
					textBox1->Text = "insert back " + str + "���\";

					if(count == 1){
						output = num;
						String^ str = gcnew String(output.c_str());
						textBox2->Text = str;
					}

					else{
						output = output + "<->" + num;
						String^ str = gcnew String(output.c_str());
						textBox2->Text = str;
					}
				}

				else{
				textBox1->Text = "���O���~";
				}
			 }

			 else{
			 textBox1->Text = "�wŪ���ɮ׵���";
			 }
			 
		 }
};
}

