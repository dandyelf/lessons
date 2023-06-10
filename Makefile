CC = g++
CFLAGS = -g -Werror -Wall -Wextra
OS := $(shell uname -s)
OS2 := $(shell cat /etc/*-release | grep ID=a)

all:

t:
	clang-format -n *.cc
	clang-format -i *.cc
	$(CC) $(CFLAGS) test.cc -o t
	./t
