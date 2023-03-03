#include "pig.h"
#include <stdio.h>

/* if c is a constant, return 1, else 0 */
int is_constant(char c) {
	int vowel;
	vowel = !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	return vowel;
}

/* counts how many starting constant. */
int constant_count(char* str) {
	int i = 0;

	int strLength = strlen(str);
	int constantCount = 0;

	for (i = 0; i < strLength; i++) {
		if (is_constant(str[i])) {
			if (str[i] == 'y') {
				if (i == 0) {
					/* y begins a word, acts as a consonant*/
					constantCount++;
				} else {
					/*  follows consonants, then it acts as a vowe. */
					return constantCount;
				}
			} else {
				/* other constant */
				constantCount++;
			}
		}else {
			/* vowel*/
			return constantCount;
		}
	}
	return constantCount;
}

/* handle the case of if the word begin with constants */
char* case_constant(char* oldstr) {
	int strLength = strlen(oldstr);

	int constantCount = constant_count(oldstr);

	int vowelCount = strLength - constantCount;


	char* newstr;
	/* +1 for '\0' character */
	int newLength = strLength + 2;
	newstr = (char*) malloc((newLength + 1)*sizeof(char)); 

	int i;

	for (i = 0; i < vowelCount; i++) {
		newstr[i] = oldstr[i + constantCount];
	}

	for (i = 0; i < constantCount; i++) {
		newstr[i + vowelCount] = oldstr[i];
	}

	newstr[newLength - 2] = 'a';
	newstr[newLength - 1] = 'y';

	return newstr;
}


/* handle the case of if the word begin with vowels */
char* case_vowel(char* oldstr) {
	int strLength = strlen(oldstr);
	int newLength = strLength + 3;

	char* newstr;
	/* +1 for '\0' character */
	newstr = (char*) malloc((newLength + 1)*sizeof(char)); 

	strcpy(newstr, oldstr);
	newstr[newLength - 3] = 'w';
	newstr[newLength - 2] = 'a';
	newstr[newLength - 1] = 'y';

	return newstr;
}

/* logical of pig, delegate task to different handler function based on the starting char */
char* pig(char* word) {
	if (is_constant(word[0])) return case_constant(word);
	return case_vowel(word);
}
