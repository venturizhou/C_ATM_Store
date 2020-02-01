/*  Steven Zhou
    2/1/2020
    CIS 2107
    Lab02. Paycheck_and_Revenue
    Create interface where store calculates total price minus any discounts given due to quantity
*/
#include <stdio.h>
#include <stdlib.h>

unsigned int discountCalc(int quantity);
void summary(double price, unsigned int quantity, unsigned int discount);

int main (void){

    double price;
    int quantity;

    puts("Welcome to \"Temple\" store");
    puts("");

    do{
    //intakes item price and breaks loop if entry is negative or zero
    printf("\t%s", "Enter item price: ");
    scanf("%lf", &price);
    if (price <= 0){
        puts("\n\tThis is not a valid item price.");
        puts("\tPlease run the program again.");
        break;
    }
    //intakes quantity and breaks loop if entry is negative or zero
    printf("\t%s", "Enter quantity: ");
    scanf("%d", &quantity);
    if (quantity <= 0){
        puts("\n\tThis is not a valid quantity order.");
        puts("\tPlease run the program again.");
        break;
    }
    //calculates discount and prints out summary
    unsigned int discount = discountCalc(quantity);
    summary(price, quantity, discount);
    }while(0);
    puts("\nThank you for using \"Temple\" store.");
    exit(0);
}

//calculates discount given by quantity purchased
unsigned int discountCalc(int quantity){
    switch (quantity) {

        case 150 ... __INT_MAX__:
            return 25;
        case 100 ... 149:
            return 15;
        case 50 ... 99:
            return 10;
        case 1 ... 49:
            return 0;
    }
}

//prints out summary statement of the transaction
void summary(double price, unsigned int quantity, unsigned int discount){
    printf("\tThe item price is: $%.1f\n", price);
    printf("\tThe order is %u item(s)\n", quantity);
    printf("\tThe cost is: $%.1f\n", price*quantity);
    printf("\tThe discount is: %.1f%%\n", (float)discount);
    double discountTotal = discount*price*quantity/100;
    printf("\tThe discount amount is: $%.1f\n", discountTotal);
    printf("\tThe total is: $%.1f\n", price*quantity-discountTotal);
}