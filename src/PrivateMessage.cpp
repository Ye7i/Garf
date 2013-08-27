#include "PrivateMessage.h"

PrivateMessage::PrivateMessage(const std::string& _data) : Message(MessageType::PRIVATE, MessageCommand::PRIVMSG, _data)
{
}

PrivateMessage::~PrivateMessage()
{
}
