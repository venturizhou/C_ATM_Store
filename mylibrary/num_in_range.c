#include <stdio.h>
#include <ctype.h>

int num_in_range(char*s1, char b, char t){
    int count = 0;
    for(size_t i = 0; s1[i] != '\0'; i++){
        if (s1[i]==b){
            count++;
            for(;s1[i] != '\0' && s1[i] != t; i++){
                count++;
            }
        }
        if(s1[i] =='\0'){
            return 0;
        }
    }
    return count;
}