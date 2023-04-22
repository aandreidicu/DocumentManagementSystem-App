#pragma once
#include "CClient.h"
#include <msclr\marshal_cppstd.h>

namespace ANDDMSCLIENT {

	using namespace System;
	using namespace msclr::interop;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for DocPrimiteForm
	/// </summary>
	public ref class TrimiteForm : public System::Windows::Forms::Form
	{
	public:
		bool flag34 = true;
		bool flagPermisie = true;
		bool flagParTara = true;
		String^ tip;
		String^ subtip;
		

	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox11;
	public:
		Pachet^ clientul;
		TrimiteForm(Pachet^ c)
		{
			clientul = c;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Button^ buttonTrimiteDoc;
	public:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;

	public: Mutex^ mtx = gcnew Mutex;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TrimiteForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonTrimiteDoc = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonTrimiteDoc
			// 
			this->buttonTrimiteDoc->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->buttonTrimiteDoc->Dock = System::Windows::Forms::DockStyle::Right;
			this->buttonTrimiteDoc->FlatAppearance->BorderSize = 0;
			this->buttonTrimiteDoc->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonTrimiteDoc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonTrimiteDoc->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonTrimiteDoc->Location = System::Drawing::Point(989, 0);
			this->buttonTrimiteDoc->Name = L"buttonTrimiteDoc";
			this->buttonTrimiteDoc->Size = System::Drawing::Size(95, 570);
			this->buttonTrimiteDoc->TabIndex = 5;
			this->buttonTrimiteDoc->Text = L"TRIMITE";
			this->buttonTrimiteDoc->UseVisualStyleBackColor = false;
			this->buttonTrimiteDoc->Click += gcnew System::EventHandler(this, &TrimiteForm::buttonTrimiteDoc_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(989, 570);
			this->panel1->TabIndex = 6;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->panel5);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(142, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(847, 570);
			this->panel3->TabIndex = 1;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->label12);
			this->panel5->Controls->Add(this->textBox12);
			this->panel5->Controls->Add(this->label11);
			this->panel5->Controls->Add(this->textBox11);
			this->panel5->Controls->Add(this->textBox6);
			this->panel5->Controls->Add(this->label6);
			this->panel5->Controls->Add(this->textBox7);
			this->panel5->Controls->Add(this->label7);
			this->panel5->Controls->Add(this->textBox8);
			this->panel5->Controls->Add(this->label8);
			this->panel5->Controls->Add(this->textBox9);
			this->panel5->Controls->Add(this->label9);
			this->panel5->Controls->Add(this->textBox10);
			this->panel5->Controls->Add(this->label10);
			this->panel5->Controls->Add(this->textBox1);
			this->panel5->Controls->Add(this->label5);
			this->panel5->Controls->Add(this->textBox2);
			this->panel5->Controls->Add(this->label4);
			this->panel5->Controls->Add(this->textBox5);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Controls->Add(this->textBox3);
			this->panel5->Controls->Add(this->label1);
			this->panel5->Controls->Add(this->textBox4);
			this->panel5->Controls->Add(this->label2);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel5->Location = System::Drawing::Point(119, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(728, 570);
			this->panel5->TabIndex = 11;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(154, 90);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(320, 20);
			this->textBox6->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(99, 438);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 22);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Scop";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(154, 177);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(320, 20);
			this->textBox7->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(95, 351);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(42, 22);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Tara";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(154, 438);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(320, 20);
			this->textBox8->TabIndex = 19;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(64, 265);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(84, 22);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Localitate";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(154, 264);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(320, 20);
			this->textBox9->TabIndex = 14;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(65, 177);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(83, 22);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Data final";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(154, 351);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(320, 20);
			this->textBox10->TabIndex = 13;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(40, 90);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(108, 22);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Data inceput";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(142, 81);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(320, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(87, 429);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 22);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Scop";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(142, 168);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(320, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(83, 342);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 22);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Judet";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(142, 429);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(320, 20);
			this->textBox5->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(52, 256);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 22);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Localitate";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(142, 255);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(320, 20);
			this->textBox3->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(53, 168);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 22);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Data final";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(142, 342);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(320, 20);
			this->textBox4->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(28, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 22);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Data inceput";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->button4);
			this->panel4->Controls->Add(this->button3);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(113, 570);
			this->panel4->TabIndex = 0;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button4->Dock = System::Windows::Forms::DockStyle::Top;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Gainsboro;
			this->button4->Location = System::Drawing::Point(0, 137);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(113, 141);
			this->button4->TabIndex = 8;
			this->button4->Text = L"RAPORT DE PARASIRE A TARII";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &TrimiteForm::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button3->Dock = System::Windows::Forms::DockStyle::Top;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Gainsboro;
			this->button3->Location = System::Drawing::Point(0, 0);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(113, 137);
			this->button3->TabIndex = 7;
			this->button3->Text = L"PERMISIE";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &TrimiteForm::button3_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(142, 570);
			this->panel2->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Gainsboro;
			this->button2->Location = System::Drawing::Point(0, 278);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 292);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Document - Personalizat";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Gainsboro;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 278);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Document - Sablon";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &TrimiteForm::button1_Click);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(142, 501);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(320, 20);
			this->textBox11->TabIndex = 21;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(47, 501);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(89, 22);
			this->label11->TabIndex = 22;
			this->label11->Text = L"Nr Telefon";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Black;
			this->label12->Location = System::Drawing::Point(59, 514);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(89, 22);
			this->label12->TabIndex = 24;
			this->label12->Text = L"Nr Telefon";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(154, 514);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(320, 20);
			this->textBox12->TabIndex = 23;
			// 
			// TrimiteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1084, 570);
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->buttonTrimiteDoc);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"TrimiteForm";
			this->ShowInTaskbar = false;
			this->Load += gcnew System::EventHandler(this, &TrimiteForm::TrimiteForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void TrimiteForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->button3->Hide();
	this->button4->Hide();

	//permisie
	this->label1->Hide();
	this->label2->Hide();
	this->label3->Hide();
	this->label4->Hide();
	this->label5->Hide();
	this->textBox1->Hide();
	this->textBox2->Hide();
	this->textBox3->Hide();
	this->textBox4->Hide();
	this->textBox5->Hide();
	this->label11->Hide();
	this->textBox11->Hide();
	//par tara
	this->label6->Hide();
	this->label7->Hide();
	this->label8->Hide();
	this->label9->Hide();
	this->label10->Hide();
	this->textBox6->Hide();
	this->textBox7->Hide();
	this->textBox8->Hide();
	this->textBox9->Hide();
	this->textBox10->Hide();
	this->label12->Hide();
	this->textBox12->Hide();

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (flag34 == true) {
		this->button3->Show();
		this->button4->Show();

		this->tip = "s";

		flag34 = false;
	}
	else
	{
		this->button3->Hide();
		this->button4->Hide();
		flag34 = true;
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (flagPermisie == true)
	{
		this->label1->Show();
		this->label2->Show();
		this->label3->Show();
		this->label4->Show();
		this->label5->Show();
		this->textBox1->Show();
		this->textBox2->Show();
		this->textBox3->Show();
		this->textBox4->Show();
		this->textBox5->Show();
		this->label11->Show();
		this->textBox11->Show();

		this->subtip = "1";

		flagPermisie = false;
	}
	else
	{
		this->label1->Hide();
		this->label2->Hide();
		this->label3->Hide();
		this->label4->Hide();
		this->label5->Hide();
		this->textBox1->Hide();
		this->textBox2->Hide();
		this->textBox3->Hide();
		this->textBox4->Hide();
		this->textBox5->Hide();
		this->label11->Hide();
		this->textBox11->Hide();

		flagPermisie = true;
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (flagParTara == true)
	{
		this->label6->Show();
		this->label7->Show();
		this->label8->Show();
		this->label9->Show();
		this->label10->Show();
		this->textBox6->Show();
		this->textBox7->Show();
		this->textBox8->Show();
		this->textBox9->Show();
		this->textBox10->Show();
		this->label12->Show();
		this->textBox12->Show();

		this->subtip = "2";

		flagParTara = false;
	}
	else
	{
		this->label6->Hide();
		this->label7->Hide();
		this->label8->Hide();
		this->label9->Hide();
		this->label10->Hide();
		this->textBox6->Hide();
		this->textBox7->Hide();
		this->textBox8->Hide();
		this->textBox9->Hide();
		this->textBox10->Hide();
		this->label12->Hide();
		this->textBox12->Hide();

		flagParTara = true;
	}
}
private: System::Void buttonTrimiteDoc_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->tip == "s" && this->subtip == "1")
	{
		std::string nrtel = marshal_as<std::string>(this->textBox11->Text);
		std::string data1= marshal_as<std::string>(this->textBox1->Text);
		std::string data2= marshal_as<std::string>(this->textBox2->Text);
		std::string localitate= marshal_as<std::string>(this->textBox3->Text);
		std::string judet= marshal_as<std::string>(this->textBox4->Text);
		std::string scop= marshal_as<std::string>(this->textBox5->Text);

		clientul->c->F_TRIMITE_DOCUMENT("s", "2", "Raport_de_parasire_a_tarii", clientul->c->getUsername(), nrtel, data1, data2, localitate, judet, scop);
	}
	if (this->tip == "s" && this->subtip == "2")
	{
		std::string nrtel = marshal_as<std::string>(this->textBox12->Text);
		std::string data1 = marshal_as<std::string>(this->textBox6->Text);
		std::string data2 = marshal_as<std::string>(this->textBox7->Text);
		std::string localitate = marshal_as<std::string>(this->textBox9->Text);
		std::string tara = marshal_as<std::string>(this->textBox10->Text);
		std::string scop = marshal_as<std::string>(this->textBox8->Text);

		clientul->c->F_TRIMITE_DOCUMENT("s", "1", "Permisie", clientul->c->getUsername(), nrtel, data1, data2, localitate, tara, scop);
	}
}
};
}
