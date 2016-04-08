#pragma once

namespace B033040009_10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Find 的摘要
	/// </summary>
	public ref class Find : public System::Windows::Forms::Form
	{
	public:
		Find(void)
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
		~Find()
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox4;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label1->Location = System::Drawing::Point(25, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"編號 :";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(91, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(64, 25);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(191, 48);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(64, 25);
			this->textBox2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label2->Location = System::Drawing::Point(157, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"至";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(276, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 25);
			this->button1->TabIndex = 4;
			this->button1->Text = L"尋找";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Find::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label3->Location = System::Drawing::Point(25, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"姓名 :";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(91, 97);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(164, 25);
			this->textBox3->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label4->Location = System::Drawing::Point(25, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"性別 :";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->checkBox1->Location = System::Drawing::Point(94, 147);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(67, 24);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"male";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->checkBox2->Location = System::Drawing::Point(194, 147);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(81, 24);
			this->checkBox2->TabIndex = 9;
			this->checkBox2->Text = L"female";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label5->Location = System::Drawing::Point(25, 195);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"E-mail :";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(100, 193);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(278, 25);
			this->textBox4->TabIndex = 11;
			// 
			// Find
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(419, 277);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Find";
			this->Text = L"尋找會員";
			this->Load += gcnew System::EventHandler(this, &Find::Find_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
			 int check;
			 int no_lb,no_ub;
			 String^ search_name;
			 bool male_check, female_check;
			 String^ search_mail;
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(textBox1->Text->Length == 0 && textBox2->Text->Length == 0 && textBox3->Text->Length == 0 && textBox4->Text->Length == 0 && checkBox1->Checked == false && checkBox2->Checked == false )
				 MessageBox::Show("請填入資料!");
				 
				 else{
				 check = 1;
					if((textBox1->Text->Length != 0 && textBox2->Text->Length == 0) || (textBox1->Text->Length == 0 && textBox2->Text->Length != 0))
						MessageBox::Show("請填入編號範圍!");
					else if(textBox1->Text->Length != 0 && textBox2->Text->Length != 0){
						no_lb = Convert::ToInt32(textBox1->Text);
						no_ub = Convert::ToInt32(textBox2->Text);
					}
					if(textBox3->Text->Length != 0)
					search_name = textBox3->Text;
					
					if(checkBox1->Checked == true)
					male_check = true;

					if(checkBox2->Checked == true)
					female_check = true;

					if(textBox4->Text->Length != 0)
					search_mail = textBox4->Text;
					

				 }
				 Close();
			 }
private: System::Void Find_Load(System::Object^  sender, System::EventArgs^  e) {
			 check = 0;
			 no_lb = 0; no_ub = 0;
			 search_name = "";
			 search_mail = "";
		 }
};
}
