#include "PrivateMessage.h"

PrivateMessage::PrivateMessage(const std::string& _data) : Message(MessageType::Value.PRIVATE _data)
{
	
}

PrivateMessage::~PrivateMessage()
{
}
