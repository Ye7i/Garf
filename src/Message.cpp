#include "Message.h"

Message::Message(const MessageType::Value& _type, const std::string& _data)
{
	type = _type;
	rawContent = _data;
}

Message::~Message()
{
}

const MessageType::Value& Message::getType() const
{
	return type;
}

bool Message::compareType(const MessageType::Value& _type)
{
	return (type == _type);
}
