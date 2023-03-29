#include <stdio.h>

#include "riffle.h"

int main() {
    int shuffles;

    char *filename = "quality.txt";
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening the file %s", filename);
        return -1;
    }

    for (shuffles = 1; shuffles <= 15; shuffles++) {
        float aq = average_quality(50, shuffles, 30);
        fprintf(fp,"average quality (with %d shuffles): %f \n", shuffles, aq);
        printf("average quality (with %d shuffles): %f \n", shuffles, aq);
    }

    fclose(fp);
    return 0;
}
