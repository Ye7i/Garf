#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

using namespace std;

class Channel
{
	public:
		Channel(std::string _name);
		
		std::string getName() const;
	private:
		std::string name;
};

#endif
