CC=gcc
CFLAGS=-Wall -O2

all: main

main: obj/main.o obj/gaussian_elimination.o
	@mkdir -pv bin
	$(CC) $(CFLAGS) obj/main.o obj/gaussian_elimination.o -o bin/main

obj/main.o: src/main.c src/gaussian_elimination.h
	@mkdir -pv obj
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/gaussian_elimination.o: src/gaussian_elimination.c src/gaussian_elimination.h
	@mkdir -pv obj
	$(CC) $(CFLAGS) -c src/gaussian_elimination.c -o obj/gaussian_elimination.o

clean:
	rm -rf bin obj test/bin
