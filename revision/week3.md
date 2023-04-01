## Pointer
### & and *
- if x is any datatype, then &x is the location in memory (its “address”) where x is currently stored
- if x is a pointer, then 
	- (datatype) * x: declears x to contain the memory address of a variable of type (datatype)
	- * x go to the memory address stored in x and bring back the value stored there

### Addresses and pointers
see more in slides

### Pointer arithmetic

### Void Pointers
void pointers can point to any datatype

### Loop idioms with pointers
```c
int i, N = 20;
int *p, powers[N];

/* Fill powers with squares */
for (i = 0; i < N; i++) powers[i] = i^2;

/* Add 2 to each element */
for (p = powers, i = 0; i< N; i++, p++) *p = *p + 2;

/* Add another 5 */
for (p = powers, i = 0; i< N; i++, p++) *p += 5;

/* Multiply each element by 10 */
for (p = powers, i = 0; i < N; i++) *p++ *= 10;

/* Make elements negative until an
* element greater 1000 is encountered
*/
for (p = powers; *p < 1000; ) *p++ *= -1;
```

### Runtime errors using pointers
- Memory fault  
- Segment fault  

Caused by
- trying to access memory to which it is not allowed access
- trying to access memory in a way that is not allowed(i.e. trying to overwrite the operating system)

### Dynamic memory allocation(see slides)
