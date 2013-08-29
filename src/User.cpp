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

#include "User.h"

User::User()
{
}

User::User(const UserType::Value& _type, const std::string& _hostname)
{
	type = _type;
	
	if (_hostname != "")
	{
		hostname = _hostname;
	} else
	{
		hostname = "";
	}
}

User::~User()
{
}

void User::setHostname(const std::string& _hostname)
{
	hostname = _hostname;
}

const std::string& User::getHostname() const
{
	return hostname;
}

const UserType::Value& User::getType() const
{
	return type;
}

bool User::compareType(const UserType::Value& _type)
{
	return (type == _type);
}
