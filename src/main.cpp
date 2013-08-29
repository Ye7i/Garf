/*	Garf IRC bot
    Copyright (C) 2013  fallenby

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. 
    
    Contact me(the founding developer) at:
    fallenby@outlook.com */

/* Greetings all..
 * Originally written by Frank Allenby.
 * 
 * This work is based on Tyler Allen's code, which can be found over 
 * at http://www.the-tech-tutorial.com/?p=1716
 * 
 * If you do hang around; thank you. I hope that you don't cringe too many times.
 * If you do, though, please drop a comment on the project repo at https://github.com/fallenby/Garf.
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
	ChannelList *list = new ChannelList();
	Channel *chan = new Channel("#test");
	list->addChannel(chan);
	Channel *chan2 = new Channel("#test2");
	list->addChannel(chan2);
	
	Server *server = new Server("127.0.0.1", "6667", 100);
	HumanUser *user = new HumanUser("garf", "USER guest tolmoon tolsun :Ronnie Reagan\r\n");
	
	Garf garf = Garf(user, server, list);
	garf.start();
	
	delete list;
	delete chan;
	delete chan2;
	delete server;
	delete user;
	
	return 0;
}
