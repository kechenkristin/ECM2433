#include<stdio.h>
#include<string.h>

int main() {
	char t[] = "A string";
	char s[50] = "Hello world";

	int i;

	// print character itself
	for (i = 0; i < 20; i++) {
		printf("The %dth element is %c\n",i, s[i]);
	}
	printf("\n");

	// print ascii code
	for (i = 0; i < 20; i++) {
		printf("The %dth element is %d\n", i, s[i]);
	}
	printf("\n");

	// Write a loop to fill the elements of the array with indices strlen(s)to 18 (inclusive) with another character
	printf("length of s is : %d\n", strlen(s));	// 11

	for (i = strlen(s); i <= 18; i++) {
		s[i] = 'X';
	}

	//  Properly null-terminate your new string with
	// s[19] = '\0';

	// Now print your string, both one character at a time using a for loop and using printf(); check that they agree.
	printf(s);
	printf("\n");
	for (i = 0; i < 20; i++) {
		printf("The %dth element is %c\n",i, s[i]);
	}
	printf("\n");


	// Now remove the null terminator by putting another character in the final element of s
	s[20] = 'Z';
	printf(s);
	printf("\n");

	return 0;
}
