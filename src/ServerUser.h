#ifndef SERVER_USER_H
#define SERVER_USER_H

#include "User.h"

class ServerUser : public User
{
	public:
		ServerUser();
		ServerUser(const std::string& _hostname);
		virtual ~ServerUser();
};

#endif
