/*
 * https://stackoverflow.com/questions/25767841/how-do-i-concatenate-the-string-elements-of-my-array-into-a-single-string-in-c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenate(size_t size, char *array[size], const char *joint){
    size_t jlen, lens[size];
    size_t i, total_size = (size-1) * (jlen=strlen(joint)) + 1;
    char *result, *p;


    for(i=0;i<size;++i){
        total_size += (lens[i]=strlen(array[i]));
    }
    p = result = malloc(total_size);
    for(i=0;i<size;++i){
        memcpy(p, array[i], lens[i]);
        p += lens[i];
        if(i<size-1){
            memcpy(p, joint, jlen);
            p += jlen;
        }
    }
    *p = '\0';
    return result;
}

/*
int main(){
    char *ss[] = { "first", "second", "last" };
    char *cat = concatenate(3, ss, "");
    puts(cat);
    free(cat);
    cat = concatenate(3, ss, ", ");
    puts(cat);
    free(cat);
    return 0;
}
*/
