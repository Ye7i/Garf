#include "PingMessage.h"

PingMessage::PingMessage(const std::string& _data) : ServerMessage(MessageCommand::PING, _data)
{
}

PingMessage::~PingMessage()
{
}
