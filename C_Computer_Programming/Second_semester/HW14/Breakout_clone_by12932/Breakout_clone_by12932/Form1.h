#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "All.h";
#include "lose.h";
#include <windows.h>
#define PI 3.14159265
namespace Breakout_clone_by12932 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	int stage_complete[6] = {0,105,195,333,555,741};
	int stage_now;
	int force_change;
	int Lx,Ly;
	int broken_brick=0;
	int life;
	struct game1{
		Point p;
		struct game1  *next,*prev;
		int color;
	};
	game1 *head=NULL;
	game1 *tail=NULL;
	void push(Point p,int color)
	{
		game1* coordinate = new game1;
		coordinate->p.X=p.X;
		coordinate->p.Y=p.Y;
		coordinate->color=color;
		coordinate->next=NULL;
		coordinate->prev=NULL;
		if(head==tail && tail==NULL)
		{
			head=coordinate;
			tail=coordinate;
		}
		else
		{
			tail->next=coordinate;
			coordinate->prev=tail;
			tail=coordinate;
		}
	}


	
	void del(game1 *cur)	//cur為球所撞到的磚塊
	{
		if(cur->color==0)	//1撞到之後變為0所以要delete
		{
			game1 *tmp;
			tmp = head;
			while(cur->p.X!=tmp->p.X && cur->p.Y!=cur->p.Y)	//如果磚塊的座標和link的座標一樣就delete
			{
				tmp=tmp->next;
			}
			if(head == tail && tail == NULL)	//link是空的
			{
				//什麼都不做
			}
			else if(head == tail && tail != NULL)	//link內只有一筆資料
			{
				head = NULL;
				tail = NULL;
				free(tmp);
			}
			else if(tmp == head)	//delete頭
			{
				head->next->prev = NULL;
				head = head->next;
				free(tmp);
			}
			else if(tmp == tail)	//delete尾
			{
				tail->prev->next = NULL;
				tail = tail->prev;
				free(tmp);
			}
			else	//一般的delete
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				free(tmp);
			}
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

	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;


	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  關卡ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  關卡一ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  關卡二ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  關卡三ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  關卡四ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  關卡五ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  即將通關ToolStripMenuItem;


	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->關卡ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->關卡一ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->關卡二ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->關卡三ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->關卡四ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->關卡五ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->即將通關ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 15));
			this->groupBox1->Location = System::Drawing::Point(970, 40);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(191, 625);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"資訊";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 486);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(143, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"剩餘生命 : 3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label2->Location = System::Drawing::Point(20, 109);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"最高分 : ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label1->Location = System::Drawing::Point(20, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"分數 : ";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(55, 552);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 31);
			this->button1->TabIndex = 2;
			this->button1->Text = L"重設";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->Location = System::Drawing::Point(42, 38);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(887, 625);
			this->panel1->TabIndex = 3;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseMove);
			// 
			// timer1
			// 
			this->timer1->Interval = 5;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &Form1::timer3_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->關卡ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1182, 27);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 關卡ToolStripMenuItem
			// 
			this->關卡ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->關卡一ToolStripMenuItem, 
				this->關卡二ToolStripMenuItem, this->關卡三ToolStripMenuItem, this->關卡四ToolStripMenuItem, this->關卡五ToolStripMenuItem, this->即將通關ToolStripMenuItem});
			this->關卡ToolStripMenuItem->Name = L"關卡ToolStripMenuItem";
			this->關卡ToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->關卡ToolStripMenuItem->Text = L"關卡";
			// 
			// 關卡一ToolStripMenuItem
			// 
			this->關卡一ToolStripMenuItem->Name = L"關卡一ToolStripMenuItem";
			this->關卡一ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->關卡一ToolStripMenuItem->Text = L"關卡一";
			this->關卡一ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::關卡一ToolStripMenuItem_Click);
			// 
			// 關卡二ToolStripMenuItem
			// 
			this->關卡二ToolStripMenuItem->Name = L"關卡二ToolStripMenuItem";
			this->關卡二ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->關卡二ToolStripMenuItem->Text = L"關卡二";
			this->關卡二ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::關卡二ToolStripMenuItem_Click);
			// 
			// 關卡三ToolStripMenuItem
			// 
			this->關卡三ToolStripMenuItem->Name = L"關卡三ToolStripMenuItem";
			this->關卡三ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->關卡三ToolStripMenuItem->Text = L"關卡三";
			this->關卡三ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::關卡三ToolStripMenuItem_Click);
			// 
			// 關卡四ToolStripMenuItem
			// 
			this->關卡四ToolStripMenuItem->Name = L"關卡四ToolStripMenuItem";
			this->關卡四ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->關卡四ToolStripMenuItem->Text = L"關卡四";
			this->關卡四ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::關卡四ToolStripMenuItem_Click);
			// 
			// 關卡五ToolStripMenuItem
			// 
			this->關卡五ToolStripMenuItem->Name = L"關卡五ToolStripMenuItem";
			this->關卡五ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->關卡五ToolStripMenuItem->Text = L"關卡五";
			this->關卡五ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::關卡五ToolStripMenuItem_Click);
			// 
			// 即將通關ToolStripMenuItem
			// 
			this->即將通關ToolStripMenuItem->Name = L"即將通關ToolStripMenuItem";
			this->即將通關ToolStripMenuItem->Size = System::Drawing::Size(152, 24);
			this->即將通關ToolStripMenuItem->Text = L"即將通關";
			this->即將通關ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::即將通關ToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1182, 703);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"嗚嗚嗚我的肝";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		array<PictureBox^>^ picturebox;
		static int start , ball_shoot, ball_angle, bar_ini_pos_X, bar_ini_pos_Y, ball_ini_pos_X, ball_ini_pos_Y;

		static SoundPlayer^ backgroundmusic1=gcnew SoundPlayer();
		static SoundPlayer^ backgroundmusic2=gcnew SoundPlayer();
		static SoundPlayer^ backgroundmusic3=gcnew SoundPlayer();
		static SoundPlayer^ backgroundmusic4=gcnew SoundPlayer();
		static SoundPlayer^ backgroundmusic5=gcnew SoundPlayer();
		static SoundPlayer^ victory=gcnew SoundPlayer();
		static SoundPlayer^ defeat=gcnew SoundPlayer();
		static SoundPlayer^ horor=gcnew SoundPlayer();

		PictureBox ^ pictureBox1;
		PictureBox ^ pictureBox2;
		Label^ lll;

		//PictureBox^ picturebox1;
		//PictureBox^ picturebox2;
		void draw_brick(int x)	//x為第幾關
		{
			delete picturebox;

			//panel1->Controls->Clear();
			//第1關
			if(x == 1)
			{
				Lx=4;
				Ly=4;
				picturebox = gcnew array<System::Windows::Forms::PictureBox^>(105);
				for(int i=0;i<15;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+15] = gcnew PictureBox();
					picturebox[i+15*2] = gcnew PictureBox();
					picturebox[i+15*3] = gcnew PictureBox();
					picturebox[i+15*4] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+15]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i+15*2]->Location = System::Drawing::Point(Lx,Ly+24*2);
					picturebox[i+15*3]->Location = System::Drawing::Point(Lx,Ly+24*3);
					picturebox[i+15*4]->Location = System::Drawing::Point(Lx,Ly+24*4);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+15]->Size = System::Drawing::Size(40,20);
					picturebox[i+15*2]->Size = System::Drawing::Size(40,20);
					picturebox[i+15*3]->Size = System::Drawing::Size(40,20);
					picturebox[i+15*4]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+15]->BackColor = Color::White;
					picturebox[i+15*2]->BackColor = Color::White;
					picturebox[i+15*3]->BackColor = Color::White;
					picturebox[i+15*4]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+15]);
					panel1->Controls->Add(picturebox[i+15*2]);
					panel1->Controls->Add(picturebox[i+15*3]);
					panel1->Controls->Add(picturebox[i+15*4]);
					Lx+=44;
				}
				Lx=4;
				Ly=124;
				for(int i=75;i<80;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					Lx+=44;
				}
				Lx=444;
				for(int i=80;i<85;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					Lx+=44;
				}
				Lx=4;
				Ly=148;
				for(int i=85;i<89;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					Lx+=44;
				}
				Lx=488;
				for(int i=89;i<93;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					Lx+=44;
				}
				Lx=4;
				Ly=172;
				for(int i=93;i<96;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					Lx+=44;
				}
				Lx=532;
				for(int i=96;i<99;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					Lx+=44;
				}
				Lx=4;
				Ly=196;
				for(int i=99;i<101;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					Lx+=44;
				}
				Lx=576;
				for(int i=101;i<103;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					Lx+=44;
				}
				Lx=4;
				Ly=220;
				picturebox[103] = gcnew PictureBox();
				picturebox[103]->Location = System::Drawing::Point(Lx,Ly);
				picturebox[103]->Size = System::Drawing::Size(40,20);
				picturebox[103]->BackColor = Color::White;
				panel1->Controls->Add(picturebox[103]);
				Lx=620;
				picturebox[104] = gcnew PictureBox();
				picturebox[104]->Location = System::Drawing::Point(Lx,Ly);
				picturebox[104]->Size = System::Drawing::Size(40,20);
				picturebox[104]->BackColor = Color::White;
				panel1->Controls->Add(picturebox[104]);
				for(int i=0;i<105;i++)
				{
					push(picturebox[i]->Location,1);
				}
			}
			//第2關
			else if(x==2)
			{
				Lx=136;
				Ly=4;
				picturebox = gcnew array<System::Windows::Forms::PictureBox^>(90);
				for(int i=0;i<9;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					Lx+=44;
				}
				Lx=136;
				Ly+=24;
				for(int i=9;i<18;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					Lx+=44;
				}
				Lx=4;
				Ly=52;
				for(int i=18;i<21;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=21;i<24;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=24;i<27;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=4;
				Ly=100;
				for(int i=36;i<51;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+15] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+15]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+15]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+15]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+15]);
					Lx+=44;
				}
				Lx=136;
				Ly=148;
				for(int i=66;i<75;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=268;
				Ly=196;
				for(int i=84;i<87;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+3] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+3]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+3]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+3]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+3]);
					Lx+=44;
				}
				for(int i=0;i<90;i++)
				{
					push(picturebox[i]->Location,1);
				}
			}
			//第三關
			if(x==3)
			{
				Lx=4;
				Ly=4;
				picturebox = gcnew array<System::Windows::Forms::PictureBox^>(114);
				for(int i=0;i<3;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=3;i<6;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=6;i<9;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=136;
				for(int i=18;i<21;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=21;i<24;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=4;
				Ly=52;
				for(int i=30;i<45;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+15] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+15]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+15]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+15]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+15]);
					Lx+=44;
				}
				Lx=4;
				Ly=100;
				for(int i=60;i<63;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=63;i<66;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=66;i<69;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=136;
				for(int i=78;i<81;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=81;i<84;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=136;
				Ly=148;
				for(int i=90;i<99;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=268;
				Ly=196;
				for(int i=108;i<111;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+3] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+3]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+3]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+3]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+3]);
					Lx+=44;
				}
				for(int i=0;i<114;i++)
				{
					if((i>=18 && i<=29) || (i>=78 && i<=89))
					{
						push(picturebox[i]->Location,2);
					}
					else
					{
						push(picturebox[i]->Location,1);
					}
				}
			}
			//第4關
			if(x==4)
			{
				Lx=4;
				Ly=4;
				picturebox = gcnew array<System::Windows::Forms::PictureBox^>(126);
				for(int i=0;i<3;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+6]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx+=132*3;
				for(int i=3;i<6;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+6]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=136;
				for(int i=12;i<15;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=15;i<18;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=4+132*2;
				for(int i=24;i<27;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+3] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+3]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+3]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Orange;
					picturebox[i+3]->BackColor = Color::Orange;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+3]);
					Lx+=44;
				}
				Lx=136;
				Ly+=48;
				for(int i=30;i<39;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=4;
				for(int i=48;i<51;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Orange;
					picturebox[i+6]->BackColor = Color::Orange;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=4+132*4;
				for(int i=51;i<54;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Orange;
					picturebox[i+6]->BackColor = Color::Orange;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=4;
				Ly+=48;
				for(int i=60;i<63;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=63;i<66;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=66;i<69;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+9]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=4+132;
				for(int i=78;i<81;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=81;i<84;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=4+132;
				Ly+=48;
				for(int i=90;i<93;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+6]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx+=132;
				for(int i=93;i<96;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+6]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=4+132*2;
				for(int i=102;i<105;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+3] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+3]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+3]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Orange;
					picturebox[i+3]->BackColor = Color::Orange;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+3]);
					Lx+=44;
				}
				Lx=4+132*2;
				Ly+=48;
				for(int i=108;i<111;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+3] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+3]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+3]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+3]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+3]);
					Lx+=44;
				}
				Lx=4;
				for(int i=114;i<117;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Orange;
					picturebox[i+6]->BackColor = Color::Orange;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx+=132*3;
				for(int i=117;i<120;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Orange;
					picturebox[i+6]->BackColor = Color::Orange;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				for(int i=0;i<126;i++)
				{
					if((i>=12 && i<=23) || (i>=78 && i<=89))
					{
						push(picturebox[i]->Location,2);
					}
					else if((i>=24 && i<=29) || (i>=48 && i<=59) || (i>=102 && i<=107) || (i>=114 && i<=125))
					{
						push(picturebox[i]->Location,3);
					}
					else
					{
						push(picturebox[i]->Location,1);
					}
				}
			}
			//第5關
			if(x==5)
			{
				//消不掉的磚塊
				/*
				picturebox1 = gcnew PictureBox();
				picturebox2 = gcnew PictureBox();
				picturebox1->Location = System::Drawing::Point(4,100);
				picturebox2->Location = System::Drawing::Point(400,100);
				picturebox1->Size = System::Drawing::Size(260,20);
				picturebox2->Size = System::Drawing::Size(260,20);
				picturebox1->BackColor = Color::Gray;
				picturebox2->BackColor = Color::Gray;
				panel1->Controls->Add(picturebox1);
				panel1->Controls->Add(picturebox2);
				*/
				//可以消的磚塊
				Lx=66;
				Ly=4;
				picturebox = gcnew array<System::Windows::Forms::PictureBox^>(102);
				for(int i=0;i<3;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Orange;
					picturebox[i+9]->BackColor = Color::Orange;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=264;
				for(int i=3;i<6;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Orange;
					picturebox[i+9]->BackColor = Color::Orange;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=467;
				for(int i=6;i<9;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Orange;
					picturebox[i+9]->BackColor = Color::Orange;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=136;
				Ly=52;
				for(int i=18;i<21;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=400;
				for(int i=21;i<24;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=4;
				Ly=124;
				for(int i=30;i<33;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+6]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=532;
				for(int i=33;i<36;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+6]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=136;
				for(int i=42;i<51;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+9]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+9]);
					Lx+=44;
				}
				Lx=268;
				Ly=172;
				for(int i=60;i<63;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+3] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i+9] = gcnew PictureBox();
					picturebox[i+12] = gcnew PictureBox();
					picturebox[i+15] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+3]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24*2);
					picturebox[i+9]->Location = System::Drawing::Point(Lx,Ly+24*3);
					picturebox[i+12]->Location = System::Drawing::Point(Lx,Ly+24*4);
					picturebox[i+15]->Location = System::Drawing::Point(Lx,Ly+24*5);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+3]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i+9]->Size = System::Drawing::Size(40,20);
					picturebox[i+12]->Size = System::Drawing::Size(40,20);
					picturebox[i+15]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::Red;
					picturebox[i+3]->BackColor = Color::Red;
					picturebox[i+6]->BackColor = Color::Red;
					picturebox[i+9]->BackColor = Color::Red;
					picturebox[i+12]->BackColor = Color::Red;
					picturebox[i+15]->BackColor = Color::Red;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+3]);
					panel1->Controls->Add(picturebox[i+6]);
					panel1->Controls->Add(picturebox[i+9]);
					panel1->Controls->Add(picturebox[i+12]);
					panel1->Controls->Add(picturebox[i+15]);
					Lx+=44;
				}
				Lx=92;
				Ly=220;
				for(int i=78;i<81;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+6]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=444;
				for(int i=81;i<84;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+6]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=136;
				Ly=268;
				for(int i=90;i<93;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+6]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				Lx=400;
				for(int i=93;i<96;i++)
				{
					picturebox[i] = gcnew PictureBox();
					picturebox[i+6] = gcnew PictureBox();
					picturebox[i]->Location = System::Drawing::Point(Lx,Ly);
					picturebox[i+6]->Location = System::Drawing::Point(Lx,Ly+24);
					picturebox[i]->Size = System::Drawing::Size(40,20);
					picturebox[i+6]->Size = System::Drawing::Size(40,20);
					picturebox[i]->BackColor = Color::White;
					picturebox[i+6]->BackColor = Color::White;
					panel1->Controls->Add(picturebox[i]);
					panel1->Controls->Add(picturebox[i+6]);
					Lx+=44;
				}
				for(int i=0;i<102;i++)
				{
					if(i>=0 && i<=17)
					{
						push(picturebox[i]->Location,3);
					}
					else if((i>=18 && i<=29) || (i>=42 && i<=59) || (i>=60 && i<=77))
					{
						push(picturebox[i]->Location,2);
					}
					else
					{
						push(picturebox[i]->Location,1);
					}
				}
			}
		}
		void delete_brick(game1 *cur,int x,int y)	//count為第幾關,cur為Double_Link的head,x,y為球座標
		{
			int i=0;
			bool found=false;	//如果是true則消掉磚塊
			while(cur!=NULL)
			{
				if((x>=cur->p.X && x<=(cur->p.X+40)) && (y>=cur->p.Y && y<=(cur->p.Y+20)))
				{
					cur->color--;
					found=true;
					break;
				}
				cur=cur->next;
				i++;
			}
			if(found==true)
			{
			++broken_brick;
				if(cur->color==0)
				{
					picturebox[i]->Visible=false;
				}
				else if(cur->color==1)
				{
					picturebox[i]->BackColor=Color::White;
				}
				else if(cur->color==2)
				{
					picturebox[i]->BackColor=Color::Red;
				}
			}
		}

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 pictureBox1 = gcnew PictureBox;
				 pictureBox1->Location = Point(265, 480);
				 pictureBox1->Image = gcnew Bitmap ("bar.png");
				 pictureBox1->Size = System::Drawing::Size(150,15);
				 panel1->Controls->Add(pictureBox1);

				 pictureBox2 = gcnew PictureBox;
				 pictureBox2->Location = Point(330, 460);
				 pictureBox2->Image = gcnew Bitmap ("ball_alternative.png");
				 pictureBox2->Size = System::Drawing::Size(20,20);
				 panel1->Controls->Add(pictureBox2);
				 backgroundmusic2->SoundLocation=("ice.wav");
				 backgroundmusic3->SoundLocation=("volcano.wav");
				 backgroundmusic4->SoundLocation=("forest.wav");
				 backgroundmusic5->SoundLocation=("sea.wav");
				 bar_ini_pos_X = pictureBox1->Location.X;
				 bar_ini_pos_Y = pictureBox1->Location.Y;
				 ball_ini_pos_X = pictureBox2->Location.X;
				 ball_ini_pos_Y = pictureBox2->Location.Y;
				 head=NULL;
				 tail=NULL;
				 start = 0;
				 ball_shoot = 0;
				 force_change = 0;
				 life = 3;
				 stage_now = 1;
				 draw_brick(1);
				 pictureBox1->BringToFront();
				 pictureBox2->BringToFront();

				 backgroundmusic1->SoundLocation=("desert.wav");
				 backgroundmusic1->PlayLooping();
				 
				 /*backgroundmusic5->SoundLocation=("sea.wav");
				 backgroundmusic5->PlayLooping();*/
				 
			 }
	private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				if (ball_shoot == 1){
					if( e->X>=70 && e->X<=585 && start == 1)  //Button_Click事件觸發後,才會執行
						  pictureBox1->Location = System::Drawing::Point(e->X-70, pictureBox1->Location.Y);
					
					if (e->X < 70 && start == 1)
						  pictureBox1->Location = System::Drawing::Point(0, pictureBox1->Location.Y);
					
					
				}
				else if(ball_shoot == 0){
					if( e->X>=70 && e->X<=585 && start == 1){  //Button_Click事件觸發後,才會執行
						  pictureBox1->Location = System::Drawing::Point(e->X-70, pictureBox1->Location.Y);
						  pictureBox2->Location = System::Drawing::Point(e->X-4, pictureBox2->Location.Y);
					}
					
					if (e->X < 70 && start == 1){
						  pictureBox1->Location = System::Drawing::Point(0, pictureBox1->Location.Y);
						  pictureBox2->Location = System::Drawing::Point(66, pictureBox2->Location.Y);
					}

					if (e->X > 585 && start == 1){
						  pictureBox1->Location = System::Drawing::Point(516, pictureBox1->Location.Y);
						  pictureBox2->Location = System::Drawing::Point(582, pictureBox2->Location.Y);
					}
					
					
				}
				

			 }
	private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(life!=0){
				 if(ball_shoot != 1){
					 if(start==0){
						 start=1;
						 
					 }
			     
					 else if(start == 1){
						ball_shoot = 1;
						srand(time(NULL));
						do{
						ball_angle=rand()%121+30;
						}while(ball_angle >= 80 && ball_angle <= 100);
						timer1->Start();
					 }
				 }
			 }
			 
			 else{
				 backgroundmusic1->Stop();
				 backgroundmusic2->Stop();
				 backgroundmusic3->Stop();
				 backgroundmusic4->Stop();
				 backgroundmusic5->Stop();
				 defeat->SoundLocation=("lose.wav");
				 defeat->Play();

				 lose^ l=gcnew lose();
				 l->Show();
				  
				 //死亡宣告
			 }

		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 
			 int ball_tmp_x=pictureBox2->Location.X;
			 int ball_tmp_y=pictureBox2->Location.Y;
			 label1->Text = "分數 : " + Convert::ToString(broken_brick * 50);
			 label2->Text = "最高分 : " + Convert::ToString(broken_brick * 50);
			 ball_tmp_y-=5*sin(  ball_angle*PI/180  );
			 ball_tmp_x+=5*( cos(  ball_angle*PI/180)   );
			 pictureBox2->Location=System::Drawing::Point( ball_tmp_x, ball_tmp_y);

			 //換關
			 if(broken_brick==741)
			 {
				 horor->SoundLocation=("horor.wav");
				 horor->PlayLooping();

				 All^ a=gcnew All();
				 a->Show();
				 timer1->Stop();
			 }
			 else if(broken_brick == stage_complete[stage_now] && force_change <1){
				 ++stage_now;
				  
				  backgroundmusic1->Stop();
				  backgroundmusic2->Stop();
				  backgroundmusic3->Stop();
				  backgroundmusic4->Stop();
				  backgroundmusic5->Stop();
			      victory->SoundLocation=("victory.wav");
			      victory->Play();
				  Sleep(7500);
				 if(stage_now==2)
				 {
					 backgroundmusic2->SoundLocation=("ice.wav");
					 backgroundmusic2->PlayLooping();
				 }
				 else if(stage_now==3)
				 {
					 backgroundmusic3->SoundLocation=("volcano.wav");
					 backgroundmusic3->PlayLooping();
				 }
				 else if(stage_now==4)
				 {
					 backgroundmusic4->SoundLocation=("forest.wav");
					 backgroundmusic4->PlayLooping();
				 }
				 else if(stage_now==5)
				 {
					 backgroundmusic5->SoundLocation=("sea.wav");
					 backgroundmusic5->PlayLooping();
				 }


				 
				 timer2->Start();
				 timer1->Stop();
				 
				 //MessageBox::Show("過關!");
				 
			 }

			 else if(force_change !=0){
			 stage_now = force_change;
			 force_change = 0;
			 
			 timer2->Start();
			 timer1->Stop();
			 }

			 //桿子
			 if(ball_tmp_y > 470 && ball_tmp_x >= pictureBox1->Location.X && ball_tmp_x <= pictureBox1->Location.X + 150){
			 timer1->Stop();
			 ball_angle = 360 - ball_angle;
			 timer1->Start();
			 }


			 //死亡
			 else if(ball_tmp_y >482){
			 life--;
			 label3->Text = "剩餘生命 : " + Convert::ToString(life);
			 timer3->Start();
			 timer1->Stop();
			 }

			 //天花板
			 else if(ball_tmp_y <= 0 ){
			 timer1->Stop();
			 ball_angle = 360 - ball_angle;
			 timer1->Start();
			 }

			 //右側牆壁
			 else if(ball_tmp_x >= 650){
			 timer1->Stop();
			 ball_angle = 180 - ball_angle;
			 timer1->Start();
			 }

			 //左側牆壁
			 else if(ball_tmp_x <= 0){
			 timer1->Stop();
			 ball_angle = 180 - ball_angle;
			 timer1->Start();
			 }

			 //撞擊磚塊
			 
			 game1 *current = head;
			 
			 Point lt = Point(ball_tmp_x, ball_tmp_y);
			 Point rt = Point(ball_tmp_x + 20, ball_tmp_y);
			 Point rb = Point(ball_tmp_x + 20, ball_tmp_y + 20);
			 Point lb = Point(ball_tmp_x, ball_tmp_y + 20);
			 Point top = Point(ball_tmp_x + 10, ball_tmp_y);
			 Point right = Point(ball_tmp_x + 20, ball_tmp_y + 10);
			 Point bot = Point(ball_tmp_x + 10, ball_tmp_y + 20);
			 Point left = Point(ball_tmp_x, ball_tmp_y + 10);
			 
			 //Point center = Point(ball_tmp_x + 7, ball_tmp_y + 7);
			 int now = 0;
			 while(current != NULL){
				 
			     if(picturebox[now]->Visible==true){

				 //撞擊到磚塊下方
				 if( (top.X >= current->p.X && top.X < current->p.X+40) && (top.Y >= current->p.Y && top.Y < current->p.Y+20) 
					 || ( (top.X >= current->p.X && top.X < current->p.X+40) && (top.Y >= current->p.Y && top.Y < current->p.Y+20) 
					 && (right.X >= current->p.X && right.X < current->p.X+40) && (right.Y >= current->p.Y && right.Y < current->p.Y+20) 
					 && (left.X >= current->p.X && left.X < current->p.X+40) && (left.Y >= current->p.Y && left.Y < current->p.Y+20) ) ){
			
					 //del(current);
					 delete_brick(head,top.X,top.Y);	//count為第幾關,cur為Double_Link的head,x,y為球座標
					 timer1->Stop();
					 ball_angle = 360 - ball_angle;
					 timer1->Start();
				 }

				 
				 //撞擊到磚塊上方
				 if( (bot.X >= current->p.X && bot.X < current->p.X+40) && (bot.Y >= current->p.Y && bot.Y < current->p.Y+20) 
					 || ( (bot.X >= current->p.X && bot.X < current->p.X+40) && (bot.Y >= current->p.Y && bot.Y < current->p.Y+20) 
					 && (right.X >= current->p.X && right.X < current->p.X+40) && (right.Y >= current->p.Y && right.Y < current->p.Y+20) 
					 && (left.X >= current->p.X && left.X < current->p.X+40) && (left.Y >= current->p.Y && left.Y < current->p.Y+20) ) ){
				
					 //del(current);
					 delete_brick(head,bot.X,bot.Y);
					 
					 timer1->Stop();
					 ball_angle = 360 - ball_angle;
					 timer1->Start();
				 }

				 //撞擊到磚塊左方
				 if( (right.X >= current->p.X && right.X < current->p.X+40) && (right.Y >= current->p.Y && right.Y < current->p.Y+20) 
					 || ( (right.X >= current->p.X && right.X < current->p.X+40) && (right.Y >= current->p.Y && right.Y < current->p.Y+20) 
					 && (top.X >= current->p.X && top.X < current->p.X+40) && (top.Y >= current->p.Y && top.Y < current->p.Y+20) 
					 && (bot.X >= current->p.X && bot.X < current->p.X+40) && (bot.Y >= current->p.Y && bot.Y < current->p.Y+20) ) ){
				 
					 //del(current);
					 delete_brick(head,right.X,right.Y);
					 
					 timer1->Stop();
					 ball_angle = 180 - ball_angle;
					 timer1->Start();
				 }

				 //撞擊到磚塊右方
				 if( (left.X >= current->p.X && left.X < current->p.X+40) && (left.Y >= current->p.Y && left.Y < current->p.Y+20) 
					 || ( (left.X >= current->p.X && left.X < current->p.X+40) && (left.Y >= current->p.Y && left.Y < current->p.Y+20) 
					 && (top.X >= current->p.X && top.X < current->p.X+40) && (top.Y >= current->p.Y && top.Y < current->p.Y+20) 
					 && (bot.X >= current->p.X && bot.X < current->p.X+40) && (bot.Y >= current->p.Y && bot.Y < current->p.Y+20) ) ){
				 
					 //del(current);
					 delete_brick(head,left.X,left.Y);
					 
					 timer1->Stop();
					 ball_angle = 180 - ball_angle;
					 timer1->Start();
				 }
				 

				 
				 }
				 current = current -> next;
				 ++now;
			 }
			 
			 
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Stop();	 
				 panel1->Controls->Clear();
				 backgroundmusic1->Stop();
				 backgroundmusic2->Stop();
				 backgroundmusic3->Stop();
				 backgroundmusic4->Stop();
				 backgroundmusic5->Stop();
				 backgroundmusic1->Play();
				 delete pictureBox1;
				 delete pictureBox2;
			     head=NULL;
				 tail=NULL;
				 start = 0;
				 ball_shoot = 0;
				 broken_brick = 0;
				 label1->Text = "分數 : 0";
				 label2->Text = "最高分 : 0";
				 life = 3;
				 label3->Text = "剩餘生命 : 3";
				 draw_brick(1);
				 pictureBox1 = gcnew PictureBox;
				 pictureBox1->Location = Point(265, 480);
				 pictureBox1->Image = gcnew Bitmap ("bar.png");
				 pictureBox1->Size = System::Drawing::Size(150,15);
				 panel1->Controls->Add(pictureBox1);

				 pictureBox2 = gcnew PictureBox;
				 pictureBox2->Location = Point(330, 460);
				 pictureBox2->Image = gcnew Bitmap ("ball_alternative.png");
				 //pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
				 pictureBox2->Size = System::Drawing::Size(20,20);
				 panel1->Controls->Add(pictureBox2);
		 }
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
			
				 panel1->Controls->Clear();
				 delete pictureBox1;
				 delete pictureBox2;
			     head=NULL;
				 tail=NULL;
				 start = 0;
				 ball_shoot = 0;
				 
				 draw_brick(stage_now);
				 pictureBox1 = gcnew PictureBox;
				 pictureBox1->Location = Point(265, 480);
				 pictureBox1->Image = gcnew Bitmap ("bar.png");
				 pictureBox1->Size = System::Drawing::Size(150,15);
				 panel1->Controls->Add(pictureBox1);

				 pictureBox2 = gcnew PictureBox;
				 pictureBox2->Location = Point(330, 460);
				 pictureBox2->Image = gcnew Bitmap ("ball_alternative.png");
				 //pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
				 pictureBox2->Size = System::Drawing::Size(20,20);
				 panel1->Controls->Add(pictureBox2);
				 
				 timer2->Stop();
		 }
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
				 start = 0;
				 ball_shoot = 0;
				 delete pictureBox1;
				 delete pictureBox2;
				 pictureBox1 = gcnew PictureBox;
				 pictureBox1->Location = Point(265, 480);
				 pictureBox1->Image = gcnew Bitmap ("bar.png");
				 pictureBox1->Size = System::Drawing::Size(150,15);
				 panel1->Controls->Add(pictureBox1);

				 pictureBox2 = gcnew PictureBox;
				 pictureBox2->Location = Point(330, 460);
				 pictureBox2->Image = gcnew Bitmap ("ball_alternative.png");
				 //pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
				 pictureBox2->Size = System::Drawing::Size(20,20);
				 panel1->Controls->Add(pictureBox2);
				 timer3->Stop();
		 }
