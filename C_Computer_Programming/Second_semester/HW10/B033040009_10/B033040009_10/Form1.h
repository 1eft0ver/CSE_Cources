#pragma once
#include "Find.h";
#include "New.h";
#include "Dinfo.h";
#include "Modify.h";
#include <string.h>
#include <stdio.h>
#include <vector>
namespace B033040009_10 {

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

	void insert_front(Dinfo **head, Dinfo **rear , int num, string nam, bool sex, string mail)
	{
		Dinfo *temp;
		temp = new Dinfo;
		temp->number = num;
		temp->name = nam;
		temp->sex = sex;
		temp->mail = mail;
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

	void insert_back(Dinfo **head, Dinfo **rear , int num, string nam, bool sex, string mail)
	{
		Dinfo *temp;
		temp = new Dinfo;
		temp->number = num;
		temp->name = nam;
		temp->sex = sex;
		temp->mail = mail;
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
			this->�x�s����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�t�s�s��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�\��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�s�W�|��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�M��|��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�ɮ�ToolStripMenuItem, 
				this->�\��ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(901, 27);
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
			this->�s�W�|��ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->�s�W�|��ToolStripMenuItem->Text = L"�s�W�|��";
			this->�s�W�|��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�s�W�|��ToolStripMenuItem_Click);
			// 
			// �M��|��ToolStripMenuItem
			// 
			this->�M��|��ToolStripMenuItem->Name = L"�M��|��ToolStripMenuItem";
			this->�M��|��ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->�M��|��ToolStripMenuItem->Text = L"�M��|��";
			this->�M��|��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�M��|��ToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(901, 571);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"�|���C��";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		static ComboBox ^combo=gcnew ComboBox();
		static DataGridView ^ Data=gcnew DataGridView();
		static int membersum=0,row=0;
		String^ filename;
		/*static array<String^>^ number=gcnew array<String^>(50);
		static array<String^>^ name=gcnew array<String^>(50);
		static array<String^>^ gender=gcnew array<String^>(50);
		static array<String^>^ e_mail=gcnew array<String^>(50);
		*/

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 //Label1
				 Label^ lab = gcnew Label();
				 lab->AutoSize = true;
				 lab->Font = (gcnew System::Drawing::Font(L"�s�ө���", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
				 lab->Location = System::Drawing::Point(450, 40);
				 lab->Size = System::Drawing::Size(53, 19);
				 lab->Text = L"�Ƨ�";
				 Controls->Add(lab);

				 //ComboBox
				 combo->FormattingEnabled = true;
				 combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"�|���s��", L"�ʧO"});
				 combo->Location = System::Drawing::Point(500, 40);
				 combo->Name = L"comboBox1";
				 combo->Size = System::Drawing::Size(121, 20);
				 combo-> SelectedValueChanged  += gcnew System::EventHandler(this, &Form1::item_SelectionChange);
				 Controls->Add(combo);

				 //DataGrid
				 Data->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
				 Data->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 Data->Location = System::Drawing::Point(12, 70);
				 Data->Name = L"dataGridView1";
				 Data->RowTemplate->Height = 24;
				 Data->Size = System::Drawing::Size(645, 408);
				 Data->Columns->Add("number","�s��");
				 Data->Columns->Add("name","�m�W");
				 Data->Columns->Add("gender","�ʧO");
				 Data->Columns->Add("E_mail","E-mail");
				 Data-> CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::member_CellContentClick);
				 DataGridViewButtonColumn ^ modify = gcnew DataGridViewButtonColumn();
				 DataGridViewButtonColumn ^ deleterow = gcnew DataGridViewButtonColumn();
				 modify -> Name = "Modify";
				 modify -> Text = "Modify";
				 modify -> UseColumnTextForButtonValue = true;
				 deleterow -> Name = "Deleterow";
				 deleterow -> Text = "Delete";
				 deleterow ->  UseColumnTextForButtonValue = true;
				 Data -> Columns ->Add(modify);
				 Data -> Columns ->Add(deleterow);
				 Controls->Add(Data);	
			 }
