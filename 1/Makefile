CC = gcc-15
CFLAGS=-g -O0 -Wall -Werror -Wunused-macros -std=c89 -pedantic

SOURCE_FILES=$(wildcard *.c)
OBJECT_FILES=$(SOURCE_FILES:.c=.o)

%.o: %.c
	$(CC) -c $@ $< $(CFLAGS)

all: $(OBJECT_FILES)

clean:
	rm -f *.o
	rm -f *.out
	rm -f 1_19_reverse_lines
