#include "pig.h"
#include <stdio.h>


void into_tokens(char* line) {
	const char s[2] = " ";
	char *token;

	/* get the first substring */
	token = strtok(line, s);

	/* continue to get other substrings */
	while( token != NULL ) {
		int len = strlen(token);
		if( token[len-1] == '\n' ) token[len-1] = 0;


		char* pig_r = pig(token);
		printf("%s\n", pig_r);
		free(pig_r);

		token = strtok(NULL, s);
	}
}


int main(int argc, const char **argv) {

	char line[BUFFER_SIZE];
	fgets(line, BUFSIZ, stdin);
	while (strcmp(line, "\n") != 0) {
		into_tokens(line);
		fgets(line, BUFSIZ, stdin);
	}
}
