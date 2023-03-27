CC = gcc

all: byn single

single: single.o beggar.o
	$(CC) single.o beggar.o -o single

byn: byn.o stats.o
	$(CC) byn.o stats.o -o byn

single.o: single.c beggar.h
	$(CC) -c single.c

beggar.o: beggar.c beggar.h riffle.h player.h list.h
	$(CC) -c beggar.c

byn.o: byn.c beggar.h stats.h
	$(CC) -c byn.c

stats.o: stats.c stats.h
	$(CC) -c stats.c

clean:
	rm *.o single byn
