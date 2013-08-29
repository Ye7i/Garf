#ifndef COMMAND_HELLO_H
#define COMMAND_HELLO_H

#include "Command.h"

class CommandHello : public Command
{
	public:
		CommandHello();
		virtual ~CommandHello();
		Message* execute();
};

#endif
