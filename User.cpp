#include "User.h"

User::User()
{
	nick = "";
	usr = "";
}

User::User(const std::string& _nick, const std::string& _usr)
{
	nick = _nick;
	usr = _usr;
}

User::~User()
{
}

void User::setNick(const std::string& _nick)
{
	nick = _nick;
}

void User::setUsr(const std::string& _usr)
{
	usr = _usr;
}

const std::string& User::getNick() const
{
	return nick;
}

const std::string& User::getUsr() const
{
	return usr;
}
