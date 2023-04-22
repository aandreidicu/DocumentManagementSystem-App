#pragma once
#include "CClient.h"

namespace ANDDMSCLIENT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DocRespinseForm
	/// </summary>
	public ref class T_CadreMilitare : public System::Windows::Forms::Form
	{
	public:
		Pachet^ clientul;
		T_CadreMilitare(Pachet^ c)
		{
			clientul = c;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public: Mutex^ mtx = gcnew Mutex;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~T_CadreMilitare()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(451, 233);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(146, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TEAM-CADRU MILITAR";
			// 
			// T_CadreMilitare
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1084, 570);
			this->ControlBox = false;
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"T_CadreMilitare";
			this->ShowInTaskbar = false;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
