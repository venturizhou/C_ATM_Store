#include <stdio.h>
#include <stdlib.h>
#define STUDENTS 4
#define EXAMS 3
/*
Steven Zhou
CIS 2107
Assignment Lab 05
*/

void minimum(size_t pupils, size_t tests, const int grades[][EXAMS]);
void maximum(size_t pupils, size_t tests, const int grades[][EXAMS]);
void average(size_t pupils, size_t tests, const int grades[][EXAMS]);
void printArray(size_t pupils, size_t tests, const int grades[][EXAMS]);

//I put the functions into array of pointers then created a do while loop to run the menu
//If the input is not valid number it will simply output the menue until user selects correct option
int main(void){
    int choice;
    int studentGrades[STUDENTS][EXAMS] = {{80,75,90},{83,60,57},{55,89,60},{99,75,22}};
    void (*processGrades[4])(size_t,size_t,const int[][EXAMS]) = {printArray, minimum, maximum, average};
    do {
        puts("Enter a choice:");
        puts("\t0  Print the array of grades");
        puts("\t1  Find the minimum grade");
        puts("\t2  Find the maximum grade");
        puts("\t3  Print the average on all tests for each student");
        puts("\t4  End Program");
        puts("");
        scanf("%d", &choice);
        if (choice > -1 && choice < 4){
            (*processGrades[choice])(STUDENTS,EXAMS,studentGrades);
        }puts("");
    }while(choice !=4);
}

//loops through 2darray to find smallest score
void minimum(size_t pupils, size_t tests, const int grades[][EXAMS]){
    unsigned int lowGrade = 100;
    for(size_t i = 0; i < pupils; i++){
        for(size_t j = 0; j < tests; j++){
            if (grades[i][j] < lowGrade){
                lowGrade = grades[i][j];
            }
        }
    }printf("\tThe lowest grade was %u", lowGrade);
    puts("");
}

//loops through 2darray to find largest score
void maximum(size_t pupils, size_t tests, const int grades[][EXAMS]){
    unsigned int highGrade = 0;
    for(size_t i = 0; i < pupils; i++){
        for(size_t j = 0; j < tests; j++){
            if (grades[i][j] > highGrade){
                highGrade = grades[i][j];
            }
        }
    }printf("\tThe highest grade was %u", highGrade);
    puts("");
}

//prints average for each student
void average(size_t pupils, size_t tests, const int grades[][EXAMS]){
    for(size_t i = 0; i < pupils; i++){
        double average = 0;
        for(size_t j = 0; j < tests; j++){
            average += grades[i][j];
            }printf("\tAverage grade for student %ld is %.2lf\n", i+1, average/EXAMS);
        }
}

//prints out formatted version of the 2darray
void printArray(size_t pupils, size_t tests, const int grades[][EXAMS]){
        puts("\t\t   [0] [1] [2]");
    for(size_t i = 0; i < pupils; i++){
        printf("\tstudent[%lu] [%d", i, grades[i][0]);
        for(size_t j = 1; j < tests; j++){
            printf(",%d", grades[i][j]);
        }printf("%s\n", "]");
    }
}