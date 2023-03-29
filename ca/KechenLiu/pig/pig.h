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
* input: a string of chars (a word)
* handle the case of if the word begin with consonants 
* return: word after manipulated
*/
char* case_constant(char*);

/*
* input: a string of chars(a word)
* handle the case of if the word begin with vowels 
* return: word after manipulated
*/
char* case_vowel(char*);

/* 
* input: a string of chars(a word)
* main logical of pig, delegate task to different handler function(case_vowel or case_constant) based on the starting char 
* return: word after manipulated
*/
char* pig(char*);
