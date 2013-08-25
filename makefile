main.o: main.cpp Garf.o Channel.o
	g++ main.cpp Garf.o Channel.o -o ircbot

Garf.o: Garf.cpp Garf.h
	g++ -c Garf.cpp
	
Channel.o: Channel.cpp Channel.h
	g++ -c Channel.cpp
