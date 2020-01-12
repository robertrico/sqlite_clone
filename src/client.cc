#include "client.h"

Client::Client()
{
	input_buffer = new InputBuffer();
	client_exit = 0;
}

Client::~Client()
{
	delete this->input_buffer;
}

void Client::start()
{
	while(true){
		if(this->client_exit)
			break;

		print_prompt();

		// TODO Create and use setter
		this->client_exit = this->input_buffer->read();

	}
	
}

void Client::print_prompt()
{
	printf("db > ");
}
