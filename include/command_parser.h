#ifndef COMMAND_PARSER
#define COMMAND_PARSER

#include <string>

class CommandParser
{
public:
	CommandParser();
	~CommandParser();

	int parse(std::string command);
	
};

#endif