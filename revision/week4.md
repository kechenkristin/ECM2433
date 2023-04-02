## Function parameters
see example codes in slides

### pass by value
```c
#include <stdio.h>
void func(char);
int main () {
	char c = 'A';
	printf("Before: c = %c &c = %p\n", c, &c);
	func(c);
	printf("After: c = %c &c = %p\n",c, &c);
}

void func(char ch) {
	ch = 'B';
	printf("func: ch = %c &ch = %p\n", ch, &ch);
}
```
### pass by reference
```c
void func(char *ch) {
	*ch = 'B';
	printf("func: *ch = %c ch = %p &ch = %p\n", *ch, ch, &ch);
}
```

### functions and arrays
see codes in slides

### pass by reference part2
- attemp1
```c
void func(char *str) {
	/* strcpy(char *dest, char *src) */
	strcpy(str, "Hello");
}


int main () {
	char *p;
	func(p);
	printf("p = %s\n", p);
}
```
result is likely to be a **memory fault**  

- attemp2
```c
void func(char *str) {
	if ( !(str = (char *)malloc(6)) ) {
		printf("Insufficient memory\n");
		exit(-1);
	}
	strcpy(str, "Hello");
	printf("str = %p: %s\n", str, str);
}

int main () {
	char *p;
	func(p);
	printf("p = %p: %s\n", p, p);
}
```
So str is correctly updated, but p is not changed

- attemp3(using pointer to pointer)  

pointer to pointer  

```c
char ch = 'A';
char *p = &ch;
char **q = &p;

printf("The value of ch is: %c, %c, %c\n", ch, *p, **q);
/* The value of ch is: A, A, A */

printf("The memory address of ch is: %p, %p, %p\n", &ch, p, *q);
/* The memory address of ch is: 0x7ffe44c2ed4f, 0x7ffe44c2ed4f, 0x7ffe44c2ed4f */
```

```c
void setString (char **);

int main () {
	char *p;
	setString(&p);
	printf("p = %p: %s\n", p, p);
}

void setString(char **str) {
	if ( !(*str = (char *)malloc(6)) ) {
		printf("Insufficient memory\n");
		exit(-1);
}
	strcpy(*str, "Hello");
	printf("*str = %p: %s\n", *str, *str);
}
```


## Passing arguments to the main function
[!avatar](https://github.com/kechenkristin/ECM2433/blob/main/img/week4/main.png)

## Function pointers
- example1
```c
int Plus (int a, int b) { return a+b; }
int Minus (int a, int b) { return a-b; }
int Multiply (int a, int b) { return a*b; }
int Divide (int a, int b) { return a/b; }

int doFunction (int a, int b, int (* myFunc)(int,int) ) {
	return myFunc(a, b);
}

int main () {
	int (*f)(int,int);
	int k;
	f = &Plus;
	k = f(10, 6);
	printf("k = %d\n", k);
	printf("1+3 = %d\n", doFunction(1, 3, Plus));
	printf("1*3 = %d\n", doFunction(1, 3, Multiply));
	return 0;
}
```

- example2
```c
void qsort ( void *myData, int numElements, int sizeOfElement, int (*comparisonFunction)(void *, void *) );

int CompareFunction(*v1 , void *v2 ) {
	int *i1 = (int *)v1; remember that you need to cast void pointers
	int *i2 = (int *)v2;
	return *i1 - *i2;
}

int myList[] = {4 ,6 ,8 ,3 ,2 ,1 ,5 ,9 ,0};
int len = sizeof(myList)/sizeof(int); /* Number of elements in myList */
qsort(myList,len, sizeof(int), &CompareFunction);
```

## Structures
see more details in slides
- def & example
- typedef

## Linked list
- what is a linkedlist?
	- a data structure
	- an ordered sequence of **nodes**
	- a memory-efficient means of storing large data structures
	- a speed-efficient means of inserting and deleting nodes
[!avatar](https://github.com/kechenkristin/ECM2433/blob/main/img/week4/linkedlist.png)

- array list
[!avatar](https://github.com/kechenkristin/ECM2433/blob/main/img/week4/arraylist.png)

## Files and Streams
### Console input
scanf()

### Stream
[!avatar](https://github.com/kechenkristin/ECM2433/blob/main/img/week4/stream.png)

```c
#include <stdio.h>
#include <stdlib.h>
int main () {
	FILE *fp; /* file pointer */
	fp = fopen("myTextFile.lis", "r");

	if ( fp == NULL ) {
		printf("Cannot open file for read access\n");
		exit(EXIT_FAILURE);
	}

	/* do some file processing */
	fclose(fp);
	return EXIT_SUCCESS;
}
```

### Trapping errors
- error.h defines int error  
see examples in slides

- A call to ferror(fp)

### Write to a stream
- fputc(ch, fp) 
	- outputs the character in ch to the file pointed to by fp
- fputs(str, fp)
	- outputs the string in str to the file pointed to by fp
	- the null terminator is not output

### Read from a stream
- char ch = fgetc(fp)
	- reads a single character from the file pointed to by fp and stores it in ch

- fgets(str,count,fp)

- fscanf(fp,"%d,%d",&x,&y)

### Other common stream functions
- fflush(fp)
	- forces the output buffer to be written to the file
- remove("myFile.txt")
	- deletes the specified file
	- return 0 on success; other integer on failure
- rewind(fp)
	- resets the file position indicator back to the beginning of the file

### Standard streams
- stdin: input from the terminal
- stdout: output to the terminal; normal program output
- stderr: output to the terminal; error and warning messages

### Streams are buffered
see example in slides
