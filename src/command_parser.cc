#include "command_parser.h"

CommandParser::CommandParser()
{

}

CommandParser::~CommandParser()
{

}

int CommandParser::parse(std::string command)
{
	if( command.compare(".exit") == 0 ){
		return 1;
	}

	return 0;
}