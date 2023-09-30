/* WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array */

#include<stdio.h>

void insert_pos(int A[], int item, int pos, int* N, int size){ // *N = no. of elements
    if(N==0){
        A[0] = item;
        *N += 1;
        printf("\nElement inserted at 1st position");
    }
    else if(*N==size){
        printf("\nThe array is full");
    }
    else{
        if(pos>*N+1 || pos>size+1){
            printf("\nInvalid position");
        }
        else{
            for(int i=*N; i>=pos; i--){
                A[i] = A[i-1];
            }
            A[pos-1] = item;
            *N += 1;
            printf("\nElement inserted");
        }
    }
}

void delete_pos(int A[], int pos, int *N){
    if(*N==0){
        printf("\nArray is Empty");
    }
    else{
        if(pos>=*N+1){
            printf("\nInvalid position");
        }
        else{
            for(int i=pos-1; i<*N; i++){
                A[i] = A[i+1];
            }
            *N -= 1;
            printf("\nElement deleted");
        }
    }
}

void linear_search(int A[], int ele, int *N){
    int c=0;
    for(int i=0; i<*N; i++){
        if(A[i]==ele){
            printf("\nElement found at position %d", i+1);
            c = 1;
        }
    }
    if(c==0){
    	printf("\nElement is not present in the array");
    }
}

void traversal(int A[], int *N){
    printf("\nArray Elements: ");
    for(int i=0; i<*N; i++){
        printf("%d ", A[i]);
    }
}

int main(){
    int arr[100];
    int n, choice, ele, pos;

    printf("\nEnter size n: ");
    scanf("%d", &n);

    printf("\nEnter elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    while(1){
        printf("\n\n***MENU***");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Linear Search");
        printf("\n4. Traverse");
        printf("\n5. Exit");

        printf("\nEnter option: ");
        scanf("%d", &choice);

        if(choice==1){
            printf("\nElement to insert: ");
            scanf("%d", &ele);
            printf("\nEnter position: ");
            scanf("%d", &pos);
            insert_pos(arr, ele, pos, &n, 100);
        }
        else if(choice==2){
            printf("\nEnter position: ");
            scanf("%d", &pos);
            delete_pos(arr, pos, &n);
        }
        else if(choice==3){
            printf("\nElement to search: ");
            scanf("%d", &ele);
            linear_search(arr, ele, &n);
        }
        else if(choice==4){
            traversal(arr, &n);
        }
        else if(choice==5){
            break;
        }
        else{
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}
