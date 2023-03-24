CC = gcc

all: demo_shuffle quality

demo_shuffle: demo_shuffle.o riffle.o
	$(CC) demo_shuffle.o riffle.o -o demo_shuffle

quality: quality.o riffle.o
	$(CC) quality.o riffle.o -o quality

demo_shuffle.o: demo_shuffle.c riffle.h
	$(CC) -c demo_shuffle.c

quality.o: quality.c riffle.h
	$(CC) -c quality.c

riffle.o: riffle.c riffle.h
	$(CC) -c riffle.c

clean:
	rm *.o demo_shuffle quality
