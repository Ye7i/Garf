#ifndef GARF_H
#define GARF_H

#include "Channel.h"
#include "ChannelList.h"

#include <string.h>
#include <vector>

class Garf
{
	public:
		Garf(const std::string& _nick, const std::string& _usr, const std::string& _serverAddress, const std::string& _port, const ChannelList& _channelList);
		
		virtual ~Garf();

		bool setup;

		void start();
		
		bool charSearch(std::string toSearch, std::string searchFor);

		void joinChannel(const Channel& _channel);

	private:
		int socketDescriptor;

		std::string nick;
		std::string usr;
		std::string port;
		std::string serverAddress;
		ChannelList channelList;
		
		unsigned int maxBufferSize;

		bool isConnected(std::string buf);

		std::string timeNow();

		bool sendData(std::string msg);

		void sendPong(std::string buf);

		void msgHandel(std::string buf);
};

#endif
