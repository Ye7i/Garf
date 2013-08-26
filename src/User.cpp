#include "User.h"

User::User()
{
}

User::User(const UserType::Value& _type, const std::string& _hostname)
{
	type = _type;
	
	if (_hostname != "")
	{
		hostname = _hostname;
	} else
	{
		hostname = "";
	}
}

User::~User()
{
}

void User::setHostname(const std::string& _hostname)
{
	hostname = _hostname;
}

const std::string& User::getHostname() const
{
	return hostname;
}

const UserType::Value& User::getType() const
{
	return type;
}

bool User::compareType(const UserType::Value& _type)
{
	return (type == _type);
}
