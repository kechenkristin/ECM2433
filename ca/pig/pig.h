#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 8912

/* functiona prototypes */

/* if c is a consonant, return 1, else 0 */
int is_constant(char); 

/* counts how many starting consonant. */
int constant_count(char*);

/* handle the case of if the word begin with consonants */
char* case_constant(char*);

/* handle the case of if the word begin with vowels */
char* case_vowel(char*);

/* logical of pig, delegate task to different handler function based on the starting char */
char* pig(char*);
