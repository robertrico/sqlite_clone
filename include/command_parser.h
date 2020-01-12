#ifndef COMMAND_PARSER
#define COMMAND_PARSER

#include <string>
#include "statement.h"

class CommandParser
{

public:
	CommandParser();
	~CommandParser();

	int parse(std::string command);
	typedef enum { META_COMMAND_SUCCESS,META_COMMAND_UNRECOGNIZED_COMMAND } MetaCommandResult;
	typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_COMMAND } PrepareResult;
	typedef enum { STATEMENT_INSERT, STATEMENT_SELECT} StatementType;
	
};

#endif