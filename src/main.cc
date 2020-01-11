#include "main.h"

int main(int argc, char* argv[])
{
	Client *client = new Client();

	client->start();

	delete client;

	return 0;
}