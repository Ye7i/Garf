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

MessageParser::MessageParser()
{
}

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
	Message *msg;
	
	// TODO: Everything else
	
	return msg;
}
