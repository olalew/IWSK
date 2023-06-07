#pragma once
#include "Endpoint.h"
#include "TokenizerService.h"
#include "SerialPortManager.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static bool listenBackground = false;
	static std::string AUTOBAUDING_SEQUENCE = "00000@###";

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
		bool messsageAcknowledged = true;
		DateTime pingStartDatetime;
	private:
		Tokenizer^ tokenizer = gcnew StringTokenizer();
	public:
		static HANDLE communicationHandle;
		static bool isCommunicationOpen;
		static CustomPortConfiguration^ portConfiguration = gcnew CustomPortConfiguration();

#pragma region Control Declaration

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
	private: System::Windows::Forms::Panel^ panel;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ comboBox1;


#pragma endregion

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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->terminatorComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ownLabel = (gcnew System::Windows::Forms::Label());
			this->ownTerminatorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(68, 101);
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
			this->comPortsComboBox->Location = System::Drawing::Point(213, 98);
			this->comPortsComboBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comPortsComboBox->Name = L"comPortsComboBox";
			this->comPortsComboBox->Size = System::Drawing::Size(143, 24);
			this->comPortsComboBox->TabIndex = 1;
			this->comPortsComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::comPortsComboBox_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(211, 226);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(143, 22);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ConfigurationForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(65, 229);
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
			this->saveConfigurationButton->Location = System::Drawing::Point(72, 487);
			this->saveConfigurationButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->saveConfigurationButton->Name = L"saveConfigurationButton";
			this->saveConfigurationButton->Size = System::Drawing::Size(283, 47);
			this->saveConfigurationButton->TabIndex = 4;
			this->saveConfigurationButton->Text = L"ZAPISZ KONFIGURACJĘ";
			this->saveConfigurationButton->UseVisualStyleBackColor = false;
			this->saveConfigurationButton->Click += gcnew System::EventHandler(this, &ConfigurationForm::saveConfiguration);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(65, 263);
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
			this->bitsCountComboBox->Location = System::Drawing::Point(211, 261);
			this->bitsCountComboBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bitsCountComboBox->Name = L"bitsCountComboBox";
			this->bitsCountComboBox->Size = System::Drawing::Size(143, 24);
			this->bitsCountComboBox->TabIndex = 6;
			this->bitsCountComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::bitsCountChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(65, 295);
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
			this->controlTypeComboBox->Location = System::Drawing::Point(211, 293);
			this->controlTypeComboBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->controlTypeComboBox->Name = L"controlTypeComboBox";
			this->controlTypeComboBox->Size = System::Drawing::Size(143, 24);
			this->controlTypeComboBox->TabIndex = 8;
			this->controlTypeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::controlTypeChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(65, 332);
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
			this->stopBitCountComboBox->Location = System::Drawing::Point(211, 329);
			this->stopBitCountComboBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->stopBitCountComboBox->Name = L"stopBitCountComboBox";
			this->stopBitCountComboBox->Size = System::Drawing::Size(143, 24);
			this->stopBitCountComboBox->TabIndex = 10;
			this->stopBitCountComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::stopBitCountComboBox_SelectedIndexChanged);
			// 
			// refreshButton
			// 
			this->refreshButton->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->refreshButton->ForeColor = System::Drawing::SystemColors::Control;
			this->refreshButton->Location = System::Drawing::Point(72, 135);
			this->refreshButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->refreshButton->Name = L"refreshButton";
			this->refreshButton->Size = System::Drawing::Size(285, 43);
			this->refreshButton->TabIndex = 11;
			this->refreshButton->Text = L"ODŚWIEŻ";
			this->refreshButton->UseVisualStyleBackColor = false;
			this->refreshButton->Click += gcnew System::EventHandler(this, &ConfigurationForm::refreshCOMList);
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Location = System::Drawing::Point(468, 356);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(732, 175);
			this->textBox2->TabIndex = 13;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1029, 553);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(171, 47);
			this->button1->TabIndex = 14;
			this->button1->Text = L"WYŚLIJ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ConfigurationForm::sendMessage);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Location = System::Drawing::Point(0, 0);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(133, 27);
			this->textBox3->TabIndex = 15;
			this->textBox3->Text = L"Read incoming messages here";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(464, 31);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(89, 17);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Tryb edytora";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(473, 79);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 17);
			this->label7->TabIndex = 18;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(609, 31);
			this->radioButton1->Margin = System::Windows::Forms::Padding(4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(64, 21);
			this->radioButton1->TabIndex = 19;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Tekst";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &ConfigurationForm::radioButton1_CheckedChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(464, 69);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(77, 17);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Terminator";
			// 
			// terminatorComboBox
			// 
			this->terminatorComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->terminatorComboBox->FormattingEnabled = true;
			this->terminatorComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"NONE", L"CR", L"LF", L"CR-LF", L"CUSTOM" });
			this->terminatorComboBox->Location = System::Drawing::Point(609, 65);
			this->terminatorComboBox->Margin = System::Windows::Forms::Padding(4);
			this->terminatorComboBox->Name = L"terminatorComboBox";
			this->terminatorComboBox->Size = System::Drawing::Size(143, 24);
			this->terminatorComboBox->TabIndex = 22;
			this->terminatorComboBox->SelectedIndex = 0;

			this->ownLabel->Visible = false;
			this->ownTerminatorTextBox->Visible = false;
			this->terminatorComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::comboBox1_SelectedIndexChanged);
			// 
			// ownLabel
			// 
			this->ownLabel->AutoSize = true;
			this->ownLabel->Location = System::Drawing::Point(468, 112);
			this->ownLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ownLabel->Name = L"ownLabel";
			this->ownLabel->Size = System::Drawing::Size(54, 17);
			this->ownLabel->TabIndex = 23;
			this->ownLabel->Text = L"Własny";
			this->ownLabel->Visible = false;
			// 
			// ownTerminatorTextBox
			// 
			this->ownTerminatorTextBox->Location = System::Drawing::Point(609, 108);
			this->ownTerminatorTextBox->Margin = System::Windows::Forms::Padding(4);
			this->ownTerminatorTextBox->Name = L"ownTerminatorTextBox";
			this->ownTerminatorTextBox->Size = System::Drawing::Size(143, 22);
			this->ownTerminatorTextBox->TabIndex = 24;
			this->ownTerminatorTextBox->TextChanged += gcnew System::EventHandler(this, &ConfigurationForm::ownTerminatorTextBox_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(847, 69);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(133, 17);
			this->label10->TabIndex = 25;
			this->label10->Text = L"Stan nasłuchiwania:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(993, 62);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(105, 29);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Stopped";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(864, 106);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(141, 39);
			this->button2->TabIndex = 27;
			this->button2->Text = L"STOP";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ConfigurationForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1013, 106);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(129, 39);
			this->button3->TabIndex = 28;
			this->button3->Text = L"START";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ConfigurationForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(871, 553);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(152, 47);
			this->button4->TabIndex = 29;
			this->button4->Text = L"PING";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ConfigurationForm::button4_Click);
			// 
			// panel
			// 
			this->panel->AutoScroll = true;
			this->textBox3->Dock = DockStyle::Fill;
			this->panel->Controls->Add(this->textBox3);
			this->panel->Location = System::Drawing::Point(468, 165);
			this->panel->Margin = System::Windows::Forms::Padding(4);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(732, 167);
			this->panel->TabIndex = 30;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(65, 368);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(128, 17);
			this->label9->TabIndex = 31;
			this->label9->Text = L"Kontrola przepływu";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"NONE", L"DTR/DSR", L"SOFTWARE", L"RST/CTS" });
			this->comboBox1->Location = System::Drawing::Point(211, 368);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(143, 24);
			this->comboBox1->TabIndex = 32;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigurationForm::comboBox1_SelectedIndexChanged_1);
			// 
			// ConfigurationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1239, 613);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->ownTerminatorTextBox);
			this->Controls->Add(this->ownLabel);
			this->Controls->Add(this->terminatorComboBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->panel);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
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
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"ConfigurationForm";
			this->Text = L"Form1";
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Configuration

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void saveConfiguration(System::Object^ sender, System::EventArgs^ e);

	private: System::Void refreshCOMList(System::Object^ sender, System::EventArgs^ e);

	private: System::Void autoConfiguration(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (System::Text::RegularExpressions::Regex::IsMatch(textBox1->Text, "[0-9]+"))
		{
			int value = System::Int32::Parse(textBox1->Text);
			if (value > 115000) {
				textBox1->Text = textBox1->Text->Remove(textBox1->Text->Length - 1);
			}
			else {
				ConfigurationForm::portConfiguration->baudRate = value;
			}
		}
		else if (textBox1->Text->Length > 0) {
			textBox1->Text = textBox1->Text->Remove(textBox1->Text->Length - 1);
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


	private: System::Void handleEditorChanged() {
		TokenizerMode mode = this->tokenizer->getTokenizerMode();

		bool textEditorSelected = this->radioButton1->Checked;

		if (textEditorSelected && this->tokenizer->getEditMode() != EditMode::TEXT) {
			this->tokenizer = gcnew StringTokenizer();
		}

		if (!textEditorSelected && this->tokenizer->getEditMode() != EditMode::HEX) {
			this->tokenizer = gcnew HexTokenizer();
		}

		this->tokenizer->setTerminator(mode, this->tokenizer->getCustomTerminator());
	}


#pragma endregion

	private:
		System::Void handle_reading(Object^ data) {
			Tokenizer^ tokenizer = static_cast<Tokenizer^>(data);

			while (CppCLRWinformsProjekt::listenBackground) {
				System::String^ message;
				int message_type = SerialPortManager::readSerialPort(
					ConfigurationForm::communicationHandle, message, CppCLRWinformsProjekt::listenBackground,
					tokenizer->getTerminator());

				if (message_type == -1 || !CppCLRWinformsProjekt::listenBackground) {
					continue;
				}

				// 0 ping request
				// 3 - ping acknowledgement
				if (message_type == 0) {
					DateTime now = DateTime::Now;
					String^ timestamp = now.ToString() + tokenizer->getTerminator();

					bool success = SerialPortManager::writeSerialPort(ConfigurationForm::communicationHandle, timestamp,
						MessageTypesEnum::PING_ACKNOWLEDGEMENT, timestamp->Length);
					continue;
				}

				if (message_type == 1) {
					UpdateResponseText(message);
					// send acknowledgement message
					bool success = SerialPortManager::writeSerialPort(ConfigurationForm::communicationHandle,
						tokenizer->getTerminator(), MessageTypesEnum::MESSAGE_ACKNOWLEDGEMENT, tokenizer->getTerminator()->Length);
					continue;
				}

				if (message_type == 2) {
					// message acknowledged - allow to send the next message
					ConfigurationForm::messsageAcknowledged = true;
					DisplayAcknowledgmentBox(NULL);
				}

				if (message_type == 3) {
					ConfigurationForm::messsageAcknowledged = true;

					DateTime pingStart = pingStartDatetime;
					DateTime pingResponseReceived = DateTime::Now;
					DateTime pingRequestReceived;

					if (DateTime::TryParse(message, pingRequestReceived)) {
						TimeSpan timeDiffPingStartToResponse = pingResponseReceived.Subtract(pingStart);
						TimeSpan timeDiffPingStartToRequest = pingRequestReceived.Subtract(pingStart);

						String^ result = "Ping Start: " + pingStart.ToString() + "\n"
							+ "Ping Request Received: " + pingRequestReceived.ToString() + "\n"
							+ "Ping Response Received: " + pingResponseReceived.ToString() + "\n\n"
							+ "Time Difference (Ping Start to Request): " + timeDiffPingStartToRequest.TotalMilliseconds.ToString() + " ms\n"
							+ "Time Difference (Ping Start to Response): " + timeDiffPingStartToResponse.TotalMilliseconds.ToString() + " ms";


						// Display the message box
						DisplayPingResultBox(result);
					}
				}
			}
		}

	private:
		void UpdateResponseText(System::String^ text) {
			if (textBox3->InvokeRequired)
			{
				textBox3->Invoke(gcnew Action<System::String^>(this, &ConfigurationForm::UpdateResponseText), text);
			}
			else
			{
				textBox3->AppendText(Environment::NewLine + "<message>" + text + "</message>");
			}
		}

		void DisplayAcknowledgmentBox(System::Object^ args) {
			if (textBox3->InvokeRequired)
			{
				textBox3->Invoke(gcnew Action<System::Object^>(this, &ConfigurationForm::DisplayAcknowledgmentBox), NULL);
			}
			else
			{
				textBox2->Clear();
			}
		}

		void DisplayPingResultBox(System::String^ args) {
			if (textBox3->InvokeRequired)
			{
				textBox3->Invoke(gcnew Action<System::String^>(this, &ConfigurationForm::DisplayPingResultBox), args);
			}
			else
			{
				MessageBox::Show(args, "Ping Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!CppCLRWinformsProjekt::ConfigurationForm::isCommunicationOpen) {
			System::Windows::Forms::MessageBox::Show("Najpierw należy nawiązać połączenie na porcie COM", "Błąd",
				System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
			return;
		}

		if (CppCLRWinformsProjekt::listenBackground) return;
		CppCLRWinformsProjekt::listenBackground = true;


		// Create a new thread and pass parameters using the delegate
		System::Threading::Thread^ myThread =
			gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(
				this, &ConfigurationForm::handle_reading));

		this->label11->Text = "Started";
		myThread->Start(this->tokenizer);
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		/*if (!ConfigurationForm::messsageAcknowledged) {
			System::Windows::Forms::MessageBox::Show("Nie otrzymano potwierdzenia poprzedniej operacji (Message not akcnowledged)", "Błąd",
				System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
			return;
		}*/

		this->pingStartDatetime = DateTime::Now;
		SerialPortManager::writeSerialPort(ConfigurationForm::communicationHandle, "", MessageTypesEnum::PING, 0);

		ConfigurationForm::messsageAcknowledged = false;
	}

	private: System::Void sendMessage(System::Object^ sender, System::EventArgs^ e) {
		/*if (!ConfigurationForm::messsageAcknowledged) {
			System::Windows::Forms::MessageBox::Show("Nie otrzymano potwierdzenia poprzedniej operacji (Message not akcnowledged)", "Błąd",
				System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
			return;
		}*/

		System::String^ toWrite = this->textBox2->Text->ToString() + tokenizer->getTerminator();
		SerialPortManager::writeSerialPort(ConfigurationForm::communicationHandle, toWrite, MessageTypesEnum::NORMAL_MESSAGE, toWrite->Length);
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLRWinformsProjekt::listenBackground = false;
		this->label11->Text = "Stopped";
	}

	private: System::Void bitsCountChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ stopBitCount = (String^)this->bitsCountComboBox->SelectedItem;
		if (stopBitCount != nullptr)
			CppCLRWinformsProjekt::ConfigurationForm::portConfiguration->bitCount = Int32::Parse(stopBitCount);
	}

	private: System::Void controlTypeChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ controlType = (String^)this->controlTypeComboBox->SelectedItem;
		if (controlType != nullptr)
			CppCLRWinformsProjekt::ConfigurationForm::portConfiguration->dataControlType = controlType->ToCharArray()[0];
	}

	private: System::Void stopBitCountComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ stopBitCount = (String^)this->stopBitCountComboBox->SelectedItem;
		if (stopBitCount != nullptr)
			CppCLRWinformsProjekt::ConfigurationForm::portConfiguration->stopBitCount = Int32::Parse(stopBitCount);
	}
	private: System::Void comboBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
		int index = this->comboBox1->SelectedIndex;
		portConfiguration->flowControl = index;
	}
private: System::Void ownTerminatorTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (this->ownTerminatorTextBox->Text->Length > 2) {
		this->ownTerminatorTextBox->Text = this->ownTerminatorTextBox->Text->ToString()->Substring(0, 2);
	}

	this->ownTerminatorTextBox->Text = this->ownTerminatorTextBox->Text->ToUpper();
	tokenizer->setTerminator(TokenizerMode::CUSTOM, this->ownTerminatorTextBox->Text->ToString());
}
};



}
