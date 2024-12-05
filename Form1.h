#pragma once
#include"Algorithms.h"

namespace project {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &project::Form1::OnLoad);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &project::Form1::OnPaint);
			T = gcnew Timer();
			T->Tick += gcnew System::EventHandler(this, &project::Form1::OnTick);
			radioButton1->CheckedChanged += gcnew System::EventHandler(this, &project::Form1::OnCheckedChanged);
			radioButton2->CheckedChanged += gcnew System::EventHandler(this, &project::Form1::OnCheckedChanged2);
			radioButton3->CheckedChanged += gcnew System::EventHandler(this, &project::Form1::OnCheckedChanged3);
			this->radioButton1->Checked = true;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &project::Form1::SetSize);
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &project::Form1::SetInterval);
			this->button1->Click += gcnew System::EventHandler(this, &project::Form1::OnClick);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			T->Stop();
			if (components)
			{
				delete components;
			}
			if(list != nullptr)
				delete list;
			if (bg != nullptr)
				delete bg;
			/*if (parsed != nullptr)
				delete parsed;
			*/
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		Bitmap ^bg = nullptr;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::GroupBox^ groupBox1;
		private: System::Windows::Forms::RadioButton^ radioButton1;
		private: System::Windows::Forms::RichTextBox^ richTextBox1;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::RadioButton^ radioButton2;
		private: System::Windows::Forms::RadioButton^ radioButton3;
		Timer^ T = nullptr;
		MEMORY<int>* list = nullptr;
		List<String^>^ parsed = gcnew List<String^>();
		List<Bitmap^>^ tracer = gcnew List<Bitmap^>();
		stack<bool>* tracer_bool = new stack<bool>();
		StringFormat^ stringFormat = gcnew StringFormat();
		bool calc = false;
		int current = 0;
		int hits = 0;
		int page_fault = 0;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"stream";
			// 
			// textBox1
			// 
			this->textBox1->ForeColor = System::Drawing::Color::Lime;
			this->textBox1->Location = System::Drawing::Point(12, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(470, 22);
			this->textBox1->TabIndex = 2;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->ForeColor = System::Drawing::Color::Lime;
			this->groupBox1->Location = System::Drawing::Point(974, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 185);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Algorithms";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(8, 72);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(86, 20);
			this->radioButton3->TabIndex = 6;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"OPTIMAL";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 46);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(55, 20);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"LRU";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 20);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(57, 20);
			this->radioButton1->TabIndex = 4;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"FIFO";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::DimGray;
			this->richTextBox1->ForeColor = System::Drawing::Color::Lime;
			this->richTextBox1->Location = System::Drawing::Point(974, 219);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(200, 262);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(977, 200);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"logs";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(488, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"size";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->ForeColor = System::Drawing::Color::Lime;
			this->numericUpDown1->Location = System::Drawing::Point(491, 29);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(119, 22);
			this->numericUpDown1->TabIndex = 8;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->ForeColor = System::Drawing::Color::Lime;
			this->button1->Location = System::Drawing::Point(616, 14);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 38);
			this->button1->TabIndex = 11;
			this->button1->Text = L"apply";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->ForeColor = System::Drawing::Color::Lime;
			this->numericUpDown2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown2->Location = System::Drawing::Point(853, 29);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(119, 22);
			this->numericUpDown2->TabIndex = 13;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Lime;
			this->label4->Location = System::Drawing::Point(850, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 16);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Interval";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1186, 493);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"page replacement (1)";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
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
		/*void str_list(MEMORY<int>* l1, List<String^>^ l2) {
			for (int i = 0; i < l2->Count; i++) {
				node<int>* pnn = new node<int>();
				pnn->data = new int;
				*(pnn->data) = int::Parse(l2[i]);
				l1->push(pnn);
			}
		}*/
		void OnLoad(System::Object^ sender, System::EventArgs^ e) {
			this->BackColor = Color::FromArgb(30,30,30);
			stringFormat->Alignment = StringAlignment::Center;
			stringFormat->LineAlignment = StringAlignment::Center;
			bg = gcnew Bitmap(this->ClientSize.Width, this->ClientSize.Height);
			T->Interval = (int)(numericUpDown2->Value);
			T->Start();
			list = new MEMORY<int>(1);
		}
		void OnPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			delete bg;
			
			if (this->ClientSize.Width != 0 && this->ClientSize.Height != 0) {
				bg = gcnew Bitmap(this->ClientSize.Width, this->ClientSize.Height);
			}
			draw(e->Graphics);
		}
		Bitmap^ draw_trace(MEMORY<int>* list, int width, int height,Color ^c1,Color ^c2,Color ^c3,int border) {
			Bitmap^ img = gcnew Bitmap(width, height);
			Graphics^ G = Graphics::FromImage(img);
			Rectangle^ text_area = gcnew Rectangle(0, 0, width, height);
			G->FillRectangle(gcnew SolidBrush(*c1), *text_area);
			for (int i = 0; i < list->size; i++) {
				Rectangle^ element = gcnew Rectangle(0, (text_area->Height/list->size)*i, text_area->Width, text_area->Height / list->size);
				G->DrawRectangle(gcnew Pen(*c2,(float)border), *element);
				if (i <= list->curr) {
					int* tmp = list->get(i)->data;
					SizeF^ s = G->MeasureString((*tmp)+"", this->Font);
					{
						float font_scale = System::Math::Max(s->Width / element->Width, s->Height / element->Height);
						System::Drawing::Font^ F = gcnew System::Drawing::Font(this->Font->FontFamily, this->Font->SizeInPoints / font_scale, GraphicsUnit::Point);
						G->DrawString((*tmp) + "", F, gcnew SolidBrush(*c3), *element, stringFormat);
					}
				}
			}
			delete G;
			return img;
		}
		void OnTick(System::Object^ sender, System::EventArgs^ e) {
			if (calc == true) {
				if (current == 0) {
					tracer->Clear();
					delete tracer_bool;
					tracer_bool = new stack<bool>();
					hits = 0;
					page_fault = 0;
				}
				node<int>* pnn = new node<int>();
				pnn->data = new int;
				*(pnn->data) = int::Parse(parsed[current]);
				node<bool>* pnn2 = new node<bool>();
				if (radioButton1->Checked == true) {//FIFO
					if (list->find(pnn) == nullptr) {//not found
						//this->richTextBox1->Text += "page_fault\n";
						page_fault++;
						*(pnn2->data) = false;
						if (list->curr == list->size - 1) {
							//this->richTextBox1->Text += "removing_entry\n";
							node<int>* tmp = list->pop();
							delete tmp;
							list->push(pnn);
						}
						else {
							//this->richTextBox1->Text += "adding_entry\n";
							list->push(pnn);
						}
					}
					else {//found
						//this->richTextBox1->Text += "hit\n";
						hits++;
						*(pnn2->data) = true;
						delete pnn;
					}
				}
				else if (radioButton2->Checked == true) { //LRU
					node<int>* tmp = list->find(pnn);
					if (tmp == nullptr) {//not found
						page_fault++;
						*(pnn2->data) = false;
						if (list->curr == list->size - 1) {//remove least recent used
							node<int>* tmp2 = list->pop();
							delete tmp2;
							list->push(pnn);
						}
						else {//append
							list->push(pnn);
						}
					}
					else {// found so update to recent
						hits++;
						*(pnn2->data) = true;
						list->delete_at(tmp);
						tmp->prev = tmp->nxt = nullptr;
						list->push(tmp);
						delete pnn;
					}
				}
				else if (radioButton3->Checked == true) {//optimal
					node<int>* tmp = list->find(pnn);
					if (tmp == nullptr) {//not found
						*(pnn2->data) = false;
						page_fault++;
						if (list->curr == list->size - 1) {
							//look to the future
							stack<int> *future = new stack<int>();
							for (int i = 0; i < list->size; i++) {
								node<int>* pnn = new node<int>();
								*(pnn->data) = 999;
								int tmp = *(list->get(i)->data);
								for (int j = current + 1; j < parsed->Count; j++) {
									if (int::Parse(parsed[j]) == tmp) {
										*(pnn->data) = j;
										break;
									}
								}
								future->push(pnn);
							}
							//get max
							int max = -1;
							int i = 0;
							int sav = -1;
							node<int>* t = future->head;
							while (t != nullptr) {
								if (*(t->data) > max) {
									sav = i;
									max = *(t->data);
								}
								i++;
								t = t->nxt;
							}
							// delete node with max (sav)
							delete future;
							tmp = list->get(sav);
							list->delete_at(tmp);
							delete tmp;
							//add new
							list->push(pnn);
						}
						else {
							list->push(pnn);
						}
					}
					else {//found
						hits++;
						*(pnn2->data) = true;
						delete pnn;
					}
				}

				Bitmap^ pnn3 = draw_trace(list, 100, 100 * list->size, Color::Gray, (*(pnn2->data))?(Color::Green):(Color::Red), Color::Lime, 4);
				tracer->Add(pnn3);
				tracer_bool->push(pnn2);
				current++;
				if (current == parsed->Count) {
					calc = false;
					this->richTextBox1->Text += "hits:"+hits+"\n";
					this->richTextBox1->Text += "page faults:" + page_fault + "\n";
					textBox1->Enabled = true;
					numericUpDown1->Enabled = true;
					button1->Enabled = true;
				}
			}
			this->draw(this->CreateGraphics());
		}
		void OnCheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			if (radioButton1->Checked) {
				richTextBox1->Text += "selected: FIFO\nenter stream: n1,n2,...\n";
			}
			calc = false;
			current = 0;
		}
		void OnCheckedChanged2(System::Object^ sender, System::EventArgs^ e) {
			if (radioButton2->Checked) {
				richTextBox1->Text += "selected: LRU\nenter stream: n1,n2,...\n";
			}
			calc = false;
			current = 0;
		}
		void OnCheckedChanged3(System::Object^ sender, System::EventArgs^ e) {
			if (radioButton3->Checked) {
				richTextBox1->Text += "selected: OPTIMAL\nenter stream: n1,n2,...\n";
			}
			calc = false;
			current = 0;
		}
		void SetSize(System::Object^ sender, System::EventArgs^ e) {
			delete list;
			list = new MEMORY<int>((unsigned int)numericUpDown1->Value);
			richTextBox1->Text += "size: " + (int)(numericUpDown1->Value) + "\n";
		}
		void SetInterval(System::Object^ sender, System::EventArgs^ e) {
			T->Stop();
			richTextBox1->Text += "interval: " + (int)(numericUpDown2->Value) + "\n";
			T->Interval = (int)(numericUpDown2->Value);
			T->Start();
		}
		void OnClick(System::Object^ sender, System::EventArgs^ e) {
			parsed->Clear();
			this->textBox1->Text = trim(this->textBox1->Text, ' ');
			parse(parsed, textBox1->Text, ',');
			richTextBox1->Text += "applying:{"+parsed->Count+"}: " + replace(this->textBox1->Text, ',', ' ') + "\n";
			//str_list(list, parsed);
			calc = true;
			current = 0;
			textBox1->Enabled = false;
			numericUpDown1->Enabled = false;
			button1->Enabled = false;
		}
		void draw(Graphics^ G) {
			if (bg != nullptr) {
				buffer(Graphics::FromImage(bg));
				G->DrawImage(bg, 0, 0);
			}
			delete G;
		}
		void buffer(Graphics^ g) {
			g->Clear(this->BackColor);
			if (parsed->Count != 0) {
				Rectangle^ text_area = gcnew Rectangle(this->textBox1->Location.X, this->textBox1->Location.Y + this->textBox1->Height + 5,(this->richTextBox1->Location.X-this->textBox1->Location.X),(this->richTextBox1->Location.Y+this->richTextBox1->Height)-(this->textBox1->Location.Y + this->textBox1->Height));
				//g->FillRectangle(Brushes::Gray, text_area->X,text_area->Y,text_area->Width,text_area->Height);
				//g->FillRectangle(Brushes::Gray, *text_area);
				for (int i = 0; i < parsed->Count; i++) {
					Rectangle^ element = gcnew Rectangle(text_area->X+(text_area->Width/parsed->Count)*i,text_area->Y, text_area->Width / parsed->Count, text_area->Height / 6);
					SizeF^ s = g->MeasureString(parsed[i], this->Font);
					{
						float font_scale = System::Math::Max(s->Width/element->Width,s->Height/element->Height);
						System::Drawing::Font^ F = gcnew System::Drawing::Font(this->Font->FontFamily,this->Font->SizeInPoints/font_scale,GraphicsUnit::Point);
						g->DrawRectangle(Pens::White, *element);
						if (i < current) {//processed
							node<bool>* tmp = tracer_bool->get(i);
							if (*(tmp->data)) {
								g->DrawString(parsed[i], F, gcnew SolidBrush(Color::Lime), *element, stringFormat);
							}
							else {
								g->DrawString(parsed[i], F, gcnew SolidBrush(Color::Red), *element, stringFormat);
							}
							g->DrawImage(tracer[i],*( gcnew Rectangle(element->X,element->Y+(element->Height*2),element->Width, element->Height * 3)),*( gcnew Rectangle(0,0,tracer[i]->Width, tracer[i]->Height) ), GraphicsUnit::Pixel);
						}
						else {
							g->DrawString(parsed[i], F, gcnew SolidBrush(Color::White), *element, stringFormat);
						}
					}

				}

				
			}
			delete g;
		}
	};
}

