#include <stdio.h>
#include <stdlib.h>

char *str_zip(char *s1, char*s2){
    size_t length1= 0;
    size_t length2 = 0;
    for(;s1[length1]!='\0';length1++);
    for(;s2[length2]!='\0';length2++);
    char *temp = malloc(length1+length2+1);
  
    size_t k = 0;
    for(;k<(length1+length2);){
        if(*s1!='\0'){
            temp[k++] = *s1++;
        }
        if(*s2!='\0'){
            temp[k++] = *s2++;
        }
    }temp[k] = '\0';
    return temp;
}