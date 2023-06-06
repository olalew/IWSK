#pragma once
#include <string>
#include <vector>
#include <map>
#include <utility> 

enum TokenizerMode {
	NONE,
	CR,
	LF,
	CR_LF,
	CUSTOM
};

enum EditMode {
	TEXT,
	HEX
};



ref class Tokenizer {
protected:
	TokenizerMode mode = TokenizerMode::NONE;
	System::String^ customTerminator;
public:
	virtual System::String^ getContentToSend() = 0;
	virtual EditMode getEditMode() = 0;

	void setTerminator(TokenizerMode mode, System::String^ customTerminator) {
		this->mode = mode;
		this->customTerminator = customTerminator;
	}

	System::String^ getTerminator() {
		switch (mode) {
		case TokenizerMode::CR:
			return "\r";
		case TokenizerMode::LF:
			return "\n";
		case TokenizerMode::CR_LF:
			return "\r\n";
		case TokenizerMode::CUSTOM:
			return customTerminator;
		default:
			return "";
		}
	}

	TokenizerMode getTokenizerMode() {
		return this->mode;
	}

	System::String^ getCustomTerminator() {
		return this->customTerminator;
	}

	static TokenizerMode parseTokenizerModeString(std::string str) {
		if (str == "NONE") return TokenizerMode::NONE;
		if (str == "CR") return TokenizerMode::CR;
		if (str == "LF") return TokenizerMode::LF;
		if (str == "CR-LF") return TokenizerMode::CR_LF;
		if (str == "CUSTOM") return TokenizerMode::CUSTOM;

		return TokenizerMode::NONE;
	}
};

ref class StringTokenizer : public Tokenizer
{
private:
	System::String^ content;

public:
	StringTokenizer() {}
	StringTokenizer(TokenizerMode mode, System::String^ customTerminator, System::String^ content) {
		this->mode = mode;
		this->customTerminator = customTerminator;
		this->content = content;
	}

	virtual System::String^ getContentToSend() override;

	virtual EditMode getEditMode() override {
		return EditMode::TEXT;
	}
};

ref class HexTokenizer: public Tokenizer
{
private:
	System::Collections::Generic::List<char>^ content;

public:
	HexTokenizer() {
		content = gcnew System::Collections::Generic::List<char>();
	}

	virtual System::String^ getContentToSend() override;

	virtual EditMode getEditMode() override {
		return EditMode::HEX;
	}
};

