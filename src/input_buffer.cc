#include "input_buffer.h"

InputBuffer::InputBuffer()
{
	this->buffer_length = 0;
	this->input_length = 0;
	this->cmd_parser = new CommandParser();
}

InputBuffer::~InputBuffer()
{

}

int InputBuffer::read()
{
	std::getline (std::cin,buffer);

	int bytes_read = buffer.size();

	if( bytes_read <= 0 ){
		printf("%s\n", "Error Reading input\n");
		exit(EXIT_FAILURE);
	}

	this->input_length = bytes_read;
	this->buffer[bytes_read] = 0;

	int alive = 0;

	alive = cmd_parser->parse(buffer);

	return alive;
}