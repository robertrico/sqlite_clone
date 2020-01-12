CC=g++
CFLAGS=-g -Wall -Iinclude
EXEC=dbclone.out
BIN=bin/
SRC=src/
WBO=build/main.o build/input_buffer.o build/client.o build/command_parser.o build/statement.o

all: main

main: $(WBO)
	$(CC) $(CFLAGS) -lm $(WBO) -o $(BIN)$(EXEC)

build/main.o: src/main.cc
	$(CC) $(CFLAGS) -c src/main.cc -o build/main.o

build/input_buffer.o: src/input_buffer.cc
	$(CC) $(CFLAGS) -c src/input_buffer.cc -o build/input_buffer.o

build/client.o: src/client.cc
	$(CC) $(CFLAGS) -c src/client.cc -o build/client.o

build/command_parser.o: src/command_parser.cc
	$(CC) $(CFLAGS) -c src/command_parser.cc -o build/command_parser.o

build/statement.o: src/statement.cc
	$(CC) $(CFLAGS) -c src/statement.cc -o build/statement.o

clean:
	rm build/*.o
	rm bin/*.out
