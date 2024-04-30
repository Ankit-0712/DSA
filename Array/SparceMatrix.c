#include<stdio.h>

int isSparse(int *matrix, int rows, int cols){
    int count = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(matrix + i *cols + j)==0){
                count++;
            }
        }
    }
        if(count>(rows * cols)/2){
            return 1;
        }
        else{
            return 0;
        }
        
}
int main(){
    int matrix[100][100], rows, cols;

    printf("Enter the number of rows and cols in matrix");
    scanf("%d%d",&rows,&cols);

    printf("Enter the elements of the matrix");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    int sparse = isSparse(&matrix[0][0],rows, cols);

    if(sparse)
    printf("The given matrix is sparse");

    else
    printf("Matrix is not sparse");

    return 0;

}