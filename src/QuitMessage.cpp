#include "QuitMessage.h"

QuitMessage::QuitMessage(const std::string& _data) : ServerMessage(MessageCommand::QUIT, _data)
{
}

QuitMessage::~QuitMessage()
{
}
