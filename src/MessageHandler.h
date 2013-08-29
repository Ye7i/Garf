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

#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include "Message.h"
#include "MessageParser.h"

#include <string>

class MessageHandler
{
	public:
        static MessageHandler* getInstance();
        virtual ~MessageHandler();
        
        void handle(const std::string& _msg);
    private:
        MessageHandler();
        MessageHandler(MessageHandler const&);
        void operator=(MessageHandler const&);
        
        static MessageHandler* instance;
};

#endif
