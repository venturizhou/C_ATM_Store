#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PIN 3014
#define MAXDEPOSIT 10000
#define MAXWITHDRAW 1000

void printBalance();
void withdraw();
void deposit();
int checkPin();
void receipt();

float balance = 5000;
unsigned int depositTotal;
unsigned int withdrawTotal;

int main(void)
{
    int check;
    check = checkPin();
    if (!check)
    {
        puts("\tYou entered the pin wrong 3 times.");
        return 0;
    }puts("");
    puts("\nWelcome to ABC Bank");
    puts("");
    int choice = 0;
    do{
        puts("\t1. Balance");
        puts("\t2. Cash Withdraw");
        puts("\t3. Cash Deposit");
        puts("\t4. Exit");
        printf("%s", "\n\t");
        scanf("%d", &choice);
        puts("");
        if (choice < 1 || choice > 4){
            puts("\tPlease enter a valid entry:");
            continue;
        }switch(choice){
            case 1:
                printBalance();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                deposit();
                break;
        }
    }while (choice != 4);
    receipt();
    exit(0);
}

//loops and gives user three attempts to find pin, if failed three times the the function returns 0
int checkPin()
{
    int userPin;
    int count = 0;
    do
    {
        printf("%s", "\tPlease enter your pin: ");
        scanf("%d", &userPin);
        if (userPin != PIN)
        {
            puts("\tThat is not correct, please try again.");
            puts("");
            count++;
        }
    } while (userPin != PIN && count < 3);
    if (count < 3)
    {
        return 1;
    }
    return 0;
}

//checks if amount is less than balance and less than daily amount
void withdraw()
{
    float amount;
    printf("%s", "\tHow much would you like to withdraw: ");
    scanf("%f", &amount);
    if (amount > balance)
    {
        puts("\tInsufficient funds.");
        puts("");
        return;
    }
    if (withdrawTotal + amount > MAXWITHDRAW)
    {
        printf("\tYou have exceeded the daily limit of $%d.00\n", MAXWITHDRAW);
        puts("");
        return;
    }
    if (fmod(amount, 20) != 0)
    {
        puts("\tPlease enter in multiples of $20.00");
        puts("");
        return;
    }
    balance -= amount;
    withdrawTotal += amount;
    puts("\tCash is dispensed below.");
    puts("");
}

//checks if less than daily amount
void deposit()
{
    float amount;
    printf("%s", "\tHow much would you like to deposit: ");
    scanf("%f", &amount);
    if (fmod(amount, 1) != 0)
    {
        puts("\tNo coins are accepted");
        puts("");
        return;
    }
    if (depositTotal + amount > MAXDEPOSIT)
    {
        printf("\tYou have exceeded the daily limit of $%d.00\n", MAXDEPOSIT);
        puts("");
        return;
    }
    balance += amount;
    depositTotal += amount;
    puts("\tPlease deposit amount now.");
    puts("");
}

void printBalance()
{
    printf("\tYour current balance is: $%.2f\n", balance);
    puts("");
}

void receipt(){
    int answer;
    while(answer != 1 && answer != 2){
        puts("\tThank you for using ABC Bank.");
        puts("\tWould you like a receipt? (1 for Yes, 2 for No)");
        printf("\t");
        scanf("%d",&answer);
        if(answer == 1){
            puts("\tReceipt printing...");
            return;
        }
    }
}