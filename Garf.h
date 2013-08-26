#ifndef GARF_H
#define GARF_H

#include "Channel.h"
#include "ChannelList.h"
#include "Server.h"
#include "User.h"

#include <string.h>
#include <vector>

class Garf
{
	public:
		Garf(const User& _user, const Server& _server, const ChannelList& _channelList);
		
		virtual ~Garf();

		bool setup;

		void start();
		
		bool charSearch(std::string toSearch, std::string searchFor);

		void joinChannel(const Channel& _channel);

	private:
		int socketDescriptor;

		User user;
		Server server;
		ChannelList channelList;
		
		unsigned int maxBufferSize;

		bool isConnected(std::string buf);

		std::string timeNow();

		bool sendData(std::string msg);

		void sendPong(std::string buf);

		void msgHandel(std::string buf);
};

#endif
