garf: main.cpp Garf.o Channel.o ChannelList.o Server.o User.o Message.o PrivateMessage.o HumanUser.o
	g++ main.cpp Garf.o Channel.o ChannelList.o Server.o User.o Message.o PrivateMessage.o HumanUser.o -o garf

Garf.o: Garf.cpp Garf.h
	g++ -c Garf.cpp

Channel.o: Channel.cpp Channel.h
	g++ -c Channel.cpp

ChannelList.o: ChannelList.cpp ChannelList.h
	g++ -c ChannelList.cpp

Server.o: Server.cpp Server.h
	g++ -c Server.cpp

User.o: User.cpp User.h
	g++ -c User.cpp

Message.o: Message.cpp Message.h
	g++ -c Message.cpp

PrivateMessage.o: PrivateMessage.h PrivateMessage.cpp
	g++ -c PrivateMessage.cpp
	
HumanUser.o: HumanUser.cpp HumanUser.h
	g++ -c HumanUser.cpp

clean:
	rm -rf *.o garf
