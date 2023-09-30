/* Write a menu driven program to create a structure to represent complex number and perform the following operation
 using function :

1. addition of two complex number  (call by value)
2. multiplication of two complex number (call by address) */

#include<stdio.h>

struct complex_num{
    int real;
    int img;
}num1,num2;

void sum(int a1, int b1, int a2, int b2){
    printf("\nSum = %d + %di\n", (a1+a2), (b1+b2));
}

void multiply(int *x1, int *y1, int *x2, int *y2){
    printf("\nMultiplication = %d + %di\n", ((*x1 * *x2) - (*y1 * *y2)), ((*x1 * *y2) + (*y1 * *x2)));
}

int main(){
    int choice;
    printf("\nEnter complex number 1: ");
    scanf("%d %d", &num1.real, &num1.img);
    printf("\nEnter complex number 2: ");
    scanf("%d %d", &num2.real, &num2.img);

    while(1){
        printf("\nMENU");
        printf("\n1. Addition");
        printf("\n2. Multiplication");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice==1)
            sum(num1.real,num1.img,num2.real,num2.img);
        else if(choice==2)
            multiply(&num1.real,&num1.img,&num2.real,&num2.img);
        else if(choice==3)
            break;
        else
            printf("\nInvalid choice\n");
    }
    return 0;
}
