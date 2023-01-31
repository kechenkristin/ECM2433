#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* changeArr(int *arr, int arrLen);

int main() {
	int arr[10];
	int i;
	int j = 10;

	for (i = 0; i < 10; i++) {
		arr[i] = j;
		j++;
	}
	
	for (i = 0; i < 10; i++) {
		printf("%d: %d\n", (i + 1), arr[i]);
	}

	// qb
	for (i = 0; i < 10; i++) {
		arr[i] = rand();
	}
	
	for (i = 0; i < 10; i++) {
                printf("%d: %d\n", (i + 1), arr[i]);
        }

	// qc
	printf("q3\n");
	int len = sizeof(arr) / sizeof(arr[0]);
	int* ret = changeArr(arr, len);
	for (i = 0; i < len; i++) {
		printf("%d: %d\n", (i + 1), *(arr + i));
	}
	return 0;
}


int* changeArr(int *arr, int arrLen) {
	int i;

	for (i = 0; i < arrLen; i++) {
		arr[i] = rand();
	}

	return arr;
}

