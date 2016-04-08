#pragma once
#include<stdio.h>
#include<stdlib.h>
namespace B033040009_6 {

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
	int count=0;
	struct listnode {
		int data;
		listnode *next;
	};
	typedef struct listnode ListNode;

	
	ListNode *q_head = NULL;
	ListNode *q_rear = NULL;
	//////////////////////////////////////

	int queue_empty(ListNode *q){
		return (q == NULL);
	}

	void enqueue(ListNode **q_head, ListNode **q_rear, int i){
		ListNode *temp = new ListNode;
		temp->data = i;
		temp->next = NULL;
		
		if(*q_head == NULL){
		(*q_head) = temp;
		(*q_rear) = temp;
		}

		else{
		(*q_rear)->next = temp;
		(*q_rear) = temp;
		}
		++count;
	}
	/*
	int dequeue(ListNode **q_head, ListNode **q_rear){
		if((*q_head) == NULL)
		return -1;
		
		else{
			if((*q_head)==(*q_rear)){
			return (*q_head)->data;                            <====== 這個有錯 窩也不知道為什麼 幹
			(*q_head) = NULL;
			(*q_rear) = NULL;
			}

			else{
			ListNode *temp = (*q_head);
			(*q_head) = (*q_head) -> next;
			return temp->data;
			free (temp);
			}
		}
	}
	*/
	int dequeue(ListNode **q_head, ListNode **q_rear){
		if((*q_head) == NULL)
		return -1;
		
		else{
			ListNode *temp = (*q_head);
			(*q_head) = (*q_head) -> next;
			return temp->data;
			free (temp);
			
			if((*q_head) == NULL)
			(*q_rear) = NULL;

			--count;
		}
		
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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(79, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(139, 25);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(247, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 25);
			this->button1->TabIndex = 1;
			this->button1->Text = L"enqueue";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(247, 54);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 25);
			this->button2->TabIndex = 3;
			this->button2->Text = L"dequeue";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(79, 54);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(139, 25);
			this->textBox2->TabIndex = 2;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Location = System::Drawing::Point(127, 94);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(187, 467);
			this->panel1->TabIndex = 4;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(437, 573);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		{
		
	            
				ListNode *current = q_head;
				
				//執行Panel與Graphics的關聯
				Graphics^ g = e->Graphics;
				Pen^ blackPen = gcnew Pen(Color::Black,3.0f);
				Pen^ blackPen2 = gcnew Pen(Color::Black,5.0f);
				SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("微軟正黑體",25);
				g->Clear(Color::White);
				
				//建立筆色與筆刷
				
				//建立字形
				g->DrawString("Front", drawFont, drawBrush, Point(16,20));
				int queue_count=0;
				int change_line = 143;
				while(queue_empty(current)==0)
				{
				
				g->DrawString(Convert::ToString(current->data), drawFont, drawBrush, Point(38,140+change_line*queue_count));
				g->DrawRectangle(blackPen,2,120+change_line*queue_count,120,100);
				g->DrawRectangle(blackPen,2,200+change_line*queue_count,120,20);

				  Point point1 = Point(59,65+change_line*queue_count);
				  Point point2 = Point(61,65+change_line*queue_count);
				  Point point3 = Point(61,110+change_line*queue_count);
				  Point point4 = Point(62,110+change_line*queue_count);
				  Point point5 = Point(60,111+change_line*queue_count);
				  Point point6 = Point(58,110+change_line*queue_count);
				  Point point7 = Point(59,110+change_line*queue_count);
				  array<Point>^ curvePoints = {point1,point2,point3,point4,point5,point6,point7};
				  g->DrawPolygon( blackPen2, curvePoints );
				  current=current->next;
				  queue_count++;
				}
				if(queue_count!=0)
				{
				  Point point1 = Point(60,83+change_line*queue_count);
				  Point point2 = Point(62,84+change_line*queue_count);
				  Point point3 = Point(61,84+change_line*queue_count);
				  Point point4 = Point(61,129+change_line*queue_count);
				  Point point5 = Point(59,129+change_line*queue_count);
				  Point point6 = Point(59,84+change_line*queue_count);
				  Point point7 = Point(58,84+change_line*queue_count);
				  array<Point>^ curvePoint3 = {point1,point2,point3,point4,point5,point6,point7};
				  g->DrawPolygon( blackPen2, curvePoint3 );
				  g->DrawString("Rear", drawFont, drawBrush, Point(18,120+change_line*queue_count));
				}  
			}
			PictureBox ^j;

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 /* 使用ListBox確認Queue正常執行
				 int val = Convert::ToInt32(textBox1->Text);
				 enqueue(&q_head, &q_rear, val);
				 ListNode *current = q_head;
				 while(current != NULL){
					listBox1->Items->Add(Convert::ToString(current->data));
					current = current -> next;
				 }
				 listBox1->Items->Add(" ");
				 */
				 if(textBox1->Text->Length == 0){
				 textBox1->Text = "ERROR!";
				 }
				 else{
					int val = Convert::ToInt32(textBox1->Text);
					enqueue(&q_head, &q_rear, val);
					delete j;
					j=gcnew PictureBox();
					j->Location=System::Drawing::Point(0,0);
					j->Size=System::Drawing::Size(285,320+150*count);
					j->Paint+=gcnew System::Windows::Forms::PaintEventHandler(this,&Form1::paint);
					this->panel1->Controls->Add(j);
				 }
			 } 
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 /* 使用ListBox確認Queue正常執行
				 int de = dequeue(&q_head,&q_rear);
				 ListNode *current = q_head;
				 while(current != NULL){
					listBox1->Items->Add(Convert::ToString(current->data));
					current = current -> next;
				 }
				 listBox1->Items->Add(" ");
				 */
				 if(queue_empty(q_head) != 0)
				 textBox2->Text = "ERROR!";
				 
				 else{
					 int val = dequeue(&q_head,&q_rear);
					 textBox2->Text = Convert::ToString(val);
					 delete j;
					 j=gcnew PictureBox();
					 j->Location=System::Drawing::Point(0,0);
					 j->Size=System::Drawing::Size(285,320+150*count);
					 j->Paint+=gcnew System::Windows::Forms::PaintEventHandler(this,&Form1::paint);
					 this->panel1->Controls->Add(j);
				 }
			 }
};
}

