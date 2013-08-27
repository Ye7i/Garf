#ifndef QUIT_MESSAGE_H
#define QUIT_MESSAGE_H

#include "ServerMessage.h"

class QuitMessage : public ServerMessage
{
	public:
		QuitMessage(const std::string& _data);
		~QuitMessage();
};

#endif
