garf: main.cpp Garf.o Channel.o
	g++ main.cpp Garf.o Channel.o -o garf

Garf.o: Garf.cpp Garf.h ChannelList.o
	g++ -c Garf.cpp ChannelList.o
	
Channel.o: Channel.cpp Channel.h
	g++ -c Channel.cpp

ChannelList.o: ChannelList.cpp ChannelList.h
	g++ -c ChannelList.cpp

clean:
	rm -rf *.o garf
