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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  檔案ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  讀取檔案LToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  儲存檔案SToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  工具ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  下一步NToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  顏色選擇CToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  字體選擇FToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->檔案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->讀取檔案LToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->儲存檔案SToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->工具ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->顏色選擇CToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->字體選擇FToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->下一步NToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->檔案ToolStripMenuItem, 
				this->工具ToolStripMenuItem, this->下一步NToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(694, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 檔案ToolStripMenuItem
			// 
			this->檔案ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->讀取檔案LToolStripMenuItem, 
				this->儲存檔案SToolStripMenuItem});
			this->檔案ToolStripMenuItem->Name = L"檔案ToolStripMenuItem";
			this->檔案ToolStripMenuItem->Size = System::Drawing::Size(69, 23);
			this->檔案ToolStripMenuItem->Text = L"檔案(&F)";
			// 
			// 讀取檔案LToolStripMenuItem
			// 
			this->讀取檔案LToolStripMenuItem->Name = L"讀取檔案LToolStripMenuItem";
			this->讀取檔案LToolStripMenuItem->Size = System::Drawing::Size(157, 24);
			this->讀取檔案LToolStripMenuItem->Text = L"讀取檔案(&L)";
			this->讀取檔案LToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::讀取檔案LToolStripMenuItem_Click);
			// 
			// 儲存檔案SToolStripMenuItem
			// 
			this->儲存檔案SToolStripMenuItem->Enabled = false;
			this->儲存檔案SToolStripMenuItem->Name = L"儲存檔案SToolStripMenuItem";
			this->儲存檔案SToolStripMenuItem->Size = System::Drawing::Size(157, 24);
			this->儲存檔案SToolStripMenuItem->Text = L"儲存檔案(&S)";
			this->儲存檔案SToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::儲存檔案SToolStripMenuItem_Click);
			// 
			// 工具ToolStripMenuItem
			// 
			this->工具ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->顏色選擇CToolStripMenuItem, 
				this->字體選擇FToolStripMenuItem});
			this->工具ToolStripMenuItem->Name = L"工具ToolStripMenuItem";
			this->工具ToolStripMenuItem->Size = System::Drawing::Size(69, 23);
			this->工具ToolStripMenuItem->Text = L"工具(&T)";
			// 
			// 顏色選擇CToolStripMenuItem
			// 
			this->顏色選擇CToolStripMenuItem->Enabled = false;
			this->顏色選擇CToolStripMenuItem->Name = L"顏色選擇CToolStripMenuItem";
			this->顏色選擇CToolStripMenuItem->Size = System::Drawing::Size(158, 24);
			this->顏色選擇CToolStripMenuItem->Text = L"顏色選擇(&C)";
			this->顏色選擇CToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::顏色選擇CToolStripMenuItem_Click);
			// 
			// 字體選擇FToolStripMenuItem
			// 
			this->字體選擇FToolStripMenuItem->Enabled = false;
			this->字體選擇FToolStripMenuItem->Name = L"字體選擇FToolStripMenuItem";
			this->字體選擇FToolStripMenuItem->Size = System::Drawing::Size(158, 24);
			this->字體選擇FToolStripMenuItem->Text = L"字體選擇(&F)";
			this->字體選擇FToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::字體選擇FToolStripMenuItem_Click);
			// 
			// 下一步NToolStripMenuItem
			// 
			this->下一步NToolStripMenuItem->Enabled = false;
			this->下一步NToolStripMenuItem->Name = L"下一步NToolStripMenuItem";
			this->下一步NToolStripMenuItem->Size = System::Drawing::Size(88, 23);
			this->下一步NToolStripMenuItem->Text = L"下一步(&N)";
			this->下一步NToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::下一步NToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"標楷體", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(12, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"當前執行步驟 :";
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
	private: System::Void 讀取檔案LToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ openD = gcnew OpenFileDialog();
				 openD->Filter = "Texture File|*.txt"; //檔案限制類型
				 openD->Title = "Select a File";       //視窗標題
				 if(openD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 sr = gcnew StreamReader(openD->FileName);
					 儲存檔案SToolStripMenuItem->Enabled = true;
					 顏色選擇CToolStripMenuItem->Enabled = true;
					 字體選擇FToolStripMenuItem->Enabled = true;
					 下一步NToolStripMenuItem->Enabled = true;

				 }

			 }
private: System::Void 儲存檔案SToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ saveD = gcnew SaveFileDialog();
				saveD->InitialDirectory = "c:\\";
				saveD->Filter = "Texture File|*.txt"; //檔案限制類型
				saveD->Title = "Select a File";       //視窗標題
				if(saveD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					StreamWriter^ sw = gcnew StreamWriter(saveD->FileName);
					String^ str = gcnew String(output.c_str());
					sw->WriteLine(str);
					sw->Close();
				}
		 }
private: System::Void 顏色選擇CToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ColorDialog^ ColorD = gcnew ColorDialog;
			 if(ColorD->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				textBox2->ForeColor = ColorD->Color;
			 }
		 }
private: System::Void 字體選擇FToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 FontDialog^ FontD = gcnew FontDialog;
			 if(FontD->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				textBox2->Font = FontD->Font;
			 }
		 }
private: System::Void 下一步NToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
						textBox1->Text = "Delete " + str + "成功";
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
					textBox1->Text = "insert front " + str + "成功";

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
					textBox1->Text = "insert back " + str + "成功";

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
				textBox1->Text = "指令錯誤";
				}
			 }

			 else{
			 textBox1->Text = "已讀至檔案結尾";
			 }
			 
		 }
};
}

