#include "Server.h"

Server::Server()
{
	port = "";
	addr = "";
}

Server::Server(const std::string _addr, const std::string& _port)
{
	addr = _addr;
	port = _port;
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

const std::string& Server::getAddr() const
{
	return addr;
}

const std::string& Server::getPort() const
{
	return port;
}
