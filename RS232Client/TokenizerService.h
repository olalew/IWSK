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



class Tokenizer {
protected:
	TokenizerMode mode = TokenizerMode::CR;
	std::string customTerminator;
public:
	virtual std::string getContentToSend() = 0;
	virtual EditMode getEditMode() = 0;

	void setTerminator(TokenizerMode mode, std::string customTerminator) {
		this->mode = mode;
		this->customTerminator = customTerminator;
	}

	TokenizerMode getTokenizerMode() {
		return this->mode;
	}

	std::string getCustomTerminator() {
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

class StringTokenizer: public Tokenizer
{
private:
	std::string content;

public:
	StringTokenizer() {}
	StringTokenizer(TokenizerMode mode, std::string customTerminator, std::string content) {
		this->mode = mode;
		this->customTerminator = customTerminator;
		this->content = content;
	}

	std::string getContentToSend();

	EditMode getEditMode() {
		return EditMode::TEXT;
	}
};

class HexTokenizer: public Tokenizer
{
private:
	std::vector<char> content;

public:
	std::string getContentToSend();

	EditMode getEditMode() {
		return EditMode::HEX;
	}
};

