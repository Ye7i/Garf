#ifndef USER_H
#define USER_H

#include <string>

class User
{
	public:
		User();
		User(const std::string& _nick, const std::string& _usr);
		virtual ~User();
		
		void setNick(const std::string& _nick);
		void setUsr(const std::string& _usr);
		
		const std::string& getNick() const;
		const std::string& getUsr() const;
	private:
		std::string nick;
		std::string usr;
};

#endif
