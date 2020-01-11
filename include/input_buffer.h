#ifndef INPUT_BUFFER
#define INPUT_BUFFER

#include <string>

class InputBuffer
{
	public:
		InputBuffer();
		~InputBuffer();
		void read();

	private:
		std::string buffer;
		size_t		buffer_length;
		ssize_t		input_length;
	
};

#endif
