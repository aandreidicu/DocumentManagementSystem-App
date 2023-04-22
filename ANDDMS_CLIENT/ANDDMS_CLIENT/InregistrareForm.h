#pragma once
#include "CClient.h"
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
	/// Summary for InregistrareForm
	/// </summary>
	public ref class InregistrareForm : public System::Windows::Forms::Form
	{
	public:
		Pachet^ clientul;
		bool flag2SI = false;
		bool flag3SI = true;
	public:
		Form^ obj;
		InregistrareForm(Pachet^ c,Form^ obj1)
		{
			obj = obj1;
			clientul = c;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;

	public:
		Mutex^ mtx = gcnew Mutex;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InregistrareForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InregistrareForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(704, 590);
			this->panel1->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Firebrick;
			this->label4->Location = System::Drawing::Point(251, 188);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 22);
			this->label4->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(138, 414);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 22);
			this->label3->TabIndex = 11;
			this->label3->Text = L" Confirmati parola:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(138, 318);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(138, 22);
			this->label1->TabIndex = 10;
			this->label1->Text = L" Alegeti o parola:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Location = System::Drawing::Point(142, 439);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(417, 55);
			this->panel2->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 15));
			this->textBox3->ForeColor = System::Drawing::Color::White;
			this->textBox3->Location = System::Drawing::Point(13, 13);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(392, 27);
			this->textBox3->TabIndex = 0;
			this->textBox3->Text = L"Parola";
			this->textBox3->UseSystemPasswordChar = true;
			this->textBox3->Click += gcnew System::EventHandler(this, &InregistrareForm::textBox3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(138, 221);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(170, 22);
			this->label2->TabIndex = 9;
			this->label2->Text = L" Introduceti e-mailul:\r\n";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(142, 515);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(417, 47);
			this->button2->TabIndex = 8;
			this->button2->Text = L"INREGISTRARE";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &InregistrareForm::button2_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panel4->Controls->Add(this->textBox2);
			this->panel4->Location = System::Drawing::Point(142, 343);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(417, 55);
			this->panel4->TabIndex = 7;
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
			this->textBox2->Click += gcnew System::EventHandler(this, &InregistrareForm::textBox2_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panel3->Controls->Add(this->textBox1);
			this->panel3->Location = System::Drawing::Point(142, 246);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(417, 55);
			this->panel3->TabIndex = 6;
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
			this->textBox1->Click += gcnew System::EventHandler(this, &InregistrareForm::textBox1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(255, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(191, 143);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &InregistrareForm::pictureBox1_Click);
			// 
			// InregistrareForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 590);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"InregistrareForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L" ";
			this->Load += gcnew System::EventHandler(this, &InregistrareForm::InregistrareForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void InregistrareForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
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
	private: System::Void textBox3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox3->Text == "Parola")
		{
			textBox3->Text = "";
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->Text != textBox3->Text)
		{
			label4->Text = "X Parolele nu corespund!";
		}
		else
		{
			label4->Text = "";
			char* emailSI = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox1->Text);
			char* parolaSI = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox2->Text);
			if (flag2SI == false)
			{
				
				clientul->c->F_INREGISTRARE(emailSI, parolaSI);
				flag2SI = true;
			}

			while (flag3SI == true && clientul->noformSI == 0)
			{
				if (clientul->newformSI == 1)
				{
					flag3SI = false;
					label4->Text = "";
					this->Hide();
					obj->Show();
					textBox1->Text = " E-mail";
					textBox2->Text = "Parola";
					textBox3->Text = "Parola";
					clientul->newformSI = 0;
				}
			}

			if (clientul->noformSI == 1 && clientul->nr_inregistrare==6)
			{
				label4->Text = "X CONTUL ESTE DEJA INREGISTRAT";
				flag3SI = true;
				flag2SI = false;
				clientul->noformSI = 0;
			}
			if (clientul->noformSI == 1 && clientul->nr_inregistrare == 8)
			{
				label4->Text = "X CONTUL NU SE AFLA IN BAZA DE DATE";
				flag3SI = true;
				flag2SI = false;
				clientul->noformSI = 0;
			}
		}
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		obj->Show();
	}
	
		
	
	//TO DO: PARSARE WINDOWS INREG->LOG IN (CHECK)

};
}
