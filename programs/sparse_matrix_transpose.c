/* WAP to perform transpose of a given sparse matrix in 3-tuple format */

#include<stdio.h>

void sparse_transpose(int arr[20][3]){
    int r, c, nonzero;
    int transpose[20][3];
    transpose[0][0] = arr[0][1];
    transpose[0][1] = arr[0][0];
    transpose[0][2] = arr[0][2];
    int k = 1;
    for (c = 0; c < arr[0][1]; c++){
        for (r = 1; r < arr[0][2] + 1; r++){
            if (arr[r][1] == c){
                transpose[k][0] = arr[r][1];
                transpose[k][1] = arr[r][0];
                transpose[k][2] = arr[r][2];
                k++;
            }
        }
    }
    printf("\nTranspose of sparse matrix:\n");
    for (r = 0; r < arr[0][2] + 1; r++){
        for (c = 0; c < 3; c++){
            printf("%d ", transpose[r][c]);
        }
        printf("\n");
    }
}

int main(){
    int arr[20][3];
    int r, c, nonzero;
    FILE *fp;
    fp = fopen("input1.txt", "r");
    printf("\nEnter sprase matrix in 3-tuple format:\n");

    // Input from file
    // fscanf(fp, "%d %d %d", &r, &c, &nonzero);
    scanf("%d %d %d", &r, &c, &nonzero);
    arr[0][0] = r;
    arr[0][1] = c;
    arr[0][2] = nonzero;
    for (r = 1; r < nonzero + 1; r++){
        for (c = 0; c < 3; c++){
            // fscanf(fp, "%d", &arr[r][c]);
            scanf("%d", &arr[r][c]);
        }
    }

    sparse_transpose(arr);

    return 0;
}
