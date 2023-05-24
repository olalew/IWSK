#include "pch.h"
#include "TokenizerService.h"

std::string StringTokenizer::getContentToSend() {
	
	std::string content;
	
	switch (mode)
	{
	case CR:
		content = this->content + "\r";
		break;
	case LF:
		content = this->content + "\n";
		break;
	case CR_LF:
		content = this->content + "\r\n";
		break;
	case CUSTOM:
		content = this->content + this->customTerminator;
		break;

	case NONE:
	default:
		content = this->content;
		break;
	}

	return content;
}

std::string HexTokenizer::getContentToSend() {
	std::string content(this->content.begin(), this->content.end());
	
	StringTokenizer tokenizer(this->mode, this->customTerminator, content);
	return tokenizer.getContentToSend();
}