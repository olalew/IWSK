#include "pch.h"
#include "TokenizerService.h"

System::String^ StringTokenizer::getContentToSend() {
	
	System::String^ content;
	
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

System::String^ HexTokenizer::getContentToSend() {
	//StringTokenizer tokenizer(this->mode, this->customTerminator, content);
	//return tokenizer.getContentToSend();
	return "";
}