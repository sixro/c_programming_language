CC=gcc-15
CFLAGS=-Wall -Werror -std=c89 -pedantic
EXEC=myapp

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

# DEPS = hellomake.h
# %.o: %.c# $(DEPS)
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

debug: $(OBJS)
	mkdir -p bin
	$(CC) -o bin/$(EXEC)-debug $^ $(CFLAGS) -g -O0

app: $(OBJS)
	mkdir -p bin
	$(CC) -o bin/$(EXEC) $^ $(CFLAGS) -O2

.PHONY: clean

clean:
	rm -f *.o
	rm -f *.out
	rm -rf bin
