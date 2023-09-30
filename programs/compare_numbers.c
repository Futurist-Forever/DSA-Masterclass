/* Write a program to read two numbers and compare the numbers using function call by address. */

#include<stdio.h>

void compare_num(int *x,int *y){
    if(*x>*y)
        printf("\n%d is greater than %d\n",*x,*y);
    else if(*x<*y)
        printf("\n%d is greater than %d\n",*y,*x);
    else if(*x==*y)
        printf("\nBoth numbers are same\n");
}

int main(){
    int a,b;

    printf("\nEnter two numbers: ");
    scanf("%d %d",&a,&b);

    compare_num(&a,&b);
    
    return 0;
}
