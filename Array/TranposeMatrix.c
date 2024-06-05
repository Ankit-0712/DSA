#include<stdio.h>

int main(){
    int matrix[100][100], transpose[100][100];
    int r, c;
    
    printf("Enter the number of rows and column");
    scanf("%d %d", &r,&c);

    printf("\nEnter the matrix element\n");
    for(int i=0;i<r;i++){
        for(int j= 0;j<c;j++){
            printf("Enter elements matrix%d%d",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
    //printing the matrix
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d",matrix[i][j]);

            if(j==c-1){
                printf("\n");
            }
        }
    }
    //transpose
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("Transpose matrix");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d",transpose[i][j]);
                if(j==r-1){
                    printf("\n");
                }
        }
    }
    return 0;
}