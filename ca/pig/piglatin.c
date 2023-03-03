#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 8192 /* or some other number */

int main(int argc, const char **argv) {
    char i[BUFFER_SIZE];
    fgets(i, BUFSIZ, stdin);
    while (strcmp(i, "\n") != 0) {
        // myMethod(i);
        printf("%s", i);
        fgets(i, BUFSIZ, stdin);
    }
}
