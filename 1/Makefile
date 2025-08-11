CFLAGS=-g -ggdb -fno-debug-types-section -O0 -Wall -Werror -std=c89 -pedantic

OBJECTS=1_19_reverse_lines.o

1_19_reverse_lines: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o 1_19_reverse_lines

1_19_reverse_lines.o: 1_19_reverse_lines.c
	$(CC) $(CFLAGS) -c 1_19_reverse_lines.c

clean:
	rm -f *.o
	rm -f *.out
	rm -f 1_19_reverse_lines
