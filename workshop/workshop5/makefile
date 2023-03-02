CC = gcc

all: print_pyramid print_many_pyramids

print_pyramid: print_pyramid.o pyramid.o
	$(CC) print_pyramid.o pyramid.o -o print_pyramid

pyramid.o: pyramid.c pyramid.h
	$(CC) -c pyramid.c

print_pyramid.o: print_pyramid.c pyramid.h
	$(CC) -c print_pyramid.c

print_many_pyramids: print_many_pyramids.o many_pyramid.o
	$(CC) print_many_pyramids.o many_pyramid.o -o print_many_pyramids

print_many_pyramids.o: print_many_pyramids.c pyramid.h
	$(CC) -c print_many_pyramids.c

many_pyramid.o: many_pyramid.c pyramid.h
	$(CC) -c many_pyramid.c

clean:
	rm *.o print_pyramid print_many_pyramids
