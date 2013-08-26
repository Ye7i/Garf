#ifndef USER_H
#define USER_H

#include <string>

namespace UserType
{
	enum Value
	{
		HUMAN,
		SERVER
	};
}

class User
{
	public:
		User();
		User(const std::string& _nick, const std::string& _usr, const std::string& hostname = "");
		virtual ~User();
		
		void setNick(const std::string& _nick);
		void setUsr(const std::string& _usr);
		void setHostname(const std::string& _hostname);
		
		const std::string& getNick() const;
		const std::string& getUsr() const;
		const std::string& getHostname() const;
	private:
		std::string nick;
		std::string usr;
		std::string hostname;
};

#endif
