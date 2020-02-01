#include <stdio.h>

int main (void){

    int employeeid;
    double salary;
    double time;

    puts("Welcome to TEMPLE HUMAN RESOURCES");
    puts("");

    while(1){
        printf("\tEnter Employee Number:");
        scanf("%d", &employeeid);

        if (employeeid < 0){
            puts("\tThis is not a valid Employee Number.");
            puts("\tPlease run the program again.");
            return 0;
        }

        printf("\tEnter Hourly Salary: ");
        scanf("%lf", &salary);
        if (salary < 0){
            puts("\tThis is not a valid hourly salary amount.");
            puts("\tPlease run the program again.");
            return 0;
        }

        printf("\tEnter Weekly Time: ");
        scanf("%lf", &time);
        if (time < 0){
            puts("\tThis is not a weekly time.");
            puts("\tPlease run the program again.");
            return 0;
        }
        puts("\t==============================");
        printf("\tEmployee #: %d\n", employeeid);
        printf("\tHourly Salary: %.1f\n", salary);
        printf("\tWeekly Time: %.1f\n", time);
        printf("\tRegular Pay: %.2f\n", salary*time);
    }system("pause");
}