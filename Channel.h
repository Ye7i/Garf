#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

using namespace std;

class Channel
{
	public:
		Channel(const std::string& _name);
		virtual ~Channel();
		
		std::string getName() const;
	private:
		std::string name;
};

#endif
