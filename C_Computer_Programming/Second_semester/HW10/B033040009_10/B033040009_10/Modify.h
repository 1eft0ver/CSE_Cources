#pragma once

namespace B033040009_10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Modify 的摘要
	/// </summary>
	public ref class Modify : public System::Windows::Forms::Form
	{
	public:
		/*
		Modify()
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}*/
		Modify(void)
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
		~Modify()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox3;
	protected: 
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label1;

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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(116, 196);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(259, 25);
			this->textBox3->TabIndex = 29;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->radioButton2->Location = System::Drawing::Point(187, 149);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(80, 24);
			this->radioButton2->TabIndex = 28;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"female";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->radioButton1->Location = System::Drawing::Point(112, 149);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(66, 24);
			this->radioButton1->TabIndex = 27;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"male";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(109, 99);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(152, 25);
			this->textBox2->TabIndex = 26;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(273, 55);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 25);
			this->button1->TabIndex = 25;
			this->button1->Text = L"修改";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Modify::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(109, 55);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(152, 25);
			this->textBox1->TabIndex = 24;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label5->Location = System::Drawing::Point(44, 197);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 20);
			this->label5->TabIndex = 23;
			this->label5->Text = L"E-mail :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label4->Location = System::Drawing::Point(44, 149);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 20);
			this->label4->TabIndex = 22;
			this->label4->Text = L"性別 :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label3->Location = System::Drawing::Point(44, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 20);
			this->label3->TabIndex = 21;
			this->label3->Text = L"姓名 :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label1->Location = System::Drawing::Point(44, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 20);
			this->label1->TabIndex = 20;
			this->label1->Text = L"編號 :";
			// 
			// Modify
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
			this->Name = L"Modify";
			this->Text = L"修改";
			this->Load += gcnew System::EventHandler(this, &Modify::Modify_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
			String^ mnum;
			String^ mname;
		    bool msex;
			String^ mmail;
			int check;
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(textBox1->Text->Length == 0 || textBox2->Text->Length == 0 || textBox3->Text->Length == 0 ){
				 MessageBox::Show("請填入資料!");
				 }

				 else{
				 check = 1;
				 mnum = textBox1->Text;
				 
				 mname = textBox2->Text;
				 if(radioButton1->Checked)
					msex = true;
				 else
					msex = false;
				 mmail = textBox3->Text;
				 
				 Close();
				 }
			 }
private: System::Void Modify_Load(System::Object^  sender, System::EventArgs^  e) {
			 check = 0;
		 }
};
}
