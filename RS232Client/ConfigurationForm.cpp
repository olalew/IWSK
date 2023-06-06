#include "pch.h"
#include "ConfigurationForm.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

System::Void CppCLRWinformsProjekt::ConfigurationForm::saveConfiguration(System::Object^ sender, System::EventArgs^ e) {
	if (CppCLRWinformsProjekt::ConfigurationForm::isCommunicationOpen) {
		CloseHandle(CppCLRWinformsProjekt::ConfigurationForm::communicationHandle);
		CppCLRWinformsProjekt::ConfigurationForm::communicationHandle = NULL;
		CppCLRWinformsProjekt::ConfigurationForm::isCommunicationOpen = false;
	}

	HANDLE handle;
	SerialPortManager::setupConnection(handle);

	CppCLRWinformsProjekt::ConfigurationForm::communicationHandle = handle;

	if (CppCLRWinformsProjekt::ConfigurationForm::communicationHandle > 0) {
		CppCLRWinformsProjekt::ConfigurationForm::isCommunicationOpen = true;
	}
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	/*bool customTerminatorMode = this->terminatorComboBox->SelectedItem == "Custom";
	this->ownLabel->Visible = customTerminatorMode;
	this->ownTerminatorTextBox->Visible = customTerminatorMode;*/

	int index = this->terminatorComboBox->SelectedIndex;
	if (index == 4) {
		this->ownLabel->Visible = true;
		this->ownTerminatorTextBox->Visible = true;
		tokenizer->setTerminator(TokenizerMode::CUSTOM, this->ownTerminatorTextBox->Text->ToString());
	}
	else {
		this->ownLabel->Visible = false;
		this->ownTerminatorTextBox->Visible = false;

		switch (index)
		{
		case 0:
			tokenizer->setTerminator(TokenizerMode::NONE, "");
			break;
		case 1:
			tokenizer->setTerminator(TokenizerMode::CR, "");
			break;
		case 2:
			tokenizer->setTerminator(TokenizerMode::LF, "");
			break;
		case 3:
			tokenizer->setTerminator(TokenizerMode::CR_LF, "");
			break;
		default:
			break;
		}
	}
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::updateTerminatorString() {

	String^ terminator = (String^)this->terminatorComboBox->Items[0];
	TokenizerMode mode = Tokenizer::parseTokenizerModeString(msclr::interop::marshal_as<std::string>(terminator));

	String^ customTerminatorString = (String^)this->ownTerminatorTextBox->Text;

	this->tokenizer->setTerminator(mode, customTerminatorString);
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::refreshCOMList(System::Object^ sender, System::EventArgs^ e) {
	this->comPortsComboBox->Items->Clear();

	std::vector<std::string> list = EndpointManager::listCOMPorts();
	for (auto ptr = list.begin(); ptr != list.end(); ptr++) {
		std::string port = *ptr;
		System::Text::StringBuilder^ portBuilder = gcnew System::Text::StringBuilder(gcnew String(port.c_str()));
		this->comPortsComboBox->Items->Add(portBuilder->ToString());
	}

	if (this->comPortsComboBox->Items->Count > 0) {
		String^ port = (String^)this->comPortsComboBox->Items[0];
		CppCLRWinformsProjekt::ConfigurationForm::portConfiguration->portName = port;
		this->comPortsComboBox->SelectedItem = this->comPortsComboBox->Items[0];
		readDefaultConfiguration();
	}
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::comPortsComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	this->portComSet = true;
	this->setComPortFollowingEnabledState(this->portComSet);

	String^ port = (String^)this->comPortsComboBox->Items[0];
	CppCLRWinformsProjekt::ConfigurationForm::portConfiguration->portName = port;

	this->readDefaultConfiguration();
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::readDefaultConfiguration() {
	EndpointManager::readCOMPortConfiguration(CppCLRWinformsProjekt::ConfigurationForm::portConfiguration);

	CustomPortConfiguration^ config = CppCLRWinformsProjekt::ConfigurationForm::portConfiguration;

	this->bitsCountComboBox->SelectedItem = (gcnew System::Text::StringBuilder(gcnew String(std::to_string(config->bitCount)
		.c_str())))->ToString();


	array<wchar_t>^ charArray = gcnew array<wchar_t>(1);
	charArray[0] = config->dataControlType;

	this->controlTypeComboBox->SelectedItem = gcnew String(charArray);

	this->textBox1->Text = (gcnew System::Text::StringBuilder(gcnew String(std::to_string(config->baudRate)
		.c_str())))->ToString();

	this->stopBitCountComboBox->SelectedItem = (gcnew System::Text::StringBuilder(gcnew String(std::to_string(config->stopBitCount)
		.c_str())))->ToString();

	this->comboBox1->SelectedIndex = config->flowControl;
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::autoConfiguration(System::Object^ sender, System::EventArgs^ e) {

}


