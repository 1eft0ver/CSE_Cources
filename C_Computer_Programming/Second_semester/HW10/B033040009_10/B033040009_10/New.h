#pragma once
#include <string>
#include <stdlib.h>
namespace B033040009_10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// New 的摘要
	/// </summary>\
	
	public ref class New : public System::Windows::Forms::Form
	{
	public:
		New(void)
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
		~New()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::TextBox^  textBox3;
	protected: 

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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label1->Location = System::Drawing::Point(44, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"編號 :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label5->Location = System::Drawing::Point(44, 195);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 20);
			this->label5->TabIndex = 13;
			this->label5->Text = L"E-mail :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label4->Location = System::Drawing::Point(44, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 20);
			this->label4->TabIndex = 12;
			this->label4->Text = L"性別 :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label3->Location = System::Drawing::Point(44, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 20);
			this->label3->TabIndex = 11;
			this->label3->Text = L"姓名 :";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(109, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(152, 25);
			this->textBox1->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(273, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 25);
			this->button1->TabIndex = 15;
			this->button1->Text = L"新增";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &New::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(109, 97);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(152, 25);
			this->textBox2->TabIndex = 16;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->radioButton1->Location = System::Drawing::Point(112, 147);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(66, 24);
			this->radioButton1->TabIndex = 17;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"male";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->radioButton2->Location = System::Drawing::Point(187, 147);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(80, 24);
			this->radioButton2->TabIndex = 18;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"female";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(116, 194);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(259, 25);
			this->textBox3->TabIndex = 19;
			// 
			// New
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(419, 277);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Name = L"New";
			this->Text = L"新增會員";
			this->Load += gcnew System::EventHandler(this, &New::New_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
			String^ nnum;
			String^ nname;
		    bool nsex;
			String^ nmail;
			int check;

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 check = 1;
				 if(textBox1->Text->Length == 0 || textBox2->Text->Length == 0 || textBox3->Text->Length == 0 ){
				 MessageBox::Show("請填入資料!");
				 }
				 else{
				 nnum = textBox1->Text;
				 
				 nname = textBox2->Text;
				 if(radioButton1->Checked)
					nsex = true;
				 else
					nsex = false;
				 nmail = textBox3->Text;
				 
				 Close();
				 }
			 }
			 \
private: System::Void New_Load(System::Object^  sender, System::EventArgs^  e) {
			 check = 0;
			 }
};
}
