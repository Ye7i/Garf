#include <iostream>
#include "Garf.h"

#include <vector>
#include "Channel.h"

using namespace std;

int main()
{
	std::vector<Channel> channels;
	Channel chan("#test");
	channels.push_back(chan);
	Garf garf = Garf("garf","USER guest tolmoon tolsun :Ronnie Reagan\r\n", "127.0.0.1", "6667", channels);
	garf.start();

	return 0;
}
