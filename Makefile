CC      = clang
CFLAGS  = -Wall -Werror -g

SRC     = $(wildcard src/*.c)
UTIL    = $(wildcard util/*.c)
OBJ     = $(SRC:.c=.o) $(UTIL:.c=.o)


test_sorters: test.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf main test_sorters *.dSYM $(OBJ)
