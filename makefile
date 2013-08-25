main.o: main.cpp IrcBot.o
	g++ main.cpp IrcBot.o -o ircbot

IrcBot.o: IrcBot.cpp IrcBot.h
	g++ -c IrcBot.cpp
