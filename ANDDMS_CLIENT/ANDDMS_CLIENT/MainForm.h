#pragma once
#include "CClient.h"

#include "DocPrimiteForm.h"
#include "DocAcceptateForm.h"
#include "DocRespinseForm.h"
#include "DocTrimiseForm.h"

#include "TrimiteForm.h"

#include "T_Studenti.h"
#include "T_Profesori.h"
#include "T_CadreMilitare.h"

#include "SETARI.h"




namespace ANDDMSCLIENT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		

	public:
		bool flag = true;
		bool flagTeams = true;

		Pachet^ clientul;
	private: System::Windows::Forms::Button^ btnTEAMS;
	private: System::Windows::Forms::Button^ buttonCadruMilitar;
	private: System::Windows::Forms::Button^ buttonProfesor;
	private: System::Windows::Forms::Button^ buttonStudent;
	public:
		Form^ obj_;
		MainForm(Pachet^ c,Form^ obj1_)
		{
			obj_ = obj1_;
			clientul = c;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		

	private:System::Windows::Forms::Form^ activeForm;
	private: System::Windows::Forms::Button^ buttonTrimiteDoc;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel5;
	public:

	public: Mutex^ mtx = gcnew Mutex;
	private: System::Windows::Forms::Button^ buttonDocTrimise;
	public:

	private: System::Windows::Forms::Button^ button2;
	public:



	public: ANDDMSCLIENT::DocPrimiteForm^ docPrimiteForm;
	private: System::Windows::Forms::Panel^ panel6;
	public:
	public: ANDDMSCLIENT::DocAcceptateForm^ docAcceptateForm;
	public: ANDDMSCLIENT::DocRespinseForm^ docRespinseForm;
	private: System::Windows::Forms::Panel^ panel7;
	public:
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	public: ANDDMSCLIENT::DocTrimiseForm^ docTrimiseForm;
	public:ANDDMSCLIENT::TrimiteForm^ trimiteForm;
	public:ANDDMSCLIENT::T_Studenti^ tStudentForm;
	public:ANDDMSCLIENT::T_Profesori^ tProfesorForm;
	public:ANDDMSCLIENT::T_CadreMilitare^ tCadruMilitarForm;
	public:ANDDMSCLIENT::SETARI^ SetariForm;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ buttonDocRespinse;

	protected:

	private: System::Windows::Forms::Button^ buttonDocAcceptate;
	private: System::Windows::Forms::Button^ buttonDocPrimite;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonCadruMilitar = (gcnew System::Windows::Forms::Button());
			this->buttonProfesor = (gcnew System::Windows::Forms::Button());
			this->buttonStudent = (gcnew System::Windows::Forms::Button());
			this->btnTEAMS = (gcnew System::Windows::Forms::Button());
			this->buttonDocTrimise = (gcnew System::Windows::Forms::Button());
			this->buttonTrimiteDoc = (gcnew System::Windows::Forms::Button());
			this->buttonDocRespinse = (gcnew System::Windows::Forms::Button());
			this->buttonDocAcceptate = (gcnew System::Windows::Forms::Button());
			this->buttonDocPrimite = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel1->Controls->Add(this->buttonCadruMilitar);
			this->panel1->Controls->Add(this->buttonProfesor);
			this->panel1->Controls->Add(this->buttonStudent);
			this->panel1->Controls->Add(this->btnTEAMS);
			this->panel1->Controls->Add(this->buttonDocTrimise);
			this->panel1->Controls->Add(this->buttonTrimiteDoc);
			this->panel1->Controls->Add(this->buttonDocRespinse);
			this->panel1->Controls->Add(this->buttonDocAcceptate);
			this->panel1->Controls->Add(this->buttonDocPrimite);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(250, 729);
			this->panel1->TabIndex = 0;
			// 
			// buttonCadruMilitar
			// 
			this->buttonCadruMilitar->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonCadruMilitar->FlatAppearance->BorderSize = 0;
			this->buttonCadruMilitar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonCadruMilitar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCadruMilitar->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonCadruMilitar->Location = System::Drawing::Point(0, 462);
			this->buttonCadruMilitar->Name = L"buttonCadruMilitar";
			this->buttonCadruMilitar->Size = System::Drawing::Size(250, 24);
			this->buttonCadruMilitar->TabIndex = 9;
			this->buttonCadruMilitar->Text = L"Cadre Militare";
			this->buttonCadruMilitar->UseVisualStyleBackColor = true;
			this->buttonCadruMilitar->Click += gcnew System::EventHandler(this, &MainForm::buttonCadruMilitar_Click);
			// 
			// buttonProfesor
			// 
			this->buttonProfesor->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonProfesor->FlatAppearance->BorderSize = 0;
			this->buttonProfesor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonProfesor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonProfesor->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonProfesor->Location = System::Drawing::Point(0, 438);
			this->buttonProfesor->Name = L"buttonProfesor";
			this->buttonProfesor->Size = System::Drawing::Size(250, 24);
			this->buttonProfesor->TabIndex = 8;
			this->buttonProfesor->Text = L"Profesori";
			this->buttonProfesor->UseVisualStyleBackColor = true;
			this->buttonProfesor->Click += gcnew System::EventHandler(this, &MainForm::buttonProfesor_Click);
			// 
			// buttonStudent
			// 
			this->buttonStudent->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonStudent->FlatAppearance->BorderSize = 0;
			this->buttonStudent->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStudent->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonStudent->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonStudent->Location = System::Drawing::Point(0, 414);
			this->buttonStudent->Name = L"buttonStudent";
			this->buttonStudent->Size = System::Drawing::Size(250, 24);
			this->buttonStudent->TabIndex = 7;
			this->buttonStudent->Text = L"Studenti";
			this->buttonStudent->UseVisualStyleBackColor = true;
			this->buttonStudent->Click += gcnew System::EventHandler(this, &MainForm::buttonStudent_Click_1);
			// 
			// btnTEAMS
			// 
			this->btnTEAMS->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnTEAMS->FlatAppearance->BorderSize = 0;
			this->btnTEAMS->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTEAMS->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTEAMS->ForeColor = System::Drawing::Color::Gainsboro;
			this->btnTEAMS->Location = System::Drawing::Point(0, 360);
			this->btnTEAMS->Name = L"btnTEAMS";
			this->btnTEAMS->Size = System::Drawing::Size(250, 54);
			this->btnTEAMS->TabIndex = 6;
			this->btnTEAMS->Text = L"TEAMS";
			this->btnTEAMS->UseVisualStyleBackColor = true;
			this->btnTEAMS->Click += gcnew System::EventHandler(this, &MainForm::btnTEAMS_Click);
			// 
			// buttonDocTrimise
			// 
			this->buttonDocTrimise->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonDocTrimise->FlatAppearance->BorderSize = 0;
			this->buttonDocTrimise->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDocTrimise->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDocTrimise->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonDocTrimise->Location = System::Drawing::Point(0, 300);
			this->buttonDocTrimise->Name = L"buttonDocTrimise";
			this->buttonDocTrimise->Size = System::Drawing::Size(250, 60);
			this->buttonDocTrimise->TabIndex = 5;
			this->buttonDocTrimise->Text = L"DOCUMENTE TRIMISE";
			this->buttonDocTrimise->UseVisualStyleBackColor = true;
			this->buttonDocTrimise->Click += gcnew System::EventHandler(this, &MainForm::buttonDocTrimise_Click);
			// 
			// buttonTrimiteDoc
			// 
			this->buttonTrimiteDoc->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->buttonTrimiteDoc->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonTrimiteDoc->FlatAppearance->BorderSize = 0;
			this->buttonTrimiteDoc->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonTrimiteDoc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonTrimiteDoc->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonTrimiteDoc->Location = System::Drawing::Point(0, 669);
			this->buttonTrimiteDoc->Name = L"buttonTrimiteDoc";
			this->buttonTrimiteDoc->Size = System::Drawing::Size(250, 60);
			this->buttonTrimiteDoc->TabIndex = 4;
			this->buttonTrimiteDoc->Text = L"TRIMITE DOCUMENT";
			this->buttonTrimiteDoc->UseVisualStyleBackColor = false;
			this->buttonTrimiteDoc->Click += gcnew System::EventHandler(this, &MainForm::buttonTrimiteDoc_Click);
			// 
			// buttonDocRespinse
			// 
			this->buttonDocRespinse->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonDocRespinse->FlatAppearance->BorderSize = 0;
			this->buttonDocRespinse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDocRespinse->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDocRespinse->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonDocRespinse->Location = System::Drawing::Point(0, 240);
			this->buttonDocRespinse->Name = L"buttonDocRespinse";
			this->buttonDocRespinse->Size = System::Drawing::Size(250, 60);
			this->buttonDocRespinse->TabIndex = 3;
			this->buttonDocRespinse->Text = L"DOCUMENTE RESPINSE";
			this->buttonDocRespinse->UseVisualStyleBackColor = true;
			this->buttonDocRespinse->Click += gcnew System::EventHandler(this, &MainForm::buttonDocRespinse_Click);
			// 
			// buttonDocAcceptate
			// 
			this->buttonDocAcceptate->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonDocAcceptate->FlatAppearance->BorderSize = 0;
			this->buttonDocAcceptate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDocAcceptate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDocAcceptate->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonDocAcceptate->Location = System::Drawing::Point(0, 180);
			this->buttonDocAcceptate->Name = L"buttonDocAcceptate";
			this->buttonDocAcceptate->Size = System::Drawing::Size(250, 60);
			this->buttonDocAcceptate->TabIndex = 2;
			this->buttonDocAcceptate->Text = L"DOCUMENTE ACCEPTATE";
			this->buttonDocAcceptate->UseVisualStyleBackColor = true;
			this->buttonDocAcceptate->Click += gcnew System::EventHandler(this, &MainForm::buttonDocAcceptate_Click);
			// 
			// buttonDocPrimite
			// 
			this->buttonDocPrimite->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonDocPrimite->FlatAppearance->BorderSize = 0;
			this->buttonDocPrimite->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDocPrimite->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDocPrimite->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonDocPrimite->Location = System::Drawing::Point(0, 120);
			this->buttonDocPrimite->Name = L"buttonDocPrimite";
			this->buttonDocPrimite->Size = System::Drawing::Size(250, 60);
			this->buttonDocPrimite->TabIndex = 1;
			this->buttonDocPrimite->Text = L"DOCUMENTE PRIMITE";
			this->buttonDocPrimite->UseVisualStyleBackColor = true;
			this->buttonDocPrimite->Click += gcnew System::EventHandler(this, &MainForm::buttonDocPrimite_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(250, 120);
			this->panel2->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-3, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(250, 100);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->panel5);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(250, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1100, 729);
			this->panel3->TabIndex = 1;
			// 
			// panel5
			// 
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(0, 120);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(1100, 609);
			this->panel5->TabIndex = 1;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->panel4->Controls->Add(this->panel7);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Controls->Add(this->panel6);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1100, 120);
			this->panel4->TabIndex = 0;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->button3);
			this->panel7->Controls->Add(this->button1);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel7->Location = System::Drawing::Point(781, 0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(133, 120);
			this->panel7->TabIndex = 8;
			// 
			// button3
			// 
			this->button3->Dock = System::Windows::Forms::DockStyle::Top;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Gainsboro;
			this->button3->Location = System::Drawing::Point(0, 60);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(133, 60);
			this->button3->TabIndex = 7;
			this->button3->Text = L"DECONECTARE";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Gainsboro;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 60);
			this->button1->TabIndex = 6;
			this->button1->Text = L"SETARI";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(19, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ACASA";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->button2);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel6->Location = System::Drawing::Point(914, 0);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(186, 120);
			this->panel6->TabIndex = 7;
			// 
			// button2
			// 
			this->button2->Dock = System::Windows::Forms::DockStyle::Right;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Gainsboro;
			this->button2->Location = System::Drawing::Point(-2, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(188, 120);
			this->button2->TabIndex = 6;
			this->button2->Text = L"USERNAME";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1350, 729);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"ANDDMS";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	//
	//FUNCTIE PENTRU CHILD-URILE FERESTREI PRINCIPALE DIN PANEL5
	//
	private: System::Void OpenChildForm(System::Windows::Forms::Form^ childForm, System::Object^ sender)
	{
		childForm->TopLevel = false;
		this->panel5->Controls->Add(childForm);
		this->panel5->Tag = childForm;
		childForm->AutoScroll = true;
		childForm->Dock = DockStyle::Fill;
		childForm->BringToFront();
		childForm->Show();
	}

	//
	//INSTRUCTIUNI PENTRU LOAD-UL FERESTREI PRINCIPALE
	//
	private:System::Void UpdateUsername(System::Object^ sender, System::EventArgs^ e) {
		String^ userNew = gcnew String(clientul->c->getUsername().c_str());
		clientul->c->getPassword().c_str();
		this->button2->Text = userNew;
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		UpdateUsername(sender, e);
		this->panel7->Hide();
		this->buttonStudent->Hide();
		this->buttonProfesor->Hide();
		this->buttonCadruMilitar->Hide();
	}

	//
	//BUTOANE PENTRU SECT CU DOCUMENTE
	//
	private: System::Void buttonDocPrimite_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->panel5->Controls->Count > 0)
		{
			delete this->panel5->Controls[0];
		}
		clientul->c->F_SEMNAL_PRIMIRE_DOC_PRIMITE();

		docPrimiteForm = gcnew ANDDMSCLIENT::DocPrimiteForm(clientul);
		label1->Text = "DOCUMENTE PRIMITE";
		OpenChildForm(docPrimiteForm,sender);
	}

	private: System::Void buttonDocAcceptate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->panel5->Controls->Count > 0)
		{
			delete this->panel5->Controls[0];
		}
		clientul->c->F_SEMNAL_PRIMIRE_DOC_ACCEPTATE();

		docAcceptateForm = gcnew ANDDMSCLIENT::DocAcceptateForm(clientul);
		label1->Text = "DOCUMENTE ACCEPTATE";
		OpenChildForm(docAcceptateForm, sender);
	}

	private: System::Void buttonDocRespinse_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->panel5->Controls->Count > 0)
		{
			delete this->panel5->Controls[0];
		}
		clientul->c->F_SEMNAL_PRIMIRE_DOC_RESPINSE();

		docRespinseForm = gcnew ANDDMSCLIENT::DocRespinseForm(clientul);
		label1->Text = "DOCUMENTE RESPINSE";
		OpenChildForm(docRespinseForm, sender);
	}

	private: System::Void buttonDocTrimise_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->panel5->Controls->Count > 0)
		{
			delete this->panel5->Controls[0];
		}
		clientul->c->F_SEMNAL_PRIMIRE_DOC_TRIMISE();
		docTrimiseForm = gcnew ANDDMSCLIENT::DocTrimiseForm(clientul);
		label1->Text = "DOCUMENTE TRIMISE";
		OpenChildForm(docTrimiseForm, sender);
	}
	private: System::Void buttonTrimiteDoc_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->panel5->Controls->Count > 0)
		{
			delete this->panel5->Controls[0];
		}
		trimiteForm = gcnew ANDDMSCLIENT::TrimiteForm(clientul);
		label1->Text = "TRIMITE DOCUMENT";
		OpenChildForm(trimiteForm, sender);
	}
	private: System::Void buttonStudent_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (this->panel5->Controls->Count > 0)
		{
			delete this->panel5->Controls[0];
		}
		tStudentForm = gcnew ANDDMSCLIENT::T_Studenti(clientul);
		label1->Text = "TEAM - STUDENT";
		OpenChildForm(tStudentForm, sender);
	}
	private: System::Void buttonProfesor_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->panel5->Controls->Count > 0)
		{
			delete this->panel5->Controls[0];
		}
		tProfesorForm = gcnew ANDDMSCLIENT::T_Profesori(clientul);
		label1->Text = "TEAM - PROFESOR";
		OpenChildForm(tProfesorForm, sender);
	}
	private: System::Void buttonCadruMilitar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->panel5->Controls->Count > 0)
		{
			delete this->panel5->Controls[0];
		}
		tCadruMilitarForm = gcnew ANDDMSCLIENT::T_CadreMilitare(clientul);
		label1->Text = "TEAM - CADRU MILITAR";
		OpenChildForm(tCadruMilitarForm, sender);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->panel5->Controls->Count > 0)
		{
			delete this->panel5->Controls[0];
		}
		SetariForm = gcnew ANDDMSCLIENT::SETARI(clientul);
		label1->Text = "SETARI";
		OpenChildForm(SetariForm, sender);
	}
	
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (flag == true)
		{
			this->panel7->Show();
			flag = false;
		}
		else
		{
			this->panel7->Hide();
			flag = true;
		}
	}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//clientul->newform = 0;
	//clientul->noform = 0;
	clientul->continua = true;
	clientul->c->F_DECONECTARE();
	this->Hide();
	obj_->Show();
}
private: System::Void btnTEAMS_Click(System::Object^ sender, System::EventArgs^ e) {
	if (flagTeams == true)
	{
		this->buttonStudent->Show();
		this->buttonProfesor->Show();
		this->buttonCadruMilitar->Show();
		flagTeams = false;
	}
	else
	{
		this->buttonStudent->Hide();
		this->buttonProfesor->Hide();
		this->buttonCadruMilitar->Hide();
		flagTeams = true;
	}
}



};
}
