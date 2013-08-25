#include <iostream>
#include "IrcBot.h"

using namespace std;

int main()
{
	IrcBot bot = IrcBot("garf","USER guest tolmoon tolsun :Ronnie Reagan\r\n");
	bot.start();

	return 0;
}
