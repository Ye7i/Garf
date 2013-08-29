#ifndef JOIN_MESSAGE_H
#define JOIN_MESSAGE_H

#include "PrivateMessage.h"

class JoinMessage : public PrivateMessage
{
	public:
		JoinMessage(const std::string& _data);
		~JoinMessage();
};

#endif
