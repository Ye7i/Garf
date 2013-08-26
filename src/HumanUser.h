#ifndef HUMAN_USER_H
#define HUMAN_USER_H

#include "User.h"

#include <string>

class HumanUser : public User
{
	public:
		HumanUser();
		HumanUser(const std::string& _nick, const std::string& _usr, const std::string& _hostname = "");
		virtual ~HumanUser();
		
		void setNick(const std::string& _nick);
		void setUsr(const std::string& _usr);
		
		const std::string& getNick() const;
		const std::string& getUsr() const;
	private:
		std::string nick;
		std::string usr;
};

#endif
