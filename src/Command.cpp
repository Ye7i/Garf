#include "Command.h"

Command::Command(const std::string& _name, Message* _message) : name(_name), message(_message)
{
}

virtual Command::~Command
{
}
