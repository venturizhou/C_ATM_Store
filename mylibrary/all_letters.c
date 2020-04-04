#include <stdio.h>
#include <ctype.h>

int all_letters(char*s){
    for (size_t i = 0; s[i] != '\0'; i++){
        if (!isalpha(s[i])){
            return 0;
        }
    }return 1;
}