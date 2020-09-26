CC      = gcc
CFLAGS  = -Wall -Werror

SRC     = $(wildcard src/*.c)
UTIL    = $(wildcard util/*.c)
OBJ     = $(SRC:.c=.o) $(UTIL:.c=.o)


test_sorters: test.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf main test_sorters *.dSYM $(OBJ)
