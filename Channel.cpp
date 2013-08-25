#include "Channel.h"

Channel::Channel(std::string _name)
{
	name = _name;
}

std::string Channel::getName() const
{
	return name;
}
