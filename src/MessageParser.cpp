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

#include "MessageParser.h"

MessageParser::MessageParser(const std::string& _message) : message(_message)
{
}

MessageParser::~MessageParser()
{
}

void MessageParser::setMessage(const std::string& _message)
{
	message = _message;
}

Message* MessageParser::getResult()
{
	return parseMessage();
}

Message* MessageParser::parseMessage()
{
	// Ugly code, sorry. Tired, and still a noob.
	
	bool priv = false;
	
	if (message[0] == ':')
	{
		priv = true;
	}
	
	if (priv)
	{
		// Grab the position of the closing ":"
		int endPos = message.find(":", 1);
		
		// Find the position of the "!" character, signifying
		// the end location of the username the message
		// originated from.
		int exclPos = message.find("!", 1);
		
		if (endPos == -1)
		{
			// Getting here means the closing ":" was not found.
			// The only one we're currently interested in is
			// the PING command.
			
			if (message.substr(0, message.find(" ", 0)) == "PING")
			{
				// Looks like we found a PING command.
				
				int spacePos = message.find(" ", exclPos);
			
				std::string hostname = message.substr(exclPos, spacePos);
				
				User *usr = new ServerUser(hostname);
				
				Message *msg = new PingMessage(usr, message.substr(message.find(":", 0), message.length()));
				return msg;
			}
			
			return 0;
		}
		
		if (exclPos > endPos)
		{
			// Getting here means that there was a "!" somewhere in
			// the user message, but not within the actual server
			// command message body. We may as well treat this as
			// a non-human message.
			
			exclPos = -1;
		}
		
		if (exclPos == -1)
		{
			// Getting here means that it's not a direct private message.
			// It's probably some sort of server message, like MODE,
			// or the /NAMES list.
			// At this time we don't care about those, so return null.
			
			return 0;
		} else {
			// Getting here means that it's a direct private message.
			// It could be one of three things:
			//		- Channel message
			//		- Private message from a human
			// 		- Server message
			
			std::string nickname = message.substr(1, exclPos);
			
			int spacePos = message.find(" ", exclPos);
			
			std::string hostname = message.substr(exclPos, spacePos);
			
			int spacePosTwo = message.find(" ", spacePos);
			
			std::string command = message.substr(spacePos, spacePosTwo);
			
			int spacePosThree = message.find(" ", spacePosTwo);
			
			std::string origin = message.substr(spacePosTwo, spacePosThree);
			
			std::string trailingMessage = message.substr(endPos, message.length());
			
			Message *msg;

			User *usr = new HumanUser(nickname, "", hostname);

			if (command == "PRIVMSG")
			{
				msg = new HumanMessage(usr, trailingMessage, message);
			} else if (command == "QUIT")
			{
				msg = new QuitMessage(usr, trailingMessage, message);
			} else if (command == "JOIN")
			{
				msg = new JoinMessage(usr, trailingMessage, message);
			}

			return msg;
			
		}
	}
	
	return 0;
}
