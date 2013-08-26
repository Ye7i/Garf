#ifndef MESSAGE_H
#define MESSAGE_H

#include "User.h"

#include <string>

namespace MessageType
{
	enum Value
	{
		PRIVATE,
		CHANNEL,
		SERVER
	};
}

class Message
{
	public:
		Message(const MessageType::Value& _type, const std::string& _data);
		virtual ~Message();

		const MessageType::Value& getType() const;
		
		bool compareType(const MessageType::Value& _type);
	private:
		MessageType::Value type;
		std::string rawContent;
		User originator;
};

#endif
