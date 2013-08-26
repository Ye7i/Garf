#include "HumanUser.h"

HumanUser::HumanUser()
{
}

HumanUser::HumanUser(const std::string& _nick, const std::string& _usr, const std::string& _hostname) : User(UserType::HUMAN, _hostname)
{
	nick = _nick;
	usr = _usr;
}

HumanUser::~HumanUser()
{
}

void HumanUser::setNick(const std::string& _nick)
{
	nick = _nick;
}

void HumanUser::setUsr(const std::string& _usr)
{
	usr = _usr;
}

const std::string& HumanUser::getNick() const
{
	return nick;
}

const std::string& HumanUser::getUsr() const
{
	return usr;
}
