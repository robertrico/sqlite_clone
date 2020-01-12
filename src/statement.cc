#include "statement.h"

Statement::Statement(std::string command)
{
	this->command = command;
};

Statement::~Statement()
{
	
};

int Statement::execute()
{
	Statement::MetaCommands is_meta = meta_command();

	switch(is_meta){
		case EXIT_COMMAND:
			return 1;
		case META_TABLES:
			std::cout << "Executing Tables " << std::endl;
			break;
		case META_COMMAND_UNRECOGNIZED_COMMAND:
			std::cout << "Unrecognized Command" << std::endl;
			break;
		case NON_META_COMMAND:
			// Non Meta Command
			break;
	}

	return 0;
}

Statement::MetaCommands Statement::meta_command()
{
	if( this->command[0] == '.' ){
		if( this->command.compare(".exit") == 0){
			return EXIT_COMMAND;
		} else if( this->command.compare(".tables") == 0){
			return META_TABLES;
		} else {
			return META_COMMAND_UNRECOGNIZED_COMMAND;
		}
	} else {

		switch ( this->prepare_statement() ) {
			case (PREPARE_SUCCESS):
				break;
			case (PREPARE_UNRECOGNIZED_STATEMENT):
				std::cout << "Unrecognized keyword at start of '" << this-> command << "'" << std::endl;
				return NON_META_COMMAND;
		}

		this->execute_statement();
		printf("Executed.\n");
	}

	return NON_META_COMMAND;
}

Statement::PrepareResult Statement::prepare_statement()
{
  if ( this->command.compare("insert") == 0 ) {
    this->type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  }

  if( this->command.compare("select") == 0 ) {
    this->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}

void Statement::execute_statement() {
  switch (this->type) {
    case (STATEMENT_INSERT):
      printf("This is where we would do an insert.\n");
      break;
    case (STATEMENT_SELECT):
      printf("This is where we would do a select.\n");
      break;
  }
}