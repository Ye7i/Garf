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
		User(const UserType::Value& _type, const std::string& _hostname = "");
		virtual ~User();

		void setHostname(const std::string& _hostname);

		const std::string& getHostname() const;
		const UserType::Value& getType() const;
		
		bool compareType(const UserType::Value& _type);
	private:
		std::string hostname;
		UserType::Value type;
};

#endif
