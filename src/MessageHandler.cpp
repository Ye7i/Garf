/*	Garf IRC bot
    Copyright (C) 2013  fallenby

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. 
    
    Contact me(the founding developer) at:
    fallenby@outlook.com */
    
#include "MessageHandler.h"

MessageHandler::MessageHandler()
{
}

// Declared and implemented as empty as we don't want other
// objects to be able to create rogue instances of the class.
MessageHandler::MessageHandler(MessageHandler const&)
{
}

// "Lazy loading" of our singleton instance.
// Only create the instance when first called.
static MessageHandler::MessageHandler* getInstance()
{
	if (!instance)
	{
		instance = new MessageHandler();
	}
	return instance;
}

// Declared and implemented as empty as we don't want other
// objects to be able to create rogue instances of the class.
void MessageHandler::operator=(MessageHandler const&)
{
}

MessageHandler::~MessageHandler()
{
	// Delete this badass up in here
	delete instance;
	instance = 0;
}

// Function accepts raw IRC message data and processes it.
void MessageHandler::handle(const std::string& _msg)
{
	MessageParser *parser = new MessageParser(_msg);
	Message *parsedMessage = parser->getResult();
}
