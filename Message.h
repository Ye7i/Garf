#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

namespace MessageType
{
	enum Value
	{
		PRIVMSG
	};
}

class Message
{
	public:
		Message();
		Message(const std::string& _data);
		virtual ~Message();
		
		void setType(const MessageType::Value& _type);
		
		const MessageType::Value& getType() const;
		
		bool compareType(const MessageType::Value& _type);
	private:
		MessageType::Value type;
		std::string rawContent;
		std::string source;
};

#endif
