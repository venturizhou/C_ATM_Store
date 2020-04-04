#include <stdio.h>

void rm_space(char*s){
    int n = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if (!isspace(s[i])){
            s[n++] = s[i];
        }
    }s[n] = '\0';
}