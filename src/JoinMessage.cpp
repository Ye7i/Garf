#include "JoinMessage.h"

JoinMessage::JoinMessage(const std::string& _data) : PrivateMessage(MessageCommand::JOIN, _data)
{
}

JoinMessage::~JoinMessage()
{
}
