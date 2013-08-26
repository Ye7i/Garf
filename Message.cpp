#include "Message.h"

Message::Message()
{
	
}

Message::Message(const std::string& _data)
{
	rawContent = _data;
}

Message::~Message()
{
}

void Message::setType(const MessageType::Value& _type)
{
	type = _type;
}

const MessageType::Value& Message::getType() const
{
	return type;
}

bool Message::compareType(const MessageType::Value& _type)
{
	return (type == _type);
}
