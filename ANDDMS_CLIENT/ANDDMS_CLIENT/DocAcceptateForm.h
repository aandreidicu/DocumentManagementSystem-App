#pragma once

#include "CClient.h"
#include "CDocACCEPTATE.h"
#include <iostream>
#include <list>
#include <vector>
#include <msclr\marshal_cppstd.h>

namespace ANDDMSCLIENT {

	using namespace System;
	using namespace msclr::interop;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Media;
	using namespace System::Text;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// Summary for DocAcceptateForm
	/// </summary>
	public ref class DocAcceptateForm : public System::Windows::Forms::Form
	{
	public:
		Pachet^ clientul;
		DocAcceptateForm(Pachet^ c)
		{
			clientul = c;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	public:


	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TITLU;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DATA;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ORA;
	private: System::Windows::Forms::DataGridViewButtonColumn^ DESCARCA;

	public: Mutex^ mtx = gcnew Mutex;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DocAcceptateForm()
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->TITLU = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DATA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ORA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DESCARCA = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeight = 40;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->TITLU,
					this->ID, this->DATA, this->ORA, this->DESCARCA
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(0, 32);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->RowHeadersVisible = false;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(1084, 538);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DocAcceptateForm::dataGridView1_CellClick_1);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DocAcceptateForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DocAcceptateForm::dataGridView1_CellDoubleClick_1);
			// 
			// TITLU
			// 
			this->TITLU->HeaderText = L"TITLU";
			this->TITLU->Name = L"TITLU";
			this->TITLU->ReadOnly = true;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			this->ID->Visible = false;
			// 
			// DATA
			// 
			this->DATA->HeaderText = L"DATA";
			this->DATA->Name = L"DATA";
			this->DATA->ReadOnly = true;
			// 
			// ORA
			// 
			this->ORA->HeaderText = L"ORA";
			this->ORA->Name = L"ORA";
			this->ORA->ReadOnly = true;
			// 
			// DESCARCA
			// 
			this->DESCARCA->HeaderText = L"DESCARCA";
			this->DESCARCA->Name = L"DESCARCA";
			this->DESCARCA->ReadOnly = true;
			this->DESCARCA->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1084, 32);
			this->panel2->TabIndex = 5;
			// 
			// DocAcceptateForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1084, 570);
			this->ControlBox = false;
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"DocAcceptateForm";
			this->ShowInTaskbar = false;
			this->Load += gcnew System::EventHandler(this, &DocAcceptateForm::DocAcceptateForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DocAcceptateForm_Load(System::Object^ sender, System::EventArgs^ e) {
		for (std::list<CDocument>::iterator i = clientul->c->get_docAcceptate()->get_docAcc()->begin(); i != clientul->c->get_docAcceptate()->get_docAcc()->end(); i++)
		{
			String^ ids;
			ids = marshal_as<String^>(i->id);
			String^ titlus;
			titlus = marshal_as<String^>(i->titlu);
			String^ expeditors;
			expeditors = marshal_as<String^>(i->expeditor);
			String^ destinatars;
			destinatars = marshal_as<String^>(i->destinatar);
			String^ datas;
			datas = marshal_as<String^>(i->data);
			String^ oras;
			oras = marshal_as<String^>(i->ora);

			this->dataGridView1->Rows->Add(titlus, ids, datas, oras);
		}
	}

	private: System::Void dataGridView1_CellClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		auto item = this->dataGridView1->Rows[e->RowIndex]->Cells[1]->Value;
		auto idSys = item->ToString();
		std::string id = marshal_as<std::string>(idSys);

		clientul->c->F_SEMNAL_AFISEAZA_CONTINUT_DOCUMENT(id);
	}
	private: System::Void dataGridView1_CellDoubleClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		auto item = this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value;
		auto titluSys = item->ToString();
		std::string titlu = marshal_as<std::string>(titluSys);

		auto item2 = this->dataGridView1->Rows[e->RowIndex]->Cells[1]->Value;
		auto idSys = item2->ToString();
		std::string id = marshal_as<std::string>(idSys);

		if (clientul->flagafis == true && clientul->c->get_afisProv() != "") {
			String^ cont;
			cont = marshal_as<String^>(clientul->c->get_afisProv());

			MessageBox::Show(cont);
		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->ColumnIndex == 4)
		{
			auto item = this->dataGridView1->Rows[e->RowIndex]->Cells[1]->Value;
			auto idSys = item->ToString();
			std::string id = marshal_as<std::string>(idSys);

			clientul->c->F_SEMNAL_AFISEAZA_CONTINUT_DOCUMENT(id);
			//String^ cont;
			//cont = marshal_as<String^>(clientul->c->get_afisProv());
			clientul->c->string_to_doc(clientul->c->get_afisProv());
		}
	}
	};
}
