/* Write a program to perform the following operations on a given square matrix using functions: 
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal */

#include<stdio.h>

void non_zero(int a[20][20], int n){
	int count=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][j]!=0){
				count+=1;
			}
		}
	}	
	printf("\nNonzero elements: %d", count);
} 

void upper_tri(int a[20][20], int n){
	printf("\nUpper triangular matrix:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i<j){
				printf("%d ", a[i][j]);
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
	}
}

void just_ab(int a[20][20], int n){
    printf("\nElements just above main diagonal: ");
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(i==j){
                printf("%d ", a[i-1][j]);
            }
        }
    }
    printf("\nElements just below main diagonal: ");
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(i==j){
                printf("%d ", a[i+1][j]);
            }
        }
    }
}

int main(){
	int n;
	int arr[20][20];
	printf("\nEnter size of the square matrix: ");
	scanf("%d", &n);
	printf("\nEnter elements of the matrix:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	non_zero(arr, n);
	upper_tri(arr, n);
	just_ab(arr, n);
	
	return 0;
}
