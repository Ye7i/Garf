#ifndef JOIN_MESSAGE_H
#define JOIN_MESSAGE_H

#include "ServerMessage.h"

class JoinMessage : public ServerMessage
{
	public:
		JoinMessage(const std::string& _data);
		~JoinMessage();
};

#endif
