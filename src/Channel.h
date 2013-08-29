#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

class Channel
{
	public:
		Channel(const std::string& _name);
		virtual ~Channel();
		
		const std::string& getName() const;
	private:
		std::string name;
};

#endif
