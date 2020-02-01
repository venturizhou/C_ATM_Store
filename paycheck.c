/*  Steven Zhou
    2/1/2020
    CIS 2107
    Lab02. Paycheck_and_Revenue
    Create interface where employee can calculate their weekly pay
*/
#include <stdio.h>
#include <stdlib.h>

void summary(int id, double sal, double time, int overtime);

int main (void){

    int employeeid;
    double salary;
    double time;

    puts("Welcome to TEMPLE HUMAN RESOURCES");
    puts("");

    do{
        printf("\tEnter Employee Number: ");
        scanf("%d", &employeeid);
        //If employeeid is not a valid entry the program will exit loop
        if (employeeid <= 0){
            puts("\n\tThis is not a valid Employee Number.");
            puts("\tPlease run the program again.\n");
            break;
        }
        //If hourly salary is not a valid entry the program will exit loop
        printf("\tEnter Hourly Salary: ");
        scanf("%lf", &salary);
        if (salary <= 0){
            puts("\n\tThis is not a valid hourly salary amount.");
            puts("\tPlease run the program again.\n");
            break;
        }
        //If weekly time is not a valid entry the program will exit loop
        printf("\tEnter Weekly Time: ");
        scanf("%lf", &time);
        if (time <= 0){
            puts("\n\tThis is not a weekly time.");
            puts("\tPlease run the program again.\n");
            break;
        }
        //If employee has worked over 40 hours, extra is stored into variable called overtime
        unsigned int overtime;
        if (time > 40){
            overtime = time - 40;
            time -= overtime;
        }
        //the following prints summary statements of the ATM transaction
        summary(employeeid, salary, time, overtime);
        break;
    }while(0);
    
    puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"");
    exit(0);
}

void summary(int id, double sal, double time, int overtime){
    puts("\t==============================");
    printf("\tEmployee #: %d\n", id);
    printf("\tHourly Salary: $%.1f\n", sal);
    printf("\tWeekly Time: %.1f\n", time);
    printf("\tRegular Pay: $%.1f\n", sal*time);
    printf("\tOvertime Pay: $%.1f\n", (double)overtime*1.5*sal);
    printf("\tTotal Pay: $%.1f\n", sal*time + (double)overtime*1.5*sal);
    puts("\t==============================");
}