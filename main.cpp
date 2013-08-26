#include <iostream>
#include <vector>

#include "Garf.h"
#include "Channel.h"
#include "ChannelList.h"
#include "Server.h"
#include "User.h"

using namespace std;

int main()
{
	ChannelList list;
	Channel chan("#test");
	list.addChannel(chan);
	
	Server server("127.0.0.1", "6667");
	User user("garf", "USER guest tolmoon tolsun :Ronnie Reagan\r\n");
	
	Garf garf = Garf(user, server, list);
	garf.start();

	return 0;
}
