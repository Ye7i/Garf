#include "MessageParser.h"

MessageParser::MessageParser()
{
}

MessageParser::MessageParser(const std::string& _message) : message(_message)
{
}

MessageParser::~MessageParser()
{
}

void MessageParser::setMessage(const std::string& _message)
{
	message = _message;
}

Message* MessageParser::getResult()
{
	return parseMessage();
}

Message* MessageParser::parseMessage()
{
	
}
