#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server
{
	public:
		Server();
		Server(const std::string _addr, const std::string& _port);
		virtual ~Server();
		
		void setAddr(const std::string& _addr);
		void setPort(const std::string& _port);
		
		const std::string& getAddr() const;
		const std::string& getPort() const;
	private:
		std::string port;
		std::string addr;
};

#endif
