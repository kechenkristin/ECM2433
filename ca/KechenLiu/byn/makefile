CC = gcc

all: byn single


single: single.o  beggar.o player.o list.o riffle.o
	$(CC) single.o  player.o list.o beggar.o riffle.o -o single

byn: byn.o stats.o beggar.o player.o list.o riffle.o
	$(CC) byn.o stats.o player.o list.o beggar.o riffle.o -o byn

single.o: single.c beggar.h
	$(CC) -c single.c

beggar.o: beggar.c beggar.h riffle.h player.h list.h
	$(CC) -c beggar.c

byn.o: byn.c beggar.h stats.h
	$(CC) -c byn.c

stats.o: stats.c stats.h
	$(CC) -c stats.c

riffle.o: riffle.c riffle.h
	$(CC) -c riffle.c

player.o: player.c player.h list.h
	$(CC) -c player.c

list.o: list.c list.h
	$(CC) -c list.c

clean:
	rm *.o single byn
