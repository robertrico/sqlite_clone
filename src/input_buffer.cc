#include "input_buffer.h"

InputBuffer::InputBuffer()
{
	buffer_length = 0;
	input_length = 0;
	cmd_parser = new CommandParser();
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

	input_length = bytes_read;
	buffer[bytes_read] = 0;

	int alive = 0;

	alive = cmd_parser->parse(buffer);

	return alive;
}