private: System::Void 關卡一ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Stop();	 
				 panel1->Controls->Clear();
				 backgroundmusic1->Stop();
				 backgroundmusic2->Stop();
				 backgroundmusic3->Stop();
				 backgroundmusic4->Stop();
				 backgroundmusic5->Stop();
				 backgroundmusic1->Play();
				 delete pictureBox1;
				 delete pictureBox2;
			     head=NULL;
				 tail=NULL;
				 force_change = 1;
				 start = 0;
				 ball_shoot = 0;
				 broken_brick = 0;
				 stage_now = 1;
				 label1->Text = "分數 : 0";
				 label2->Text = "最高分 : 0";
				 life = 3;
				 label3->Text = "剩餘生命 : 3";
				 draw_brick(1);
				 pictureBox1 = gcnew PictureBox;
				 pictureBox1->Location = Point(265, 480);
				 pictureBox1->Image = gcnew Bitmap ("bar.png");
				 pictureBox1->Size = System::Drawing::Size(150,15);
				 panel1->Controls->Add(pictureBox1);

				 pictureBox2 = gcnew PictureBox;
				 pictureBox2->Location = Point(330, 460);
				 pictureBox2->Image = gcnew Bitmap ("ball_alternative.png");
				 //pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
				 pictureBox2->Size = System::Drawing::Size(20,20);
				 panel1->Controls->Add(pictureBox2);
		 }
