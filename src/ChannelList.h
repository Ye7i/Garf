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
		
		void addChannel(const Channel& _channel);
		
		void removeChannel(const Channel& _channel);
		void removeChannel(const std::string& _channelName);
		
		bool channelExists(const std::string& _channelName) const;
		bool channelExists(const Channel& _channel) const;
		
		int getChannelIndex(const std::string& _channelName) const;
		int getChannelIndex(const Channel& _channel) const;
		
		const Channel& getChannel(int _index) const;
		
		int size() const;
	private:
		std::vector<Channel> channels;
};

#endif
