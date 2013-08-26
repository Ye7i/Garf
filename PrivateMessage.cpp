#include "PrivateMessage.h"

PrivateMessage::PrivateMessage(const std::string& _data) : Message(MessageType::PRIVATE, _data)
{
}

PrivateMessage::~PrivateMessage()
{
}
