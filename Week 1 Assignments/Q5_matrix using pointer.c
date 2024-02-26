#include <stdio.h>
#include <stdlib.h>

void mul_mat(int *mat_a, int *mat_b, int *mat_res, int n){
    for(int i=0;i<n;++i){
        for(int j =0;j<n;++j){
            *(mat_res + i*n + j) = 0;
            for (int k=0;k<n;++k){
                *(mat_res + i*n + j) += (*(mat_a +i*n + k)) * (*(mat_b +k*n+ j));
            }   }   }   }

void dis_mat(int *matrix, int n){
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            printf("%d\t", *(matrix + i * n + j));
        }
        printf("\n");
    }   }
int main() {
    int n;
    printf("Enter the row/col of the square matrix: ");
    scanf("%d",&n);
    int *mat_a =(int *)malloc(n*n*sizeof(int));
    int *mat_b =(int *)malloc(n*n*sizeof(int));
    int *mat_res =(int *)malloc(n*n*sizeof(int));
    printf("Enter the elements of matrix a:\n");
    for (int i=0;i<n*n;++i) {
        scanf("%d", &mat_a[i]);
    }
    printf("Enter the elements of matrix b:\n");
    for (int i=0;i<n*n;++i) {
        scanf("%d", &mat_b[i]);
    }

    mul_mat(mat_a, mat_b, mat_res, n);

    printf("result Matrix:\n");
    dis_mat(mat_res, n);

    free(mat_a);
    free(mat_b);
    free(mat_res);
}
