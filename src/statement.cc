#include "statement.h"

Statement::Statement(std::string command)
{
	this->command = command;

	// Allowable Commands. Is there a cleaner way to do this?
	this->meta_commands.push_back(".exit");
	this->meta_commands.push_back(".tables");
};

Statement::~Statement()
{
	
};

int Statement::execute()
{
	Statement::MetaCommandResult is_meta = meta_command();

	switch(is_meta){
		case EXIT_COMMAND:
			return 1;
		case META_COMMAND_SUCCESS:
			std::cout << "Executing Meta Command " << this->command << std::endl;
			break;
		case META_COMMAND_UNRECOGNIZED_COMMAND:
			std::cout << "Unrecognized Command" << std::endl;
			break;
		default:
			// Execute Statement
			std::cout << "Executing Command " << this->command << std::endl;
			break;
	}

	return 0;
}

Statement::MetaCommandResult Statement::meta_command()
{
	if( this->command[0] == '.' ){

		std::vector<std::string>::iterator it;
		//TODO this can probably be a CommandParser function
		it = find (this->meta_commands.begin(), this->meta_commands.end(), this->command);

		if( this->command.compare(".exit") == 0){
			return EXIT_COMMAND;
		} else if (it != this->meta_commands.end()){
			return META_COMMAND_SUCCESS;
		} else {
			return META_COMMAND_UNRECOGNIZED_COMMAND;
		}
	}

	return NON_META_COMMAND;
}
