#ifndef STATEMENT
#define STATEMENT

#include <string>
#include <iostream>
#include <vector>

class Statement
{

	public:
		typedef enum { EXIT_COMMAND,META_TABLES,META_COMMAND_UNRECOGNIZED_COMMAND,NON_META_COMMAND } MetaCommands;
		typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;
		typedef enum { STATEMENT_INSERT, STATEMENT_SELECT} StatementType;

		Statement(std::string command);
		~Statement();
		int execute();
		void execute_statement();
		PrepareResult prepare_statement();


		MetaCommands meta_command();
		StatementType type;


	private:
		std::string command;

	
};

#endif