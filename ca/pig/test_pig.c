#include "pig.h"


int main() {
        char happy[] = "happy";                                                                   
        char* happy_r = pig(happy);
        printf("%s => %s\n", happy, happy_r);
        free(happy_r);

        char duck[] = "duck";
        char* duck_r = pig(duck);
        printf("%s => %s\n", duck, duck_r);
        free(duck_r);

        char glove[] = "glove";
        char* glove_r = pig(glove);
        printf("%s => %s\n", glove, glove_r);
        free(glove_r);


        char evil[] = "evil";
        char* evil_r = pig(evil);
        printf("%s => %s\n", evil, evil_r);
        free(evil_r);

        char eight[] = "eight";
        char* eight_r = pig(eight);
        printf("%s => %s\n", eight, eight_r);
        free(eight_r);

        char yowler[] = "yowler";
        char* yowler_r = pig(yowler);
        printf("%s => %s\n", yowler, yowler_r);
        free(yowler_r);

        char crystal[] = "crystal";
        char* crystal_r = pig(crystal);
        printf("%s => %s\n", crystal, crystal_r);
        free(crystal_r);

        return 0;
}

