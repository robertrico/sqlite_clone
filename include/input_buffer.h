#ifndef INPUT_BUFFER
#define INPUT_BUFFER

#include <string>
#include <iostream>
#include "command_parser.h"

class InputBuffer
{
	public:
		InputBuffer();
		~InputBuffer();
		int read();

	private:
		std::string 	buffer;
		size_t			buffer_length;
		ssize_t			input_length;
		CommandParser 	*cmd_parser;
	
};

#endif
