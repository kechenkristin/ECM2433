#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 8912 /* or some other number */

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

/* logical of pig, delegate task to different handler function based on the     starting char */
char* pig(char* word) {
    if (is_constant(word[0])) return case_constant(word);
    return case_vowel(word);
}


/* https://cboard.cprogramming.com/c-programming/70320-how-remove-newline-string.html#:~:text=All%20you%20have%20to%20do,2005%20at%2004%3A33%20AM.
 */

/* for every single token, get rid of '\n' */
char* clean_token(char *token) {
    char* ct = malloc(strlen(token ? token : '\n'));
    if (token) strcpy(ct, token);
    ct[strlen(ct) - 1] = '\0';
    return ct;
}


void into_tokens(char* line) {
    const char s[2] = " ";
    char *token;
    
    /* 获取第一个子字符串 */
   token = strtok(line, s);
   // char* pig_r = pig(token);
   // printf("%s\n", pig_r);
   
   /* 继续获取其他的子字符串 */
   while( token != NULL ) {
      // printf( "%s\n", token );
      char* c_t;
      c_t = clean_token(token);
      char* pig_r = pig(c_t);
      printf("%s\n", pig_r);
      free(pig_r);
      //char* token_ptr = token;
      //printf("%s\n", pig(token_ptr));
      token = strtok(NULL, s);
   }
}





/* https://stackoverflow.com/questions/26771388/taking-continuous-input-from-user-in-c */
int main(int argc, const char **argv) {
    
    char line[BUFFER_SIZE];
    fgets(line, BUFSIZ, stdin);
    while (strcmp(line, "\n") != 0) {
        // line[strcspn(line, "\n")] = 0;
        // printf("%s", line);
        into_tokens(line);
        fgets(line, BUFSIZ, stdin);
    }
    
    // char test[1024] = "hello world\n";
    // into_tokens(test);
}
