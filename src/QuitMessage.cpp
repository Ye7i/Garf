#include "QuitMessage.h"

QuitMessage::QuitMessage(const std::string& _data) : PrivateMessage(MessageCommand::QUIT, _data)
{
}

QuitMessage::~QuitMessage()
{
}
