#ifndef COMMAND_H
#define COMMAND_H

class Command
{
	public:
		Command(const std::string& _name, Message* _message);
		virtual ~Command;
		
		virtual Message* execute() = 0;
	private:
		std::string name;
		Message* message;
};

#endif
