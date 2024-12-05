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
	/// Summary for Form4
	/// </summary>
	public ref class Form4 : public System::Windows::Forms::Form
	{
	public:
		Form4(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->Load += gcnew System::EventHandler(this, &project::Form4::OnLoad);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &project::Form4::OnPaint);
			T->Tick += gcnew System::EventHandler(this, &project::Form4::OnTick);
			this->button1->Click += gcnew System::EventHandler(this, &project::Form4::OnClick);
			numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &project::Form4::OnValueChanged1);
			numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &project::Form4::OnValueChanged2);
			numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &project::Form4::OnValueChanged3);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form4()
		{
			T->Stop();
			if (components)
			{
				delete components;
			}
			if (bg != nullptr)
				delete bg;
		}
		private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
		protected:
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::RichTextBox^ richTextBox1;
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		Bitmap^ bg;
		Timer^ T = gcnew Timer();
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::Label^ label5;
		   StringFormat^ stringFormat = gcnew StringFormat();
		   int size = 1;
		   int bits = 1;
		   int current = 0;
		   bool calc = false;
		   List<String^>^ parsed = gcnew List<String^>();
		   List<int>^ seq = gcnew List<int>();
		   int hits = 0;
		   int page_faults = 0;
		   MEMORY<mem_bits>* ADDITIONAL = nullptr;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->BackColor = System::Drawing::Color::Black;
			this->numericUpDown2->ForeColor = System::Drawing::Color::Lime;
			this->numericUpDown2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown2->Location = System::Drawing::Point(829, 28);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(119, 22);
			this->numericUpDown2->TabIndex = 22;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Lime;
			this->label4->Location = System::Drawing::Point(826, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 16);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Interval";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Lime;
			this->button1->Location = System::Drawing::Point(738, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 38);
			this->button1->TabIndex = 20;
			this->button1->Text = L"apply";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::Color::Black;
			this->numericUpDown1->ForeColor = System::Drawing::Color::Lime;
			this->numericUpDown1->Location = System::Drawing::Point(488, 27);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(119, 22);
			this->numericUpDown1->TabIndex = 19;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(485, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 16);
			this->label3->TabIndex = 18;
			this->label3->Text = L"size";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(956, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 16);
			this->label2->TabIndex = 17;
			this->label2->Text = L"logs";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->BackColor = System::Drawing::Color::DimGray;
			this->richTextBox1->ForeColor = System::Drawing::Color::Lime;
			this->richTextBox1->Location = System::Drawing::Point(953, 26);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(200, 352);
			this->richTextBox1->TabIndex = 16;
			this->richTextBox1->Text = L"";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->ForeColor = System::Drawing::Color::Lime;
			this->textBox1->Location = System::Drawing::Point(12, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(470, 22);
			this->textBox1->TabIndex = 15;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(12, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 16);
			this->label1->TabIndex = 14;
			this->label1->Text = L"stream";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->BackColor = System::Drawing::Color::Black;
			this->numericUpDown3->ForeColor = System::Drawing::Color::Lime;
			this->numericUpDown3->Location = System::Drawing::Point(613, 28);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, 0 });
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(119, 22);
			this->numericUpDown3->TabIndex = 24;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Lime;
			this->label5->Location = System::Drawing::Point(610, 8);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(28, 16);
			this->label5->TabIndex = 23;
			this->label5->Text = L"bits";
			// 
			// Form4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1165, 390);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Form4";
			this->Text = L"page replacement (2)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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
			this->BackColor = Color::FromArgb(30, 30, 30);
			this->WindowState = FormWindowState::Maximized;
			stringFormat->Alignment = StringAlignment::Center;
			stringFormat->LineAlignment = StringAlignment::Center;
			bg = gcnew Bitmap(this->ClientSize.Width, this->ClientSize.Height);
			T->Interval = (int)(numericUpDown2->Value);
			T->Start();
		}
		void OnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			delete bg;

			if (this->ClientSize.Width != 0 && this->ClientSize.Height != 0) {
				bg = gcnew Bitmap(this->ClientSize.Width, this->ClientSize.Height);
			}
			draw(e->Graphics);
		}
		void OnTick(System::Object^ sender, System::EventArgs^ e) {
			if (calc) {
				if (current == 0) {
					page_faults = 0;
					hits = 0;
					ADDITIONAL = new MEMORY<mem_bits>(size);
				}
				node<mem_bits> *tmp = ADDITIONAL->_find(int::Parse(parsed[current]));
				if (tmp == nullptr) {
					page_faults++;
					if (ADDITIONAL->size < size) {
						node<mem_bits>* pnn = new node<mem_bits>();
						pnn->data->bits = int::Parse(parsed[current]);
						pnn->data->frame = 0;
						unsigned long long min = 9999;
						node<mem_bits> *pos = nullptr;
						node<mem_bits>* t = ADDITIONAL->getHead();
						while (t != nullptr) {
							if (t->data->bits < min) {
								min = t->data->bits;
								pos = t;
							}
							t = t->nxt;
						}
						ADDITIONAL->delete_at(t);
						ADDITIONAL->push(pnn);
					}
					else {
						
						node<mem_bits>* pnn = new node<mem_bits>();
						pnn->data->bits = int::Parse(parsed[current]);
						pnn->data->frame = 0;
						ADDITIONAL->push(pnn);
					}
				}
				else {
					tmp->data->bits >>= 1;
					tmp->data->bits |= (1 << (sizeof(tmp->data->bits) * 8 - 1));
					hits++;
				}
				current++;
				if (current >= parsed->Count) {
					calc = false;
					
				}
			}
			draw(this->CreateGraphics());
		}
		void draw(Graphics^ G) {
			if (bg != nullptr) {
				buffer(Graphics::FromImage(bg));
				G->DrawImage(bg, 0, 0);
			}
			delete G;
		}
		void buffer(Graphics^ g) {
			/*g->Clear(this->BackColor);
			//draw sections
			Rectangle^ area = gcnew Rectangle(textBox1->Location.X, textBox1->Location.Y + 10 + textBox1->Height, richTextBox1->Location.X - textBox1->Location.X, ClientSize.Height - (textBox1->Location.Y + 10 + textBox1->Height));
			//g->FillRectangle(Brushes::White, *area);
			//draw text
			if (parsed->Count != 0) {
				int w = area->Width / (parsed->Count /* + (int)(parsed->Count / bits) - 1 );
				int h = area->Height / 20;
				int x=area->X, y = area->Y;
				for (int i = 0; i < parsed->Count;) {
					Rectangle^ element = gcnew Rectangle(x, y, w, h);
					String^ txt = "";
					/*if (i % bits == 0 && i != 0) {
						txt = " ";
					}
					else {
						txt = parsed[i];
					}
					g->DrawRectangle(Pens::Lime, *element);
					{
						SizeF^ s = g->MeasureString(txt, this->Font);
						float font_scale = System::Math::Max(s->Width / element->Width, s->Height / element->Height);
						System::Drawing::Font^ F = gcnew System::Drawing::Font(this->Font->FontFamily, this->Font->SizeInPoints / font_scale, GraphicsUnit::Point);
						g->DrawString(txt, F, gcnew SolidBrush((current == (j-1)) ? (Color::Lime) : (Color::White)), *(gcnew Rectangle(element->X, element->Y, element->Width, element->Height)), stringFormat);
					}
					x += w;
					if (i % bits != 0) {
						i++;
					}
				}
				//draw tracer
			}
			delete g;*/
		}
		void OnClick(System::Object^ sender, System::EventArgs^ e) {
			parsed->Clear();
			this->textBox1->Text = trim(this->textBox1->Text, ' ');
			parse(parsed, textBox1->Text, ',');
			richTextBox1->Text += "applying:{" + parsed->Count + "}: " + replace(this->textBox1->Text, ',', ' ') + "\n";
			str_int(parsed, seq);
			calc = true;
			current = 0;
			if (ADDITIONAL != nullptr) {
				delete[] ADDITIONAL;
			}
			ADDITIONAL = new MEMORY<mem_bits>(size);
		}
		void OnValueChanged1(System::Object^ sender, System::EventArgs^ e) {
			//size
			size = (int)numericUpDown1->Value;
			richTextBox1->Text += "size: " + size + "\n";
		}
		void OnValueChanged2(System::Object^ sender, System::EventArgs^ e) {
			//bits
			bits = (int)numericUpDown3->Value;
			richTextBox1->Text += "bits: " + bits + "\n";
		}
		void OnValueChanged3(System::Object^ sender, System::EventArgs^ e) {
			//interval
			T->Stop();
			T->Interval = (int)numericUpDown2->Value;
			T->Start();
		}
};
}