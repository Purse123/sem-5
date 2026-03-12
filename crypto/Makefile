CC = gcc
CFLAGS = -Wpedantic -Wall -Wextra -std=c11

.PHONY: all clean
all: q1

q1: 1-caesar_cipher.c
	$(CC) $^ -o $@ $(CFLAGS)
q2: 2-rail_fence_cipher.c
	$(CC) $^ -o $@ $(CFLAGS)
q3: 3-vigenere_cipher.c
	$(CC) $^ -o $@ $(CFLAGS)
q4: 4-hill_cipher.c
	$(CC) $^ -o $@ $(CFLAGS)
q5: 5-euclidean.c
	$(CC) $^ -o $@ $(CFLAGS)
q6: 6-ext_euclidean.c
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm *~ q1 q2 q3 q4 q5 q6
