#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <cctype>


namespace B033040009_3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	int data[26]={0},n=1,read_all_check=0;  

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
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(77, 34);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Read";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(269, 34);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(144, 53);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Read All";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(56, 104);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(379, 189);
			this->panel1->TabIndex = 2;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 367);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			  FILE *input3;  
			  char input[26],input_char,check_char1='A',check_char2='a';
			  int a=0;

			  Graphics^ g = this->panel1->CreateGraphics(); 
			  SolidBrush^ sb = gcnew SolidBrush(Color::Blue);  
			  System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Calibri",50 );   

			  if( (input3=fopen("input3.txt","r"))!=NULL && read_all_check!=1) 
			    { 
				  for(a=0;a<n;a++)  
					  fscanf(input3,"%c",&input_char);
			      g->Clear(Color::White); 
			      if(input_char!=',' && input_char!='.' && input_char!=' ' && input_char!='\n' && input_char!='“')   
					  {
						if(input_char>='A' && input_char<='Z')  
					      {
						   for(a=0;a<26;a++)   
					          {
							   if(input_char==check_char1)
								  break;
							   else
								  check_char1++;
						      }
					       data[a]++; 
						   String^ drawString = Char::ToString(input_char)+data[a];   
                           g->DrawString( drawString, drawFont,sb,40,10 );   
						   check_char1='A';
						   
					      }
					    else
						 {
						   data[input_char-'a']++;  
						   String^ drawString = Char::ToString(input_char)+data[input_char-'a'];
                           g->DrawString( drawString, drawFont,sb,40,40 );  
						 }  
					   }
			    }
			    n++; 
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			  FILE *input3;  
			  char input[26],input_char,check_char1='A',check_char2='a',tmp;
			  int a=0;
			  for(a=0;a<26;a++)   
				  data[a]=0;

			  Graphics^ g = this->panel1->CreateGraphics();  
			  SolidBrush^ sb = gcnew SolidBrush(Color::Blue);  
			  System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Calibri",50 );   
			  
			  if( (input3=fopen("input3.txt","r"))!=NULL && read_all_check!=1)
			    { 
				   while(!feof(input3)) 
				   {
					   
				      fscanf(input3,"%c",&input_char);
				      g->Clear(Color::White); 
			          if(input_char!=',' && input_char!='.' && input_char!=' ' && input_char!='“')   
					     {
						    if(input_char>='A' && input_char<='Z')   
					         {
						      for(a=0;a<26;a++)  
					            {
							     if(input_char==check_char1)
								    break;
							     else
								    check_char1++;
						        }
					          data[a]++; 
						      check_char1='A';
					         }
					        else
						     {
						      data[input_char-'a']++;  
						     } 
							tmp=tolower(input_char); 

					     }
			       }
				
				    String^ drawString = Char::ToString(tmp)+data[tmp-'a'];
                    g->DrawString( drawString, drawFont,sb,40,40 );  
				    read_all_check=1;  
				  
			  }
			 }
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
	};
}

