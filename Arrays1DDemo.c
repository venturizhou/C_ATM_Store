//Steven Zhou
//CIS 2107 
// 2-14-20
//Create functions working with arrays

#include <stdio.h>
#include <stdlib.h>
#define LOW 10
#define HIGH 5
#define SIZE 36
#define LINE 6


void fillArray(int a[]);
void printArray(int a[]);
void findWithRange(int a[]);
void reverseArray(int a[]);
void reverseRange(int a[]);
void findSequence(int a[]);

//checks before any programs are run that LOW is smaller than HIGH and will exit the main if so
int main(void){
    if (HIGH < LOW){
    printf("LOW: %d is greater than HIGH: %d. Please fix before running again. \n", LOW, HIGH);
    return 0;
    }
    int a[SIZE];
    fillArray(a);
    printArray(a);
    puts("");
    puts("Max number in range.");
    puts("");
    findWithRange(a);
    puts("");
    puts("Reverse");
    puts("");
    reverseArray(a);
    puts("");
    puts("Reverse Range");
    puts("");
    reverseRange(a);
    puts("");
    findSequence(a);
    exit(0);
}

//generates random numbers for the array using rand() and using LOW HIGH constants to determine the range
void fillArray(int a[]){
    for(size_t i = 0; i < SIZE; i++){
        a[i] = rand()%(HIGH+1);
    }
}
//locate max number between the index of predefined constants LOW and HIGH
void findWithRange(int a[]){
    int max = a[LOW];
    for(size_t i = LOW+1; i <= HIGH; i++){
        if(a[i]>max){
            max = a[i];
        }
    }printf("The max number between index %d, and index %d, is %d.", LOW, HIGH, max);
    puts("");
}
//prints out the array in a 6 by 6 format
void printArray(int a[]){
    for (size_t j = 0; j < SIZE; j += LINE){
    for (size_t i = j; i < j+LINE; i++){
        printf("%2d ", a[i]);
    }puts("");
    }
}
//swaps int at corresponding positions in the array so the array ends up being reversed
void reverseArray(int a[]){
    puts("Original:");
    printArray(a);
    for(size_t i = 0; i < SIZE/2; i++){
        int temp = a[i];
        a[i] = a[SIZE-1-i];
        a[SIZE-1-i] = temp;
    }puts("");
    puts("Reversed:");
    printArray(a);
}
//reverses a section of the range between the index LOW and index HIGH
void reverseRange(int a[]){
    puts("Original");
    printArray(a);
    for(size_t i = LOW; i <= (HIGH+LOW)/2; i++){
        int temp = a[i];
        a[i] = a[SIZE-1-i];
        a[SIZE-1-i] = temp;
    }puts("");
    puts("Reversed.");
    printArray(a);
}
//find if sequence of two numbers followed by each other exists within the array
void findSequence(int a[]){
    int Tom;
    int Jerry;
    printf("%s", "Enter two numbers: ");
    scanf("%d", &Tom);
    scanf("%d", &Jerry);
    puts("");
    for(size_t i = 0; i < SIZE-1; i++){
        if(a[i] == Tom && a[i+1] == Jerry){
            printf("Sequence found at: %d", a[Tom]);
            puts("");
            return;
        }
    }puts("Sequence not found.");
}