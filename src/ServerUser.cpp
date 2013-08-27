#include "ServerUser.h"

ServerUser::ServerUser() : User(UserType::SERVER)
{
}

ServerUser::ServerUser(const std::string& _hostname) : User(UserType::SERVER, _hostname)
{
}

ServerUser::~ServerUser()
{
}
