#include <stdio.h>

int is_empty(char*s){
    for(; *s != '\0'; s++){
        if(!isspace(*s)){
            return 0;
        }
    }return 1;
}