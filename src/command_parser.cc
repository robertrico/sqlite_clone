#include "command_parser.h"

CommandParser::CommandParser()
{

}

CommandParser::~CommandParser()
{

}

int CommandParser::parse(std::string command)
{

	Statement *statement = new Statement(command);

	int return_code = statement->execute();

	delete statement;

	return return_code;
}