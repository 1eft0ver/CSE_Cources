#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
namespace B033040009_5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	struct listnode {
		int data;
		listnode *next;
	};
	typedef struct listnode ListNode;

	int stack_count = 0;
	ListNode *s_top = NULL; //此專案即將使用的Stack 命名為s_top
	//////////////////////////////////////
	
	//判斷stack是否為空
	int stack_empty(ListNode *s){
		return (s == NULL);
	}

	//Push元素入Stack
	ListNode* push_stack(ListNode *s, char i){
		ListNode *current = (ListNode *)malloc(sizeof(ListNode));
		assert(current != NULL);
		current->data = i;
		current->next = s;
		s = current;
		return s;
	}

	//Pop元素自Stack s_top
	int pop_stack(){
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

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			label1->Visible = false;
			label2->Visible = false;
			label3->Visible = false;
			label4->Visible = false;
			label5->Visible = false;
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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(81, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 25);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(81, 68);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(117, 25);
			this->textBox2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(227, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 34);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Push";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(227, 61);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 34);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Pop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(34, 119);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(350, 550);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(144, 585);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(135, 50);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(144, 476);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 50);
			this->label2->TabIndex = 6;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(144, 370);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 50);
			this->label3->TabIndex = 7;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(144, 263);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(135, 50);
			this->label4->TabIndex = 8;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(144, 155);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(135, 50);
			this->label5->TabIndex = 9;
			this->label5->Text = L"label5";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 681);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(textBox1->Text->Length == 0)
				textBox1->Text = "ERROR!";

			 else{
				 if(stack_count >= 5){
				 textBox1->Text = "ERROR!";
				 }

				 else{
				 s_top = push_stack(s_top, Convert::ToInt32(textBox1->Text));
				 ++stack_count;
						switch(stack_count){
							case 1:								
								label1->Text = System::Convert::ToString(s_top->data);
								label1->Visible = true;
								break;

							case 2:
								label2->Text = System::Convert::ToString(s_top->data);
								label2->Visible = true;
								break;

							case 3:
								label3->Text = System::Convert::ToString(s_top->data);
								label3->Visible = true;
								break;

							case 4:
								label4->Text = System::Convert::ToString(s_top->data);
								label4->Visible = true;
								break;

							case 5:
								label5->Text = System::Convert::ToString(s_top->data);
								label5->Visible = true;
								break;
						}
				 } 
			 }
			 
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 
				if(stack_count == 0){
				textBox2->Text = "ERROR!";
				}

				else{
				int pop = pop_stack();
				textBox2->Text = System::Convert::ToString(pop);
				--stack_count;
					switch(stack_count){
						case 0:
							label1->Visible = false;
							break;

						case 1:
							label2->Visible = false;
							break;

						case 2:
							label3->Visible = false;
							break;

						case 3:
							label4->Visible = false;
							break;

						case 4:
							label5->Visible = false;
							break;
					}
				}
			 
		 }
};
}

