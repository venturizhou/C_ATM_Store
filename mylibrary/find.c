#include <stdio.h>

int find(char *h, char*n){
    for(int i = 0; h[i] != '\0';i++){
        if(h[i]==*n){
            return i;
        }
    }return -1;
}