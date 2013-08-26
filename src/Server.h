#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server
{
	public:
		Server();
		Server(const std::string _addr, const std::string& _port, const unsigned int& _maxBufSize);
		virtual ~Server();
		
		void setAddr(const std::string& _addr);
		void setPort(const std::string& _port = "6667");
		void setMaxBufSize(const unsigned int& _maxBufSize = 500);
		
		const std::string& getAddr() const;
		const std::string& getPort() const;
		const unsigned int& getMaxBufSize() const;
	private:
		std::string port;
		std::string addr;
		unsigned int maxBufferSize;
};

#endif
