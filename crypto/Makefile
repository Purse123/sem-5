CC = gcc
CFLAGS = -Wpedantic -Wall -Wextra -std=c11

.PHONY: all clean
all: q1

q1: 1-caesar_cipher.c
	$(CC) $^ -o $@ $(CFLAGS)
q2: 2-rail_fence_cipher.c
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm *~ q1 
