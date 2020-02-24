#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Steven Zhou
CIS 2107
Assignment Lab 05
*/

void max(int row, int col, int a[row][col]);
void rowsum(int row, int col, int a[row][col]);
void colsum(int row, int col, int a[row][col]);
void isSquare(int row, int col);
void displayOutputs(int row, int col, int a[row][col]);

int main(void){
    puts("Let's declare a 2Dim Array!");

    int row = 0;
    int col = 0;

    printf("\t%s", "How many rows? ");
    scanf("%d", &row);
    printf("\t%s", "How many columns? ");
    scanf("%d", &col);
    puts("");

    int arr[row][col];

    for (size_t i = 0; i < row; i++){
        for(size_t j = 0; j < col; j++){
            printf("\tEnter [%lu][%lu]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    puts("");
    //testing max
    max(row,col,arr);
    puts("");
    //testing rowsum first row
    rowsum(row,col,arr);
    puts("");
    //testing colsum first col
    colsum(row,col,arr);
    puts("");
    //testing isSquare
    isSquare(row,col);
    puts("");
    displayOutputs(row,col,arr);
}

//sets default max to the constant min value and then replaces if the number is greater than max
void max(int row, int col, int a[row][col]){
    int max = INT_MIN;
    for(size_t i = 0; i < row; i++){
        for(size_t j = 0; j < col; j++){
            if(a[i][j] > max){
                max = a[i][j];
            }
        }
    }printf("\tMax is %d", max);
    puts("");
}
//nested loop that iterates and sums the cols inside each row
void rowsum(int row, int col, int a[row][col]){
    for(size_t i = 0; i < row; i++){
        int sum = 0;
        for(size_t j = 0; j < col; j++){
            sum += a[i][j];
        }printf("\tThe sum is of row %2ld is %2d", i, sum);
        puts("");
    }
}

//nested loop that iterates and sums the row for each col
void colsum(int row, int col, int a[row][col]){
    for(size_t i = 0; i < col; i++){
        int sum = 0;
        for(size_t j = 0; j < row; j++){
            sum += a[j][i];
        }printf("\tThe sum is of col %ld is %d", i, sum);
        puts("");
    }
}

//checks is row == col
void isSquare(int row, int col){
    if(row == col){
        puts("\tThis is a square array.");
        return;
    }puts("\tThis is not a square array.");
}

//prints array by printing one row at a time then using a newline character to go to second row
void displayOutputs(int row, int col, int a[row][col]){
    puts("\tHere is your 2Dim array.");
    for(size_t i = 0; i < row; i++){
        printf("\t[%d", a[i][0]);
        for(size_t j = 1; j < col; j++){
            printf(",%d", a[i][j]);
        }printf("%s\n", "]");
    }
}