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

#ifndef CHANNEL_LIST_H
#define CHANNEL_LIST_H

#include "Channel.h"

#include <vector>
#include <string>

class ChannelList
{
	public:
		ChannelList();
		virtual ~ChannelList();
		
		void addChannel(Channel* _channel);
		
		void removeChannel(Channel* _channel);
		void removeChannel(const std::string& _channelName);
		
		bool channelExists(const std::string& _channelName) const;
		bool channelExists(Channel* _channel) const;
		
		int getChannelIndex(const std::string& _channelName) const;
		int getChannelIndex(Channel* _channel) const;
		
		Channel* getChannel(int _index) const;
		
		int size() const;
	private:
		std::vector<Channel*> channels;
};

#endif