private: System::Void 關卡二ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			     timer1->Stop();	 
				 panel1->Controls->Clear();
				 backgroundmusic1->Stop();
				 backgroundmusic2->Stop();
				 backgroundmusic3->Stop();
				 backgroundmusic4->Stop();
				 backgroundmusic5->Stop();
				 backgroundmusic2->Play();
				 delete pictureBox1;
				 delete pictureBox2;
			     head=NULL;
				 tail=NULL;
				 force_change = 2;
				 start = 0;
				 ball_shoot = 0;
				 broken_brick = 0;
				 stage_now = 1;
				 label1->Text = "分數 : " + Convert::ToString(broken_brick * 50);
				 label2->Text = "最高分 : " + Convert::ToString(broken_brick * 50);
				 life = 3;
				 label3->Text = "剩餘生命 : 3";
				 draw_brick(2);
				 pictureBox1 = gcnew PictureBox;
				 pictureBox1->Location = Point(265, 480);
				 pictureBox1->Image = gcnew Bitmap ("bar.png");
				 pictureBox1->Size = System::Drawing::Size(150,15);
				 panel1->Controls->Add(pictureBox1);

				 pictureBox2 = gcnew PictureBox;
				 pictureBox2->Location = Point(330, 460);
				 pictureBox2->Image = gcnew Bitmap ("ball_alternative.png");
				 //pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
				 pictureBox2->Size = System::Drawing::Size(20,20);
				 panel1->Controls->Add(pictureBox2);
		 }
