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

#ifndef MESSAGE_H
#define MESSAGE_H

#include "User.h"

#include <string>

namespace MessageType
{
	enum Value
	{
		PRIVATE,
		CHANNEL,
		SERVER
	};
}

namespace MessageCommand
{
	enum Value
	{
		PRIVMSG,
		JOIN,
		QUIT,
		PING
	};
}

class Message
{
	public:
		Message(const MessageType::Value& _type, User* _user, const MessageCommand::Value& _command, const std::string& _data);
		virtual ~Message();

		const MessageType::Value& getType() const;
		User* getOriginator();
		const std::string& getRawContent();
		const MessageCommand::Value& getCommand();
		
		bool compareType(const MessageType::Value& _type);
	private:
		MessageType::Value type;
		std::string rawContent;
		User* originator;
		MessageCommand::Value command;
};

#endif
