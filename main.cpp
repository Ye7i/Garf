#include <iostream>
#include <vector>

#include "Garf.h"
#include "Channel.h"
#include "ChannelList.h"

using namespace std;

int main()
{
	ChannelList list;
	Channel chan("#test");
	list.addChannel(chan);
	Garf garf = Garf("garf","USER guest tolmoon tolsun :Ronnie Reagan\r\n", "127.0.0.1", "6667", list);
	garf.start();

	return 0;
}
