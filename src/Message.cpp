#include "Message.h"

Message::Message(const MessageType::Value& _type, const MessageCommand::Value& _command, const std::string& _data) : type(_type), rawContent(_data), command(_command)
{
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
