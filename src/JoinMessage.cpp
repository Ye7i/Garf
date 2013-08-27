#include "JoinMessage.h"

JoinMessage::JoinMessage(const std::string& _data) : ServerMessage(MessageCommand::JOIN, _data)
{
}

JoinMessage::~JoinMessage()
{
}
