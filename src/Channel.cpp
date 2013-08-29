#include "Channel.h"

Channel::Channel(const std::string& _name)
{
	name = _name;
}

Channel::~Channel()
{
}

const std::string& Channel::getName() const
{
	return name;
}
