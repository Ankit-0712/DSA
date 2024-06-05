#include<stdio.h>
void insertion(int arr[]);
void swapArray(int arr[], int first, int second);
int main(){
    int arr[] ={5,3,4,1,2};
    insertion(arr);
    for(int i=0;i<5;i++){
        printf("%d",&arr);
    }
}

void insertion(int arr[]){
    for(int i=0;i<5;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j]<arr[j-1]){
                swapArray(arr,j,j-1);
            }
            else{
                break;
            }
        }
    }
}

void swapArray(int arr[], int first, int second){
    int temp  = arr[first];
    arr[first]= arr[second];
    arr[second] = temp;
}