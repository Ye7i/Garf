garf: src/main.cpp Garf.o Channel.o ChannelList.o Server.o User.o Message.o PrivateMessage.o HumanUser.o
	g++ src/main.cpp bin/Garf.o bin/Channel.o bin/ChannelList.o bin/Server.o bin/User.o bin/Message.o bin/PrivateMessage.o bin/HumanUser.o -o bin/garf

Garf.o: src/Garf.cpp src/Garf.h
	g++ -c src/Garf.cpp -o bin/Garf.o

Channel.o: src/Channel.cpp src/Channel.h
	g++ -c src/Channel.cpp -o bin/Channel.o

ChannelList.o: src/ChannelList.cpp src/ChannelList.h
	g++ -c src/ChannelList.cpp -o bin/ChannelList.o

Server.o: src/Server.cpp src/Server.h
	g++ -c src/Server.cpp -o bin/Server.o

User.o: src/User.cpp src/User.h
	g++ -c src/User.cpp -o bin/User.o

Message.o: src/Message.cpp src/Message.h
	g++ -c src/Message.cpp -o bin/Message.o

PrivateMessage.o: src/PrivateMessage.h src/PrivateMessage.cpp
	g++ -c src/PrivateMessage.cpp -o bin/PrivateMessage.o
	
HumanUser.o: src/HumanUser.cpp src/HumanUser.h
	g++ -c src/HumanUser.cpp -o bin/HumanUser.o

clean:
	rm -rf bin/*.o bin/garf
