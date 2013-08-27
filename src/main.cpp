/* Greetings all who dare to tread here.
 * Originally written by Frank Allenby.
 * Based on Tyler Allen's, which can be found over at http://www.the-tech-tutorial.com/?p=1716
 * 
 * His work is likely to end up a shuddering, sputtering remnant of its original self. Can't say I mind that, though.
 * 
 * If you do hang around; thank you. I hope that you don't cringe too many times.
 * If you do, though, please drop a comment on the project repo at https://github.com/Ye7i/Garf.
 * If you're really, really nice, add a few lines of code or fix some stuff.
 */

#include <iostream>
#include <vector>

#include "Garf.h"
#include "Channel.h"
#include "ChannelList.h"
#include "Server.h"
#include "HumanUser.h"

using namespace std;

int main()
{
	ChannelList list;
	Channel chan("#test");
	list.addChannel(chan);
	Channel chan2("#test2");
	list.addChannel(chan2);
	
	Server server("127.0.0.1", "6667", 100);
	HumanUser user("garf", "USER guest tolmoon tolsun :Ronnie Reagan\r\n");
	
	Garf garf = Garf(user, server, list);
	garf.start();
	
	return 0;
}
