#include "ChannelList.h"

#include <algorithm>

ChannelList::ChannelList()
{
}

ChannelList::~ChannelList()
{
}

void ChannelList::addChannel(const Channel& _channel)
{
	channels.push_back(_channel);
}

void ChannelList::removeChannel(const Channel& _channel)
{
	
}

void ChannelList::removeChannel(const std::string& _channelName)
{
	
}

bool ChannelList::channelExists(const std::string& _channelName) const
{
	for (int i = 0; i < size(); ++i)
	{
		if (channels[i].getName() == _channelName)
		{
			return true;
		}
	}
	return false;
}

bool ChannelList::channelExists(const Channel& _channel) const
{
	return channelExists(_channel.getName());
}

int ChannelList::getChannelIndex(const std::string& _channelName) const
{
	for (int i = 0; i < size(); ++i)
	{
		if (channels[i].getName() == _channelName)
		{
			return i;
		}
	}
	return 0;
}

int ChannelList::getChannelIndex(const Channel& _channel) const
{
	return getChannelIndex(_channel.getName());
}

const Channel& ChannelList::getChannel(int _index) const
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
