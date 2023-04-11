## Introduction to C 
C is:  
- imperative (what should it do?)  
cf: declarative: what outcomes should it achieve?
- procedure/functional
- compiled
- statically typed: types are checked before runtime
- weakly typed: supports implicit type conversions, variable types must be declared, but can coerced to other types
	- good: implicit type conversions
	```c
	unsigned short int x = 68;
	short int y = x;
	char c = x;
	float f = x;
	printf("x = %d\n", x);	// x = 68
	printf("y = %d\n", y);	// y = 68
	printf("c = %c\n", c);	// c = D
	printf("f = %f\n", f);	// f = 68.000000
	```
	- bad
	```c
	unsigned short int x = 65535;
	short int y = x;
	char c = x;
	float f = x;
	printf("x = %d\n", x);	// x = 65535
	printf("y = %d\n", y);	// y = -1
	printf("c = %c\n", c);	// c= ???
	printf("f = %f\n", f);	// f = 65535.000000
	```

ps: why 65535 is -1?  

- portable: available on just about every platform

## Compile, link and execute
- Compilation: translation of source code into object code
- Linking/loading:  link object code together to form an executable

## Grammar
- program return values
in int main(), 0 => success, any other value => failure  

- variable declarations

- base data types  
| Data type        | Size (in bytes) |
| ------------------ | ---------------- |
| unsigned char    | 1              |
| char             | 1              |
| unsigned short   | 2              |
| short            | 2              |
| int              | 4              |
| long             | 4 or 8         |
| float            | 4              |
| double           | 8              |
| long double      | 10 or 16       |

- Formatted printing - printf (see slides)

- ASCII codes  
https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html

- Conditionals
	- if - then - else
	- Boolean conditions (== vs =) (and & or |)

- loops
	- for
		- break: jump to the first statement after the end of the loop
		- continue jump to the start of the next iteration
	- while and do while