private: System::Void �}������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			  head = NULL;
			  rear = NULL;
			  membersum=0;
			  row=0;
			  Data->Rows->Clear();
			  String ^ line;
				 StreamReader^ sr;
				 OpenFileDialog^ open=gcnew OpenFileDialog();
				 open->Filter="Texture |*.txt";
				 open->Title="����ɮ�";
				 if(open->ShowDialog()==System::Windows::Forms::DialogResult::OK){
					 sr=gcnew StreamReader(open->FileName);
					 filename = open->FileName;
					 while(3){
						 if(sr->EndOfStream){
							 break;
						 }
						 line = sr -> ReadLine();
						 String^ seperator = " ";
						 array<Char>^ sep = seperator -> ToCharArray();
						 array<String^>^ split = line -> Split(sep);
						 int number = Convert::ToInt32(split[0]);
						 string name;
						 MarshalString ( split[1], name );
						 bool sex;	
						 if (split[2] == "male")
								sex = true;
						 else
								sex = false;
						 string mail;
						 MarshalString ( split[3], mail );

						 insert_back(&head, &rear , number, name, sex, mail);
						 /*
						 number[membersum]=split[0];
						 name[membersum]=split[1];
						 gender[membersum]=split[2];
						 e_mail[membersum]=split[3];
						 */
						 Data->Rows->Add(split[0],split[1],split[2],split[3]);
						 membersum++;
						 row++;
					 }
				 }
				 sr->Close();
		 }
private: System::Void �s�W�|��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 New^ newmem = gcnew New;
			 newmem->ShowDialog();
			 if(newmem->check==1){
			 string nname;
			 string nmail;
			 int nnum;
			 String^ nsex;
			 const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(newmem->nname)).ToPointer();
			 nname = chars;
			 chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(newmem->nmail)).ToPointer();
			 nnum = Convert::ToInt32(newmem->nnum);
			 nmail = chars;
			 if(newmem->nsex == true)
				 nsex = "male";
			 else
				 nsex = "female";
			 insert_back(&head, &rear , nnum, nname, newmem->nsex, nmail);
			 Data->Rows->Add(newmem->nnum, newmem->nname, nsex, newmem->nmail);
			 membersum++;
			 row++;
			 }
		 }
private: System::Void �M��|��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 /* findmem->
			 int check;
			 int no_lb,no_ub;
			 String^ search_name;
			 bool male_check, female_check;
			 String^ search_mail;
			 */
			 
			 Find^ findmem = gcnew Find;
			 findmem->ShowDialog();
			 vector<bool> search;
			 search.resize(membersum);
			 for(int j = 0 ; j < membersum ; ++j)
				 search[j] = true;
			 if(findmem->check == 1){
				 
				 if(findmem->no_lb != 0 && findmem->no_ub != 0){
					Dinfo *current = head;
					int counter = 0;
					while(current!=NULL){
						if(current->number >= findmem->no_lb && current->number <= findmem->no_ub){
						counter++;
						current = current->getnext();
						}

						else{
						search[counter] = false;
						counter++;
						current = current->getnext();
						}
					}
				 }

				 if(findmem->search_name != ""){
					 Dinfo *current = head;
					 int counter = 0;
					 while(current!=NULL){
						
						if(search[counter] == true){
						const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(findmem->search_name)).ToPointer();
						string convert = chars; 
						if(current->name.find(convert) == -1)
							search[counter] = false;
						counter++;
						current = current->getnext();
						}

						else{
						counter++;
						current = current->getnext();
						}
					 }
				 }

				 if(findmem->male_check == true && findmem->female_check == true){
				 }
				 else if(findmem->male_check == true){
					 Dinfo *current = head;
					 int counter = 0;
					 while(current!=NULL){
						
						if(search[counter] == true){
							if(current->sex == false)
							search[counter] = false;
						counter++;
						current = current->getnext();
						}

						else{
						counter++;
						current = current->getnext();
						}
					 }
				 }
				 else if(findmem->female_check == true){
					Dinfo *current = head;
					 int counter = 0;
					 while(current!=NULL){
						
						if(search[counter] == true){
							if(current->sex == true)
							search[counter] = false;
						counter++;
						current = current->getnext();
						}

						else{
						counter++;
						current = current->getnext();
						}
					 }
				 }

				 if(findmem->search_mail != ""){
					 Dinfo *current = head;
					 int counter = 0;
					 while(current!=NULL){
						
						if(search[counter] == true){
						const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(findmem->search_mail)).ToPointer();
						string convert = chars; 
						if(current->mail.find(convert) == -1)
							search[counter] = false;
						counter++;
						current = current->getnext();
						}

						else{
						counter++;
						current = current->getnext();
						}
					 }
				 }

				 Dinfo *current = head;
				 int counter = 0;
				 Data-> Rows->Clear();
				 while(current != NULL){
					 if(search[counter] == true){
					 String^ name = gcnew String((current->name).c_str());
					 String^ mail = gcnew String((current->mail).c_str());
					 String^ sex;
					 if(current->sex == 1)
						 sex = "male";
					 else
						 sex = "female";
					 Data->Rows->Add(Convert::ToString(current->number), name, sex, mail);
					 }
				 counter++;
				 current = current->getnext();
				 }
			 }
		 }
