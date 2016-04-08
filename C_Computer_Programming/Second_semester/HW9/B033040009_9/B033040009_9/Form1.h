#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "CreateTree.h";
#include "ToPost.h";
#include <cstring>
#include <msclr\marshal_cppstd.h>
namespace B033040009_9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
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
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(15, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Pre-Order :";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->textBox1->Location = System::Drawing::Point(113, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(609, 25);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->textBox2->Location = System::Drawing::Point(113, 57);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(609, 25);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(8, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Post-Order :";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(113, 88);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(462, 25);
			this->textBox3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(15, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"In-Order :";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(582, 88);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 25);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Create Binary Tree";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(752, 589);
			this->panel1->TabIndex = 7;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 542);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int q;
	
	void paint_tree(Node *root,int x,int y,int use)
	{
		
		Label ^lable=gcnew System::Windows::Forms::Label();
		lable->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 15.00F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
		lable->Size = System::Drawing::Size(25, 25);
		if(q ==0)
			lable->Location = System::Drawing::Point(x, y);
		else
			lable->Location = System::Drawing::Point(x, y);
		lable->BorderStyle = BorderStyle::FixedSingle;
		lable->Text=Char::ToString(root->data);
		panel1->Controls->Add(lable);
		if(root->left!=NULL)
		{
			if(q ==0)
				paint_tree(root->left,x-use-20,y+use,use-10);
			else
				paint_tree(root->left,x-use+20,y+use,use-10);
			Label ^l=gcnew Label();
			
			l->AutoSize=true;
			if(q ==0)
				l->Location = System::Drawing::Point(x-use/2, y+use/2);
			else
				l->Location = System::Drawing::Point(x-use/2, y+use/2);
			l->Text="↙";
			panel1->Controls->Add(l);
		}
		if(root->right!=NULL)
		{
			
				paint_tree(root->right,x+use,y+use,use-20);
			
			Label ^r=gcnew Label();
			
			r->AutoSize=true;
			if(q==0)
				r->Location = System::Drawing::Point(x+use/2, y+use/2); 
			else
				r->Location = System::Drawing::Point(x+use/2, y+use/2); 
			r->Text="↘";
			panel1->Controls->Add(r);
			q = 1;
		}
	}

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 panel1->Controls->Clear();
		      q=0;
			 Node *root = nullptr;
			 toPost topost1;
			 string infix;
			 string postfix;
			 string prefix;
			 msclr::interop::marshal_context ^cvt=gcnew msclr::interop::marshal_context();
			 infix = cvt->marshal_as<std::string>(textBox3->Text);
			 topost1.Change(infix);
			 postfix = topost1.getPost();
			 textBox2->Text = gcnew String(postfix.c_str());

			 toTree totree1;
			 root = totree1.maketree(postfix);
			 totree1.PreOrder(root);
			 prefix = totree1.getPrefix();
			 textBox1->Text = gcnew String(prefix.c_str());
			 
			 paint_tree(root,350,130,postfix.size()*8);

		 }
};
}
