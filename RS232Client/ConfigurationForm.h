#pragma once
#include "Endpoint.h"
#include "TokenizerService.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static CustomPortConfiguration portConfiguration;

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
	private:
		Tokenizer* tokenizer = new StringTokenizer();

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
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ terminatorComboBox;
	private: System::Windows::Forms::Label^ ownLabel;
	private: System::Windows::Forms::TextBox^ ownTerminatorTextBox;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->terminatorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ownLabel = (gcnew System::Windows::Forms::Label());
			this->ownTerminatorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(51, 82);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Port COM:";
			this->label1->Click += gcnew System::EventHandler(this, &ConfigurationForm::label1_Click);
			// 
			// comPortsComboBox
			// 
			this->comPortsComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comPortsComboBox->FormattingEnabled = true;
			this->comPortsComboBox->Location = System::Drawing::Point(160, 80);
			this->comPortsComboBox->Margin = System::Windows::Forms::Padding(2);
			this->comPortsComboBox->Name = L"comPortsComboBox";
			this->comPortsComboBox->Size = System::Drawing::Size(108, 21);
			this->comPortsComboBox->TabIndex = 1;
			this->comPortsComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::comPortsComboBox_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(158, 184);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(108, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ConfigurationForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(49, 186);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Baud Rate:";
			this->label2->Click += gcnew System::EventHandler(this, &ConfigurationForm::label2_Click);
			// 
			// saveConfigurationButton
			// 
			this->saveConfigurationButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->saveConfigurationButton->ForeColor = System::Drawing::SystemColors::Control;
			this->saveConfigurationButton->Location = System::Drawing::Point(54, 396);
			this->saveConfigurationButton->Margin = System::Windows::Forms::Padding(2);
			this->saveConfigurationButton->Name = L"saveConfigurationButton";
			this->saveConfigurationButton->Size = System::Drawing::Size(212, 38);
			this->saveConfigurationButton->TabIndex = 4;
			this->saveConfigurationButton->Text = L"ZAPISZ KONFIGURACJĘ";
			this->saveConfigurationButton->UseVisualStyleBackColor = false;
			this->saveConfigurationButton->Click += gcnew System::EventHandler(this, &ConfigurationForm::saveConfiguration);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(49, 214);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Liczba Bitów";
			// 
			// bitsCountComboBox
			// 
			this->bitsCountComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->bitsCountComboBox->FormattingEnabled = true;
			this->bitsCountComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"7", L"8" });
			this->bitsCountComboBox->Location = System::Drawing::Point(158, 212);
			this->bitsCountComboBox->Margin = System::Windows::Forms::Padding(2);
			this->bitsCountComboBox->Name = L"bitsCountComboBox";
			this->bitsCountComboBox->Size = System::Drawing::Size(108, 21);
			this->bitsCountComboBox->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(49, 240);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Kontrola Danych";
			// 
			// controlTypeComboBox
			// 
			this->controlTypeComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->controlTypeComboBox->FormattingEnabled = true;
			this->controlTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"E", L"O", L"N" });
			this->controlTypeComboBox->Location = System::Drawing::Point(158, 238);
			this->controlTypeComboBox->Margin = System::Windows::Forms::Padding(2);
			this->controlTypeComboBox->Name = L"controlTypeComboBox";
			this->controlTypeComboBox->Size = System::Drawing::Size(108, 21);
			this->controlTypeComboBox->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(49, 270);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(98, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Liczba Bitów Stopu";
			this->label5->Click += gcnew System::EventHandler(this, &ConfigurationForm::label5_Click);
			// 
			// stopBitCountComboBox
			// 
			this->stopBitCountComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->stopBitCountComboBox->FormattingEnabled = true;
			this->stopBitCountComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1", L"2" });
			this->stopBitCountComboBox->Location = System::Drawing::Point(158, 267);
			this->stopBitCountComboBox->Margin = System::Windows::Forms::Padding(2);
			this->stopBitCountComboBox->Name = L"stopBitCountComboBox";
			this->stopBitCountComboBox->Size = System::Drawing::Size(108, 21);
			this->stopBitCountComboBox->TabIndex = 10;
			this->stopBitCountComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::stopBitCountComboBox_SelectedIndexChanged);
			// 
			// refreshButton
			// 
			this->refreshButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->refreshButton->ForeColor = System::Drawing::SystemColors::Control;
			this->refreshButton->Location = System::Drawing::Point(54, 110);
			this->refreshButton->Margin = System::Windows::Forms::Padding(2);
			this->refreshButton->Name = L"refreshButton";
			this->refreshButton->Size = System::Drawing::Size(214, 35);
			this->refreshButton->TabIndex = 11;
			this->refreshButton->Text = L"ODŚWIEŻ";
			this->refreshButton->UseVisualStyleBackColor = false;
			this->refreshButton->Click += gcnew System::EventHandler(this, &ConfigurationForm::refreshCOMList);
			// 
			// autoconfigurationButton
			// 
			this->autoconfigurationButton->BackColor = System::Drawing::SystemColors::ControlDark;
			this->autoconfigurationButton->Location = System::Drawing::Point(54, 345);
			this->autoconfigurationButton->Margin = System::Windows::Forms::Padding(2);
			this->autoconfigurationButton->Name = L"autoconfigurationButton";
			this->autoconfigurationButton->Size = System::Drawing::Size(214, 38);
			this->autoconfigurationButton->TabIndex = 12;
			this->autoconfigurationButton->Text = L"AUTOKONFIGURACJA";
			this->autoconfigurationButton->UseVisualStyleBackColor = false;
			this->autoconfigurationButton->Click += gcnew System::EventHandler(this, &ConfigurationForm::autoConfiguration);
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Location = System::Drawing::Point(351, 289);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(549, 142);
			this->textBox2->TabIndex = 13;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(772, 449);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 38);
			this->button1->TabIndex = 14;
			this->button1->Text = L"WYŚLIJ";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(351, 134);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(549, 136);
			this->textBox3->TabIndex = 15;
			this->textBox3->Text = L"Read incoming messages here";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(348, 25);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Tryb edytora";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(355, 64);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 13);
			this->label7->TabIndex = 18;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(457, 25);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(52, 17);
			this->radioButton1->TabIndex = 19;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Tekst";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &ConfigurationForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(566, 25);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(44, 17);
			this->radioButton2->TabIndex = 20;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Hex";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &ConfigurationForm::radioButton2_CheckedChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(348, 56);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(57, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Terminator";
			// 
			// terminatorComboBox
			// 
			this->terminatorComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->terminatorComboBox->FormattingEnabled = true;
			this->terminatorComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"NONE", L"CR", L"LF", L"CR-LF", L"CUSTOM" });
			this->terminatorComboBox->Location = System::Drawing::Point(457, 53);
			this->terminatorComboBox->Name = L"terminatorComboBox";
			this->terminatorComboBox->Size = System::Drawing::Size(108, 21);
			this->terminatorComboBox->TabIndex = 22;
			this->terminatorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::comboBox1_SelectedIndexChanged);
			// 
			// ownLabel
			// 
			this->ownLabel->AutoSize = true;
			this->ownLabel->Location = System::Drawing::Point(351, 91);
			this->ownLabel->Name = L"ownLabel";
			this->ownLabel->Size = System::Drawing::Size(44, 13);
			this->ownLabel->TabIndex = 23;
			this->ownLabel->Text = L"Własny";
			this->ownLabel->Visible = false;
			// 
			// ownTerminatorTextBox
			// 
			this->ownTerminatorTextBox->Location = System::Drawing::Point(457, 88);
			this->ownTerminatorTextBox->Name = L"ownTerminatorTextBox";
			this->ownTerminatorTextBox->Size = System::Drawing::Size(108, 20);
			this->ownTerminatorTextBox->TabIndex = 24;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(635, 56);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(104, 13);
			this->label10->TabIndex = 25;
			this->label10->Text = L"Stan nasłuchiwania:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(745, 50);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(81, 24);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Stopped";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(648, 86);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(106, 32);
			this->button2->TabIndex = 27;
			this->button2->Text = L"STOP";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(760, 86);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(97, 32);
			this->button3->TabIndex = 28;
			this->button3->Text = L"START";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(653, 449);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(114, 38);
			this->button4->TabIndex = 29;
			this->button4->Text = L"PING";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// ConfigurationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(929, 498);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->ownTerminatorTextBox);
			this->Controls->Add(this->ownLabel);
			this->Controls->Add(this->terminatorComboBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
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
			this->Margin = System::Windows::Forms::Padding(2);
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
			int value = System::Int32::Parse(textBox1->Text);
			if (value > 115000) {
				textBox1->Text = textBox1->Text->Remove(textBox1->Text->Length - 1);
			}
		}
	}

	private: System::Void comPortsComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void readDefaultConfiguration();
	private: System::Void setComPortFollowingEnabledState(bool enabled) {
		this->textBox1->Enabled = enabled;
		this->bitsCountComboBox->Enabled = enabled;
		this->controlTypeComboBox->Enabled = enabled;
		this->controlTypeComboBox->Enabled = enabled;
		this->stopBitCountComboBox->Enabled = enabled;
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void updateTerminatorString();

	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		handleEditorChanged();
	}

	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		handleEditorChanged();
	}
	
	private: System::Void handleEditorChanged() {
		TokenizerMode mode = this->tokenizer->getTokenizerMode();
		std::string customTerminator = this->tokenizer->getCustomTerminator();

		bool textEditorSelected = this->radioButton1->Checked;

		if (textEditorSelected && this->tokenizer->getEditMode() != EditMode::TEXT) {
			this->tokenizer = new StringTokenizer();
		}

		if (!textEditorSelected && this->tokenizer->getEditMode() != EditMode::HEX) {
			this->tokenizer = new HexTokenizer();
		}

		this->tokenizer->setTerminator(mode, customTerminator);
	}

	};


}
