#pragma once

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class ConfigurationForm : public System::Windows::Forms::Form
	{
	public:
		ConfigurationForm(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~ConfigurationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		bool portComSet = false;
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::ComboBox^ comPortsComboBox;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ saveConfigurationButton;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ bitsCountComboBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ controlTypeComboBox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ stopBitCountComboBox;
	private: System::Windows::Forms::Button^ refreshButton;
	private: System::Windows::Forms::Button^ autoconfigurationButton;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comPortsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->saveConfigurationButton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->bitsCountComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->controlTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->stopBitCountComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->refreshButton = (gcnew System::Windows::Forms::Button());
			this->autoconfigurationButton = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Port COM:";
			this->label1->Click += gcnew System::EventHandler(this, &ConfigurationForm::label1_Click);
			// 
			// comPortsComboBox
			// 
			this->comPortsComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comPortsComboBox->FormattingEnabled = true;
			this->comPortsComboBox->Location = System::Drawing::Point(157, 75);
			this->comPortsComboBox->Name = L"comPortsComboBox";
			this->comPortsComboBox->Size = System::Drawing::Size(143, 24);
			this->comPortsComboBox->TabIndex = 1;
			this->comPortsComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::comPortsComboBox_SelectedIndexChanged);
			this->setComPortFollowingEnabledState(false);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(157, 111);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(143, 22);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ConfigurationForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 113);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Baud Rate:";
			this->label2->Click += gcnew System::EventHandler(this, &ConfigurationForm::label2_Click);
			// 
			// saveConfigurationButton
			// 
			this->saveConfigurationButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->saveConfigurationButton->ForeColor = System::Drawing::SystemColors::Control;
			this->saveConfigurationButton->Location = System::Drawing::Point(221, 454);
			this->saveConfigurationButton->Name = L"saveConfigurationButton";
			this->saveConfigurationButton->Size = System::Drawing::Size(195, 47);
			this->saveConfigurationButton->TabIndex = 4;
			this->saveConfigurationButton->Text = L"ZAPISZ KONFIGURACJĘ";
			this->saveConfigurationButton->UseVisualStyleBackColor = false;
			this->saveConfigurationButton->Click += gcnew System::EventHandler(this, &ConfigurationForm::saveConfiguration);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 148);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Liczba Bitów";
			// 
			// bitsCountComboBox
			// 
			this->bitsCountComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->bitsCountComboBox->FormattingEnabled = true;
			this->bitsCountComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"7", L"8" });
			this->bitsCountComboBox->Location = System::Drawing::Point(157, 145);
			this->bitsCountComboBox->Name = L"bitsCountComboBox";
			this->bitsCountComboBox->Size = System::Drawing::Size(143, 24);
			this->bitsCountComboBox->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 180);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Kontrola Danych";
			// 
			// controlTypeComboBox
			// 
			this->controlTypeComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->controlTypeComboBox->FormattingEnabled = true;
			this->controlTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"E", L"O", L"N" });
			this->controlTypeComboBox->Location = System::Drawing::Point(157, 177);
			this->controlTypeComboBox->Name = L"controlTypeComboBox";
			this->controlTypeComboBox->Size = System::Drawing::Size(143, 24);
			this->controlTypeComboBox->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 216);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(127, 17);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Liczba Bitów Stopu";
			this->label5->Click += gcnew System::EventHandler(this, &ConfigurationForm::label5_Click);
			// 
			// stopBitCountComboBox
			// 
			this->stopBitCountComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->stopBitCountComboBox->FormattingEnabled = true;
			this->stopBitCountComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			this->stopBitCountComboBox->Location = System::Drawing::Point(157, 213);
			this->stopBitCountComboBox->Name = L"stopBitCountComboBox";
			this->stopBitCountComboBox->Size = System::Drawing::Size(143, 24);
			this->stopBitCountComboBox->TabIndex = 10;
			this->stopBitCountComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::stopBitCountComboBox_SelectedIndexChanged);
			// 
			// refreshButton
			// 
			this->refreshButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->refreshButton->ForeColor = System::Drawing::SystemColors::Control;
			this->refreshButton->Location = System::Drawing::Point(321, 65);
			this->refreshButton->Name = L"refreshButton";
			this->refreshButton->Size = System::Drawing::Size(95, 43);
			this->refreshButton->TabIndex = 11;
			this->refreshButton->Text = L"ODŚWIEŻ";
			this->refreshButton->UseVisualStyleBackColor = false;
			this->refreshButton->Click += gcnew System::EventHandler(this, &ConfigurationForm::refreshCOMList);
			// 
			// autoconfigurationButton
			// 
			this->autoconfigurationButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->autoconfigurationButton->Location = System::Drawing::Point(15, 454);
			this->autoconfigurationButton->Name = L"autoconfigurationButton";
			this->autoconfigurationButton->Size = System::Drawing::Size(200, 47);
			this->autoconfigurationButton->TabIndex = 12;
			this->autoconfigurationButton->Text = L"AUTOKONFIGURACJA";
			this->autoconfigurationButton->UseVisualStyleBackColor = false;
			this->autoconfigurationButton->Click += gcnew System::EventHandler(this, &ConfigurationForm::autoConfiguration);
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Location = System::Drawing::Point(468, 253);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(732, 175);
			this->textBox2->TabIndex = 13;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1030, 454);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 47);
			this->button1->TabIndex = 14;
			this->button1->Text = L"WYŚLIJ";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(468, 65);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(732, 168);
			this->textBox3->TabIndex = 15;
			this->textBox3->Text = L"Read incoming messages here";
			// 
			// ConfigurationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1239, 613);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->autoconfigurationButton);
			this->Controls->Add(this->refreshButton);
			this->Controls->Add(this->stopBitCountComboBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->controlTypeComboBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->bitsCountComboBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->saveConfigurationButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comPortsComboBox);
			this->Controls->Add(this->label1);
			this->Name = L"ConfigurationForm";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void saveConfiguration(System::Object^ sender, System::EventArgs^ e);

	private: System::Void refreshCOMList(System::Object^ sender, System::EventArgs^ e);

	private: System::Void autoConfiguration(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void stopBitCountComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (System::Text::RegularExpressions::Regex::IsMatch(textBox1->Text, "[^0-9]"))
		{
			textBox1->Text = textBox1->Text->Remove(textBox1->Text->Length - 1);
		}
	}

	private: System::Void comPortsComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		this->portComSet = true;
		this->setComPortFollowingEnabledState(this->portComSet);
		// enable other fields

	}

	private: void setComPortFollowingEnabledState(bool enabled) {
		this->textBox1->Enabled = enabled;
		this->bitsCountComboBox->Enabled = enabled;
		this->controlTypeComboBox->Enabled = enabled;
		this->controlTypeComboBox->Enabled = enabled;
		this->stopBitCountComboBox->Enabled = enabled;
	}
	};
}
