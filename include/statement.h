#ifndef STATEMENT
#define STATEMENT

#include <string>
#include <iostream>
#include <vector>

class Statement
{

	public:
		typedef enum { EXIT_COMMAND,META_COMMAND_SUCCESS,META_COMMAND_UNRECOGNIZED_COMMAND,NON_META_COMMAND } MetaCommandResult;
		typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_COMMAND } PrepareResult;
		typedef enum { STATEMENT_INSERT, STATEMENT_SELECT} StatementType;

		Statement(std::string command);
		~Statement();
		int execute();

		MetaCommandResult meta_command();


	private:
		std::string command;
		std::vector<std::string> meta_commands;


	
};

#endif