private: System::Void 關卡三ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Stop();	 
				 panel1->Controls->Clear();
				 backgroundmusic3->Play();
				 delete pictureBox1;
				 delete pictureBox2;
			     head=NULL;
				 tail=NULL;
				 force_change = 3;
				 start = 0;
				 ball_shoot = 0;
				 broken_brick = 0;
				 stage_now = 2;
				 label1->Text = "分數 : " + Convert::ToString(broken_brick * 50);
				 label2->Text = "最高分 : " + Convert::ToString(broken_brick * 50);
				 life = 3;
				 label3->Text = "剩餘生命 : 3";
				 draw_brick(3);
				 pictureBox1 = gcnew PictureBox;
				 pictureBox1->Location = Point(265, 480);
				 pictureBox1->Image = gcnew Bitmap ("bar.png");
				 pictureBox1->Size = System::Drawing::Size(150,15);
				 panel1->Controls->Add(pictureBox1);

				 pictureBox2 = gcnew PictureBox;
				 pictureBox2->Location = Point(330, 460);
				 pictureBox2->Image = gcnew Bitmap ("ball_alternative.png");
				 //pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
				 pictureBox2->Size = System::Drawing::Size(20,20);
				 panel1->Controls->Add(pictureBox2);
		 }
private: System::Void 關卡四ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			     timer1->Stop();	 
				 panel1->Controls->Clear();
				 backgroundmusic1->Stop();
				 backgroundmusic2->Stop();
				 backgroundmusic3->Stop();
				 backgroundmusic4->Stop();
				 backgroundmusic5->Stop();
				 backgroundmusic4->Play();
				 delete pictureBox1;
				 delete pictureBox2;
			     head=NULL;
				 tail=NULL;
				 force_change = 4;
				 start = 0;
				 ball_shoot = 0;
				 broken_brick = 0;
				 stage_now = 3;
				 label1->Text = "分數 : " + Convert::ToString(broken_brick * 50);
				 label2->Text = "最高分 : " + Convert::ToString(broken_brick * 50);
				 life = 3;
				 label3->Text = "剩餘生命 : 3";
				 draw_brick(4);
				 pictureBox1 = gcnew PictureBox;
				 pictureBox1->Location = Point(265, 480);
				 pictureBox1->Image = gcnew Bitmap ("bar.png");
				 pictureBox1->Size = System::Drawing::Size(150,15);
				 panel1->Controls->Add(pictureBox1);

				 pictureBox2 = gcnew PictureBox;
				 pictureBox2->Location = Point(330, 460);
				 pictureBox2->Image = gcnew Bitmap ("ball_alternative.png");
				 //pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
				 pictureBox2->Size = System::Drawing::Size(20,20);
				 panel1->Controls->Add(pictureBox2);
		 }
