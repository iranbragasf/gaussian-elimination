CC=gcc
CFLAGS=-Wall -O2

all: gaussian-elimination

gaussian-elimination: obj/main.o obj/gaussian_elimination.o obj/ui.o
	@mkdir -pv bin
	$(CC) $(CFLAGS) obj/main.o obj/gaussian_elimination.o obj/ui.o -o bin/gaussian-elimination

obj/main.o: src/main.c src/gaussian_elimination.h src/ui.h
	@mkdir -pv obj
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/gaussian_elimination.o: src/gaussian_elimination.c src/gaussian_elimination.h
	@mkdir -pv obj
	$(CC) $(CFLAGS) -c src/gaussian_elimination.c -o obj/gaussian_elimination.o

obj/ui.o: src/ui.c src/gaussian_elimination.h
	@mkdir -pv obj
	$(CC) $(CFLAGS) -c src/ui.c -o obj/ui.o

clean:
	rm -rf bin obj
