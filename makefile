garf: main.cpp Garf.o Channel.o ChannelList.o
	g++ main.cpp Garf.o Channel.o ChannelList.o -o garf

Garf.o: Garf.cpp Garf.h
	g++ -c Garf.cpp
	
Channel.o: Channel.cpp Channel.h
	g++ -c Channel.cpp

ChannelList.o: ChannelList.cpp ChannelList.h
	g++ -c ChannelList.cpp

clean:
	rm -rf *.o garf
