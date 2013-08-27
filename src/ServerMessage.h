#ifndef SERVER_MESSAGE_H
#define SERVER_MESSAGE_H

#include "Message.h"

class ServerMessage : public Message
{
	public:
		ServerMessage(const MessageCommand::Value& _command, const std::string& _data);
		virtual ~ServerMessage();
};

#endif
