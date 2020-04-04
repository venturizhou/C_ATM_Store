#include <stdio.h>

void rm_right_space(char*s){
    int n = -1;
    for(int i = 0; s[i] != '\0'; i++){
        if(!isspace(s[i])){
            n = i;
        }
    }s[i++] = '\0';
}