#ifndef PRIVATE_MESSAGE_H
#define PRIVATE_MESSAGE_H

#include "Message.h"

class PrivateMessage : public Message
{
	public:
		PrivateMessage(const std::string& _data);
		virtual ~PrivateMessage();
};

#endif