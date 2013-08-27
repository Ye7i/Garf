#ifndef PING_MESSAGE_H
#define PING_MESSAGE_H

#include "ServerMessage.h"

class PingMessage : ServerMessage
{
	public:
		PingMessage(const std::string& _data);
		~PingMessage();
};

#endif
