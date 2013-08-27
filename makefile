garf: src/main.cpp Garf.o Channel.o ChannelList.o Server.o User.o Message.o MessageParser.o PingMessage.o QuitMessage.o JoinMessage.o HumanUser.o ServerUser.o ServerMessage.o PrivateMessage.o
	g++ -Wall src/main.cpp bin/Garf.o bin/Channel.o bin/ChannelList.o bin/Server.o bin/User.o bin/Message.o bin/MessageParser.o bin/PingMessage.o bin/QuitMessage.o bin/JoinMessage.o bin/HumanUser.o bin/ServerUser.o bin/ServerMessage.o bin/PrivateMessage.o -o bin/garf

Garf.o: src/Garf.cpp src/Garf.h
	g++ -Wall -c src/Garf.cpp -o bin/Garf.o

Channel.o: src/Channel.cpp src/Channel.h
	g++ -Wall -c src/Channel.cpp -o bin/Channel.o

ChannelList.o: src/ChannelList.cpp src/ChannelList.h
	g++ -Wall -c src/ChannelList.cpp -o bin/ChannelList.o

Server.o: src/Server.cpp src/Server.h
	g++ -Wall -c src/Server.cpp -o bin/Server.o

User.o: src/User.cpp src/User.h ServerUser.o
	g++ -Wall -c src/User.cpp -o bin/User.o

HumanUser.o: src/HumanUser.cpp src/HumanUser.h
	g++ -Wall -c src/HumanUser.cpp -o bin/HumanUser.o

ServerUser.o: src/ServerUser.cpp src/ServerUser.h
	g++ -Wall -c src/ServerUser.cpp -o bin/ServerUser.o

Message.o: src/Message.cpp src/Message.h
	g++ -Wall -c src/Message.cpp -o bin/Message.o

PrivateMessage.o: src/PrivateMessage.h src/PrivateMessage.cpp
	g++ -Wall -c src/PrivateMessage.cpp -o bin/PrivateMessage.o

ServerMessage.o: src/ServerMessage.h src/ServerMessage.cpp 
	g++ -Wall -c src/ServerMessage.cpp -o bin/ServerMessage.o

PingMessage.o: src/PingMessage.h src/PingMessage.cpp
	g++ -Wall -c src/PingMessage.cpp -o bin/PingMessage.o

QuitMessage.o: src/QuitMessage.h src/QuitMessage.cpp
	g++ -Wall -c src/QuitMessage.cpp -o bin/QuitMessage.o

JoinMessage.o: src/JoinMessage.h src/JoinMessage.cpp
	g++ -Wall -c src/JoinMessage.cpp -o bin/JoinMessage.o

MessageParser.o: src/MessageParser.cpp src/MessageParser.h
	g++ -Wall -c src/MessageParser.cpp -o bin/MessageParser.o

clean:
	rm -rf bin/*.o bin/garf
