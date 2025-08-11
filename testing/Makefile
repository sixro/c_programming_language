CC=gcc-15
CFLAGS=-Wall -Werror -std=c89 -pedantic
EXEC=myapp

ALL_C_FILES=$(wildcard *.c)
SOURCE_FILES=$(filter-out test_%.c, $(ALL_C_FILES))
OBJECT_FILES=$(SOURCE_FILES:.c=.o)
TEST_FILES=$(wildcard test_*.c)

# DEPS = hellomake.h
# %.o: %.c# $(DEPS)
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

debug: $(OBJECT_FILES)
	mkdir -p bin
	$(CC) -o bin/$(EXEC)-debug $^ $(CFLAGS) -g -O0

app: $(OBJECT_FILES)
	mkdir -p bin
	$(CC) -o bin/$(EXEC) $^ $(CFLAGS) -O2

.PHONY: clean

clean:
	rm -f *.o
	rm -f *.out
	rm -rf bin
