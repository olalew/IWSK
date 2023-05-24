#include "pch.h"
#include "ConfigurationForm.h"

System::Void CppCLRWinformsProjekt::ConfigurationForm::saveConfiguration(System::Object^ sender, System::EventArgs^ e) {
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::refreshCOMList(System::Object^ sender, System::EventArgs^ e) {
	// read configuration code goes here

	this->comPortsComboBox->Items->Clear();
	this->comPortsComboBox->Items->Add("COM1");
	this->comPortsComboBox->Items->Add("COM4");
	this->comPortsComboBox->Items->Add("COM7");
	this->comPortsComboBox->Items->Add("COM10");
}

System::Void CppCLRWinformsProjekt::ConfigurationForm::autoConfiguration(System::Object^ sender, System::EventArgs^ e) {

}