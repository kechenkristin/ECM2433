#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 8912

/* functiona prototypes */

/* 
* parametr: a single char
* determine whether a char is a constant or not
* if c is a consonant, return 1, else 0 
*/
int is_constant(char); 

/*  
* para: a string
* counts how many starting consonant.
* return how many constant chars are there in the input string
*/
int constant_count(char*);

/* 
* handle the case of if the word begin with consonants */
char* case_constant(char*);

/* handle the case of if the word begin with vowels */
char* case_vowel(char*);

/* logical of pig, delegate task to different handler function based on the starting char */
char* pig(char*);
