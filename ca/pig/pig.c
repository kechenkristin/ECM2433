#include "pig.h"
#include <stdio.h>


/* if c is a consonant, return 1, else 0 */
int is_consonant(char c) {
        int lowercase_vowel, uppercase_vowel;
        lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c ==  'u');
        uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c ==  'U');
        return !(lowercase_vowel || uppercase_vowel);
}


/* counts how many starting consonant. */
int consonant_count(char* str) {
	int i = 0;

	int strLength = strlen(str);
	int consonantCount = 0;

	for (i = 0; i < strLength; i++) {
		if (is_consonant(str[i])) {
			if (str[i] == 'y') {
				if (i == 0) {
					/* y begins a word, acts as a consonant*/
					consonantCount++;
				} else {
					/*  follows consonants, then it acts as a vowe. */
					return consonantCount;
				}
			} else {
				/* other consonant */
				consonantCount++;
			}
		}else {
			/* vowel*/
			return consonantCount;
		}
	}
	return consonantCount;
}

/* handle the case of if the word begin with consonants */
char* case_consonant(char* oldstr) {
	int strLength = strlen(oldstr);

	int consonantCount = consonant_count(oldstr);

	int vowelCount = strLength - consonantCount;


	char* newstr;
	/* +1 for '\0' character */
	int newLength = strLength + 2;
	newstr = (char*) malloc((newLength + 1)*sizeof(char)); 

	int i;

	for (i = 0; i < vowelCount; i++) {
		newstr[i] = oldstr[i + consonantCount];
	}

	for (i = 0; i < consonantCount; i++) {
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
	if (is_consonant(word[0])) return case_consonant(word);
	return case_vowel(word);
}
