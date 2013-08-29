#include "PrivateMessage.h"

PrivateMessage::PrivateMessage(const MessageCommand::Value& _command, const std::string& _data) : Message(MessageType::PRIVATE, _command, _data)
{
}

PrivateMessage::~PrivateMessage()
{
}