private: System::Void 關卡五ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Stop();	 
				 panel1->Controls->Clear();
				 backgroundmusic1->Stop();
				 backgroundmusic2->Stop();
				 backgroundmusic3->Stop();
				 backgroundmusic4->Stop();
				 backgroundmusic5->Stop();
				 backgroundmusic5->Play();
				 delete pictureBox1;
				 delete pictureBox2;
			     head=NULL;
				 tail=NULL;
				 force_change = 5;
				 start = 0;
				 ball_shoot = 0;
				 broken_brick = 0;
				 stage_now = 4;
				 label1->Text = "分數 : " + Convert::ToString(broken_brick * 50);
				 label2->Text = "最高分 : " + Convert::ToString(broken_brick * 50);
				 life = 3;
				 label3->Text = "剩餘生命 : 3";
				 draw_brick(5);
				 pictureBox1 = gcnew PictureBox;
				 pictureBox1->Location = Point(265, 480);
				 pictureBox1->Image = gcnew Bitmap ("bar.png");
				 pictureBox1->Size = System::Drawing::Size(150,15);
				 panel1->Controls->Add(pictureBox1);

				 pictureBox2 = gcnew PictureBox;
				 pictureBox2->Location = Point(330, 460);
				 pictureBox2->Image = gcnew Bitmap ("ball_alternative.png");
				 //pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
				 pictureBox2->Size = System::Drawing::Size(20,20);
				 panel1->Controls->Add(pictureBox2);
		 }
