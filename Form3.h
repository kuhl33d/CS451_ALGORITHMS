#pragma once
#include "Algorithms.h"
namespace project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	/// <summary>
	/// Summary for Form3
	/// </summary>
enum Algo
{
	NONE,
	FCFS,
	SSTF,
	SCAN,
	CSCAN,
	LOOK,
	CLOOK
};
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		Form3(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &project::Form3::OnLoad);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &project::Form3::OnPaint);
			this->button1->Click += gcnew System::EventHandler(this, &project::Form3::button1_Click);
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &project::Form3::OnValueChanged1);
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &project::Form3::OnValueChanged2);
			T->Tick += gcnew System::EventHandler(this, &project::Form3::OnTick);
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form3::textBox1_TextChanged);
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &project::Form3::OnCheckedChanged);
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &project::Form3::OnCheckedChanged);
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &project::Form3::OnCheckedChanged);
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &project::Form3::OnCheckedChanged);
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &project::Form3::OnCheckedChanged);
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &project::Form3::OnCheckedChanged);
			this->dirButton1->CheckedChanged += gcnew System::EventHandler(this, &project::Form3::OnCheckedChanged2);
			this->dirButton2->CheckedChanged += gcnew System::EventHandler(this, &project::Form3::OnCheckedChanged2);
		}
	protected:
		~Form3()
		{
			T->Stop();
			if (components)
			{
				delete components;
			}
			delete seq;
			delete parsed;
			if (bg != nullptr)
				delete bg;
			delete T;
		}
	private:
		Bitmap^ bg;
		int head_intial = 0;
		int max = 199;
		List<String^>^ parsed = gcnew List<String^>();
		List<int>^ seq = gcnew List<int>();
		Timer^ T = gcnew Timer();
		bool flash = false;
		int flash_cnt=0;
		int curr = -1;
		StringFormat^ stringFormat = gcnew StringFormat();
		Rectangle^ drawable;
		char dir = ' ';//l left r right 
		Algo choice = NONE;
		bool solve = false;
		stack<line>* sol = nullptr;
		//stack<int>* sequnce = new stack<int>();
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::TextBox^ textBox2;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::RichTextBox^ richTextBox1;
		private: System::Windows::Forms::GroupBox^ groupBox1;
		private: System::Windows::Forms::RadioButton^ radioButton1;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
		private: System::Windows::Forms::GroupBox^ groupBox2;
		private: System::Windows::Forms::RadioButton^ dirButton2;
		private: System::Windows::Forms::RadioButton^ dirButton1;
		private: System::Windows::Forms::RadioButton^ radioButton6;
		private: System::Windows::Forms::RadioButton^ radioButton5;
		private: System::Windows::Forms::RadioButton^ radioButton4;
		private: System::Windows::Forms::RadioButton^ radioButton3;
		private: System::Windows::Forms::RadioButton^ radioButton2;
		private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
		private: System::Windows::Forms::Label^ label4;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dirButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->dirButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"head intial:";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->ForeColor = System::Drawing::Color::Lime;
			this->textBox1->Location = System::Drawing::Point(12, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(71, 15);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Black;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->ForeColor = System::Drawing::Color::Lime;
			this->textBox2->Location = System::Drawing::Point(128, 28);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(758, 15);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(128, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"queue:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->BackColor = System::Drawing::Color::Black;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->ForeColor = System::Drawing::Color::Lime;
			this->richTextBox1->Location = System::Drawing::Point(1155, 9);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(199, 508);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->radioButton6);
			this->groupBox1->Controls->Add(this->radioButton5);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->ForeColor = System::Drawing::Color::Lime;
			this->groupBox1->Location = System::Drawing::Point(15, 49);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(299, 94);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"algorithms";
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(210, 62);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(76, 20);
			this->radioButton6->TabIndex = 13;
			this->radioButton6->Text = L"C-LOOK";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(209, 15);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(63, 20);
			this->radioButton5->TabIndex = 10;
			this->radioButton5->Text = L"LOOK";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(113, 62);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(78, 20);
			this->radioButton4->TabIndex = 12;
			this->radioButton4->Text = L"C-SCAN";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(113, 15);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(65, 20);
			this->radioButton3->TabIndex = 11;
			this->radioButton3->Text = L"SCAN";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 62);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(63, 20);
			this->radioButton2->TabIndex = 10;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"SSTF";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 21);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(62, 20);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->Text = L"FCFS";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Lime;
			this->button1->Location = System::Drawing::Point(892, 28);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 115);
			this->button1->TabIndex = 6;
			this->button1->Text = L"apply";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(973, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"max:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::Color::Black;
			this->numericUpDown1->ForeColor = System::Drawing::Color::Lime;
			this->numericUpDown1->Location = System::Drawing::Point(973, 28);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 199, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(78, 22);
			this->numericUpDown1->TabIndex = 8;
			this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 199, 0, 0, 0 });
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox2->Controls->Add(this->dirButton2);
			this->groupBox2->Controls->Add(this->dirButton1);
			this->groupBox2->ForeColor = System::Drawing::Color::Lime;
			this->groupBox2->Location = System::Drawing::Point(710, 49);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(176, 94);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"location";
			// 
			// dirButton2
			// 
			this->dirButton2->AutoSize = true;
			this->dirButton2->Location = System::Drawing::Point(6, 47);
			this->dirButton2->Name = L"dirButton2";
			this->dirButton2->Size = System::Drawing::Size(53, 20);
			this->dirButton2->TabIndex = 1;
			this->dirButton2->TabStop = true;
			this->dirButton2->Text = L"right";
			this->dirButton2->UseVisualStyleBackColor = true;
			// 
			// dirButton1
			// 
			this->dirButton1->AutoSize = true;
			this->dirButton1->Location = System::Drawing::Point(6, 21);
			this->dirButton1->Name = L"dirButton1";
			this->dirButton1->Size = System::Drawing::Size(45, 20);
			this->dirButton1->TabIndex = 0;
			this->dirButton1->TabStop = true;
			this->dirButton1->Text = L"left";
			this->dirButton1->UseVisualStyleBackColor = true;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->BackColor = System::Drawing::Color::Black;
			this->numericUpDown2->ForeColor = System::Drawing::Color::Lime;
			this->numericUpDown2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown2->Location = System::Drawing::Point(973, 121);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(119, 22);
			this->numericUpDown2->TabIndex = 15;
			this->numericUpDown2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Lime;
			this->label4->Location = System::Drawing::Point(970, 101);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 16);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Interval";
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1366, 529);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Form3";
			this->Text = L"disk scheduling";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ numeric(String^ S) {
			String^ tmp = "";
			for (int i = 0; i < S->Length; i++) {
				if (S[i] >= '0' && S[i]<= '9') {
					tmp += S[i];
				}
			}
			return tmp;
		}
		String^ trim(String^ S, char del) {
			String^ S2 = "";
			for (int i = 0; i < S->Length; i++) {
				if (S[i] != del) {
					S2 += S[i];
				}
			}
			return S2;
		}
		String^ replace(String^ S, char old, char n) {
			String^ S2 = "";
			for (int i = 0; i < S->Length; i++) {
				if (S[i] != old) {
					S2 += S[i];
				}
				else {
					S2 += (Char)(n);
				}
			}
			return S2;
		}
		void parse(List<String^>^ list, String^ S, char dele) {
			String^ tmp = " ";
			for (int i = 0; i < S->Length; i++) {
				if (S[i] != dele) {
					tmp += S[i];
				}
				else {
					list->Add(tmp);
					tmp = "";
				}
			}
			if (S->Length != 0 && S[S->Length - 1] != ',') {//handle last comma 
				list->Add(tmp);
			}
		}
		void str_int(List<String^>^ l1, List<int>^ l2) {
			for (int i = 0; i < l1->Count; i++) {
				int x = int::Parse(l1[i]);
				l2->Add(x);
			}
		}
		void OnLoad(System::Object^ sender, System::EventArgs^ e) {
			groupBox2->Visible = false;
			textBox1->Text = "0";
			stringFormat->Alignment = StringAlignment::Center;
			stringFormat->LineAlignment = StringAlignment::Center;
			bg = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
			this->WindowState = FormWindowState::Maximized;
			this->BackColor = Color::FromArgb(30, 30, 30);
			/*richTextBox1->Width = ClientSize.Width / 10;
			richTextBox1->Height = ClientSize.Height - Height - label1->Location.Y * 2;
			richTextBox1->Location = Point(ClientSize.Width - richTextBox1->Width,label1->Location.Y);*/
			T->Start();
		}
		void OnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e){
			delete bg;

			if (this->ClientSize.Width != 0 && this->ClientSize.Height != 0) {
				bg = gcnew Bitmap(this->ClientSize.Width, this->ClientSize.Height);
			}
			draw(e->Graphics);
		}
		void draw(Graphics^ G) {
			if (bg != nullptr) {
				buffer(Graphics::FromImage(bg));
				G->DrawImage(bg, 0, 0);
			}
			delete G;
		}
		void buffer(Graphics ^g) {
			g->Clear(this->BackColor);
			drawable = gcnew Rectangle(
				groupBox1->Location.X + (ClientSize.Width/10),
				groupBox1->Location.Y+groupBox1->Height + 10,
				richTextBox1->Location.X-groupBox1->Location.X - ClientSize.Width/10 - ClientSize.Width / 10,
				(richTextBox1->Location.Y+richTextBox1->Height)-(groupBox1->Location.Y + groupBox1->Height)
			);
			
			Rectangle^ H = gcnew Rectangle(
				drawable->X + (int) (((float)head_intial) * (drawable->Width / ((float)max)) ),
				drawable->Y,
				drawable->Width / (max / 5),
				drawable->Height / 20);
			g->DrawRectangle(gcnew Pen((curr == -1) ? (Color::Lime) : (Color::White), 2), H->X - H->Width / 2, H->Y, H->Width, H->Height);
			g->DrawLine(gcnew Pen((curr==-1)?(Color::Lime):(Color::White), 2), H->X, H->Y + H->Height, H->X, drawable->Y + drawable->Height);
			{
				SizeF^ s = g->MeasureString(head_intial+"", this->Font);
				float font_scale = System::Math::Max(s->Width / H->Width, s->Height / H->Height);
				System::Drawing::Font^ F = gcnew System::Drawing::Font(this->Font->FontFamily, this->Font->SizeInPoints / font_scale, GraphicsUnit::Point);
				g->DrawString(head_intial+"", F, gcnew SolidBrush((curr == -1) ? (Color::Lime) : (Color::White)), *(gcnew Rectangle(H->X - H->Width / 2, H->Y, H->Width, H->Height)), stringFormat);
			}
			Rectangle^ L = gcnew Rectangle(
				drawable->X + (int)(((float)0) * (drawable->Width / ((float)max))),
				drawable->Y,
				drawable->Width / (max / 5),
				drawable->Height / 20);
			g->DrawRectangle(gcnew Pen((curr == -1) ? (Color::Lime) : (Color::White), 2), L->X - L->Width / 2, L->Y, L->Width, L->Height);
			g->DrawLine(gcnew Pen((curr == -1) ? (Color::Lime) : (Color::White), 2), L->X, L->Y + L->Height, L->X, drawable->Y + drawable->Height);
			{
				SizeF^ s = g->MeasureString(0 + "", this->Font);
				float font_scale = System::Math::Max(s->Width / L->Width, s->Height / L->Height);
				System::Drawing::Font^ F = gcnew System::Drawing::Font(this->Font->FontFamily, this->Font->SizeInPoints / font_scale, GraphicsUnit::Point);
				g->DrawString(0 + "", F, gcnew SolidBrush((curr == -1) ? (Color::Lime) : (Color::White)), *(gcnew Rectangle(L->X - L->Width / 2, L->Y, L->Width, L->Height)), stringFormat);
			}
			Rectangle^ M = gcnew Rectangle(
				drawable->X + (int)(((float)max) * (drawable->Width / ((float)max))),
				drawable->Y,
				drawable->Width / (max / 5),
				drawable->Height / 20);
			g->DrawRectangle(gcnew Pen((curr == -1) ? (Color::Lime) : (Color::White), 2), M->X - M->Width / 2, M->Y, M->Width, M->Height);
			g->DrawLine(gcnew Pen((curr == -1) ? (Color::Lime) : (Color::White), 2), M->X, M->Y + M->Height, M->X, drawable->Y + drawable->Height);
			{
				SizeF^ s = g->MeasureString(max + "", this->Font);
				float font_scale = System::Math::Max(s->Width / M->Width, s->Height / M->Height);
				System::Drawing::Font^ F = gcnew System::Drawing::Font(this->Font->FontFamily, this->Font->SizeInPoints / font_scale, GraphicsUnit::Point);
				g->DrawString(max + "", F, gcnew SolidBrush((curr == -1) ? (Color::Lime) : (Color::White)), *(gcnew Rectangle(M->X - M->Width / 2, M->Y, M->Width, M->Height)), stringFormat);
			}
			//g->FillRectangle(Brushes::Gray, *drawable);
			for (int i = 0; i < seq->Count; i++) {
				
				Rectangle^ element = gcnew Rectangle(
					drawable->X + (int)(((float)seq[i]) * (drawable->Width / ((float)max))),
					drawable->Y,
					drawable->Width/(max/5),
					drawable->Height/20);
				g->DrawRectangle(gcnew Pen((curr == i) ? (Color::Lime) : (Color::White), 2), element->X-element->Width/2,element->Y,element->Width,element->Height);
				g->DrawLine(gcnew Pen((curr == i) ? (Color::Lime) : (Color::White), 2), element->X, element->Y + element->Height, element->X, drawable->Y + drawable->Height);
				{
				SizeF^ s = g->MeasureString(seq[i]+"", this->Font);
					float font_scale = System::Math::Max(s->Width / element->Width, s->Height / element->Height);
					System::Drawing::Font^ F = gcnew System::Drawing::Font(this->Font->FontFamily, this->Font->SizeInPoints / font_scale, GraphicsUnit::Point);
					g->DrawString(seq[i] + "", F, gcnew SolidBrush((curr == i) ? (Color::Lime) : (Color::White)), *(gcnew Rectangle(element->X - element->Width / 2, element->Y, element->Width, element->Height)), stringFormat);
				}
			}
			//draw lines
			/*if (test != nullptr) {
				test->draw_line(drawable->X,drawable->Y, drawable->X+drawable->Width, drawable->Y+drawable->Height,g);
			}*/
			if (sol != nullptr) {
				node<line>* t = sol->head;
				float space = (drawable->Height - drawable->Height / 20.0f)/(float)sol->size;
				float tmp = drawable->Y + drawable->Height / 20.0f;
				while (t != nullptr) {
					float xs = drawable->X + ( t->data->from * ( drawable->Width / ((float)max)) );
					float xe = drawable->X + (t->data->to * (drawable->Width / ((float)max)) );
					t->data->draw_line(
						xs,
						tmp,
						xe,
						tmp+space,
						g);
					if (t->data->reach == false) {
						break;
					}
					tmp += space;

					t = t->nxt;
				}
			}
			delete g;
		}
		
		void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			if (choice == NONE) {
				richTextBox1->Text += "please choose algorithm!!!\n";
				return;
			}
			else {
				if (choice != FCFS && choice != SSTF) {
					if (dir == ' ') {
						richTextBox1->Text += "please choose direction!!!\n";
						return;
					}
				}
			}
			parsed->Clear();
			seq->Clear();
			
			if (this->textBox1->Text->Length == 0) {
				richTextBox1->Text += "invalid intial head\n";
				flash = true;
				return;
			}
			head_intial = int::Parse(textBox1->Text);
			this->textBox2->Text = trim(this->textBox2->Text, ' ');
			parse(parsed, textBox2->Text, ',');
			str_int(parsed, seq);
			if (choice != FCFS) {
				seq->Sort();
			}
			richTextBox1->Text += "head: " + head_intial + "\n";
			richTextBox1->Text += "applying: {" + seq->Count + "} : " + replace(this->textBox2->Text, ',', ' ')+"\n";
			solve = true;
		}
		void OnCheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			choice = NONE;
			if (radioButton1->Checked == true) {
				groupBox2->Visible = false;
				richTextBox1->Text += "selected: FCFS\nenter stream: n1,n2,...\n";
				choice = FCFS;
			}
			else if (radioButton2->Checked == true) {
				richTextBox1->Text += "selected: SSTF\nenter stream: n1,n2,...\n";
				choice = SSTF;
			}
			else {
				groupBox2->Visible = true;
				if (radioButton3->Checked == true) {
					richTextBox1->Text += "selected: SSTF\nenter stream: n1,n2,...\n";
					choice = SCAN;
				}
				else if (radioButton4->Checked == true) {
					richTextBox1->Text += "selected: C-SCAN\nenter stream: n1,n2,...\n";
					choice = CSCAN;
				}
				else if (radioButton5->Checked == true) {
					richTextBox1->Text += "selected: C-SCAN\nenter stream: n1,n2,...\n";
					choice = LOOK;
				}
				else if (radioButton6->Checked == true) {
					richTextBox1->Text += "selected: C-LOOK\nenter stream: n1,n2,...\n";
					choice = CLOOK;
				}
			}
		}
		void OnCheckedChanged2(System::Object^ sender, System::EventArgs^ e) {
			if (dirButton1->Checked == true) {
				dir = 'l';
				richTextBox1->Text += "direction: left\n";
			}
			else if (dirButton2->Checked == true) {
				dir = 'r';
				richTextBox1->Text += "direction: right\n";
			}
			else {
				dir = ' ';
				richTextBox1->Text += "direction: invalid!!!\n";
			}
		}
		void OnValueChanged1(System::Object^ sender, System::EventArgs^ e) {
			max = (int)this->numericUpDown1->Value;
		}
		void OnValueChanged2(System::Object^ sender, System::EventArgs^ e) {
			//max = (int)this->numericUpDown1->Value;
			T->Stop();
			T->Interval = (int)this->numericUpDown2->Value;
			T->Start();
		}
		void OnTick(System::Object^ sender, System::EventArgs^ e) {
			if (flash) {
				
				switch (flash_cnt) {
				/*case 0:
					richTextBox1->Text += "flash start\n";
					break;*/
				case 2:
					label1->BackColor = Color::Red;
					break;
				case 5:
					label1->BackColor = Color::Transparent;
					break;
				case 8:
					label1->BackColor = Color::Red;
					break;
				case 10:
					//richTextBox1->Text += "flash end\n";
					label1->BackColor = Color::Transparent;
					flash_cnt = -1;
					flash = false;
				}
				flash_cnt++;
			}
			if (solve) {
				if (sol != nullptr)
					delete sol;
				sol = new stack<line>();
				switch (choice) {
				case FCFS:
					doFCFS(sol, seq, head_intial);
					break;
				case SSTF:
					doSSTF(sol, seq, head_intial);
					break;
				case SCAN:
					doSCAN(sol, seq, head_intial, dir);
					break;
				case CSCAN:
					doCSCAN(sol, seq, head_intial, dir);
					break;
				case LOOK:
					doLOOK(sol, seq, head_intial, dir);
					break;
				case CLOOK:
					doCLOOK(sol, seq, head_intial, dir);
					break;
				}

				
				int sols = 0;
				node<line>* trav = sol->head;
				while (trav != nullptr) {
					richTextBox1->Text += trav->data->from + " -> ";
					richTextBox1->Text += trav->data->to + " : ";
					richTextBox1->Text += trav->data->solution + "\n";
					sols += trav->data->solution;
					trav = trav->nxt;
				}
				richTextBox1->Text += "total: " + sols + "\n";
				solve = false;
			}

			if (sol != nullptr) {
				node<line>* t = sol->head;
				while (t != nullptr) {
					if (t->data->reach == false) {
						t->data->curr += 0.1f;//update for fast speed
						break;
					}
					t = t->nxt;
				}
			}
			draw(this->CreateGraphics());
		}
		void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			this->textBox1->Text = numeric(this->textBox1->Text);
			if (this->textBox1->Text != "") {
				head_intial = int::Parse(this->textBox1->Text);
				if (head_intial > max)
					head_intial = max;
			}
			else {
				head_intial = 0;
			}
		}
		void doFCFS(stack<line>* sol, List<int>^ seq, int head_intial) {
			node<line>* pnn = new node<line>();
			pnn->data->intial = true;
			pnn->data->from = head_intial;
			pnn->data->to = seq[0];
			pnn->data->solution = System::Math::Abs(head_intial - seq[0]);
			sol->push(pnn);
			for (int i = 0; i < seq->Count - 1; i++) {
				pnn = new node<line>();
				pnn->data->from = seq[i];
				pnn->data->to = seq[i + 1];
				pnn->data->solution = System::Math::Abs(seq[i] - seq[i + 1]);
				sol->push(pnn);
			}
		}
		void doSSTF(stack<line>* sol, List<int>^ seq1, int head_intial) {
			List<int>^ seq = gcnew List<int>();
			for (int i = 0; i < seq1->Count; i++) {
				seq->Add(seq1[i]);
			}
			int min = max;
			int pos = -1;
			int tmp;
			for (int i = 0; i < seq->Count; i++) {
				if (Math::Abs(head_intial - seq[i]) < min) {
					min = Math::Abs(head_intial - seq[i]);
					pos = i;
				}
			}
			node<line>* pnn = new node<line>();
			pnn->data->intial = true;
			pnn->data->from = head_intial;
			pnn->data->to = seq[pos];
			pnn->data->solution = Math::Abs(head_intial - seq[pos]);
			sol->push(pnn);
			tmp = seq[pos];
			seq->RemoveAt(pos);
			while (seq->Count != 0) {
				min = max;
				pos = -1;
				for (int i = 0; i < seq->Count; i++) {
					if (Math::Abs(tmp - seq[i]) < min) {
						min = Math::Abs(tmp - seq[i]);
						pos = i;
					}
				}
				pnn = new node<line>();
				pnn->data->from = tmp;
				pnn->data->to = seq[pos];
				pnn->data->solution = Math::Abs(tmp - seq[pos]);
				sol->push(pnn);
				tmp = seq[pos];
				seq->RemoveAt(pos);
			}
		}
		void doSCAN(stack<line>* sol, List<int>^ seq1, int head_intial,char d) {
			List<int>^ seq = gcnew List<int>();
			for (int i = 0; i < seq1->Count; i++) {
				seq->Add(seq1[i]);
			}
			//find head 0 frame
			bool found = false;
			for (int i = 0; i < seq->Count; i++) {
				if (seq[i] == head_intial) {
					found = true;
					break;
				}
			}
			node<line>* pnn;
			if (found) {
				pnn = new node<line>();
				pnn->data->from = head_intial;
				pnn->data->to = head_intial;
				pnn->data->intial = true;
				pnn->data->solution = 0;
				sol->push(pnn);
			}
			else {
				seq->Add(head_intial);
				seq->Sort();
				if (seq[seq->Count - 1] != max) {
					seq->Add(max);
					seq->Sort();
				}
				if (seq[0] != 0) {
					seq->Add(0);
					seq->Sort();
				}
			}
			//find head location
			int pos = -1;
			for (int i = 0; i < seq->Count; i++) {
				if (seq[i] == head_intial) {
					pos = i;
					break;
				}
			}
			if (pos == -1) {
				richTextBox1->Text += "error head not found!!!\n";
				return;
			}
			
			if (d == 'l') {
				for (int i = pos; i > 0; i--) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i-1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i - 1]);
					sol->push(pnn);
				}
				pnn = new node<line>();
				pnn->data->from = seq[0];
				pnn->data->to = seq[pos+1];
				pnn->data->solution = Math::Abs(seq[pos+1] - seq[0]);
				sol->push(pnn);
				for (int i = pos + 1; i < seq->Count-1; i++) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i + 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i + 1]);
					sol->push(pnn);
				}
			}
			else if (d == 'r') {
				for (int i = pos; i < seq->Count-1; i++) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i + 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i + 1]);
					sol->push(pnn);
				}
				pnn = new node<line>();
				pnn->data->from = seq[seq->Count-1];
				pnn->data->to = seq[pos - 1];
				pnn->data->solution = Math::Abs(seq[seq->Count-1] - seq[pos-1]);
				sol->push(pnn);
				for (int i = pos - 1; i > 0; i--) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i - 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i - 1]);
					sol->push(pnn);
				}
			}
			
		}
		void doCSCAN(stack<line>* sol, List<int>^ seq1, int head_intial, char d) {
			List<int>^ seq = gcnew List<int>();
			for (int i = 0; i < seq1->Count; i++) {
				seq->Add(seq1[i]);
			}
			//find head 0 frame
			bool found = false;
			for (int i = 0; i < seq->Count; i++) {
				if (seq[i] == head_intial) {
					found = true;
					break;
				}
			}
			node<line>* pnn;
			if (found) {
				pnn = new node<line>();
				pnn->data->from = head_intial;
				pnn->data->to = head_intial;
				pnn->data->intial = true;
				pnn->data->solution = 0;
				sol->push(pnn);
			}
			else {
				seq->Add(head_intial);
				seq->Sort();
				if (seq[seq->Count - 1] != max) {
					seq->Add(max);
					seq->Sort();
				}
				if (seq[0] != 0) {
					seq->Add(0);
					seq->Sort();
				}
			}
			//find head location
			int pos = -1;
			for (int i = 0; i < seq->Count; i++) {
				if (seq[i] == head_intial) {
					pos = i;
					break;
				}
			}
			if (pos == -1) {
				richTextBox1->Text += "error head not found!!!\n";
				return;
			}
			if (d == 'l') {
				for (int i = pos; i > 0; i--) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i - 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i - 1]);
					sol->push(pnn);
				}
				pnn = new node<line>();
				pnn->data->from = seq[0];
				pnn->data->to = seq[seq->Count-1];
				pnn->data->solution = Math::Abs(seq[seq->Count-1] - seq[0]);
				sol->push(pnn);
				for (int i = seq->Count-1; i > pos+1; i--) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i - 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i - 1]);
					sol->push(pnn);
				}
			}
			else if (dir == 'r') {
				for (int i = pos; i < seq->Count - 1; i++) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i + 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i + 1]);
					sol->push(pnn);
				}
				pnn = new node<line>();
				pnn->data->from = seq[seq->Count - 1];
				pnn->data->to = seq[0];
				pnn->data->solution = Math::Abs(seq[seq->Count - 1] - seq[0]);
				sol->push(pnn);
				for (int i = 0; i < pos - 1; i++) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i + 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i + 1]);
					sol->push(pnn);
				}
			}
		}
		void doLOOK(stack<line>* sol, List<int>^ seq1, int head_intial, char d) {
			List<int>^ seq = gcnew List<int>();
			for (int i = 0; i < seq1->Count; i++) {
				seq->Add(seq1[i]);
			}
			//find head 0 frame
			bool found = false;
			for (int i = 0; i < seq->Count; i++) {
				if (seq[i] == head_intial) {
					found = true;
					break;
				}
			}
			node<line>* pnn;
			if (found) {
				pnn = new node<line>();
				pnn->data->from = head_intial;
				pnn->data->to = head_intial;
				pnn->data->intial = true;
				pnn->data->solution = 0;
				sol->push(pnn);
			}
			else {
				seq->Add(head_intial);
				seq->Sort();
			}
			//find head location
			int pos = -1;
			for (int i = 0; i < seq->Count; i++) {
				if (seq[i] == head_intial) {
					pos = i;
					break;
				}
			}
			if (pos == -1) {
				richTextBox1->Text += "error head not found!!!\n";
				return;
			}

			if (d == 'l') {
				for (int i = pos; i > 0; i--) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i - 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i - 1]);
					sol->push(pnn);
				}
				pnn = new node<line>();
				pnn->data->from = seq[0];
				pnn->data->to = seq[pos + 1];
				pnn->data->solution = Math::Abs(seq[pos + 1] - seq[0]);
				sol->push(pnn);
				for (int i = pos + 1; i < seq->Count - 1; i++) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i + 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i + 1]);
					sol->push(pnn);
				}
			}
			else if (d == 'r') {
				for (int i = pos; i < seq->Count - 1; i++) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i + 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i + 1]);
					sol->push(pnn);
				}
				pnn = new node<line>();
				pnn->data->from = seq[seq->Count - 1];
				pnn->data->to = seq[pos - 1];
				pnn->data->solution = Math::Abs(seq[seq->Count - 1] - seq[pos - 1]);
				sol->push(pnn);
				for (int i = pos - 1; i > 0; i--) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i - 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i - 1]);
					sol->push(pnn);
				}
			}
		}
		void doCLOOK(stack<line>* sol, List<int>^ seq1, int head_intial, char d) {
			List<int>^ seq = gcnew List<int>();
			for (int i = 0; i < seq1->Count; i++) {
				seq->Add(seq1[i]);
			}
			//find head 0 frame
			bool found = false;
			for (int i = 0; i < seq->Count; i++) {
				if (seq[i] == head_intial) {
					found = true;
					break;
				}
			}
			node<line>* pnn;
			if (found) {
				pnn = new node<line>();
				pnn->data->from = head_intial;
				pnn->data->to = head_intial;
				pnn->data->intial = true;
				pnn->data->solution = 0;
				sol->push(pnn);
			}
			else {
				seq->Add(head_intial);
				seq->Sort();
			}
			//find head location
			int pos = -1;
			for (int i = 0; i < seq->Count; i++) {
				if (seq[i] == head_intial) {
					pos = i;
					break;
				}
			}
			if (pos == -1) {
				richTextBox1->Text += "error head not found!!!\n";
				return;
			}
			if (d == 'l') {
				for (int i = pos; i > 0; i--) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i - 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i - 1]);
					sol->push(pnn);
				}
				pnn = new node<line>();
				pnn->data->from = seq[0];
				pnn->data->to = seq[seq->Count - 1];
				pnn->data->solution = Math::Abs(seq[seq->Count - 1] - seq[0]);
				sol->push(pnn);
				for (int i = seq->Count - 1; i > pos + 1; i--) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i - 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i - 1]);
					sol->push(pnn);
				}
			}
			else if (dir == 'r') {
				for (int i = pos; i < seq->Count - 1; i++) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i + 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i + 1]);
					sol->push(pnn);
				}
				pnn = new node<line>();
				pnn->data->from = seq[seq->Count - 1];
				pnn->data->to = seq[0];
				pnn->data->solution = Math::Abs(seq[seq->Count - 1] - seq[0]);
				sol->push(pnn);
				for (int i = 0; i < pos - 1; i++) {
					pnn = new node<line>();
					pnn->data->from = seq[i];
					pnn->data->to = seq[i + 1];
					pnn->data->solution = Math::Abs(seq[i] - seq[i + 1]);
					sol->push(pnn);
				}
			}
		}
	};
}
