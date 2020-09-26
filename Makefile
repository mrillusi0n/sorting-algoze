CC      = gcc
CFLAGS  = -g -Wall -Werror

SRC     = $(wildcard src/*.c)
UTIL    = $(wildcard util/*.c)
OBJ     = $(SRC:.c=.o) $(UTIL:.c=.o)


test_sorters: test.c $(OBJ) $(UTIL)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf main test_sorters *.dSYM $(OBJ)
