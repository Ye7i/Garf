/*
 * IrcBot.h
 *
 *  Created on: 15 Jul 2011
 *      Author: tyler
 */

#ifndef IRCBOT_H_
#define IRCBOT_H_

#include <string>

class IrcBot
{
	public:
		IrcBot(std::string _nick, std::string _usr);
		virtual ~IrcBot();

		bool setup;

		void start();
		bool charSearch(std::string toSearch, std::string searchFor);

	private:
		std::string port;
		
		int socketDescriptor;

		std::string nick;
		std::string usr;

		bool isConnected(std::string buf);

		std::string timeNow();

		bool sendData(std::string msg);

		void sendPong(std::string buf);

		void msgHandel(std::string buf);
};

#endif /* IRCBOT_H_ */
