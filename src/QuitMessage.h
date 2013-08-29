#ifndef QUIT_MESSAGE_H
#define QUIT_MESSAGE_H

#include "PrivateMessage.h"

class QuitMessage : public PrivateMessage
{
	public:
		QuitMessage(const std::string& _data);
		~QuitMessage();
};

#endif
