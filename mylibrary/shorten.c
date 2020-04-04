#include <stdio.h>

void shorten(char*s, int new_len){
    int length = 0;
    for(int i = 0; s[i] != '\0'; i++){
        length++;
    }
    if (new_len < length){
        s[new_len] = '\0';
    }
}