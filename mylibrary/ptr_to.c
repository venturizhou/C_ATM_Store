#include <stdio.h>

char *ptr_to(char*h, char*n){
    for(; *h !='\0'; h++){
        if(*h==*n){
            return h;
        }
    }return "NULL";
}