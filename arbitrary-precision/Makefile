CC = g++
CFLAGS = -std=c++11 -O2
TARGETS = miller-rabin.o test.out generate.out primality.out

all: $(TARGETS)

test.out: miller-rabin.o test.cpp
	$(CC) $(CFLAGS) -o $@ $^

generate.out: miller-rabin.o generate_prime_by_bits.cpp
	$(CC) $(CFLAGS) -o $@ $^

primality.out: miller-rabin.o primality_test.cpp
	$(CC) $(CFLAGS) -o $@ $^

miller-rabin.o: ./miller-rabin.cpp ./miller-rabin.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY:clean
clean:
	rm -f $(TARGETS)
