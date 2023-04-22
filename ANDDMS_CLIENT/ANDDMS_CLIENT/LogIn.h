#pragma once
#include "CClient.h"
#include "InregistrareForm.h"
#include "MainForm.h"

namespace ANDDMSCLIENT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for LogIn
	/// </summary>
	public ref class LogIn : public System::Windows::Forms::Form
	{

	public:
		Pachet^ clientul;
		bool flag = false;
		bool flag1 = true;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:
		//urmatoarea fereastra
		ANDDMSCLIENT::InregistrareForm^ inregForm;
	private: System::Windows::Forms::Label^ label4;
	public:
		ANDDMSCLIENT::MainForm^ mainForm;

		LogIn(Pachet^ cli)
		{
			clientul = cli;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public: Mutex^ mtx = gcnew Mutex;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox1;




	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LogIn()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LogIn::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel1->Location = System::Drawing::Point(368, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(820, 681);
			this->panel1->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Firebrick;
			this->label4->Location = System::Drawing::Point(278, 194);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 22);
			this->label4->TabIndex = 13;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(212, 453);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(417, 47);
			this->button2->TabIndex = 4;
			this->button2->Text = L"AUTENTIFICARE";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &LogIn::button2_Click_1);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panel3->Controls->Add(this->textBox1);
			this->panel3->Location = System::Drawing::Point(212, 236);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(417, 55);
			this->panel3->TabIndex = 5;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(13, 14);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(392, 27);
			this->textBox1->TabIndex = 7;
			this->textBox1->Text = L" E-mail";
			this->textBox1->Click += gcnew System::EventHandler(this, &LogIn::textBox1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 27, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(274, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(292, 48);
			this->label3->TabIndex = 4;
			this->label3->Text = L"AUTENTIFICARE\r\n";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panel4->Controls->Add(this->textBox2);
			this->panel4->Location = System::Drawing::Point(212, 331);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(417, 55);
			this->panel4->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 15));
			this->textBox2->ForeColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(13, 13);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(392, 27);
			this->textBox2->TabIndex = 0;
			this->textBox2->Text = L"Parola";
			this->textBox2->UseSystemPasswordChar = true;
			this->textBox2->Click += gcnew System::EventHandler(this, &LogIn::textBox2_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Blue;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(368, 681);
			this->panel2->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(66, 82);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(230, 150);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(56, 270);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(246, 88);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Sistem online de management \r\n                 documente\r\n                       "
				L"   - \r\n           ATM \"Ferdinand I\"";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(118, 539);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 32);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Inregistrare";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &LogIn::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(131, 500);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Nu ai cont\?";
			// 
			// LogIn
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1188, 681);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"LogIn";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L" ";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		//LOGIN

	private: System::Void textBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == " E-mail")
		{
			textBox1->Text = "";
		}
	}
	private: System::Void textBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->Text == "Parola")
		{
			textBox2->Text = "";
		}
	}


	public:System::Void parsare_client(Pachet^ cli)
	{
		clientul = cli;
	}

		  //private:System::Void some()
		  //{
		  //	if (clientul->newform == 1)
		  //	{
		  //		flag1 = false;
		  //		mainForm = gcnew ANDDMSCLIENT::MainForm(clientul);
		  //		this->Hide();
		  //		this->Close();
		  //		mainForm->ShowDialog();
		  //		//this->ShowDialog();
		  //	}
		  //}

	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {

		char* email = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox1->Text);
		char* passw = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox2->Text);

		//TO DO: SISTEMUL DE FERESTRE pentru login -> MAIN 

		if (flag == false)
		{
			clientul->c->F_LOGIN(email, passw);
			std::string str(passw);
			clientul->c->setPassword(str);
			flag = true;
		}

		/*while (flag1 == true && clientul->noform==0)
		{
			if (clientul->newform == 1) {
				flag1 = false;
				this->label4->Text = "";
				textBox1->Text = " E-mail";
				textBox2->Text = "Parola";

				mainForm = gcnew ANDDMSCLIENT::MainForm(clientul,this);
				this->Hide();
				mainForm->ShowDialog();

				clientul->newform = 0;
				flag = false;
			}
		}*/
		while (clientul->continua == true && clientul->noform == 0)
		{
			if (clientul->newform == 1) {
				clientul->continua = false;
				this->label4->Text = "";
				textBox1->Text = " E-mail";
				textBox2->Text = "Parola";

				clientul->newform = 0;
				flag = false;

				mainForm = gcnew ANDDMSCLIENT::MainForm(clientul, this);
				this->Hide();
				mainForm->ShowDialog();
				break;
			}
		}

		if (clientul->noform == 1)
		{
			label4->Text = "X E-mail/Parola introduse incorect!";
			flag1 = true;
			flag = false;
			clientul->noform = 0;
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		label4->Text = "";
		textBox1->Text = " E-mail";
		textBox2->Text = "Parola";
		inregForm = gcnew ANDDMSCLIENT::InregistrareForm(clientul, this);
		this->Hide();
		inregForm->ShowDialog();
	}
	};
}
	



