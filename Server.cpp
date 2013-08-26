#include "Server.h"

Server::Server()
{
	port = "";
	addr = "";
}

Server::Server(const std::string _addr, const std::string& _port, const unsigned int& _maxBufSize)
{
	addr = _addr;
	port = _port;
	maxBufferSize = _maxBufSize;
}

Server::~Server()
{
}

void Server::setAddr(const std::string& _addr)
{
	addr = _addr;
}

void Server::setPort(const std::string& _port)
{
	port = _port;
}

void Server::setMaxBufSize(const unsigned int& _maxBufSize)
{
	maxBufferSize = _maxBufSize;
}

const std::string& Server::getAddr() const
{
	return addr;
}

const std::string& Server::getPort() const
{
	return port;
}

const unsigned int& Server::getMaxBufSize() const
{
	return maxBufferSize;
}
