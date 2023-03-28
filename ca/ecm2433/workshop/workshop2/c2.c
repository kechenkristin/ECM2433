#include<stdio.h>
#include<string.h>

int containElephants(char *str);

int main() {
	// e2.a
	char s1[20];
	char s2[20] = "hello world";

	// copy s2 to s1
	strcpy(s1, s2);
	printf(s1);
	printf("\n");

	// e2.b
	printf("%d", containElephants(s2));	// 1
	printf("\n");

	char s3[20] = "bananaelephantsapple";
	printf("%d", containElephants(s3));	// 1
	printf("\n");


	return 0;
}

int containElephants(char *str) {
	char e[9] = "elephants";
	int i;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == 'e') {
			if (strncmp((str + i), e, 9) == 0) return 0;
		}
	}
	return 1;
}
