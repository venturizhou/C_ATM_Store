#include <stdio.h>

int len_diff(char *s1, char*s2){
    int count = 0;
    for(;*s1 != '\0' && *s2 != '\0'; s1++, s2++){
    }
    if (*s1 != '\0'){
        for(;*s1 != '\0'; s1++){
            count++;
        }return count;
    }else if (*s2 != '\0'){
        for(;*s2 != '\0'; s2++){
            count++;
        }return count;
    }return 0;
}