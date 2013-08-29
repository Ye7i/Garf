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

#include "ChannelList.h"

#include <algorithm>

ChannelList::ChannelList()
{
}

ChannelList::~ChannelList()
{
}

void ChannelList::addChannel(Channel* _channel)
{
	// Prevent adding duplicate channels.
	// There's no use for that, really. We're using the same nickname for each instance.
	if (!channelExists(_channel))
	{
		channels.push_back(_channel);
	}
}

void ChannelList::removeChannel(Channel* _channel)
{
	int index = getChannelIndex(_channel->getName());
	if (index != -1)
	{
		channels.erase(channels.begin() + getChannelIndex(_channel));
	}
}

void ChannelList::removeChannel(const std::string& _channelName)
{
	int index = getChannelIndex(_channelName);
	if (index != -1)
	{
		channels.erase(channels.begin() + getChannelIndex(_channelName));
	}
}

bool ChannelList::channelExists(const std::string& _channelName) const
{
	for (int i = 0; i < size(); ++i)
	{
		if (channels[i]->getName() == _channelName)
		{
			return true;
		}
	}
	return false;
}

bool ChannelList::channelExists(Channel* _channel) const
{
	return channelExists(_channel->getName());
}

int ChannelList::getChannelIndex(const std::string& _channelName) const
{
	for (int i = 0; i < size(); ++i)
	{
		if (channels[i]->getName() == _channelName)
		{
			return i;
		}
	}
	return -1;
}

int ChannelList::getChannelIndex(Channel* _channel) const
{
	return getChannelIndex(_channel->getName());
}

Channel* ChannelList::getChannel(int _index) const
{
	if (_index < size())
	{
		return channels[_index];
	}
	throw new std::string("ChannelList::getChannel(int) : Attempted to get channel but channel did not exist!");
}

int ChannelList::size() const
{
	return channels.size();
}