private: System::Void item_SelectionChange(System::Object^  sender, System::EventArgs^  e) {
				 if(combo -> SelectedItem == "�|���s��")
					 this->Data->Sort(this->Data->Columns[0],ListSortDirection::Ascending);
				 else if(combo -> SelectedItem == "�ʧO")
					 this->Data->Sort(this->Data->Columns[2],ListSortDirection::Ascending);
		 }
private: System::Void member_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e){
			 
			 int i = e->RowIndex;
			 if(e->ColumnIndex==5){
						 Data->Rows->RemoveAt(i);
						 row--;
						 Dinfo *current = head;
						 for(int j = 0 ; j < i ; ++j)
							 current = current->getnext();
						 remove(&head, &rear, &current);
						 membersum--;
			 }
			 else{
				 Modify^ modify = gcnew Modify;
				 modify->ShowDialog();
				 if(modify->check==1){
				 int mnum;
				 string mname;
				 String^ msex;
				 string mmail;
				 
				 mnum = Convert::ToInt32(modify->mnum);
				 const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(modify->mname)).ToPointer();
				 mname = chars;
				 chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(modify->mmail)).ToPointer();
				 mmail = chars;
				 if(modify->msex==true)
					 msex = "male";
				 else
					 msex = "female";
				 Dinfo *current = head;
				 for(int j = 0 ; j < i ; ++j)
					 current = current->getnext();
				 current->number = mnum;
				 current->name = mname;
				 current->sex = modify->msex;
				 current->mail = mmail;
				 Data->Rows->RemoveAt(i);
				 Data->Rows->Insert(i,modify->mnum, modify->mname, msex,modify->mmail);
				 }
			 }
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
					String^ name_out = gcnew String((current->name).c_str());
					String^ mail_out = gcnew String((current->mail).c_str());
					String^ gender;
					if(current -> sex == true)
						gender = "male";
					else
						gender = "female";
					String^ output = gcnew String(Convert::ToString(current->number) + " " + name_out + " " + gender + " " + mail_out+"\n");
					sw->WriteLine(output);
					current = current->getnext();
					}

					sw->Close();
				}
		 }
private: System::Void �x�s����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			

					StreamWriter^ sw = gcnew StreamWriter(filename,false);
					Dinfo *current = head;
					while(current != NULL){
					String^ name_out = gcnew String((current->name).c_str());
					String^ mail_out = gcnew String((current->mail).c_str());
					String^ gender;
					if(current -> sex == true)
						gender = "male";
					else
						gender = "female";
					String^ output = gcnew String(Convert::ToString(current->number) + " " + name_out + " " + gender + " " + mail_out);
					sw->WriteLine(output);
					current = current->getnext();
					}

					sw->Close();
				
		 }
		 
};
}

