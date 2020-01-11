#ifndef CLIENT
#define CLIENT

#include "client.h"

class Client
{
	public:
		Client();
		~Client();
		void start();
		void print_prompt();
};

#endif