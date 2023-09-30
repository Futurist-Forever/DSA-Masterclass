/* Write a program to create an array of n elements using dynamic memory allocation. 
Calculate sum of all the prime elements of the array using function and de-allocate 
the memory of the array after its use. */

#include<stdio.h>
#include<stdlib.h>

int checkprime(int num) {
    int i;

    if (num <= 1) {
        return 0;
    }

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int sumofprime(int *arr, int n) {
    int i, sum = 0;

    for (i = 0; i < n; i++) {
        if (checkprime(arr[i])) 
            sum += arr[i];
    }

    free(arr);
    return sum;
}

int main() {
    int i, n;
    printf("\nEnter size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("\nEnter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nSum = %d\n", sumofprime(arr, n));

    return 0;
}
