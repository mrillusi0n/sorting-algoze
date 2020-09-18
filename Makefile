CC = clang
CFLAGS = -g -Wall
SORT_FUNCTION_IMPLS = src/*

test_sorters: test.c sort_functions.h src/*.c
	$(CC) $(CFLAGS) -o test_sorters test.c $(SORT_FUNCTION_IMPLS)

clean:
	rm -rf main test_sorters *.dSYM
