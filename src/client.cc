#include "client.h"

Client::Client()
{
	input_buffer = new InputBuffer();
	client_exit = 0;
}

Client::~Client()
{
	delete input_buffer;
}

void Client::start()
{
	while(true){
		if(client_exit)
			break;

		print_prompt();
		
		client_exit = input_buffer->read();

	}
	
}

void Client::print_prompt()
{
	printf("db > ");
}
