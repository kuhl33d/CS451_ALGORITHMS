#pragma once
#include "Form1.h"
#include "Form3.h"
#include "Form4.h"
#include"Algorithms.h"

namespace project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;

	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->BackColor = Color::FromArgb(30, 30, 30);
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			this->button4->Click += gcnew System::EventHandler(this, &Form2::button4_Click);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button4;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Lime;
			this->button1->Location = System::Drawing::Point(12, 46);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(385, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"page replacement (1)";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(12, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(133, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"FIFO, LRU, OPTIMAL";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(12, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(276, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"FCFS, SSTF, SCAN, C-SCAN, LOOK, C-LOOK";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Black;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::Color::Lime;
			this->button2->Location = System::Drawing::Point(12, 149);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(385, 52);
			this->button2->TabIndex = 2;
			this->button2->Text = L"disk scheduling";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Black;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->ForeColor = System::Drawing::Color::Lime;
			this->button3->Location = System::Drawing::Point(12, 355);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(385, 52);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(12, 218);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Additional Bit";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Black;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->ForeColor = System::Drawing::Color::Lime;
			this->button4->Location = System::Drawing::Point(12, 237);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(385, 52);
			this->button4->TabIndex = 5;
			this->button4->Text = L"page replacement (2)";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(409, 419);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(427, 466);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(427, 466);
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdvanceOS_Project";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form ^F = gcnew project::Form1();
		F->Show();
		//F->ShowDialog();	
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ F = gcnew project::Form3();
		F->Show();
		//F->ShowDialog();	
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ F = gcnew project::Form4();
		F->Show();
		//F->ShowDialog();	
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
