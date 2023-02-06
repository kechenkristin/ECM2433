### E1
Easy

### E2
The prototype for the main function is:
```
int main(int argc, char **argv);
```
Here argc is the number of parameters supplied to the program, including the name of the program itself and argv is an array of strings, that is a pointer to pointers to char.

- Write and test a program to print its command line arguments. 
easy, see e21.c

- e22.c
The part of cancating is tricky, I use  
https://stackoverflow.com/questions/25767841/how-do-i-concatenate-the-string-elements-of-my-array-     into-a-single-string-in-c
  
as reference

### E3
Easy

### E4 
Interesting
- free
```
(base) kristin@kristin-PC:~/study/exeter/y2term2/ECM2433/workshop/workshop3$ gcc -o freeE4Test e4.c 
(base) kristin@kristin-PC:~/study/exeter/y2term2/ECM2433/workshop/workshop3$ valgrind --leak-check=full freeE4Test 4
==12175== Memcheck, a memory error detector
==12175== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12175== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==12175== Command: freeE4Test 4
==12175== 
1
2
3
4
==12175== 
==12175== HEAP SUMMARY:
==12175==     in use at exit: 0 bytes in 0 blocks
==12175==   total heap usage: 2 allocs, 2 frees, 1,032 bytes allocated
==12175== 
==12175== All heap blocks were freed -- no leaks are possible
==12175== 
==12175== For lists of detected and suppressed errors, rerun with: -s
==12175== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

- comment free
```
(base) kristin@kristin-PC:~/study/exeter/y2term2/ECM2433/workshop/workshop3$ gcc -o leakE4Test e4.c
(base) kristin@kristin-PC:~/study/exeter/y2term2/ECM2433/workshop/workshop3$ valgrind --leak-check=full leakE4Test 4
==12210== Memcheck, a memory error detector
==12210== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12210== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==12210== Command: leakE4Test 4
==12210== 
1
2
3
4
==12210== 
==12210== HEAP SUMMARY:
==12210==     in use at exit: 8 bytes in 1 blocks
==12210==   total heap usage: 2 allocs, 1 frees, 1,032 bytes allocated
==12210== 
==12210== 8 bytes in 1 blocks are definitely lost in loss record 1 of 1
==12210==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==12210==    by 0x1091CF: main (in /home/kristin/study/exeter/y2term2/ECM2433/workshop/workshop3/leakE4Test)
==12210== 
==12210== LEAK SUMMARY:
==12210==    definitely lost: 8 bytes in 1 blocks
==12210==    indirectly lost: 0 bytes in 0 blocks
==12210==      possibly lost: 0 bytes in 0 blocks
==12210==    still reachable: 0 bytes in 0 blocks
==12210==         suppressed: 0 bytes in 0 blocks
==12210== 
==12210== For lists of detected and suppressed errors, rerun with: -s
==12210== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

cs61c  
https://inst.eecs.berkeley.edu/~cs61c/fa20/labs/lab02/#exercise-3-memory-management
