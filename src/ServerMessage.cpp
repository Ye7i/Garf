#include "ServerMessage.h"

ServerMessage::ServerMessage(const MessageCommand::Value& _command, const std::string& _data) : Message(MessageType::SERVER, _command, _data)
{
}

ServerMessage::~ServerMessage()
{
}
