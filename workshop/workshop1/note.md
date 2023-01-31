### download vpn
https://www.exeter.ac.uk/media/level1/academicserviceswebsite/it/documents/networks/vpn/Installing_VIA_VPN_Client_on_Ubuntu.pdf  

https://itsfoss.com/install-deb-files-ubuntu/  

### connect to uni server
- login
> (base) kristin@kristin-PC:~$ ssh kl572@emps-ugcs2  
password is uni password  
- logout
> exit

## workshop
### Exercise1
- Hello World
> [kl572@emps-ugcs2 workshop1]$ vi hello.c  

```c
#include <stdio.h>

int main() {
	printf("hello world\n");
	return 0;
}
```

```shell
[kl572@emps-ugcs2 workshop1]$ gcc hello.c -o hello
[kl572@emps-ugcs2 workshop1]$ ls
hello  hello.c
[kl572@emps-ugcs2 workshop1]$ ./hello
hello world
```

- remove #include

```shell
[kl572@emps-ugcs2 workshop1]$ gcc hello.c -o hello
hello.c: In function ‘main’:
hello.c:4:2: warning: incompatible implicit declaration of built-in function ‘printf’ [enabled by default]
  printf("hello world\n");
  ^
```

- edit ~/.bashrc

```shell
[kl572@emps-ugcs2 workshop1]$ vim ~/.bashrc	// put PATH=.:$PATH
[kl572@emps-ugcs2 workshop1]$ source ~/.bashrc
[kl572@emps-ugcs2 workshop1]$ hello
hello world
```

### Exercise2

```c
#include <stdio.h>

int main() {
	unsigned short int x = 1;
	short int y = 65535;
	unsigned char c = 'A';

	printf("x has the value %d \n", x);
	printf("y has the value %d \n", y);
	printf("c has the value %c \n", c);
	
	return 0;
}
```

```shell
[kl572@emps-ugcs2 workshop1]$ gcc e2.c -o e2
[kl572@emps-ugcs2 workshop1]$ e2
x has the value 1 
y has the value -1 
c has the value A 
```

- b
Set the value of the y variable to 65540. What happens when you
compile the program? 

```shell
[kl572@emps-ugcs2 workshop1]$ gcc e2.c -o e2
e2.c: In function ‘main’:
e2.c:6:2: warning: overflow in implicit constant conversion [-Woverflow]
  short int y = 65540;
  ^
```

- c   
Set the value of the y variable back to 65535. Then add a new
program line, as follows:
y = y + 5;
before the printf statement(s). Do you get what you expect?

```shell
[kl572@emps-ugcs2 workshop1]$ gcc e2.c -o e2
[kl572@emps-ugcs2 workshop1]$ e2
x has the value 1 
y has the value 4 
c has the value A 
```

- d
(d) Set the values of the x and c variables, like this:  
x = -1;
c = 66;
before the printf statement(s). Do you get what you expect?

```shell
[kl572@emps-ugcs2 workshop1]$ gcc e2.c -o e2
[kl572@emps-ugcs2 workshop1]$ e2
x has the value 65535 
y has the value 4 
c has the value B 
```

- e
```c
#include <stdio.h>

int main() {
	int x = 0;
	int y = 100;
	int z = -123456;

	printf("variable1 is %10d\n", x);
	printf("variable2 is %10d\n", y);
	printf("variable3 is %10d\n", z);
}
```

```shell
[kl572@emps-ugcs2 workshop1]$ gcc e2e.c -o e2e
[kl572@emps-ugcs2 workshop1]$ e2e
variable1 is          0
variable2 is        100
variable3 is    -123456
```

### Exercise 3
```c
#include <stdio.h>

int main() {
	// for loop
	int i;
	for(i = 1; i <= 20; i++) {
		printf("%d\n", i);
	}

	// while loop
	int x = 1;
	while (x <= 20) {
		printf("%d\n", x);
		x++;
	}

	return 0;
}
```

### Exercise4

- First, compile all the source code and link it in one go:
```shell
[kl572@emps-ugcs2 workshop1]$ gcc circle.c radius.c -o circle -lm
[kl572@emps-ugcs2 workshop1]$ circle
The radius of a circle with area 23.400000 is 2.729185
```

- Compile and link separately: 
> gcc -c circle.c  
> gcc -c radius.c  
> gcc circle.o radius.o -o circle -lm  

```shell
[kl572@emps-ugcs2 workshop1]$ gcc -c circle.c
[kl572@emps-ugcs2 workshop1]$ gcc -c radius.c
[kl572@emps-ugcs2 workshop1]$ ls
circle.c  e2    e2e    e3    hello    radius.c
circle.o  e2.c  e2e.c  e3.c  hello.c  radius.o
[kl572@emps-ugcs2 workshop1]$ gcc circle.o radius.o -o circle -lm
[kl572@emps-ugcs2 workshop1]$ ls
circle    circle.o  e2.c  e2e.c  e3.c   hello.c   radius.o
circle.c  e2        e2e   e3     hello  radius.c
[kl572@emps-ugcs2 workshop1]$ circle
The radius of a circle with area 23.400000 is 2.729185
```

- Compile one and link with other object code :
> gcc –c radius.c  
> gcc circle.c radius.o -o circle -lm  

```shell
[kl572@emps-ugcs2 workshop1]$ gcc -c radius.c
[kl572@emps-ugcs2 workshop1]$ gcc circle.c radius.o -o circle -lm
[kl572@emps-ugcs2 workshop1]$ ls
circle    e2    e2e    e3    hello    radius.c
circle.c  e2.c  e2e.c  e3.c  hello.c  radius.o
[kl572@emps-ugcs2 workshop1]$ circle
The radius of a circle with area 23.400000 is 2.729185
```

- Fails because radius not defined:
> gcc circle.c -o circle -lm  
- Fails because main not defined:  
> gcc radius.o -o circle –lm  
- Fails because sqrt not defined:
> gcc circle.o radius.o -o circle  
