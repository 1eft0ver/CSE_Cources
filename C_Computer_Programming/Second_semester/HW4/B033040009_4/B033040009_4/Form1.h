#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string>
namespace B033040009_4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	FILE *open = fopen("input4.txt", "r");
	int find_check = 0;//�P�_�O�_�wpop�ܥؼЦr��
	int add_check = 0;//�P�_�O�_�w�[�W�D�Ĥ@���X�{�r��������
	int character[123]; //�����O�_�X�{�L�Y�Ӧr��
	char c; //�{�bŪ�쪺�r��

	//��Ƹ`�I
	struct listnode {
		char data;
		listnode *next;
	};
	typedef struct listnode ListNode;

	ListNode *s_top = NULL; //���M�קY�N�ϥΪ�Stack �R�W��s_top
	ListNode *temp = NULL; //�ΥH�x�spop�X������Stack
	//////////////////////////////////////
	
	//�P�_stack�O�_����
	int stack_empty(ListNode *s){
		return (s == NULL);
	}

	//Push�����JStack
	ListNode* push_stack(ListNode *s, char i){
		ListNode *current = (ListNode *)malloc(sizeof(ListNode));
		assert(current != NULL);
		current->data = i;
		current->next = s;
		s = current;
		return s;
	}

	//Pop������Stack s_top
	char pop_stack(){
		ListNode *current;
		char c;
			if(stack_empty(s_top))
			return -1;
		current = s_top;
		s_top = s_top->next;
		c = current->data;
		free(current);
		return(c);	
	}

	//Pop������Stack temp
	char pop_temp(){
		ListNode *current;
		char c;
			if(stack_empty(temp))
			return -1;
		current = temp;
		temp = temp->next;
		c = current->data;
		free(current);
		return(c);	
	}
				


	////////////////////////////
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
			for(int i = 0 ; i < 123 ; ++i)
				character[i] = 0;
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
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ListBox^  listBox1;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"�L�n������", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(26, 26);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 50);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Read";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"�L�n������", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(208, 26);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(149, 50);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Draw Next";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"�L�n������", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(392, 26);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(149, 50);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Read All";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(595, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"�Ȯ�Pop�X���r��";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(26, 96);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(549, 461);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 15;
			this->listBox1->Location = System::Drawing::Point(600, 96);
			this->listBox1->Name = L"listBox1";
			this->listBox1->ScrollAlwaysVisible = true;
			this->listBox1->Size = System::Drawing::Size(220, 454);
			this->listBox1->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(845, 564);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 while(!feof(open)){
				 
				 Graphics^ g = this->panel1->CreateGraphics();  //�ŧi�e��
				 SolidBrush^ sb_char = gcnew SolidBrush(Color::Blue);  //�ŧi�g�r������
				 Pen^ pen_rec = gcnew Pen(System::Drawing::Color::Black);  //�ŧi�e����Ϊ�����
				 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Calibri",18 );   //�ŧi�r���P�r��j�p


				 
				 fscanf(open,"%c",&c);
				 if(c >= 'A' && c <= 'Z')
					c += 32;

				 
				 if(character[c] == 0 && (c>='a' && c<='z')){
					s_top = push_stack(s_top,c);
					character[c] += 1;
						g->Clear(Color::White); 
						ListNode* current = s_top;
						int count = 0; //�p��ثe��Stack���۳��ݼƨӲĴX�Ӥ���
						while(current != NULL ){

							string str;       //�r�������A�ഫ char to system::string
							str += current->data;
							String^ strNew = gcnew String(str.c_str());	

							g->DrawString( strNew, drawFont,sb_char,13+50*(count%8),13+100*(count/8) );
							g->DrawString( System::Convert::ToString(character[current->data]), drawFont,sb_char,13+50*(count%8),46+100*(count/8) );
							g->DrawRectangle(pen_rec, 3+50*(count%8), 3+100*(count/8), 40, 90);
							current = current -> next;
							++count;
						}
				 }	
				 else if(character[c] > 0){
					button1->Enabled = false;
					button2->Enabled = true;
					button3->Enabled = false;
				 }
				 return;
				 }
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Graphics^ g = this->panel1->CreateGraphics();  //�ŧi�e��
			 SolidBrush^ sb_char = gcnew SolidBrush(Color::Blue);  //�ŧi�g�r������
			 Pen^ pen_rec = gcnew Pen(System::Drawing::Color::Black);  //�ŧi�e����Ϊ�����
			 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Calibri",18 );   //�ŧi�r���P�r��j�p
			 char check;
			 int count = 0; //�p��ثe��Stack���۳��ݼƨӲĴX�Ӥ���
			 if(find_check == 0 && add_check == 0){
				check = pop_stack(); //pop���ݪ������X�ӨýT�{�O�_�����ƪ�����
				if(check != c){
					temp = push_stack(temp, check);
					listBox1->Items->Insert(0,Char::ToString(check) + " " + character[check]);
						ListNode* current = s_top;
					
						g->Clear(Color::White); 
						while(current != NULL){ 
							string str;       //�r�������A�ഫ char to system::string
							str += current->data;
							String^ strNew = gcnew String(str.c_str());		

							g->DrawString( strNew, drawFont,sb_char,13+50*(count%8),13+100*(count/8) );
							g->DrawString( System::Convert::ToString(character[current->data]), drawFont,sb_char,13+50*(count%8),46+100*(count/8) );
							g->DrawRectangle(pen_rec, 3+50*(count%8), 3+100*(count/8), 40, 90);
							current = current -> next;
							++count;
						}
				}
				else {
				s_top = push_stack(s_top,check);
				find_check = 1;
				++character[c];
				add_check = 1;
						g->Clear(Color::White); 
						ListNode* current = s_top;
						while(current != NULL){ 
							string str;       //�r�������A�ഫ char to system::string
							str += current->data;
							String^ strNew = gcnew String(str.c_str());		

							g->DrawString( strNew, drawFont,sb_char,13+50*(count%8),13+100*(count/8) );
							g->DrawString( System::Convert::ToString(character[current->data]), drawFont,sb_char,13+50*(count%8),46+100*(count/8) );
							g->DrawRectangle(pen_rec, 3+50*(count%8), 3+100*(count/8), 40, 90);
							current = current -> next;
							++count;
						}
				}
			 }
			 else{
				char tmp;
				tmp = pop_temp();
				listBox1->Items->RemoveAt(0);
				s_top = push_stack(s_top,tmp);
						g->Clear(Color::White); 
						ListNode* current = s_top;
						int count = 0; //�p��ثe��Stack���۳��ݼƨӲĴX�Ӥ���
						while(current != NULL ){

							string str;       //�r�������A�ഫ char to system::string
							str += current->data;
							String^ strNew = gcnew String(str.c_str());			

							g->DrawString( strNew, drawFont,sb_char,13+50*(count%8),13+100*(count/8) );
							g->DrawString( System::Convert::ToString(character[current->data]), drawFont,sb_char,13+50*(count%8),46+100*(count/8) );
							g->DrawRectangle(pen_rec, 3+50*(count%8), 3+100*(count/8), 40, 90);
							current = current -> next;
							++count;
						}
					if(stack_empty(temp)){
					button1->Enabled = true;
					button2->Enabled = false;
					button3->Enabled = true;
					add_check = 0;
					find_check = 0;
					}

			 }
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 Graphics^ g = this->panel1->CreateGraphics();  //�ŧi�e��
			 SolidBrush^ sb_char = gcnew SolidBrush(Color::Blue);  //�ŧi�g�r������
			 Pen^ pen_rec = gcnew Pen(System::Drawing::Color::Black);  //�ŧi�e����Ϊ�����
			 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Calibri",18 );   //�ŧi�r���P�r��j�p
			 char c;
			 while(fscanf(open,"%c",&c)!=EOF)
				{
					if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')){	
						if(c >= 'A' && c <= 'Z')
						c = c + 32;

						if(character[c] == 0){
							character[c]++;
							s_top = push_stack(s_top,c);
						}

						else
							character[c]++;
						
					}
				}
				g->Clear(Color::White); 
				ListNode* current = s_top;
				int count = 0; //�p��ثe��Stack���۳��ݼƨӲĴX�Ӥ���
					while(current != NULL ){

						string str;       //�r�������A�ഫ char to system::string
						str += current->data;
						String^ strNew = gcnew String(str.c_str());			

						g->DrawString( strNew, drawFont,sb_char,13+50*(count%8),13+100*(count/8) );
						g->DrawString( System::Convert::ToString(character[current->data]), drawFont,sb_char,13+50*(count%8),46+100*(count/8) );
						g->DrawRectangle(pen_rec, 3+50*(count%8), 3+100*(count/8), 40, 90);
						current = current -> next;
						++count;
					}
			 
		 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};
}

