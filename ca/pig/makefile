CC = gcc

test_pig: test_pig.o pig.o
	$(CC) test_pig.o pig.o -o test_pig

test_pig.o: test_pig.c pig.h
	$(CC) -c test_pig.c

pig.o: pig.c pig.h
	$(CC) -c pig.c

clean:
	rm *.o test_pig
