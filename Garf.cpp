#include "Garf.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

Garf::Garf(const std::string& _nick, const std::string& _usr, const std::string& _serverAddress, const std::string& _port, const std::vector<Channel>& _channels)
{
	nick = _nick;
	usr = _usr;
	port = _port;
	serverAddress = _serverAddress;
	channels = _channels;
}

Garf::~Garf()
{
	close(socketDescriptor);
}

void Garf::start()
{
	struct addrinfo hints, *servinfo;

	//Setup run with no errors
	setup = true;

	//Ensure that servinfo is clear
	memset(&hints, 0, sizeof hints); // make sure the struct is empty

	//setup hints
	hints.ai_family = AF_UNSPEC; // don't care IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; // TCP stream sockets

	//Setup the structs if error print why
	int res;
	if ((res = getaddrinfo(serverAddress.c_str(), port.c_str(), &hints, &servinfo)) != 0)
	{
		setup = false;
		fprintf(stderr,"getaddrinfo: %s\n", gai_strerror(res));
	}

	//setup the socket
	if ((socketDescriptor = socket(servinfo->ai_family,servinfo->ai_socktype,servinfo->ai_protocol)) == -1)
	{
		perror("client: socket");
	}

	//Connect
	if (connect(socketDescriptor,servinfo->ai_addr, servinfo->ai_addrlen) == -1)
	{
		close(socketDescriptor);
		perror("Client Connect");
	}

	freeaddrinfo(servinfo);

	//Recv some data
	int numbytes;
	char buf[maxBufferSize];

	int count = 0;
	while (1)
	{
		//declars
		count++;

		switch (count) {
			case 3:
					//after 3 recives send data to server (as per IRC protacol)
					sendData("NICK " + nick + "\r\n");
					sendData(usr);
				break;
			case 4:
					for (int i = 0; i < channels.size(); ++i)
					{
						joinChannel(channels[i]);
					}
			default:
				break;
		}

		//Recv & print Data
		numbytes = recv(socketDescriptor,buf,maxBufferSize-1,0);
		buf[numbytes]='\0';
		std::cout << buf;
		//buf is the data that is recived

		//Pass buf to the message handeler
		msgHandel(buf);

		//If Ping Recived
		/*
		 * must reply to ping overwise connection will be closed
		 * see http://www.irchelp.org/irchelp/rfc/chapter4.html
		 */
		if (charSearch(buf,"PING"))
		{
			sendPong(buf);
		}

		//break if connection closed
		if (numbytes==0)
		{
			std::cout << "----------------------CONNECTION CLOSED---------------------------"<< std::endl;
			std::cout << timeNow() << std::endl;

			break;
		}
	}
}


bool Garf::charSearch(std::string haystack, std::string needle)
{
	return (haystack.find(needle) != std::string::npos);
}

bool Garf::isConnected(std::string buf)
{//returns true if "/MOTD" is found in the input strin
	//If we find /MOTD then its ok join a channel
	if (charSearch(buf,"/MOTD") == true)
		return true;
	else
		return false;
}

std::string Garf::timeNow()
{//returns the current date and time
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	return asctime (timeinfo);
}

bool Garf::sendData(std::string msg)
{//Send some data
	//Send some data
	int len = msg.length();
	int bytes_sent = send(socketDescriptor,msg.c_str(),len,0);

	if (bytes_sent == 0)
		return false;
	else
		return true;
}

void Garf::sendPong(std::string buf)
{
	//Get the reply address
	//loop through bug and find the location of PING
	//Search through each char in toSearch

	std::string toSearch = "PING ";

	for (int i = 0; i < buf.length(); ++i)
	{
		//If the active char is equil to the first search item then search toSearch
		if (buf[i] == toSearch[0])
		{
			bool found = true;
			//search the char array for search field
			for (int x = 1; x < 4; ++x)
			{
				if (buf[i+x]!=toSearch[x])
				{
					found = false;
				}
			}

			//if found return true;
			if (found == true)
			{
				int count = 0;
				//Count the chars
				for (int x = (i+toSearch.length()); x < buf.length(); ++x)
				{
					count++;
				}

				//Create the new char array
				char returnHost[count + 5];
				returnHost[0]='P';
				returnHost[1]='O';
				returnHost[2]='N';
				returnHost[3]='G';
				returnHost[4]=' ';


				count = 0;
				//set the hostname data
				for (int x = (i+toSearch.length()); x < buf.length(); ++x)
				{
					returnHost[count+5]=buf[x];
					count++;
				}

				//send the pong
				if (sendData(returnHost))
				{
					std::cout << timeNow() <<"  Ping Pong" << std::endl;
				}

				return;
			}
		}
	}
}

void Garf::msgHandel(std::string buf)
{
	if (charSearch(buf, "!" + nick))
	{
		sendData("PRIVMSG #test :Yes?\r\n");
	}
}

void Garf::joinChannel(Channel _channel)
{
	sendData("JOIN " + _channel.getName() + "\r\n");
}
