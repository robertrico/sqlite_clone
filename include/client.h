#ifndef CLIENT
#define CLIENT

#include "input_buffer.h"

class Client
{
	public:
		Client();
		~Client();
		void start();
		void print_prompt();
		InputBuffer *input_buffer;
		int client_exit;
};

#endif