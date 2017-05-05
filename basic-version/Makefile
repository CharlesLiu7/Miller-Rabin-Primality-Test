CC = g++
CFLAGS = -std=c++11 -O2
TARGETS = miller-rabin.o test.out

all: $(TARGETS)

test.out: miller-rabin.o test.cpp
	$(CC) $(CFLAGS) -o $@ $^

miller-rabin.o: ./miller-rabin.cpp ./miller-rabin.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY:clean
clean:
	rm -f $(TARGETS)
