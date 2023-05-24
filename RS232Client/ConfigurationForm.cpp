#include "pch.h"
#include "ConfigurationForm.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

System::Void CppCLRWinformsProjekt::ConfigurationForm::saveConfiguration(System::Object^ sender, System::EventArgs^ e) {
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::refreshCOMList(System::Object^ sender, System::EventArgs^ e) {
	this->comPortsComboBox->Items->Clear();

	std::vector<std::string> list = listCOMPorts();
	for (auto ptr = list.begin(); ptr != list.end(); ptr++) {
		std::string port = *ptr;
		System::Text::StringBuilder^ portBuilder = gcnew System::Text::StringBuilder(gcnew String(port.c_str()));
		this->comPortsComboBox->Items->Add(portBuilder->ToString());
	}

	if (this->comPortsComboBox->Items->Count > 0) {
		String^ port = (String^)this->comPortsComboBox->Items[0];
		CppCLRWinformsProjekt::portConfiguration.portName = msclr::interop::marshal_as<std::string>(port);
		this->comPortsComboBox->SelectedItem = this->comPortsComboBox->Items[0];
		readDefaultConfiguration();
	}
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::comPortsComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	this->portComSet = true;
	this->setComPortFollowingEnabledState(this->portComSet);

	String^ port = (String^)this->comPortsComboBox->Items[0];
	CppCLRWinformsProjekt::portConfiguration.portName = msclr::interop::marshal_as<std::string>(port);

	this->readDefaultConfiguration();
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::readDefaultConfiguration() {
	readCOMPortConfiguration(CppCLRWinformsProjekt::portConfiguration);

	CustomPortConfiguration config = CppCLRWinformsProjekt::portConfiguration;

	this->bitsCountComboBox->SelectedItem = (gcnew System::Text::StringBuilder(gcnew String(std::to_string(CppCLRWinformsProjekt::portConfiguration.bitCount)
		.c_str())))->ToString();
	this->controlTypeComboBox->SelectedItem = gcnew String(&CppCLRWinformsProjekt::portConfiguration.dataControlType);

	this->textBox1->Text = (gcnew System::Text::StringBuilder(gcnew String(std::to_string(CppCLRWinformsProjekt::portConfiguration.baudRate)
		.c_str())))->ToString();

	this->stopBitCountComboBox->SelectedItem = (gcnew System::Text::StringBuilder(gcnew String(std::to_string(CppCLRWinformsProjekt::portConfiguration.stopBitCount)
		.c_str())))->ToString();
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::autoConfiguration(System::Object^ sender, System::EventArgs^ e) {

}