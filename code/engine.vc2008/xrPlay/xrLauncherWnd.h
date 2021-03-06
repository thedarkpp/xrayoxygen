////////////////////////////////////////
#pragma once
////////////////////////////////////////
#include <msclr\marshal.h>  
#include "IParserSystem.h"
////////////////////////////////////////

namespace xrPlay 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct returned_values
	{
		unsigned int type_ptr;
		char const* params_list;
	};

	extern returned_values ret_values;
	/// <summary>
	/// Сводка для xrLauncherWnd
	/// </summary>
	public ref class xrLauncherWnd : public System::Windows::Forms::Form
	{
	public:
		xrLauncherWnd(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~xrLauncherWnd()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::MaskedTextBox^ textBox1;
	private: System::Windows::Forms::Label^ BtnClose;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::Label^ label2;
	protected: 
		config* launch;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(xrLauncherWnd::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->BtnClose = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(412, 163);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &xrLauncherWnd::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(3, 189);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(500, 20);
			this->textBox1->TabIndex = 3;
			// 
			// BtnClose
			// 
			this->BtnClose->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->BtnClose->AutoSize = true;
			this->BtnClose->BackColor = System::Drawing::Color::Transparent;
			this->BtnClose->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->BtnClose->Location = System::Drawing::Point(491, 0);
			this->BtnClose->Name = L"BtnClose";
			this->BtnClose->Size = System::Drawing::Size(12, 13);
			this->BtnClose->TabIndex = 4;
			this->BtnClose->Text = L"x";
			this->BtnClose->Click += gcnew System::EventHandler(this, &xrLauncherWnd::BtnClose_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(474, -2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"_";
			this->label1->Click += gcnew System::EventHandler(this, &xrLauncherWnd::label1_Click);
			// 
			// radioButton2
			// 
			this->radioButton2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::Transparent;
			this->radioButton2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->radioButton2->Location = System::Drawing::Point(347, 25);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(147, 17);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->Text = L"Dynamic Light (D3D9)      ";
			this->radioButton2->UseVisualStyleBackColor = false;
			// 
			// radioButton3
			// 
			this->radioButton3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioButton3->AutoSize = true;
			this->radioButton3->BackColor = System::Drawing::Color::Transparent;
			this->radioButton3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->radioButton3->Location = System::Drawing::Point(348, 48);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(154, 17);
			this->radioButton3->TabIndex = 8;
			this->radioButton3->Text = L"Full Dynamic Light (D3D9)  ";
			this->radioButton3->UseVisualStyleBackColor = false;
			// 
			// radioButton4
			// 
			this->radioButton4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioButton4->AutoSize = true;
			this->radioButton4->BackColor = System::Drawing::Color::Transparent;
			this->radioButton4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->radioButton4->Location = System::Drawing::Point(348, 71);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(154, 17);
			this->radioButton4->TabIndex = 9;
			this->radioButton4->Text = L"Full Dynamic Light (D3D10)";
			this->radioButton4->UseVisualStyleBackColor = false;
			// 
			// radioButton5
			// 
			this->radioButton5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioButton5->AutoSize = true;
			this->radioButton5->BackColor = System::Drawing::Color::Transparent;
			this->radioButton5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->radioButton5->Location = System::Drawing::Point(348, 94);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(154, 17);
			this->radioButton5->TabIndex = 10;
			this->radioButton5->Text = L"Full Dynamic Light (D3D11)";
			this->radioButton5->UseVisualStyleBackColor = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 170);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 11;
			// 
			// xrLauncherWnd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(506, 212);
			this->ControlBox = false;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radioButton5);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BtnClose);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"xrLauncherWnd";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &xrLauncherWnd::xrLauncherWnd_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Forms
	private: System::Void button1_Click		(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button3_Click		(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void xrLauncherWnd_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnClose_Click	(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label1_Click		(System::Object^ sender, System::EventArgs^ e);
	// Oxy

	/// <summary>
	/// Checking for a AVX and SSE4.1 instructions
	/// </summary>
	private: void CPUTest();
	private: void Init();
};
}
