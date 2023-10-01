/* WAP to represent a given sparse matrix in 3-tuple format using 2-D array. */

#include<stdio.h>

void sparse(int a[20][20], int r, int c){ // r = no. of rows, c = no. of columns
    int mat_sparse[20][3];
    mat_sparse[0][0] = r;
    mat_sparse[0][1] = c;
    int m=0; // m = no. of non-zero elements
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(a[i][j]!=0){
                mat_sparse[m+1][0] = i;
                mat_sparse[m+1][1] = j;
                mat_sparse[m+1][2] = a[i][j];
                m++;
            }
        }
    }
    mat_sparse[0][2] = m;

    printf("\nSparse matrix in 3-tuple format:\n");
    for(int i=0; i<m+1; i++){
        for(int j=0; j<3; j++){
            printf("%d ", mat_sparse[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int size, r, c; // r = no. of rows, c = no. of columns
    int arr[20][20];

    printf("\nEnter size of the sparse matrix: ");
    scanf("%d %d", &r, &c);

    printf("\nEnter elements of sparse matrix:\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    sparse(arr, r, c);

    return 0;
}
