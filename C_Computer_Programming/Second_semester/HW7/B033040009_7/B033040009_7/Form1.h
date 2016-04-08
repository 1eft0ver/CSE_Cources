#pragma once
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
namespace B033040009_7 {

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
		std::string name;
		std::string date;
		struct Dnode *next;
		struct Dnode *prev;
	};

	Dnode *head;
	Dnode *rear;
	int count = 0;

	int is_empty(Dnode *dl)
	{
		return (dl == NULL);
	}

	void insert_front(Dnode **head, Dnode **rear , std::string n, std::string d)
	{
		Dnode *temp;
		temp = new Dnode;
		temp -> name = n;
		temp -> date = d;
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

	void insert_back(Dnode **head, Dnode **rear, std::string n, std::string d)
	{
		Dnode *temp;
		temp = new Dnode;
		temp -> name = n;
		temp -> date = d;
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
	
	void system_to_std ( String ^ s, string& os ) 
	{
    using namespace Runtime::InteropServices;
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	
			

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
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Panel^  panel1;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 50);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(174, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(133, 50);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(13, 81);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(179, 50);
			this->button3->TabIndex = 2;
			this->button3->Text = L"InsertFront";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button4->Location = System::Drawing::Point(216, 81);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(179, 50);
			this->button4->TabIndex = 3;
			this->button4->Text = L"InsertBack";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Location = System::Drawing::Point(13, 138);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(317, 373);
			this->panel1->TabIndex = 4;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 523);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Double Linked List";
			this->ResumeLayout(false);

		}
#pragma endregion

void paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		{		
			
				Dnode *current = head;
				
				//執行Panel與Graphics的關聯
				Graphics^ g = e->Graphics;
				Pen^ blackPen = gcnew Pen(Color::Black,3.0f);
				Pen^ blackPen2 = gcnew Pen(Color::Black,1.0f);
				SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("微軟正黑體",14);
				g->Clear(Color::White);
				
				//建立筆色與筆刷
				
				//建立字形
				g->DrawString("head", drawFont, drawBrush, Point(170,55));
				int list_count=0;
				int change_line = 143;
				while(is_empty(current)==0)
				{
				if(count > 1 && list_count +1 != count){
					Point point5 = Point(50,120+change_line*list_count);
					Point point6 = Point(50,165+change_line*list_count);
					Point point7 = Point(47,162+change_line*list_count);
					Point point8 = Point(53,162+change_line*list_count);
					g->DrawLine(blackPen2 ,point5,point6);
					g->DrawLine(blackPen2 ,point6,point7);
					g->DrawLine(blackPen2 ,point6,point8);

					Point point9 = Point(70,120+change_line*list_count);
					Point point10 = Point(70,165+change_line*list_count);
					Point point11 = Point(67,123+change_line*list_count);
					Point point12 = Point(73,123+change_line*list_count);
					g->DrawLine(blackPen2 ,point9,point10);
					g->DrawLine(blackPen2 ,point9,point11);
					g->DrawLine(blackPen2 ,point9,point12);
				}

				String^ temp = gcnew String((current->name).c_str());
				g->DrawString(temp, drawFont, drawBrush, Point(10,45+change_line*list_count));
				temp = gcnew String((current->date).c_str());
				g->DrawString(temp, drawFont, drawBrush, Point(10,65+change_line*list_count));
				g->DrawRectangle(blackPen,2,10+change_line*list_count,120,100);
				g->DrawRectangle(blackPen,2,30+change_line*list_count,120,100);
				
				Point point1 = Point(168,67);
				Point point2 = Point(138,67);
				Point point3 = Point(143,70);
				Point point4 = Point(143,64);
				g->DrawLine(blackPen2 ,point1,point2);
				g->DrawLine(blackPen2 ,point2,point3);
				g->DrawLine(blackPen2 ,point2,point4);
				  current=current->next;
				  list_count++;
				}
				
		 }
			 StreamReader^ sr;
			 PictureBox ^j;
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ openD = gcnew OpenFileDialog();
				 openD->Filter = "Texture File|*.txt"; //檔案限制類型
				 openD->Title = "Select a File";       //視窗標題
				 if(openD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 sr = gcnew StreamReader(openD->FileName);
				 }
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				SaveFileDialog^ saveD = gcnew SaveFileDialog();
				saveD->InitialDirectory = "c:\\";
				saveD->Filter = "Texture File|*.txt"; //檔案限制類型
				saveD->Title = "Select a File";       //視窗標題
				if(saveD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					StreamWriter^ sw = gcnew StreamWriter(saveD->FileName);
					Dnode *current = head;
					while(current != NULL)
					{
						String^ convert = gcnew String ((current->name).c_str());
						sw->WriteLine(convert);
						convert = gcnew String ((current->date).c_str());
						sw->WriteLine(convert);
						sw->WriteLine("\n");
						current = current -> next;
					}
					sw->Close();
				}
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 string command, name, date;
			 if ( sr->Peek() >= 0 )
			 {
				string temp;
				system_to_std(sr->ReadLine(), temp);
				command = temp;
			 }
			 stringstream ss(command);
			 string temp;
			 if(getline(ss,temp,' '))
			 {
					name = temp;
					//String^ convert = gcnew String (name.c_str());
					//listBox1->Items->Add(convert);
			 }
			 ss >> temp;
			 date = temp;

			 insert_front(&head, &rear, name, date);
			 delete j;
			 j=gcnew PictureBox();
			 j->Location=System::Drawing::Point(0,0);
			 j->Size=System::Drawing::Size(285,320+150*count);
			 j->Paint+=gcnew System::Windows::Forms::PaintEventHandler(this,&Form1::paint);
			 this->panel1->Controls->Add(j);
		 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 string command, name, date;
			 if ( sr->Peek() >= 0 )
			 {
				string temp;
				system_to_std(sr->ReadLine(), temp);
				command = temp;
			 }
			 stringstream ss(command);
			 string temp;
			 if(getline(ss,temp,' '))
			 {
					name = temp;
					//String^ convert = gcnew String (name.c_str());
					//listBox1->Items->Add(convert);
			 }
			 ss >> temp;
			 date = temp;

			 insert_back(&head, &rear, name, date);
			 delete j;
			 j=gcnew PictureBox();
			 j->Location=System::Drawing::Point(0,0);
			 j->Size=System::Drawing::Size(285,320+150*count);
			 j->Paint+=gcnew System::Windows::Forms::PaintEventHandler(this,&Form1::paint);
			 this->panel1->Controls->Add(j);
		 }
};
}

