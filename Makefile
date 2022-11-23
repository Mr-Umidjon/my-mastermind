all: mastermind

mastermind: mastermind.o mastermind.h
	gcc -Wall -Wextra -Werror -o mastermind mastermind.o



.PHONY: clean

clean:
	rm -f mastermind.o mastermind
