CC = gcc

all: byn single

single: single.o beggar.o
	$(CC) single.o beggar.o -o single

byn: byn.o beggar.o
	$(CC) byn.o beggar.o -o byn

single.o: single.c
	$(CC) -c single.c

beggar.o: 
