CC = gcc

all: test_pig piglatin

test_pig: test_pig.o pig.o
	$(CC) test_pig.o pig.o -o test_pig

piglatin: pig.o piglatin.o
	$(CC) pig.o piglatin.o -o piglatin

test_pig.o: test_pig.c pig.h
	$(CC) -c test_pig.c

piglatin.o: piglatin.c pig.h
	$(CC) -c piglatin.c

pig.o: pig.c pig.h
	$(CC) -c pig.c

clean:
	rm *.o test_pig piglatin
