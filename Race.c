#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define END 70

/*
Steven Zhou
2/27/20
CIS 2107
Lab 06 Race
*/

void turtlemove(size_t num, int*tPtr);
void haremove(size_t num, int*hPtr);
void race(int*tPtr, int*hPtr);

int main(void){
    //intialize the starting positions and setup the game and seed the random number generator
    int tpos = 0;
    int hpos = 0;
    puts("\tON YOUR MARK, GET SET");
    puts(" \tBANG");
    puts("\tAND THEY'RE OFF");
    srand(time(NULL));

    //race logic
    do{
        size_t random = rand() % 10; //generates random number from 0-9
        turtlemove(random, &tpos);
        haremove(random, &hpos);
        puts("");
        race(&tpos,&hpos);
        sleep(1);
    }while(tpos < 70 && hpos < 70);
    
    //Print the finish of the race
    if(tpos == hpos){
        puts("\tTIE!");
    }
    else if(tpos == 70){
        puts("\tTORTOISE WINS!");
    }
    else{
        puts("\tHARE WINS!");
    }
    return 0;
}
//pass in random int to pick the movment and pass in reference of tortoise position
void turtlemove(size_t num, int*tPtr){
    //fast plod
    if(num < 5){
        *tPtr+=3;
    }
    //slip
    else if(num < 7){
        *tPtr-=6;
    }
    //slow plod
    else{
        *tPtr+=1;
    }
    //these statements make sure I don't exceed 70 when printing and that the position is set to 0 after negative
    if (*tPtr > END){
        *tPtr = END;
    }
    if (*tPtr < 0){
        *tPtr = 0;
    }
}

//pass in value from random for movement then pass in reference to hare position
void haremove(size_t num, int*hPtr){
    //sleep
    if(num < 2){
    }
    //big hop
    else if(num < 4){
        *hPtr+=9;
    }
    //big slip
    else if (num < 5){
        *hPtr-=12;
    }
    //small hop
    else if (num < 8){
        *hPtr+=1;
    }
    //small slip
    else{
        *hPtr-=2;
    }
    //these statements make sure I don't exceed 70 when printing and that the position is set to 0 after negative
    if (*hPtr > END){
        *hPtr = END;
    }
    if (*hPtr < 0){
        *hPtr = 0;
    }
}

void race(int*tPtr, int*hPtr){
    //if same position we can just loop to print space either less than hpos or tpos and then print ouch
    if(*tPtr == *hPtr){
        for (size_t i = 0; i < *tPtr; i++){
            printf("%s", " ");
        }
        puts("OUCH");
    }
    //if tortoise is behind print space up to its position and then print t at the value
    //then print spaces inbetween the tortoise and the hare, exit and print h position
    else if(*tPtr < *hPtr){
        for (size_t i = 0; i < *tPtr; i++){
            printf("%s", " ");
        }printf("%s", "T");
        for (size_t i = *tPtr+1; i < *hPtr; i++ ){
            printf("%s", " ");
        }puts("H");
    }
    //if hare is behind print space up to its position and then print h at the value
    //then print spaces inbetween the tortoise and the hare, exit and print t position
    else{
        for (size_t i = 0; i < *hPtr; i++){
            printf("%s", " ");
        }printf("%s", "H");
        for (size_t i = *hPtr+1; i < *tPtr; i++ ){
            printf("%s", " ");
        }puts("T");
    }
}