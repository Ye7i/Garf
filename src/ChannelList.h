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
