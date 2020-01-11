#include "main.h"

int main(int argc, char* argv[])
{
	printf("Hello, %s","world!\n");

	InputBuffer *in_buff = new InputBuffer();

	delete in_buff;

	Client *client = new Client();

	delete client;

	return 0;
}