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

class StringTokenizer
{
private:
	TokenizerMode mode;
	std::string customTerminator;
	std::string content;

public:
	StringTokenizer(TokenizerMode _mode, std::string _customTerminator, std::string _content)
		: mode(_mode), customTerminator(_customTerminator), content(_content)  {}

	StringTokenizer(TokenizerMode _mode, std::string _content)
		: mode(_mode), content(_content) {}

	std::string getContentToSend();
};

class HexTokenizer
{
private:
	TokenizerMode mode;
	std::string customTerminator;
	std::vector<char> content;

public:
	std::string getContentToSend();
};

