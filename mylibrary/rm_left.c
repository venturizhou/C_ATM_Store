#include <stdio.h>

void rm_left_space(char *s){

    int n = 0;
    while(isspace(s[n])){
        n++;
    }
    int i = 0;
    for(; s[n] != '\0'; i++, n++){
        s[i] = s[n];
    }s[i] = '\0';
}

