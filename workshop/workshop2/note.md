e1 to e3 are super easy, skip

### e4
#### GSL: the GNU Scientific Library
https://www.gnu.org/software/gsl/doc/html/usage.html

#### example codes in slides
```c
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main() {
	const gsl_rng_type *T;
	gsl_rng *r;
	/* create a random number generator */
	gsl_rng_env_setup();
	T = gsl_rng_default;
	r = gsl_rng_alloc(T);
	/* seed it – equivalent of srand(time(0)) */
	gsl_rng_set(r,time(0));

	int i;

	printf("Uniform distributed between 2 and 10\n");
	for (i=0; i<10; i++) {
		printf("%2d: %lf\n", i, gsl_ran_flat(r,2,10));
	}

	return 0;
}
```

#### compiling and linking
- Compile step, as before

```
gcc -ansi -c myProgram.c -o myProgram.o
```

- Extra info in the link step

```c
gcc myProgram.o -lgsl -lgslcblas –o myProgram
```

“-lgsl” means “link with the libgsl library”  
“-lgslcblas” means “link with the libgslcblas library

- example output
```
[kl572@emps-ugcs2 workshop2]$ gcc c4.o -lgsl -lgslcblas -o c4
[kl572@emps-ugcs2 workshop2]$ c4
Uniform distributed between 2 and 10
 0: 5.309443
 1: 4.773926
 2: 5.539420
 3: 8.472523
 4: 7.024867
 5: 9.683806
 6: 5.994775
 7: 3.919441
 8: 7.734723
 9: 2.497929
[kl572@emps-ugcs2 workshop2]$ c4
Uniform distributed between 2 and 10
 0: 3.283580
 1: 2.446980
 2: 6.325835
 3: 3.144223
 4: 5.571059
 5: 5.118062
 6: 9.777844
 7: 2.004354
 8: 6.181084
 9: 2.536101
```

each time you run this program you get a different sequence of random numbers.

### extra
ummmm, 剩下的练习都比较简单， 最后一个练习我错误地使用了c的整除, 使用gdb debug轻松解决， 但注意编译时要加上-g参数

```
gcc -ansi -g -c e4.c -o e4.o
```

gsl 随机数doc 链接  
https://www.gnu.org/software/gsl/doc/html/randist.html?highlight=random  

https://www.gnu.org/software/gsl/doc/html/rng.html?highlight=random
