#ifndef GARF_H
#define GARF_H

#include "Channel.h"
#include "ChannelList.h"
#include "Server.h"
#include "HumanUser.h"

#include <string.h>
#include <vector>

class Garf
{
	public:
		Garf(HumanUser* _user, Server* _server, ChannelList* _channelList);
		
		virtual ~Garf();

		bool setup;

		void start();

		void joinChannel(Channel* _channel);

	private:
		int socketDescriptor;

		HumanUser* user;
		Server* server;
		ChannelList* channelList;

		bool isConnected(std::string buf);

		std::string timeNow();

		bool sendData(const std::string& msg);

		void sendPong(const std::string& buf);

		void msgHandel(const std::string& buf);
		
		bool charSearch(const std::string& toSearch, const std::string& searchFor);
};

#endif