private: System::Void 即將通關ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1->Stop();	 
				 panel1->Controls->Clear();
				 backgroundmusic1->Stop();
				 backgroundmusic2->Stop();
				 backgroundmusic3->Stop();
				 backgroundmusic4->Stop();
				 backgroundmusic5->Stop();
				 backgroundmusic5->Play();
				 delete pictureBox1;
				 delete pictureBox2;
			     head=NULL;
				 tail=NULL;
				 start = 0;
				 ball_shoot = 0;
				 broken_brick = 740;
				 label1->Text = "分數 : " + Convert::ToString(broken_brick * 50);
				 label2->Text = "最高分 : " + Convert::ToString(broken_brick * 50);
				 life = 3;
				 label3->Text = "剩餘生命 : 3";
				 draw_brick(5);
				 pictureBox1 = gcnew PictureBox;
				 pictureBox1->Location = Point(265, 480);
				 pictureBox1->Image = gcnew Bitmap ("bar.png");
				 pictureBox1->Size = System::Drawing::Size(150,15);
				 panel1->Controls->Add(pictureBox1);

				 pictureBox2 = gcnew PictureBox;
				 pictureBox2->Location = Point(330, 460);
				 pictureBox2->Image = gcnew Bitmap ("ball_alternative.png");
				 //pictureBox2->SizeMode = PictureBoxSizeMode::Zoom;
				 pictureBox2->Size = System::Drawing::Size(20,20);
				 panel1->Controls->Add(pictureBox2);
		 }
};
}

